/* win32 shell tools */

/* shell_quote()
 surround dangerous strings with double quotes.
 escape quotes and backslashes.
 dest should be twice as large as source
  + 2 (for quotes) + 1 for zero byte + 1 for possible endslash */
int shell_quote (char * dest, const char * source) {
  const char * characters = " &<>|^\t";
  /* Chars other than command separators are actual only when command
     interpreter is used */
  BOOL ech, quote = !(*source); /* quote empty arguments */
  int escaped = 0;
  char * dcp = dest;
  *dcp++ = ' ';
  while (*source) {
    quote = quote || strchr(characters,*source);
    ech = *source == '\\';
    if (!escaped && *source == '"') *dcp++ = '\\';
    *dcp++ = *source++;
    escaped = !escaped && ech;
  }
  if (quote) {
    if (escaped) *dcp++ = '\\'; /* double ending slash */
    *dcp++ = '"'; *dest = '"'; }
  *dcp = 0;
  /* shift string left if no quote was inserted */
  if (!quote) for (dcp = dest;;dcp++) if (!(*dcp = dcp[1])) break;
  return dcp - dest;
}

/*========== shell shortcut resolution ==========*/
#include <shlobj.h>

/* is_cygwin_symlink based on path.cc from cygwin sources
   for win_shortcut_hdr description see also,
   http://msdn.microsoft.com/en-us/library/dd871305(PROT.10).aspx */

static const GUID GUID_shortcut =
  {0x00021401L, 0, 0, {0xc0, 0, 0, 0, 0, 0, 0, 0x46}};

enum {
  WSH_FLAG_IDLIST = 0x01,
  WSH_FLAG_FILE = 0x02,
  WSH_FLAG_DESC = 0x04,
  WSH_FLAG_RELPATH = 0x08,
  WSH_FLAG_WD = 0x10,
  WSH_FLAG_CMDLINE = 0x20,
  WSH_FLAG_ICON = 0x40
};

struct win_shortcut_hdr
  {
    DWORD size;            /* Header size in bytes.  Must contain 0x4c. */
    GUID magic;            /* GUID of shortcut files. */
    DWORD flags;           /* Content flags.  See above. */

    /* The next fields from attr to icon_no are always set to 0 in Cygwin
       and U/Win shortcuts. */
    DWORD attr;            /* Target file attributes. */
    FILETIME ctime;        /* These filetime items are never touched by the */
    FILETIME mtime;        /* system, apparently. Values don't matter. */
    FILETIME atime;
    DWORD filesize;        /* Target filesize. */
    DWORD icon_no;         /* Icon number. */

    DWORD run;             /* Values defined in winuser.h. Use SW_NORMAL. */
    DWORD hotkey;          /* Hotkey value. Set to 0.  */
    DWORD dummy[2];        /* Future extension probably. Always 0. */
  };

#define WINSHDRSIZE sizeof(struct win_shortcut_hdr)

static int
cmp_shortcut_header (struct win_shortcut_hdr *file_header)
{
  /* A Cygwin or U/Win shortcut only contains a description and a relpath.
     Cygwin shortcuts also might contain an ITEMIDLIST. The run type is
     always set to SW_NORMAL. */
  DWORD * pzero = &file_header->attr;
  /* FILETIME is two DWORDS so check it as array of DWORDS */
  while (pzero < &file_header->run && !*pzero++);
  return file_header->size == WINSHDRSIZE
      && !memcmp (&file_header->magic, &GUID_shortcut, sizeof GUID_shortcut)
      && (file_header->flags & ~WSH_FLAG_IDLIST)
         == (WSH_FLAG_DESC | WSH_FLAG_RELPATH)
      && pzero >= &file_header->run
      && file_header->run == SW_NORMAL;
}

enum cygsym_enum { cygsym_notsym = 0, cygsym_issym, cygsym_err };

enum cygsym_enum is_cygwin_symlink (const char * filename);

enum cygsym_enum is_cygwin_symlink (const char * filename)
{
  HANDLE handle;
  enum cygsym_enum result = cygsym_err;
  handle = CreateFile(filename,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,
                      NULL,OPEN_EXISTING,FILE_FLAG_SEQUENTIAL_SCAN,NULL);
  if (handle == INVALID_HANDLE_VALUE) return result;
  do {
    DWORD got;
    BY_HANDLE_FILE_INFORMATION finfo;
    struct win_shortcut_hdr header;
    if (!GetFileInformationByHandle (handle, &finfo)) break;
    result = cygsym_notsym;
    if (!(finfo.dwFileAttributes & FILE_ATTRIBUTE_READONLY)) break;
    if (GetFileSize (handle, NULL) > 8192) break;
    if (!ReadFile (handle, &header, WINSHDRSIZE, &got, NULL)) break;
    if (got != WINSHDRSIZE || !cmp_shortcut_header (&header))
      break;
    result = cygsym_issym;
  } while (0);
  CloseHandle(handle);
  return result;
}

/* We will need "breakthrough" (BT) version of every COM function
   which could be called on unitialized (in the current thread)
   COM library  */

HRESULT BTCoCreateInstance (REFCLSID rclsid,  LPUNKNOWN pUnkOuter,
                            DWORD dwClsContext, REFIID riid,
                            LPVOID * ppv)
{
  HRESULT result = CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
  if (result != CO_E_NOTINITIALIZED || CoInitialize(NULL) != S_OK)
    return result;
  return CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
}

/* extracts a filename field from windows shortcut
 > filename: name the shortcut file
 < resolved: buffer not less than MAX_PATH
 < result:   true if link was successfully resolved */
static BOOL resolve_shell_shortcut (LPCSTR filename, LPSTR resolved) {
  HRESULT hres;
  IShellLink* psl;
  WIN32_FIND_DATA wfd;
  BOOL result = FALSE;
  IPersistFile* ppf;

  /* no matter it's FS error or not cygwin shortcut -
     probably it should be fixed */
  if (is_cygwin_symlink(filename) != cygsym_issym) return FALSE;
  /* Get a pointer to the IShellLink interface. */
  hres = BTCoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
                            &IID_IShellLink, (LPVOID*)&psl);
  if (FAILED(hres)) return FALSE;
  /* Get a pointer to the IPersistFile interface. */
  hres = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile,(LPVOID *) &ppf);
  if (SUCCEEDED(hres)) {
    WCHAR wsz[MAX_PATH];
    /* Ensure that the string is Unicode. */
    MultiByteToWideChar(CP_ACP, 0, filename, -1, wsz,MAX_PATH);
    /* Load the shortcut. */
    hres = ppf->lpVtbl->Load(ppf, wsz, STGM_READ);
    if (SUCCEEDED(hres)) {
      /* Get the path to the link target. */
      hres = psl->lpVtbl->GetPath(psl, resolved, MAX_PATH,
                                  (WIN32_FIND_DATA *)&wfd,
                                  4 /* SLGP_RAWPATH */);
      if (SUCCEEDED(hres)) result = TRUE;
      if (!*resolved) {
        /* empty string. maybe broken link. try to get description
           as cygwin stores filenames there */
        hres = psl->lpVtbl->GetDescription(psl, resolved, MAX_PATH);
        if (FAILED(hres)) *resolved = 0;
      }
    }
    /* Release the pointer to the IPersistFile interface. */
    ppf->lpVtbl->Release(ppf);
  }
  /* Release the pointer to the IShellLink interface. */
  psl->lpVtbl->Release(psl);
  return result;
}

#if !defined(cpslashp)
# define cpslashp(c) ((c) == '\\' || (c) == '/')
#endif

/* Uses the base from filename to augment pathname.
   Return false when (pathname is relative AND filename doesn't
   contain the base), so pathname (contained in shortcut)
   cannot be referenced other than to current directory
   what is wrong. */
static BOOL augment_relative_pathname(LPCSTR filename, LPSTR pathname) {
  /* check if pathname is absolute */
  /* what to do with "/bar/foo" pathnames ?*/
  if (cpslashp(pathname[0])) return FALSE; /* let's panic */
  if (((pathname[0] >= 'a' && pathname[0] <= 'z')
    || (pathname[0] >= 'A' && pathname[0] <= 'Z'))
    && pathname[1] == ':' && cpslashp(pathname[2])) return TRUE;
  if (pathname[0] == '\\' && pathname[1] == '\\') return TRUE;
  {
    int fl = strlen(filename);
    int pl = strlen(pathname);
    const char * cp = filename + fl - 1;
    /* find the last slash */
    for (;!cpslashp(*cp) && cp > filename;cp--);
    if (!cpslashp(*cp)) return FALSE; /* no slash */
    memmove(pathname + (cp - filename + 1),pathname,pl + 1);
    memmove(pathname,filename,cp - filename + 1);
  }
  return TRUE;
}

typedef enum {
  shell_shortcut_notresolved = 0,
  shell_shortcut_notexists,
  shell_shortcut_file,
  shell_shortcut_directory
} shell_shortcut_target_t;

/* resolves shortcuts to shortcuts
 > filename : name of link file to resolve
 < resolved : buffer to receive resolved name
 < result : status of resolving and target file attributes */
static shell_shortcut_target_t
resolve_shell_shortcut_more (LPCSTR filename, LPSTR resolved)
{
  char pathname[_MAX_PATH];
  char pathname1[_MAX_PATH];
  int dirp = 0;
  int exists = 0;
  int try_counter = 33;
  int l, resolvedp = resolve_shell_shortcut(filename,pathname)
    && augment_relative_pathname(filename,pathname);
  /* handle links to links. cygwin can do such */
  while (resolvedp && try_counter--) {
    l=strlen(pathname);
    if (l >= 4 && stricmp(pathname+l-4,".lnk") == 0)
      resolvedp = resolve_shell_shortcut(pathname,pathname1)
              && augment_relative_pathname(pathname,pathname1)
              && strcpy(pathname,pathname1);
    else {
    /* not a link to shortcut but can be the symbolic filename */
      strcpy(pathname+l,".lnk");
      if (!resolve_shell_shortcut(pathname,pathname1)
        || !augment_relative_pathname(pathname,pathname1)) {
        pathname[l] = '\0'; break; }
      else strcpy(pathname,pathname1);
    }
  }
  if (resolvedp) { /* additional checks */
    DWORD fileattr = GetFileAttributes(pathname);
    exists = fileattr != 0xFFFFFFFF;
    dirp = exists && fileattr&FILE_ATTRIBUTE_DIRECTORY;
    if (resolved) {
      strcpy(resolved,pathname);
      if (dirp) strcat(resolved,"\\");
    }
    if (dirp) return shell_shortcut_directory;
    if (exists && !dirp) return shell_shortcut_file;
    return shell_shortcut_notexists;
  } else return shell_shortcut_notresolved;
}

/* see if a file is normal file or it is a "shell symlink"
 If directory+filename exists do nothing return false
 If it doesn't but direstory+filename+".lnk" exists then
 try to read it. On reading success return true with lnk
 filename value as resolved. See resolve_shell_shortcut also.
 > filename: resolving file name
 < resolved: buffer for resolved path and filename.
 < result: shell_shortcut_notresolved if file exists or link is invalid.
           otherwise - shortcut target status */
static shell_shortcut_target_t
resolve_shell_symlink (LPCSTR filename, LPSTR resolved)
{
  char pathname[_MAX_PATH];
  DWORD fileattr;

  strcpy(pathname,filename);
  fileattr = GetFileAttributes(pathname);
  if (fileattr != 0xFFFFFFFF) return shell_shortcut_notresolved;
  strcat(pathname,".lnk");
  fileattr = GetFileAttributes(pathname);
  if (fileattr == 0xFFFFFFFF) return shell_shortcut_notresolved;
  return resolve_shell_shortcut_more(pathname,resolved);
}

/* the ultimate shortcut megaresolver
   style inspired by directory_search_scandir
 > namein: absolute filename pointing to file or directory
            wildcards (only asterisk) may appear only as filename
 < nameout: filename with directory and file shortcuts resolved
             on failure holds filename resolved so far
 < result:  true if resolving succeeded */
BOOL real_path (LPCSTR namein, LPSTR nameout) {
  WIN32_FIND_DATA wfd;
  HANDLE h = NULL;
  char * nametocheck;
  char * nametocheck_end;
  int    name_len;
  /* drive|dir1|dir2|name
           ^nametocheck
               ^nametocheck_end */
  char saved_char;
  BOOL next_name = 0;/* if we found an lnk and need to start over */
  int try_counter = 33;
  if ((name_len = strlen(namein)) >= MAX_PATH) return FALSE;
  strcpy(nameout,namein);
  do { /* whole file names */
    next_name = FALSE;
    if (!*nameout) return FALSE;
    /* skip drive or host or first slash */
    nametocheck = nameout;
    if (((*nametocheck >= 'a' && *nametocheck <= 'z')
         || (*nametocheck >= 'A' && *nametocheck <= 'Z'))
        && nametocheck[1] == ':')
    { if (cpslashp(nametocheck[2])) {
        /* drive */
        nametocheck += 3;
      } else {
        /* default directory on drive */
        char drive[4] = "C:.", *name;
        int default_len;
        drive[0] = namein[0];
        if (!GetFullPathName(drive,_MAX_PATH,nameout,&name)
            || (default_len = strlen(nameout)) + name_len
               >= _MAX_PATH) return FALSE;
        nameout[default_len] = '\\';
        strcpy(nameout + default_len + 1, namein + 2);
        name_len += default_len - 1; /* Was C:lisp.exe
                                        Now C:\clisp\lisp.exe
                                        removed 2
                                        added default_len + 1 chars */
        nametocheck += default_len + 1;
    } }
    else if (nametocheck[0]=='\\' && nametocheck[1]=='\\') {
      int i;
      /* host */
      nametocheck+=2;
      for (i=0;i<2;i++) {/* skip host and sharename */
        while (*nametocheck && !cpslashp(*nametocheck))
          nametocheck++;
        if (*nametocheck) nametocheck++; else return FALSE;
      }
    } else if (cpslashp(*nametocheck)) nametocheck++;
    /* prefix skipped; start checking */
    do { /* each component after just skipped */
      int dots_only = 0;
      int have_stars = 0;
      /* separate a component */
      for (nametocheck_end = nametocheck;
           *nametocheck_end && !cpslashp(*nametocheck_end);
           nametocheck_end++);
      if (*nametocheck_end && nametocheck_end == nametocheck)
        return FALSE;/* two slashes one after another */
      /* save slash or zero */
      saved_char = *nametocheck_end;
      *nametocheck_end = 0;
      /* Is it . or .. ? FFF handles this strange way */
      { char * cp = nametocheck;
        for (;*cp=='.';cp++);
        dots_only = !(*cp) && cp > nametocheck; }
      /* Asterisks in the middle of filename: error
         Asterisks as pathname: success */
      { char * cp = nametocheck;
        for (;*cp && *cp!='*';cp++);
        have_stars = *cp == '*'; }
      if (have_stars && saved_char) return FALSE;
      if (!have_stars) {
        if (dots_only || !*nametocheck) {
          /* treat 'start/./end', 'drive/', 'host/' specially */
          /* search for ....\.\* */
          char saved[2];
          if (nametocheck_end - nameout + 2 > MAX_PATH) return FALSE;
          saved[0] = nametocheck_end[1]; saved[1] = nametocheck_end[2];
          /* !*nametocheck here means there was "something\" before */
          strcpy(nametocheck_end,*nametocheck?"\\*":"*");
          h = FindFirstFile(nameout,&wfd);
          nametocheck_end[1] = saved[0]; nametocheck_end[2] = saved[1];
          nametocheck_end[0] = 0;
          if (h != INVALID_HANDLE_VALUE) {
            FindClose(h); /* don't substitute */
          } else return FALSE; /* don't try lnk */
        } else {/* not only dots */
          h = FindFirstFile(nameout,&wfd);
          if (h != INVALID_HANDLE_VALUE) {
            /* make space for full (non 8.3) name component */
            int     l = strlen(wfd.cFileName),
                 oldl = nametocheck_end - nametocheck,
                 new_name_len = name_len + l - oldl;
            FindClose(h);
            if (new_name_len >= _MAX_PATH) return FALSE;
            if (l != oldl) {
              int restlen =
                saved_char?(name_len - (nametocheck_end - nameout)):0;
              memmove(nametocheck+l,nametocheck_end,restlen);
            }
            strncpy(nametocheck,wfd.cFileName,l);
            nametocheck_end = nametocheck + l;
            name_len = new_name_len;
          } else {/* try shortcut
                     Note: something\cyglink.lnk doesn't resolve to the contents
                           of cyglink.lnk so one can read/write symlink .lnk
                           files although they are not present in DIRECTORY output.
                           Is it bug or feature? */
            char saved[4];
            char resolved[MAX_PATH];
            int  resolved_len;
            shell_shortcut_target_t rresult;
            if (nametocheck_end - nameout + 4 > MAX_PATH) return FALSE;
            strncpy(saved,nametocheck_end+1,4);
            strncpy(nametocheck_end,".lnk",5);
            rresult = resolve_shell_shortcut_more(nameout,resolved);
            strncpy(nametocheck_end+1,saved,4);
            *nametocheck_end = 0;
            /* use saved_char as directory indicator */
            if (rresult == shell_shortcut_notresolved
                || rresult == shell_shortcut_notexists
                || (saved_char ? rresult == shell_shortcut_file
                    : rresult == shell_shortcut_directory))
              return FALSE;
            resolved_len = strlen(resolved);
            if (saved_char) {
              /*need to subst nameout..nametocheck-1 with resolved path */
              int l2 = name_len - (nametocheck_end - nameout);
              if (resolved_len + l2 + 2 > MAX_PATH) return FALSE;
              strncpy(resolved + resolved_len, nametocheck_end + 1, l2);
              name_len = l2 - 1;
            }
            name_len += resolved_len;
            strcpy(nameout,resolved);
            next_name = TRUE;
          }
        }
      }
      if (!next_name) {
        *nametocheck_end = saved_char;
        nametocheck = nametocheck_end;
        if (*nametocheck) nametocheck++;
      }
    } while (!next_name && *nametocheck);
    if (!(--try_counter)) return FALSE;
  } while (next_name);
  return TRUE;
}
