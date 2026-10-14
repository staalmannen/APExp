# installer for GNU CLISP
# using Nullsoft Install System
# (C) 2007 Elliott Slaughter
#
# this source code is a part of CLISP,
# and is released under the GPL v2
# (or newer, as the user sees fit).
#
# usage: place script and additional files
# (is_user_admin and add_to_path) to directory
# where clisp distro is stored, then compile
# with NSIS (latest version used was 2.31).
#
# note: this script globs all files in the current
# directory, ignoring files that match "install*"


# general

    !include MUI.nsh

    # compression method
    SetCompressor /SOLID LZMA
    SetCompressorDictSize 16 # MB

    # http://nsis.sourceforge.net/IsUserAdmin
    !include "is_user_admin.nsh"

    # name and file
    !define VERSION "@VERSION@"
    !define NAME "@NAME@"
    !define FULL_MODULES "@MODULES@"
    !define BASE_MODULES "@BASE_MODULES@"

    # http://nsis.sourceforge.net/Path_Manipulation
    !include "add_to_path.nsh"

    # name and output of file
    Name "${NAME} ${VERSION}"
    OutFile "clisp-${VERSION}-win32-install.exe"

    # default installation folder
    InstallDir "$PROGRAMFILES\clisp-${VERSION}"

    # get installation folder from registry if available
    InstallDirRegKey HKCU "Software\${NAME} ${VERSION}" ""

# variables

    Var LinkingSet
    Var LinkingCmd
    Var UserSetting
    Var STARTMENU_FOLDER
    Var STARTMENU_TEMP

# interface configuration

    !define MUI_ABORTWARNING

# installation types
InstType "Typical"

# page definitions and settings

    #installer pages

    !define MUI_COMPONENTSPAGE_SMALLDESC

    !insertmacro MUI_PAGE_WELCOME
    !insertmacro MUI_PAGE_LICENSE "COPYRIGHT.rtf"
    !insertmacro MUI_PAGE_COMPONENTS
    !insertmacro MUI_PAGE_DIRECTORY

    !define MUI_STARTMENUPAGE_DEFAULTFOLDER "${NAME} ${VERSION}"
    !define MUI_STARTMENUPAGE_REGISTRY_ROOT HKCU
    !define MUI_STARTMENUPAGE_REGISTRY_KEY "Software\${NAME} ${VERSION}"
    !define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "Start Menu Folder"
    !insertmacro MUI_PAGE_STARTMENU StartMenu $STARTMENU_FOLDER

    !insertmacro MUI_PAGE_INSTFILES

    # uninstaller pages
    !insertmacro MUI_UNPAGE_CONFIRM
    !insertmacro MUI_UNPAGE_INSTFILES

# language files

    !insertmacro MUI_LANGUAGE "English"

# installer sections

# install for all users or just current user?
SectionGroup /e "!Install For"

    Section "All Users" SecAllUsers

        # set shell var context to all
        SetShellVarContext all

        # save in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "Shell Var Context" "all"

        # save env var context in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "Environment Context" "all"
    SectionEnd

    Section "Just Me" SecCurUser
    SectionIn 1
        # set shell var context to current
        SetShellVarContext current

        # save in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "Shell Var Context" "current"

        # save env var context in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "Environment Context" "current"
    SectionEnd

SectionGroupEnd

SectionGroup /e "!${NAME} Core"

    Section "${NAME} ${VERSION}" SecCore
    SectionIn 1 RO

        SetOutPath $INSTDIR

        # create files
        File /r /x "*.nsi" /x "*.nsh" /x "text_to_rtf.*" /x "COPYRIGHT.rtf" /x "install*.*" ".\"

        # set linking set to base
        StrCpy $LinkingCmd "base"

        # store installation folder in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "" $INSTDIR

        # create uninstaller
        WriteUninstaller "uninstall.exe"
    SectionEnd

    Section "Base Linking Set" SecBase

        # set linking set to base
        StrCpy $LinkingCmd "base"
    SectionEnd

    Section "Full Linking Set" SecFull
    SectionIn 1

        # set linking set to base
        StrCpy $LinkingCmd "full"
    SectionEnd

    Section "-Add/Remove Programs"

        # add uninstaller to add/remove programs
        StrCmp $UserSetting ${SecAllUsers} WriteRegStr_all
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayName" "${NAME} ${VERSION}"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayIcon" "$INSTDIR\clisp.exe,0"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayVersion" "${VERSION}"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "InstallLocation" "$INSTDIR"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "UninstallString" "$INSTDIR\uninstall.exe"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "URLInfoAbout" "http://clisp.cons.org/"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "URLUpdateInfo" "http://clisp.cons.org/"
            WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "HelpLink" "http://clisp.cons.org/"
            WriteRegDWord HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "NoModify" 1
            WriteRegDWord HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "NoRepair" 1
        Goto WriteRegStr_done
        WriteRegStr_all:
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayName" "${NAME} ${VERSION}"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayIcon" "$INSTDIR\clisp.exe,0"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "DisplayVersion" "${VERSION}"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "InstallLocation" "$INSTDIR"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "UninstallString" "$INSTDIR\uninstall.exe"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "URLInfoAbout" "http://clisp.cons.org/"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "URLUpdateInfo" "http://clisp.cons.org/"
            WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "HelpLink" "http://clisp.cons.org/"
            WriteRegDWord HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "NoModify" 1
            WriteRegDWord HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}" \
                "NoRepair" 1
        WriteRegStr_done:
    SectionEnd

    Section "-Start Menu"

        # add start menu shortcuts
        !insertmacro MUI_STARTMENU_WRITE_BEGIN StartMenu
            CreateDirectory $SMPROGRAMS\$STARTMENU_FOLDER
            CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\${NAME} ${VERSION}.lnk" "$INSTDIR\clisp.exe" "-K $LinkingCmd"
            CreateShortCut "$SMPROGRAMS\$STARTMENU_FOLDER\Uninstall ${NAME} ${VERSION}.lnk" $INSTDIR\uninstall.exe
        !insertmacro MUI_STARTMENU_WRITE_END
    SectionEnd

    Section "Desktop Shortcut" SecDesktop
    SectionIn 1

        # create shortcut
        createShortCut "$DESKTOP\${NAME} ${VERSION}.lnk" "$INSTDIR\clisp.exe" "-K $LinkingCmd"

        # record installation of desktop shortcut in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "Desktop Shortcut" "true"
    SectionEnd

    Section "File Associations" SecAssoc
    SectionIn 1

        # add file associations to registry
        WriteRegStr HKCR ".lisp" "" "lispfile"
        WriteRegStr HKCR ".lsp" "" "lispfile"
        WriteRegStr HKCR ".cl" "" "lispfile"
        WriteRegStr HKCR ".fas" "" "fasfile"
        WriteRegStr HKCR ".mem" "" "memfile"

        WriteRegStr HKCR "lispfile" "" "Lisp source file"
        WriteRegDWord HKCR "lispfile" "EditFlags" 0
        WriteRegStr HKCR "lispfile\DefaultIcon" "" "%SystemRoot%\system32\SHELL32.dll,41"
        WriteRegStr HKCR "lispfile\Shell\Compile_with_CLISP" "" "Compile with CLISP"
        WriteRegStr HKCR "lispfile\Shell\Compile_with_CLISP\command" "" '"$INSTDIR\clisp.exe" -K $LinkingCmd -c "%1"'

        WriteRegStr HKCR "fasfile" "" "CLISP compiled file"
        WriteRegDWord HKCR "fasfile" "EditFlags" 0
        WriteRegStr HKCR "fasfile\DefaultIcon" "" "%SystemRoot%\system32\SHELL32.dll,21"
        WriteRegStr HKCR "fasfile\Shell\Execute_with_CLISP" "" "Execute with CLISP"
        WriteRegStr HKCR "fasfile\Shell\Execute_with_CLISP\command" "" '"$INSTDIR\clisp.exe" -K $LinkingCmd "%1"'
        WriteRegStr HKCR "fasfile\Shell\Load_into_CLISP" "" "Load into CLISP"
        WriteRegStr HKCR "fasfile\Shell\Load_into_CLISP\command" "" '"$INSTDIR\clisp.exe" -K $LinkingCmd -i "%1"'

        WriteRegStr HKCR "memfile" "" "CLISP memory image"
        WriteRegDWord HKCR "memfile" "EditFlags" 0
        WriteRegStr HKCR "memfile\DefaultIcon" "" "%SystemRoot%\system32\SHELL32.dll,21"
        WriteRegStr HKCR "memfile\Shell\Run_with_CLISP" "" "Run with CLISP"
        WriteRegStr HKCR "memfile\Shell\Run_with_CLISP\command" "" '"$INSTDIR\clisp.exe" -K $LinkingCmd -M "%1"'

        # record installation of desktop shortcut in registry
        WriteRegStr HKCU "Software\${NAME} ${VERSION}" "File Associations" "true"
    SectionEnd

    Section "PATH Variable" SecPath
    SectionIn 1

        # add to PATH Variable
        Push $INSTDIR
        Call AddToPath
    SectionEnd
SectionGroupEnd

# component descriptions

    # language strings
    LangString DESC_SecAllUsers ${LANG_ENGLISH} "Install ${NAME} ${VERSION} for all users. (Requires administrative privileges.)"
    LangString DESC_SecCurUser ${LANG_ENGLISH} "Install ${NAME} ${VERSION} for current user only."
    LangString DESC_SecCore ${LANG_ENGLISH} "${NAME} ${VERSION}, an ANSI Common Lisp implementation."
    LangString DESC_SecBase ${LANG_ENGLISH} "Enable basic linking set. (Includes ${BASE_MODULES}.)"
    LangString DESC_SecFull ${LANG_ENGLISH} "Enable full linking set. (Includes ${BASE_MODULES} ${FULL_MODULES}.)"
    LangString DESC_SecDesktop ${LANG_ENGLISH} "Create a desktop shortcut for ${NAME}."
    LangString DESC_SecAssoc ${LANG_ENGLISH} "Associate ${NAME} with files of types .lisp, .lsp, .cl, .fas, and .mem."
    LangString DESC_SecPath ${LANG_ENGLISH} "Add ${NAME} directory to PATH environment variable."

    # assign language strings to sections
    !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
        !insertmacro MUI_DESCRIPTION_TEXT ${SecAllUsers} $(DESC_SecAllUsers)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecCurUser} $(DESC_SecCurUser)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecCore} $(DESC_SecCore)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecBase} $(DESC_SecBase)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecFull} $(DESC_SecFull)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecDesktop} $(DESC_SecDesktop)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecAssoc} $(DESC_SecAssoc)
        !insertmacro MUI_DESCRIPTION_TEXT ${SecPath} $(DESC_SecPath)
    !insertmacro MUI_FUNCTION_DESCRIPTION_END

# installer functions

Function .onInit

    StrCpy $UserSetting ${SecCurUser}
    StrCpy $LinkingSet ${SecFull}

    # if the user does *not* have administrator privileges,
    # then make section SecAllUsers readonly
    Call IsUserAdmin
    Pop $0
    StrCmp $0 "true" onInit_cont 0
        # Set the fifth bit to set the read only flag.
        !define READ_ONLY 0x00000010
        SectionGetFlags ${SecAllUsers} $0
        IntOp $0 $0 | ${READ_ONLY}
        SectionSetFlags ${SecAllUsers} $0
        !undef READ_ONLY
    onInit_cont:

FunctionEnd

Function .onSelChange

    !insertmacro StartRadioButtons $UserSetting
        !insertmacro RadioButton ${SecAllUsers}
        !insertmacro RadioButton ${SecCurUser}
    !insertmacro EndRadioButtons

    !insertmacro StartRadioButtons $LinkingSet
        !insertmacro RadioButton ${SecBase}
        !insertmacro RadioButton ${SecFull}
    !insertmacro EndRadioButtons

FunctionEnd

# uninstaller sections

Section "un.Install For"

    # get state of SetShellVarContext
    ReadRegStr $R0 HKCU "Software\${NAME} ${VERSION}" "Shell Var Context"
    StrCmp $R0 "all" SetShellUserContext_all
        Goto SetShellUserContext_done
    SetShellUserContext_all:
        SetShellVarContext all
    SetShellUserContext_done:

SectionEnd

Section "Uninstall"

    Delete $INSTDIR\uninstall.exe

    # delete files
    RMDir /r $INSTDIR

    # delete uninstaller from add/remove programs
    ReadRegStr $R0 HKCU "SOFTWARE\${NAME} ${VERSION}" "Environment Context"
    StrCmp $R0 "all" DeleteRegStr_all
        DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}"
    Goto DeleteRegStr_done
    DeleteRegStr_all:
        DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${NAME} ${VERSION}"
    DeleteRegStr_done:

    # delete desktop shortcut if it was created by the installer
    ReadRegStr $R0 HKCU "Software\${NAME} ${VERSION}" "Desktop Shortcut"
    StrCmp $R0 "true" deleteDesktopShortcut
        Goto doneDeletingDesktopShortcut
    deleteDesktopShortcut:
        Delete "$DESKTOP\${NAME} ${VERSION}.lnk"
    doneDeletingDesktopShortcut:

    # delete file associations if they were created by the installer
    ReadRegStr $R0 HKCU "Software\${NAME} ${VERSION}" "File Associations"
    StrCmp $R0 "true" DeleteFileAssociations
        Goto DeleteFileAssociations_done
    DeleteFileAssociations:
        DeleteRegKey HKCR ".lisp"
        DeleteRegKey HKCR ".lsp"
        DeleteRegKey HKCR ".cl"
        DeleteRegKey HKCR ".fas"
        DeleteRegKey HKCR ".mem"
        DeleteRegKey HKCR "lispfile"
        DeleteRegKey HKCR "fasfile"
        DeleteRegKey HKCR "memfile"
    DeleteFileAssociations_done:

    Push $INSTDIR
    Call un.RemoveFromPath

    # delete contents of start menu folder
    !insertmacro MUI_STARTMENU_GETFOLDER StartMenu $STARTMENU_TEMP

    Delete "$SMPROGRAMS\$STARTMENU_TEMP\${NAME} ${VERSION}.lnk"
    Delete "$SMPROGRAMS\$STARTMENU_TEMP\Uninstall ${NAME} ${VERSION}.lnk"

    # delete empty start menu parent diretories
    StrCpy $STARTMENU_TEMP "$SMPROGRAMS\$STARTMENU_TEMP"

    startMenuDeleteLoop:
        ClearErrors
        RMDir $STARTMENU_TEMP
        GetFullPathName $STARTMENU_TEMP "$STARTMENU_TEMP\.."

        IfErrors startMenuDeleteLoopDone

        StrCmp $STARTMENU_TEMP $SMPROGRAMS startMenuDeleteLoopDone startMenuDeleteLoop
    startMenuDeleteLoopDone:

    DeleteRegKey /ifempty HKCU "Software\${NAME} ${VERSION}"
SectionEnd
