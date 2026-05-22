/*
 * Minimal ELF64 support for Plan9 linkers.
 * Derived from Go 1.4 ld/elf.h; dynamic-linking support removed.
 */

#ifndef _LD_ELF_H_
#define _LD_ELF_H_

/* ELF identification indices */
#define EI_MAG0         0
#define EI_MAG1         1
#define EI_MAG2         2
#define EI_MAG3         3
#define EI_CLASS        4
#define EI_DATA         5
#define EI_VERSION      6
#define EI_OSABI        7
#define EI_ABIVERSION   8
#define EI_NIDENT       16

/* Magic numbers */
#define ELFMAG0         0x7f
#define ELFMAG1         'E'
#define ELFMAG2         'L'
#define ELFMAG3         'F'

/* EI_CLASS values */
#define ELFCLASS32      1
#define ELFCLASS64      2

/* EI_DATA values */
#define ELFDATA2LSB     1
#define ELFDATA2MSB     2

/* EI_OSABI values */
#define ELFOSABI_NONE       0
#define ELFOSABI_FREEBSD    9
#define ELFOSABI_NETBSD     2
#define ELFOSABI_OPENBSD    12

/* EI_VERSION / e_version */
#define EV_CURRENT      1

/* e_type values */
#define ET_REL          1
#define ET_EXEC         2
#define ET_DYN          3

/* e_machine values */
#define EM_386          3
#define EM_ARM          40
#define EM_X86_64       62

/* p_type values */
#define PT_NULL         0
#define PT_LOAD         1
#define PT_DYNAMIC      2
#define PT_INTERP       3
#define PT_NOTE         4
#define PT_PHDR         6
#define PT_TLS          7
#define PT_GNU_STACK    0x6474e551
#define PT_PAX_FLAGS    0x65041580

/* p_flags values */
#define PF_X            0x1
#define PF_W            0x2
#define PF_R            0x4

/* sh_type values */
#define SHT_NULL        0
#define SHT_PROGBITS    1
#define SHT_SYMTAB      2
#define SHT_STRTAB      3
#define SHT_RELA        4
#define SHT_HASH        5
#define SHT_DYNAMIC     6
#define SHT_NOTE        7
#define SHT_NOBITS      8
#define SHT_REL         9
#define SHT_DYNSYM      11
#define SHT_GNU_VERSYM  0x6fffffff
#define SHT_GNU_VERNEED 0x6ffffffe

/* sh_flags values */
#define SHF_WRITE       0x1
#define SHF_ALLOC       0x2
#define SHF_EXECINSTR   0x4
#define SHF_TLS         0x400

/* ELF header sizes */
#define ELF32HDRSIZE    52
#define ELF64HDRSIZE    64
#define ELF32PHDRSIZE   32
#define ELF64PHDRSIZE   56
#define ELF32SHDRSIZE   40
#define ELF64SHDRSIZE   64

/* Symbol sizes */
#define ELF32SYMSIZE    16
#define ELF64SYMSIZE    24
#define ELF32RELSIZE    8
#define ELF32RELASIZE   12
#define ELF64RELASIZE   24

/* Integer types used in ELF structures (lib.h defines these for ld/ files;
 * define them here for files that include elf.h without lib.h). */
#ifndef _LD_LIB_H_
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef long           uint32;
typedef uvlong         uint64;
#endif

/* ELF structures — we use 64-bit fields for both 32 and 64 bit */
typedef struct ElfEhdr ElfEhdr;
struct ElfEhdr
{
    uchar   ident[EI_NIDENT];
    uint16  type;
    uint16  machine;
    uint32  version;
    uint64  entry;
    uint64  phoff;
    uint64  shoff;
    uint32  flags;
    uint16  ehsize;
    uint16  phentsize;
    uint16  phnum;
    uint16  shentsize;
    uint16  shnum;
    uint16  shstrndx;
};

typedef struct ElfPhdr ElfPhdr;
struct ElfPhdr
{
    uint32  type;
    uint32  flags;
    uint64  off;
    uint64  vaddr;
    uint64  paddr;
    uint64  filesz;
    uint64  memsz;
    uint64  align;
};

typedef struct ElfShdr ElfShdr;
struct ElfShdr
{
    uint32  name;
    uint32  type;
    uint64  flags;
    uint64  addr;
    uint64  off;
    uint64  size;
    uint32  link;
    uint32  info;
    uint64  addralign;
    uint64  entsize;
    /* non-disk fields */
    int     shnum;
    Sym*    secsym;
};

/* Elf Note header */
typedef struct Elf_Note Elf_Note;
struct Elf_Note
{
    uint32  namesz;
    uint32  descsz;
    uint32  type;
};

/* Aliases */
#define Elf64_Ehdr  ElfEhdr
#define Elf64_Phdr  ElfPhdr
#define Elf64_Shdr  ElfShdr

#define ELFRESERVE  3072

/* Dynamic tag values (not used for static ELF, but referenced by some code) */
#define DT_NULL     0
#define DT_NEEDED   1
#define DT_PLTRELSZ 2
#define DT_PLTGOT   3
#define DT_HASH     4
#define DT_STRTAB   5
#define DT_SYMTAB   6
#define DT_RELA     7
#define DT_RELASZ   8
#define DT_RELAENT  9
#define DT_STRSZ    10
#define DT_SYMENT   11
#define DT_INIT     12
#define DT_FINI     13
#define DT_SONAME   14
#define DT_RPATH    15
#define DT_REL      17
#define DT_RELSZ    18
#define DT_RELENT   19
#define DT_PLTREL   20
#define DT_DEBUG    21
#define DT_JMPREL   23
#define DT_RUNPATH  29
#define DT_VERNEED  0x6ffffffe
#define DT_VERNEEDNUM 0x6fffffff
#define DT_VERSYM   0x6ffffff0

/* Declarations */
void        elfinit(void);
void        elfforce32(void);
ElfEhdr*    getElfEhdr(void);
ElfShdr*    newElfShdr(vlong);
ElfPhdr*    newElfPhdr(void);
uint32      elfwritehdr(void);
uint32      elfwritephdrs(void);
uint32      elfwriteshdrs(void);
uint32      elfwritestrtab(void);
ElfShdr*    elfshname(char*);
extern int  numelfphdr;
extern int  numelfshdr;
extern int  iself;
void        dwarfaddelfheaders(void);
void        asmbelf(long headr, vlong datafoff, vlong datva);

#endif /* _LD_ELF_H_ */
