/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void guiGenerate( char *__b2c_data) {
    char*data = NULL; data = b2c_CopyString(NULL, __b2c_data); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_item_ptr = 0; char* b2c_forin_item_string = NULL; char* b2c_forin_item_string_org = NULL; char* b2c_forin_item_step = NULL; char *b2c_select_4016 = NULL; int b2c_forin_func_ptr = 0; char* b2c_forin_func_string = NULL; char* b2c_forin_func_string_org = NULL; char* b2c_forin_func_step = NULL;
    char *widget = NULL;
    char *type = NULL;
    char *name = NULL;
    char *parent = NULL;
    char *callback = NULL;
    char *uid = NULL;
    char *resource = NULL;
    char *icon = NULL;
    char *map = NULL;
    char *func = NULL;
    char *prop = NULL;
    char *arg = NULL;
    FILE* gui = NULL;
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".gui.h") ;
    gui = fopen((const char*)CONCAT( g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".gui.h" ), "w");
if(gui == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 3945, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    if( g_WHICH_GUI == 2 ){
    fputs("void* b2c_cld = NULL; struct b2c_cdk{ void *addr; char *name; }; struct b2c_cdk *b2c_cdknames = { NULL }; int b2c_cdknr = 0;\n", gui);
    fputs("void *__b2c_get_by_name(uintptr_t id, char *name) { void *result = NULL; int x; for(x=0; x<b2c_cdknr; x++){ if(!strcmp(name, b2c_cdknames[x].name)) { result = b2c_cdknames[x].addr; break; } } return(result); }\n", gui);
    fputs("static int __b2c_cdk_callback(EObjectType cdktype GCC_UNUSED, void *object, void *clientData, chtype key GCC_UNUSED) { b2c_cld = clientData; return(TRUE); }\n", gui);
    fputs("char *b2c_guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long len; int key; boolean function; CDKOBJS *obj; CDKSCREEN *screen; screen = (CDKSCREEN*)id; b2c_cld = NULL; refreshCDKScreen(screen);\n", gui);
    fputs("while(b2c_cld == NULL) { obj = getCDKFocusCurrent(screen); if(obj != NULL) { key = getchCDKObject(obj, &function); traverseCDKOnce(screen, obj, key, function, NULL); } } len = strlen((char *) b2c_cld); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", gui);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], b2c_cld, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", gui);
    fputs("uintptr_t b2c_guiDefine(void){ atexit(endCDK);\n", gui);
    } else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
    fputs("gpointer b2c_cld = NULL; gpointer b2c_cad = NULL;\n", gui);
    fputs("void *__b2c_get_by_name(uintptr_t id, char *name) { GList *widget, *x; widget = (GList*)id; for(x = widget; x != NULL; x = x->next) { if(!strcmp(name, gtk_widget_get_name(GTK_WIDGET(x->data)))) { break; } } if(x==NULL) { return(NULL); } else { return(x->data); } }\n", gui);
    fputs("void __b2c_gtk_callback(gpointer client_data, uintptr_t call_data, GtkWidget *w) { size_t size; b2c_cld = client_data;\n", gui);
    fputs("if(call_data) {if( (sizeof(call_data)>sizeof(gint) ? call_data>>(sizeof(gint)*8) : 0) == 0 && (gint)call_data < 0 && (gint)call_data > -16) { b2c_cad = realloc(b2c_cad, sizeof(gint)); (*(gint*)b2c_cad) = (gint)call_data; } else\n", gui);
        if( g_WHICH_GUI == 1 ){
        fputs("{ switch(((GdkEventAny*)call_data)->type) { case GDK_BUTTON_PRESS: size = sizeof(GdkEventButton); break; case GDK_2BUTTON_PRESS: size = sizeof(GdkEventButton); break; case GDK_3BUTTON_PRESS: size = sizeof(GdkEventButton); break;\n", gui);
        fputs("case GDK_BUTTON_RELEASE: size = sizeof(GdkEventButton); break; case GDK_EXPOSE: size = sizeof(GdkEventExpose); break; case GDK_DAMAGE: size = sizeof(GdkEventExpose); break; case GDK_ENTER_NOTIFY: size = sizeof(GdkEventCrossing); break;\n", gui);
        fputs("case GDK_LEAVE_NOTIFY: size = sizeof(GdkEventCrossing); break; case GDK_FOCUS_CHANGE: size = sizeof(GdkEventFocus); break; case GDK_CONFIGURE: size = sizeof(GdkEventConfigure); break; case GDK_PROPERTY_NOTIFY: size = sizeof(GdkEventProperty); break;\n", gui);
        fputs("case GDK_SCROLL: size = sizeof(GdkEventScroll); break; case GDK_KEY_PRESS: size = sizeof(GdkEventKey); break; case GDK_KEY_RELEASE: size = sizeof(GdkEventKey); break; case GDK_SETTING: size = sizeof(GdkEventSetting); break;\n", gui);
        fputs("default: size = sizeof(GdkEventAny); } b2c_cad = realloc(b2c_cad, size); memcpy(b2c_cad, (void*)call_data, size); } } }\n", gui);
        } else {
        fputs("{ size = sizeof(void*); b2c_cad = realloc(b2c_cad, size); memcpy(b2c_cad, (void*)call_data, size); } } }\n", gui);
        }
    fputs("char *b2c_guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; GList *widget; const char *name = NULL; unsigned long len, total = 0; widget=(GList*)id; b2c_cld = NULL;\n", gui);
    fputs("GTKWIDGETSHOW(widget->data); while(1) { GTKMAINITERATION; if(b2c_cld) { break; } } len = strlen((char*)b2c_cld); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], b2c_cld, len);\n", gui);
    fprintf(gui, "if(type == 1) { total += len; buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+1+%s+1); len = snprintf(buf[idx]+total, %s, \" %p\", b2c_cad); }\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("total += len; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", gui);
    fputs("uintptr_t b2c_guiDefine(void){ GList *widget_list = NULL; GTKINIT;\n", gui);
    } else if( g_WHICH_GUI == 4 ){
    fputs("void *b2c_cld = NULL; int __b2c_tk_callback (ClientData client_data, Tcl_Interp * i, int argc, Tcl_Obj * const objv[]) { char *data, *token = NULL; if(client_data) { data = b2c_strdup(client_data);\n", gui);
    fputs("b2c_cld = strtok(data, \"+\"); token = strtok(NULL, \"+\"); if(token) { if (!strncmp(token, \"error\", 5)) { return(TCL_ERROR); } if (!strncmp(token, \"return\", 6)) { return(TCL_RETURN); } if(!strncmp(token, \"break\", 5))\n", gui);
    fputs("{ return (TCL_BREAK); } if(!strncmp (token, \"continue\", 8)) { return(TCL_CONTINUE); } } } else { b2c_cld = NULL; } return(TCL_OK); }\n", gui);
    fputs("char *b2c_guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long len; while(1) { if(Tcl_DoOneEvent(TCL_ALL_EVENTS)) { if(b2c_cld) { __b2c__STRFREE(b2c_cld); break; } } }\n", gui);
    fputs("len = b2c_len(b2c_cld); buf[idx] = (char*) __b2c_str_realloc (buf[idx], len+1); memmove(buf[idx], b2c_cld, len); __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; b2c_cld = NULL; return(char*)(buf[idx]); }\n", gui);
    fprintf(gui, "uintptr_t b2c_guiDefine(void){ Tcl_Interp *interp; char *gui = NULL; Tcl_FindExecutable(\"%s\"); interp = Tcl_CreateInterp();\n", BASENAME(g_CURFILE, 1));
    fputs("if(Tcl_Init(interp) == TCL_ERROR) { fprintf(stderr, \"No TCL INIT possible: %s\\n\", Tcl_GetStringResult(interp)); exit(TCL_ERROR); }\n", gui);
    fputs("if(Tk_Init(interp) == TCL_ERROR) { fprintf(stderr, \"No TK INIT possible: %s\\n\", Tcl_GetStringResult(interp)); exit(TCL_ERROR); }\n", gui);
    fprintf(gui, "gui = (char*)calloc(128+%s, sizeof(char)); strncpy(gui, \"package require Tk\\n\", 127);\n", STR( LEN(data)));
        if( LEN(data) ){
        fprintf(gui, "gui = strcat(gui, \"%s\");\n", data);
        }
        b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, data); b2c_forin_item_string_org = b2c_forin_item_string;
        b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, ";");
        b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
        for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
            if( ISTOKEN(item, "\\\"WM_DELETE_WINDOW\\\"")  AND  REGEX(TOKEN(item, ISTOKEN(item, "\\\"WM_DELETE_WINDOW\\\"")+1), "^[a-zA-Z0-9_]+$") ){
                callback = F_APPEND(callback,callback, 0, TOKEN(item, ISTOKEN(item, "\\\"WM_DELETE_WINDOW\\\"")+1));
            }
            if( ISTOKEN(item, "-command")  AND  REGEX(TOKEN(item, ISTOKEN(item, "-command")+1), "^[a-zA-Z0-9+_]+$") ){
                callback = F_APPEND(callback,callback, 0, TOKEN(item, ISTOKEN(item, "-command")+1));
            }
            if( __b2c__STRCMP(HEAD(CHOP(item)) ,  "bind") == 0  AND  AMOUNT(item) == 4  AND  REGEX(TAIL(CHOP(item)), "^[a-zA-Z0-9+_]+$") ){
                callback = F_APPEND(callback,callback, 0, TAIL(CHOP(item)));
            }
        }
        if( LEN(callback) ){
            b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, SORT(UNIQ(callback))); b2c_forin_item_string_org = b2c_forin_item_string;
            b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
            b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
            for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
            fprintf(gui, "Tcl_CreateObjCommand(interp, \"%s\", __b2c_tk_callback, (ClientData)\"%s\", NULL);\n", item, item);
            }
        }
    fputs("Tcl_Eval(interp, gui); return((uintptr_t)interp); }\n", gui);
    } else {
    fputs("Widget __b2c__CallbackedWidget; XtPointer b2c_cld = NULL; XtPointer b2c_cad = NULL; Atom __b2c_wm_delete_window = 0;\n", gui);
    fputs("int __b2c_xt_close(Display *dpy) { XtCloseDisplay(dpy); exit(EXIT_SUCCESS); }\n", gui);
    fputs("static void __b2c_wm_delete(Widget w, XEvent *event, String *params, Cardinal *num_params)\n", gui);
    fputs("{ if(event->type == ClientMessage && event->xclient.data.l[0] == __b2c_wm_delete_window) { __b2c__CallbackedWidget = w; b2c_cld = params[0]; } }\n", gui);
    fputs("void __b2c_xt_callback(Widget w, XtPointer client_data, XtPointer call_data)\n", gui);
    fputs("{ __b2c__CallbackedWidget = w; if(client_data) { b2c_cld = client_data; } if(call_data) { b2c_cad = calloc(1, sizeof(XtPointer)); memcpy(b2c_cad, call_data, sizeof(XtPointer)); } }\n", gui);
    fputs("char *b2c_guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *name; unsigned long len, total = 0; __b2c__CallbackedWidget = NULL; if(b2c_cad) { free(b2c_cad); } b2c_cad = NULL; b2c_cld = NULL;\n", gui);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } XtRealizeWidget((Widget)id); if(__b2c_wm_delete_window) { XSetWMProtocols(XtDisplay((Widget)id), XtWindow((Widget)id), &__b2c_wm_delete_window, 1); }\n", gui);
    fputs("while(1) { XtAppProcessEvent(XtWidgetToApplicationContext((Widget)id), XtIMAll); if(__b2c__CallbackedWidget) { break; } } if(b2c_cld) { len = strlen(b2c_cld); buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], b2c_cld, len); }\n", gui);
    fputs("else { name = XtName(__b2c__CallbackedWidget); if(name == NULL) { return(NULL); } len = strlen(name); buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], name, len); } if(type == 1) { total += len;\n", gui);
    fprintf(gui, "buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+1+%s+1); len = snprintf(buf[idx]+total, %s, \" %p\", b2c_cad); }\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("total += len; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", gui);
    fputs("uintptr_t b2c_guiDefine(void){XtAppContext app; Display *dpy; Screen *scr; Arg args[32]; int n = 0, argc = 1; char *argv[1];\n", gui);
    }
    while( (LEN(data) )> 2  AND  g_WHICH_GUI != 4 ){
        widget = b2c_CopyString(widget, (char*) FLATTEN(INBETWEEN(data, "{" , "}")));
        data = F_CHOP(data,OUTBETWEEN(data, "{", "}"));
        type = b2c_CopyString(type, (char*) "");
        name = b2c_CopyString(name, (char*) "");
        parent = b2c_CopyString(parent, (char*) "");
        callback = b2c_CopyString(callback, (char*) "");
        prop = b2c_CopyString(prop, (char*) ",");
        arg = b2c_CopyString(arg, (char*) "");
        b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, widget); b2c_forin_item_string_org = b2c_forin_item_string;
        b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
        b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
        for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
            item = b2c_CopyString(item, (char*) REPLACE(CHOP(item), "\\$$", g_STRINGSIGN, TRUE));
            b2c_select_4016 = b2c_CopyString(b2c_select_4016, TOKEN(item, 1, "="));
            if ( !b2c_strcmp(b2c_select_4016, "type")){
                type = b2c_CopyString(type, (char*) TOKEN(item, 2, "="));
                if( (g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3)  AND  NOT(INSTR(type, "_TYPE_")) ){
                    type = F_CONCAT(type, "GTK_TYPE_" , UCASE(type));
                }
            } else  if ( !b2c_strcmp(b2c_select_4016, "name")){
                name = b2c_CopyString(name, (char*) TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "parent")){
                parent = b2c_CopyString(parent, (char*) TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "callback")){
                callback = F_APPEND(callback,callback, 0, TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "map")){
                map = F_APPEND(map,map, 0, TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "uid")){
                uid = F_APPEND(uid,uid, 0, TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "resources")){
                resource = b2c_CopyString(resource, (char*) TOKEN(item, 2, "="));
            } else  if ( !b2c_strcmp(b2c_select_4016, "args")){
                arg = b2c_CopyString(arg, (char*) TOKEN(item, 2, "="));
                arg = b2c_CopyString(arg, (char*) REPLACE(CHOP(arg), "$", g_STRINGSIGN));
            } else {
                if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
                    prop = F_CONCAT(prop, prop , CHR(34) , TOKEN(item, 1, "=") , CHR(34) , "," , TOKEN(item, 2, "=") , ",") ;
                } else if( g_WHICH_GUI == 0 ){
                fprintf(gui, "XtSetArg(args[n], %s); n++;\n", DELIM(item, "=", ","));
                }
            }
        }
if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        if( LEN(name) == 0  AND  g_WHICH_GUI != 4 ){
        fprintf(stderr, "%sSyntax error: widget does not have a name at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( LEN(type) == 0  AND  g_WHICH_GUI != 4 ){
        fprintf(stderr, "%sSyntax error: widget does not have a type at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( g_WHICH_GUI == 2 ){
            if( __b2c__STRCMP(LCASE(type) ,  "window") == 0 ){
            fprintf(gui, "%s\n", CONCAT( "CDKSCREEN *" , name , ", *__main_window;" ));
            fprintf(gui, "%s = initCDKScreen(initscr()); initCDKColor(); __main_window = %s;\n", name, name);
            } else {
            fprintf(gui, "CDK%s *%s;\n", UCASE(type), name);
            fprintf(gui, "%s = newCDK%s(%s);\n", name, PROPER(type), arg);
            }
        fputs("b2c_cdknames = realloc(b2c_cdknames, sizeof(struct b2c_cdk)*(b2c_cdknr+1));\n", gui);
        fprintf(gui, "b2c_cdknames[b2c_cdknr].name = b2c_strdup(\"%s\"); b2c_cdknames[b2c_cdknr].addr = %s; b2c_cdknr++;\n", name, name);
            if( LEN(callback) ){
                b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, callback); b2c_forin_item_string_org = b2c_forin_item_string;
                b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
                b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
                for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
                    if( HASDELIM(item, ",") ){
                    fprintf(gui, "bindCDKObject(v%s, %s, %s, __b2c_cdk_callback, \"%s\");\n", UCASE(type), name, TOKEN(item, 1, ","), TOKEN(item, 2, ","));
                    } else {
                    fprintf(gui, "bindCDKObject(v%s, %s, %s, __b2c_cdk_callback, \"%s\");\n", UCASE(type), name, TOKEN(item, 1, ","), name);
                    }
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
            }
        } else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
        fprintf(gui, "GtkWidget *%s;\n", name);
        fprintf(gui, "%s%s\n", name, CONCAT( "= GTK_WIDGET(g_object_new(" , type , " " , prop , " NULL));" ));
            if( __b2c__STRCMP(type ,  "GTK_TYPE_WINDOW") == 0  OR  INSTR(type, "DIALOG") ){
            fprintf(gui, "%s\n", CONCAT( "gtk_window_set_icon_name(GTK_WINDOW(" , name , "), \"bacon\");" ));
            }
        fprintf(gui, "%s\n", CONCAT( "gtk_widget_set_name(" , name , ", \"" , name , "\");" ));
        fprintf(gui, "widget_list = g_list_append(widget_list, %s);\n", name);
            if( LEN(parent) ){
                if( __b2c__STRCMP(type ,  "GTK_TYPE_MENU") == 0  OR  __b2c__STRCMP(type ,  "GTK_TYPE_MENU_ITEM") == 0 ){
                fprintf(gui, "%s\n", CONCAT( "gtk_menu_shell_append(GTK_MENU_SHELL(" , parent , "), " , name , ");" ));
                } else {
                fprintf(gui, "%s\n", CONCAT( "GTKCONTAINERADD(" , parent , ", " , name , ");" ));
                }
            }
            if( LEN(callback) ){
                b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, callback); b2c_forin_item_string_org = b2c_forin_item_string;
                b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
                b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
                for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
                    if( HASDELIM(item, ",") ){
                    fprintf(gui, "g_signal_connect_swapped(G_OBJECT(%s), \"%s\", G_CALLBACK(__b2c_gtk_callback), \"%s\");\n", name, TOKEN(item, 1, ","), TOKEN(item, 2, ","));
                    } else {
                    fprintf(gui, "g_signal_connect_swapped(G_OBJECT(%s), \"%s\", G_CALLBACK(__b2c_gtk_callback), \"%s\");\n", name, TOKEN(item, 1, ","), name);
                    }
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
            }
        } else {
        fprintf(gui, "Widget %s;\n", name);
            if( __b2c__STRCMP(type ,  "window") == 0 ){
            fputs("Widget __main_window; Dimension w, h;\n", gui);
                if( LEN(callback) ){
                fputs("XtActionsRec actions[1];\n", gui);
                }
            fputs("XtSetLanguageProc(NULL, NULL, NULL);\n", gui);
            fputs("argv[0] = calloc(1, sizeof(char));\n", gui);
                if( FILEEXISTS("/usr/local/share/pixmaps/BaCon.xbm") ){
                    icon = b2c_CopyString(icon, (char*) "/usr/local/share/pixmaps/BaCon.xbm");
                } else if( FILEEXISTS("/usr/share/pixmaps/BaCon.xbm") ){
                    icon = b2c_CopyString(icon, (char*) "/usr/share/pixmaps/BaCon.xbm");
                } else {
                    icon = b2c_CopyString(icon, (char*) "xlogo32");
                }
                if( LEN(resource) ){
                fprintf(gui, "%s%s, NULL };\n", CONCAT( "String resources[] = { \"*iconPixmap:" , icon , "\", "), resource);
                } else {
                fprintf(gui, "%s\n", CONCAT( "String resources[] = { \"*iconPixmap:" , icon , "\", NULL };" ));
                }
            fprintf(gui, "%s = XtOpenApplication(&app, \"BaConGUI\", NULL, 0, &argc, argv, resources, sessionShellWidgetClass, args, n);\n", name);
            fprintf(gui, "dpy = XtDisplay(%s);\n", name);
            fprintf(gui, "scr = XtScreen(%s);\n", name);
            fprintf(gui, "XtVaGetValues(%s, XtNwidth, &w, XtNheight, &h, NULL);\n", name);
            fprintf(gui, "XtVaSetValues(%s, XtNx, WidthOfScreen(scr)/2-(w/2), XtNy, HeightOfScreen(scr)/2-(h/2), NULL);\n", name);
                if( LEN(callback) ){
                fputs("__b2c_wm_delete_window = XInternAtom(dpy, \"WM_DELETE_WINDOW\", False);\n", gui);
                fputs("actions[0].string = \"__b2c_wm_delete\"; actions[0].proc = __b2c_wm_delete;\n", gui);
                fputs("XtAppAddActions(app, actions, XtNumber(actions));\n", gui);
                fprintf(gui, "XtOverrideTranslations(%s, XtParseTranslationTable(\"<Message>WM_PROTOCOLS: __b2c_wm_delete(%s)\"));\n", name, callback);
                fputs("#ifndef b2c_gui_xaw\n", gui);
                fprintf(gui, "XtVaSetValues(%s, XmNdeleteResponse, XmDO_NOTHING, NULL);\n", name);
                fputs("#endif\n", gui);
                }
            fprintf(gui, "__main_window = %s;\n", name);
            fputs("XSetIOErrorHandler(__b2c_xt_close);\n", gui);
            fputs("#ifdef b2c_gui_uil\n", gui);
            fputs("MrmHierarchy hierarchy;\n", gui);
            fputs("MrmType class_code;\n", gui);
            fputs("Widget main_object;\n", gui);
            fputs("static MrmRegisterArg callback_list[] = {\n", gui);
                if( LEN(map) ){
                    b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, map); b2c_forin_item_string_org = b2c_forin_item_string;
                    b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
                    b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
                    for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
                        b2c_forin_func_string = b2c_CopyString(b2c_forin_func_string, item); b2c_forin_func_string_org = b2c_forin_func_string;
                        b2c_forin_func_step = b2c_CopyString(b2c_forin_func_step, ",");
                        b2c_forin_func_ptr = b2c_for_amount(b2c_forin_func_string, b2c_forin_func_step);
                        for(; b2c_forin_func_ptr > 0; b2c_forin_func_ptr--) { b2c_for_item(&b2c_forin_func_string_org, b2c_forin_func_step, &func);
                        fprintf(gui, "{ \"%s\", (XtPointer)__b2c_xt_callback },\n", func);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                } else {
                fputs(" NULL \n", gui);
                }
            fputs("};\n", gui);
            fputs("static String uid_file_list[] = {\n", gui);
                if( AMOUNT(uid) ){
                fprintf(gui, "\"%s\"\n", HEAD(uid));
                    if( (AMOUNT(uid) )> 1 ){
                        b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, LAST(uid)); b2c_forin_item_string_org = b2c_forin_item_string;
                        b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
                        b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
                        for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
                        fprintf(gui, ", \"%s\" \n", item);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    }
                } else {
                fputs(" NULL \n", gui);
                }
            fputs("};\n", gui);
            fputs("MrmInitialize();\n", gui);
            fputs("MrmOpenHierarchyPerDisplay(dpy, XtNumber(uid_file_list), uid_file_list, NULL, &hierarchy);\n", gui);
            fputs("MrmRegisterNames(callback_list, XtNumber(callback_list));\n", gui);
            fprintf(gui, "MrmFetchWidget(hierarchy, \"main\", %s, &main_object, &class_code);\n", name);
            fputs("MrmCloseHierarchy(hierarchy);\n", gui);
            fputs("XtManageChild(main_object);\n", gui);
            fputs("#endif\n", gui);
            fputs("free(argv[0]);\n", gui);
            } else {
                if( __b2c__STRCMP(LEFT(type, 5) ,  "shell") == 0  OR  __b2c__STRCMP(LEFT(type, 10) ,  "simpleMenu") == 0  OR  INSTR(type, "Shell") ){
                fprintf(gui, "%s = XtCreatePopupShell(\"%s\", %s, %s, args, n);\n", name, name, type, parent);
                    if( INSTR(LCASE(type), "shell") ){
                    fprintf(gui, "XtVaGetValues(%s, XtNwidth, &w, XtNheight, &h, NULL);\n", name);
                    fprintf(gui, "XtVaSetValues(%s, XtNx, WidthOfScreen(scr)/2-(w/2), XtNy, HeightOfScreen(scr)/2-(h/2), NULL);\n", name);
                    }
                } else {
                fprintf(gui, "%s = XtCreateManagedWidget(\"%s\", %s, %s, args, n);\n", name, name, type, parent);
                }
                if( LEN(callback) ){
                    b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, callback); b2c_forin_item_string_org = b2c_forin_item_string;
                    b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, b2c_option_delim);
                    b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
                    for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
                        if( HASDELIM(item, ",") ){
                        fprintf(gui, "XtAddCallback(%s, %s, __b2c_xt_callback, \"%s\");\n", name, TOKEN(item, 1, ","), TOKEN(item, 2, ","));
                        } else {
                        fprintf(gui, "XtAddCallback(%s, %s, __b2c_xt_callback, NULL);\n", name, item);
                        }
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                }
            }
        fputs("n = 0;\n", gui);
        }
    }
    if( g_WHICH_GUI == 2 ){
    fputs("refreshCDKScreen(__main_window); setCDKFocusFirst(__main_window); resetCDKScreen(__main_window); return((uintptr_t)__main_window); }\n", gui);
    } else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
    fputs("return((uintptr_t)widget_list); }\n", gui);
    } else if( g_WHICH_GUI == 0 ){
    fputs("return((uintptr_t)__main_window); }\n", gui);
    }
    fclose(gui);
    __b2c__STRFREE(b2c_forin_item_string); b2c_forin_item_string = NULL; __b2c__STRFREE(b2c_forin_item_step); b2c_forin_item_step = NULL; __b2c__STRFREE(b2c_forin_func_string); b2c_forin_func_string = NULL; __b2c__STRFREE(b2c_forin_func_step); b2c_forin_func_step = NULL;
    __b2c__STRFREE(data);
    __b2c__STRFREE(widget);
    __b2c__STRFREE(type);
    __b2c__STRFREE(name);
    __b2c__STRFREE(parent);
    __b2c__STRFREE(callback);
    __b2c__STRFREE(uid);
    __b2c__STRFREE(resource);
    __b2c__STRFREE(icon);
    __b2c__STRFREE(map);
    __b2c__STRFREE(func);
    __b2c__STRFREE(prop);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(b2c_select_4016);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
