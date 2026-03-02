/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void guiGenerate( char *__b2c_data__b2c__string_var) {
 char*data__b2c__string_var = NULL; data__b2c__string_var = __b2c_Copy_String(NULL, __b2c_data__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_item__b2c__string_var_ptr = 0; char* __b2c__forin_item__b2c__string_var_string = NULL; char* __b2c__forin_item__b2c__string_var_string_org = NULL; char* __b2c__forin_item__b2c__string_var_step = NULL; char *__b2c__select_4016__b2c__string_var = NULL; int __b2c__forin_func__b2c__string_var_ptr = 0; char* __b2c__forin_func__b2c__string_var_string = NULL; char* __b2c__forin_func__b2c__string_var_string_org = NULL; char* __b2c__forin_func__b2c__string_var_step = NULL;
#line 3940 "bacon.bac"
char *widget__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *name__b2c__string_var = NULL;
char *parent__b2c__string_var = NULL;
char *callback__b2c__string_var = NULL;
char *uid__b2c__string_var = NULL;
char *resource__b2c__string_var = NULL;
char *icon__b2c__string_var = NULL;
char *map__b2c__string_var = NULL;
char *func__b2c__string_var = NULL;
char *prop__b2c__string_var = NULL;
char *arg__b2c__string_var = NULL;
#line 3941 "bacon.bac"
FILE* gui = NULL;
#line 3943 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".gui.h") ;
#line 3945 "bacon.bac"
gui = fopen((const char*)CONCAT__b2c__string_var( g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".gui.h" ), "w");
if(gui == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 3945, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 3946 "bacon.bac"
if( g_WHICH_GUI == 2 ){
#line 3947 "bacon.bac"
__b2c__assign = (char*)"void* __b2c__cld = NULL; struct __b2c__cdk{ void *addr; char *name; }; struct __b2c__cdk *__b2c__cdknames = { NULL }; int __b2c__cdknr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3948 "bacon.bac"
__b2c__assign = (char*)"void *__b2c_get_by_name(uintptr_t id, char *name) { void *result = NULL; int x; for(x=0; x<__b2c__cdknr; x++){ if(!strcmp(name, __b2c__cdknames[x].name)) { result = __b2c__cdknames[x].addr; break; } } return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3949 "bacon.bac"
__b2c__assign = (char*)"static int __b2c_cdk_callback(EObjectType cdktype GCC_UNUSED, void *object, void *clientData, chtype key GCC_UNUSED) { __b2c__cld = clientData; return(TRUE); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3950 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long len; int key; boolean function; CDKOBJS *obj; CDKSCREEN *screen; screen = (CDKSCREEN*)id; __b2c__cld = NULL; refreshCDKScreen(screen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3951 "bacon.bac"
__b2c__assign = (char*)"while(__b2c__cld == NULL) { obj = getCDKFocusCurrent(screen); if(obj != NULL) { key = getchCDKObject(obj, &function); traverseCDKOnce(screen, obj, key, function, NULL); } } len = strlen((char *) __b2c__cld); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3952 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], __b2c__cld, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3953 "bacon.bac"
__b2c__assign = (char*)"uintptr_t __b2c__guiDefine(void){ atexit(endCDK);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3954 "bacon.bac"
} else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
#line 3955 "bacon.bac"
__b2c__assign = (char*)"gpointer __b2c__cld = NULL; gpointer __b2c__cad = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3956 "bacon.bac"
__b2c__assign = (char*)"void *__b2c_get_by_name(uintptr_t id, char *name) { GList *widget, *x; widget = (GList*)id; for(x = widget; x != NULL; x = x->next) { if(!strcmp(name, gtk_widget_get_name(GTK_WIDGET(x->data)))) { break; } } if(x==NULL) { return(NULL); } else { return(x->data); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3957 "bacon.bac"
__b2c__assign = (char*)"void __b2c_gtk_callback(gpointer client_data, uintptr_t call_data, GtkWidget *w) { size_t size; __b2c__cld = client_data;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3958 "bacon.bac"
__b2c__assign = (char*)"if(call_data) {if( (sizeof(call_data)>sizeof(gint) ? call_data>>(sizeof(gint)*8) : 0) == 0 && (gint)call_data < 0 && (gint)call_data > -16) { __b2c__cad = realloc(__b2c__cad, sizeof(gint)); (*(gint*)__b2c__cad) = (gint)call_data; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3959 "bacon.bac"
if( g_WHICH_GUI == 1 ){
#line 3960 "bacon.bac"
__b2c__assign = (char*)"{ switch(((GdkEventAny*)call_data)->type) { case GDK_BUTTON_PRESS: size = sizeof(GdkEventButton); break; case GDK_2BUTTON_PRESS: size = sizeof(GdkEventButton); break; case GDK_3BUTTON_PRESS: size = sizeof(GdkEventButton); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3961 "bacon.bac"
__b2c__assign = (char*)"case GDK_BUTTON_RELEASE: size = sizeof(GdkEventButton); break; case GDK_EXPOSE: size = sizeof(GdkEventExpose); break; case GDK_DAMAGE: size = sizeof(GdkEventExpose); break; case GDK_ENTER_NOTIFY: size = sizeof(GdkEventCrossing); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3962 "bacon.bac"
__b2c__assign = (char*)"case GDK_LEAVE_NOTIFY: size = sizeof(GdkEventCrossing); break; case GDK_FOCUS_CHANGE: size = sizeof(GdkEventFocus); break; case GDK_CONFIGURE: size = sizeof(GdkEventConfigure); break; case GDK_PROPERTY_NOTIFY: size = sizeof(GdkEventProperty); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3963 "bacon.bac"
__b2c__assign = (char*)"case GDK_SCROLL: size = sizeof(GdkEventScroll); break; case GDK_KEY_PRESS: size = sizeof(GdkEventKey); break; case GDK_KEY_RELEASE: size = sizeof(GdkEventKey); break; case GDK_SETTING: size = sizeof(GdkEventSetting); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3964 "bacon.bac"
__b2c__assign = (char*)"default: size = sizeof(GdkEventAny); } __b2c__cad = realloc(__b2c__cad, size); memcpy(__b2c__cad, (void*)call_data, size); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3965 "bacon.bac"
} else {
#line 3966 "bacon.bac"
__b2c__assign = (char*)"{ size = sizeof(void*); __b2c__cad = realloc(__b2c__cad, size); memcpy(__b2c__cad, (void*)call_data, size); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3967 "bacon.bac"
}
#line 3968 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; GList *widget; const char *name = NULL; unsigned long len, total = 0; widget=(GList*)id; __b2c__cld = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3969 "bacon.bac"
__b2c__assign = (char*)"GTKWIDGETSHOW(widget->data); while(1) { GTKMAINITERATION; if(__b2c__cld) { break; } } len = strlen((char*)__b2c__cld); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], __b2c__cld, len);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3970 "bacon.bac"
__b2c__assign = (char*)"if(type == 1) { total += len; buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+1+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), gui);
__b2c__assign = (char*) "+1); len = snprintf(buf[idx]+total, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), gui);
__b2c__assign = (char*) ", \" %p\", __b2c__cad); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3971 "bacon.bac"
__b2c__assign = (char*)"total += len; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3972 "bacon.bac"
__b2c__assign = (char*)"uintptr_t __b2c__guiDefine(void){ GList *widget_list = NULL; GTKINIT;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3973 "bacon.bac"
} else if( g_WHICH_GUI == 4 ){
#line 3974 "bacon.bac"
__b2c__assign = (char*)"void *__b2c__cld = NULL; int __b2c_tk_callback (ClientData client_data, Tcl_Interp * i, int argc, Tcl_Obj * const objv[]) { char *data, *token = NULL; if(client_data) { data = __b2c__strdup(client_data);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3975 "bacon.bac"
__b2c__assign = (char*)"__b2c__cld = strtok(data, \"+\"); token = strtok(NULL, \"+\"); if(token) { if (!strncmp(token, \"error\", 5)) { return(TCL_ERROR); } if (!strncmp(token, \"return\", 6)) { return(TCL_RETURN); } if(!strncmp(token, \"break\", 5))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3976 "bacon.bac"
__b2c__assign = (char*)"{ return (TCL_BREAK); } if(!strncmp (token, \"continue\", 8)) { return(TCL_CONTINUE); } } } else { __b2c__cld = NULL; } return(TCL_OK); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3977 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long len; while(1) { if(Tcl_DoOneEvent(TCL_ALL_EVENTS)) { if(__b2c__cld) { __b2c__STRFREE(__b2c__cld); break; } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3978 "bacon.bac"
__b2c__assign = (char*)"len = __b2c__len(__b2c__cld); buf[idx] = (char*) __b2c_str_realloc (buf[idx], len+1); memmove(buf[idx], __b2c__cld, len); __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; __b2c__cld = NULL; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3979 "bacon.bac"
__b2c__assign = (char*)"uintptr_t __b2c__guiDefine(void){ Tcl_Interp *interp; char *gui = NULL; Tcl_FindExecutable(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_CURFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\"); interp = Tcl_CreateInterp();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3980 "bacon.bac"
__b2c__assign = (char*)"if(Tcl_Init(interp) == TCL_ERROR) { fprintf(stderr, \"No TCL INIT possible: %s\\n\", Tcl_GetStringResult(interp)); exit(TCL_ERROR); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3981 "bacon.bac"
__b2c__assign = (char*)"if(Tk_Init(interp) == TCL_ERROR) { fprintf(stderr, \"No TK INIT possible: %s\\n\", Tcl_GetStringResult(interp)); exit(TCL_ERROR); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3982 "bacon.bac"
__b2c__assign = (char*)"gui = (char*)calloc(128+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs(STR__b2c__string_var( LEN(data__b2c__string_var)), gui);
__b2c__assign = (char*) ", sizeof(char)); strncpy(gui, \"package require Tk\\n\", 127);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3983 "bacon.bac"
if( LEN(data__b2c__string_var) ){
__b2c__assign = (char*)"gui = strcat(gui, \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) data__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
}
#line 3984 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, data__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, ";");
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 3985 "bacon.bac"
if( ISTOKEN(item__b2c__string_var, "\\\"WM_DELETE_WINDOW\\\"")  AND  REGEX(TOKEN__b2c__string_var(item__b2c__string_var, ISTOKEN(item__b2c__string_var, "\\\"WM_DELETE_WINDOW\\\"")+1), "^[a-zA-Z0-9_]+$") ){
callback__b2c__string_var = F_APPEND__b2c__string_var(callback__b2c__string_var,callback__b2c__string_var, 0, TOKEN__b2c__string_var(item__b2c__string_var, ISTOKEN(item__b2c__string_var, "\\\"WM_DELETE_WINDOW\\\"")+1));
}
#line 3986 "bacon.bac"
if( ISTOKEN(item__b2c__string_var, "-command")  AND  REGEX(TOKEN__b2c__string_var(item__b2c__string_var, ISTOKEN(item__b2c__string_var, "-command")+1), "^[a-zA-Z0-9+_]+$") ){
callback__b2c__string_var = F_APPEND__b2c__string_var(callback__b2c__string_var,callback__b2c__string_var, 0, TOKEN__b2c__string_var(item__b2c__string_var, ISTOKEN(item__b2c__string_var, "-command")+1));
}
#line 3987 "bacon.bac"
if( __b2c__STRCMP(HEAD__b2c__string_var(CHOP__b2c__string_var(item__b2c__string_var)) ,  "bind") == 0  AND  AMOUNT(item__b2c__string_var) == 4  AND  REGEX(TAIL__b2c__string_var(CHOP__b2c__string_var(item__b2c__string_var)), "^[a-zA-Z0-9+_]+$") ){
callback__b2c__string_var = F_APPEND__b2c__string_var(callback__b2c__string_var,callback__b2c__string_var, 0, TAIL__b2c__string_var(CHOP__b2c__string_var(item__b2c__string_var)));
}
#line 3988 "bacon.bac"
}
#line 3989 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
#line 3990 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, SORT__b2c__string_var(UNIQ__b2c__string_var(callback__b2c__string_var))); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 3991 "bacon.bac"
__b2c__assign = (char*)"Tcl_CreateObjCommand(interp, \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) item__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", __b2c_tk_callback, (ClientData)\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) item__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3992 "bacon.bac"
}
#line 3993 "bacon.bac"
}
#line 3994 "bacon.bac"
__b2c__assign = (char*)"Tcl_Eval(interp, gui); return((uintptr_t)interp); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3995 "bacon.bac"
} else {
#line 3996 "bacon.bac"
__b2c__assign = (char*)"Widget __b2c__CallbackedWidget; XtPointer __b2c__cld = NULL; XtPointer __b2c__cad = NULL; Atom __b2c_wm_delete_window = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3997 "bacon.bac"
__b2c__assign = (char*)"int __b2c_xt_close(Display *dpy) { XtCloseDisplay(dpy); exit(EXIT_SUCCESS); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3998 "bacon.bac"
__b2c__assign = (char*)"static void __b2c_wm_delete(Widget w, XEvent *event, String *params, Cardinal *num_params)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 3999 "bacon.bac"
__b2c__assign = (char*)"{ if(event->type == ClientMessage && event->xclient.data.l[0] == __b2c_wm_delete_window) { __b2c__CallbackedWidget = w; __b2c__cld = params[0]; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4000 "bacon.bac"
__b2c__assign = (char*)"void __b2c_xt_callback(Widget w, XtPointer client_data, XtPointer call_data)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4001 "bacon.bac"
__b2c__assign = (char*)"{ __b2c__CallbackedWidget = w; if(client_data) { __b2c__cld = client_data; } if(call_data) { __b2c__cad = calloc(1, sizeof(XtPointer)); memcpy(__b2c__cad, call_data, sizeof(XtPointer)); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4002 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__guiExecute(uintptr_t id, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *name; unsigned long len, total = 0; __b2c__CallbackedWidget = NULL; if(__b2c__cad) { free(__b2c__cad); } __b2c__cad = NULL; __b2c__cld = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4003 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } XtRealizeWidget((Widget)id); if(__b2c_wm_delete_window) { XSetWMProtocols(XtDisplay((Widget)id), XtWindow((Widget)id), &__b2c_wm_delete_window, 1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4004 "bacon.bac"
__b2c__assign = (char*)"while(1) { XtAppProcessEvent(XtWidgetToApplicationContext((Widget)id), XtIMAll); if(__b2c__CallbackedWidget) { break; } } if(__b2c__cld) { len = strlen(__b2c__cld); buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], __b2c__cld, len); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4005 "bacon.bac"
__b2c__assign = (char*)"else { name = XtName(__b2c__CallbackedWidget); if(name == NULL) { return(NULL); } len = strlen(name); buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memmove(buf[idx], name, len); } if(type == 1) { total += len;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4006 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+1+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), gui);
__b2c__assign = (char*) "+1); len = snprintf(buf[idx]+total, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), gui);
__b2c__assign = (char*) ", \" %p\", __b2c__cad); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4007 "bacon.bac"
__b2c__assign = (char*)"total += len; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4008 "bacon.bac"
__b2c__assign = (char*)"uintptr_t __b2c__guiDefine(void){XtAppContext app; Display *dpy; Screen *scr; Arg args[32]; int n = 0, argc = 1; char *argv[1];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4009 "bacon.bac"
}
#line 4010 "bacon.bac"
while( (LEN(data__b2c__string_var) )> 2  AND  g_WHICH_GUI != 4 ){
#line 4011 "bacon.bac"
widget__b2c__string_var = __b2c_Copy_String(widget__b2c__string_var, (char*) FLATTEN__b2c__string_var(INBETWEEN__b2c__string_var(data__b2c__string_var, "{" , "}")));
#line 4012 "bacon.bac"
data__b2c__string_var = F_CHOP__b2c__string_var(data__b2c__string_var,OUTBETWEEN__b2c__string_var(data__b2c__string_var, "{", "}"));
#line 4013 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "");
name__b2c__string_var = __b2c_Copy_String(name__b2c__string_var, (char*) "");
parent__b2c__string_var = __b2c_Copy_String(parent__b2c__string_var, (char*) "");
callback__b2c__string_var = __b2c_Copy_String(callback__b2c__string_var, (char*) "");
prop__b2c__string_var = __b2c_Copy_String(prop__b2c__string_var, (char*) ",");
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) "");
#line 4014 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, widget__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4015 "bacon.bac"
item__b2c__string_var = __b2c_Copy_String(item__b2c__string_var, (char*) REPLACE__b2c__string_var(CHOP__b2c__string_var(item__b2c__string_var), "\\$$", g_STRINGSIGN__b2c__string_var, TRUE));
#line 4016 "bacon.bac"
__b2c__select_4016__b2c__string_var = __b2c_Copy_String(__b2c__select_4016__b2c__string_var, TOKEN__b2c__string_var(item__b2c__string_var, 1, "="));
#line 4017 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "type")){
#line 4018 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4019 "bacon.bac"
if( (g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3)  AND  NOT(INSTR(type__b2c__string_var, "_TYPE_")) ){
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, "GTK_TYPE_" , UCASE__b2c__string_var(type__b2c__string_var));
}
#line 4020 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "name")){
#line 4021 "bacon.bac"
name__b2c__string_var = __b2c_Copy_String(name__b2c__string_var, (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4022 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "parent")){
#line 4023 "bacon.bac"
parent__b2c__string_var = __b2c_Copy_String(parent__b2c__string_var, (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4024 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "callback")){
#line 4025 "bacon.bac"
callback__b2c__string_var = F_APPEND__b2c__string_var(callback__b2c__string_var,callback__b2c__string_var, 0, TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4026 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "map")){
#line 4027 "bacon.bac"
map__b2c__string_var = F_APPEND__b2c__string_var(map__b2c__string_var,map__b2c__string_var, 0, TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4028 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "uid")){
#line 4029 "bacon.bac"
uid__b2c__string_var = F_APPEND__b2c__string_var(uid__b2c__string_var,uid__b2c__string_var, 0, TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4030 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "resources")){
#line 4031 "bacon.bac"
resource__b2c__string_var = __b2c_Copy_String(resource__b2c__string_var, (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4032 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4016__b2c__string_var, "args")){
#line 4033 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, "="));
#line 4034 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) REPLACE__b2c__string_var(CHOP__b2c__string_var(arg__b2c__string_var), "$", g_STRINGSIGN__b2c__string_var));
#line 4035 "bacon.bac"
} else {
#line 4036 "bacon.bac"
if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
#line 4037 "bacon.bac"
prop__b2c__string_var = F_CONCAT__b2c__string_var(prop__b2c__string_var, prop__b2c__string_var , CHR__b2c__string_var(34) , TOKEN__b2c__string_var(item__b2c__string_var, 1, "=") , CHR__b2c__string_var(34) , "," , TOKEN__b2c__string_var(item__b2c__string_var, 2, "=") , ",") ;
#line 4038 "bacon.bac"
} else if( g_WHICH_GUI == 0 ){
#line 4039 "bacon.bac"
__b2c__assign = (char*)"XtSetArg(args[n], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) DELIM__b2c__string_var(item__b2c__string_var, "=", ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "); n++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4040 "bacon.bac"
}
#line 4041 "bacon.bac"
}
#line 4042 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4043 "bacon.bac"
if( LEN(name__b2c__string_var) == 0  AND  g_WHICH_GUI != 4 ){
#line 4044 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: widget does not have a name at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4045 "bacon.bac"
exit(1);
#line 4046 "bacon.bac"
}
#line 4047 "bacon.bac"
if( LEN(type__b2c__string_var) == 0  AND  g_WHICH_GUI != 4 ){
#line 4048 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: widget does not have a type at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4049 "bacon.bac"
exit(1);
#line 4050 "bacon.bac"
}
#line 4051 "bacon.bac"
if( g_WHICH_GUI == 2 ){
#line 4052 "bacon.bac"
if( __b2c__STRCMP(LCASE__b2c__string_var(type__b2c__string_var) ,  "window") == 0 ){
#line 4053 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "CDKSCREEN *" , name__b2c__string_var , ", *__main_window;" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4054 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " = initCDKScreen(initscr()); initCDKColor(); __main_window = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4055 "bacon.bac"
} else {
#line 4056 "bacon.bac"
__b2c__assign = (char*)"CDK"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) UCASE__b2c__string_var(type__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4057 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " = newCDK"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) PROPER__b2c__string_var(type__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4058 "bacon.bac"
}
#line 4059 "bacon.bac"
__b2c__assign = (char*)"__b2c__cdknames = realloc(__b2c__cdknames, sizeof(struct __b2c__cdk)*(__b2c__cdknr+1));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4060 "bacon.bac"
__b2c__assign = (char*)"__b2c__cdknames[__b2c__cdknr].name = __b2c__strdup(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\"); __b2c__cdknames[__b2c__cdknr].addr = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "; __b2c__cdknr++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4061 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
#line 4062 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, callback__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4063 "bacon.bac"
if( HASDELIM(item__b2c__string_var, ",") ){
#line 4064 "bacon.bac"
__b2c__assign = (char*)"bindCDKObject(v"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) UCASE__b2c__string_var(type__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", __b2c_cdk_callback, \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4065 "bacon.bac"
} else {
#line 4066 "bacon.bac"
__b2c__assign = (char*)"bindCDKObject(v"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) UCASE__b2c__string_var(type__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", __b2c_cdk_callback, \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4067 "bacon.bac"
}
#line 4068 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4069 "bacon.bac"
}
#line 4070 "bacon.bac"
} else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
#line 4071 "bacon.bac"
__b2c__assign = (char*)"GtkWidget *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4072 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) CONCAT__b2c__string_var( "= GTK_WIDGET(g_object_new(" , type__b2c__string_var , " " , prop__b2c__string_var , " NULL));" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4073 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "GTK_TYPE_WINDOW") == 0  OR  INSTR(type__b2c__string_var, "DIALOG") ){
__b2c__assign = (char*)CONCAT__b2c__string_var( "gtk_window_set_icon_name(GTK_WINDOW(" , name__b2c__string_var , "), \"bacon\");" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
}
#line 4074 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "gtk_widget_set_name(" , name__b2c__string_var , ", \"" , name__b2c__string_var , "\");" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4075 "bacon.bac"
__b2c__assign = (char*)"widget_list = g_list_append(widget_list, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4076 "bacon.bac"
if( LEN(parent__b2c__string_var) ){
#line 4077 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "GTK_TYPE_MENU") == 0  OR  __b2c__STRCMP(type__b2c__string_var ,  "GTK_TYPE_MENU_ITEM") == 0 ){
#line 4078 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "gtk_menu_shell_append(GTK_MENU_SHELL(" , parent__b2c__string_var , "), " , name__b2c__string_var , ");" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4079 "bacon.bac"
} else {
#line 4080 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "GTKCONTAINERADD(" , parent__b2c__string_var , ", " , name__b2c__string_var , ");" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4081 "bacon.bac"
}
#line 4082 "bacon.bac"
}
#line 4083 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
#line 4084 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, callback__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4085 "bacon.bac"
if( HASDELIM(item__b2c__string_var, ",") ){
#line 4086 "bacon.bac"
__b2c__assign = (char*)"g_signal_connect_swapped(G_OBJECT("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "), \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", G_CALLBACK(__b2c_gtk_callback), \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4087 "bacon.bac"
} else {
#line 4088 "bacon.bac"
__b2c__assign = (char*)"g_signal_connect_swapped(G_OBJECT("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "), \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", G_CALLBACK(__b2c_gtk_callback), \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4089 "bacon.bac"
}
#line 4090 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4091 "bacon.bac"
}
#line 4092 "bacon.bac"
} else {
#line 4093 "bacon.bac"
__b2c__assign = (char*)"Widget "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4094 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "window") == 0 ){
#line 4095 "bacon.bac"
__b2c__assign = (char*)"Widget __main_window; Dimension w, h;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4096 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
__b2c__assign = (char*)"XtActionsRec actions[1];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
}
#line 4097 "bacon.bac"
__b2c__assign = (char*)"XtSetLanguageProc(NULL, NULL, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4098 "bacon.bac"
__b2c__assign = (char*)"argv[0] = calloc(1, sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4099 "bacon.bac"
if( FILEEXISTS("/usr/local/share/pixmaps/BaCon.xbm") ){
#line 4100 "bacon.bac"
icon__b2c__string_var = __b2c_Copy_String(icon__b2c__string_var, (char*) "/usr/local/share/pixmaps/BaCon.xbm");
#line 4101 "bacon.bac"
} else if( FILEEXISTS("/usr/share/pixmaps/BaCon.xbm") ){
#line 4102 "bacon.bac"
icon__b2c__string_var = __b2c_Copy_String(icon__b2c__string_var, (char*) "/usr/share/pixmaps/BaCon.xbm");
#line 4103 "bacon.bac"
} else {
#line 4104 "bacon.bac"
icon__b2c__string_var = __b2c_Copy_String(icon__b2c__string_var, (char*) "xlogo32");
#line 4105 "bacon.bac"
}
#line 4106 "bacon.bac"
if( LEN(resource__b2c__string_var) ){
#line 4107 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "String resources[] = { \"*iconPixmap:" , icon__b2c__string_var , "\", ") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) resource__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4108 "bacon.bac"
} else {
#line 4109 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "String resources[] = { \"*iconPixmap:" , icon__b2c__string_var , "\", NULL };" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4110 "bacon.bac"
}
#line 4111 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " = XtOpenApplication(&app, \"BaConGUI\", NULL, 0, &argc, argv, resources, sessionShellWidgetClass, args, n);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4112 "bacon.bac"
__b2c__assign = (char*)"dpy = XtDisplay("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4113 "bacon.bac"
__b2c__assign = (char*)"scr = XtScreen("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4114 "bacon.bac"
__b2c__assign = (char*)"XtVaGetValues("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XtNwidth, &w, XtNheight, &h, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4115 "bacon.bac"
__b2c__assign = (char*)"XtVaSetValues("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XtNx, WidthOfScreen(scr)/2-(w/2), XtNy, HeightOfScreen(scr)/2-(h/2), NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4116 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
#line 4117 "bacon.bac"
__b2c__assign = (char*)"__b2c_wm_delete_window = XInternAtom(dpy, \"WM_DELETE_WINDOW\", False);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4118 "bacon.bac"
__b2c__assign = (char*)"actions[0].string = \"__b2c_wm_delete\"; actions[0].proc = __b2c_wm_delete;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4119 "bacon.bac"
__b2c__assign = (char*)"XtAppAddActions(app, actions, XtNumber(actions));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4120 "bacon.bac"
__b2c__assign = (char*)"XtOverrideTranslations("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XtParseTranslationTable(\"<Message>WM_PROTOCOLS: __b2c_wm_delete("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) callback__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ")\"));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4121 "bacon.bac"
__b2c__assign = (char*)"#ifndef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4122 "bacon.bac"
__b2c__assign = (char*)"XtVaSetValues("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XmNdeleteResponse, XmDO_NOTHING, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4123 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4124 "bacon.bac"
}
#line 4125 "bacon.bac"
__b2c__assign = (char*)"__main_window = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4126 "bacon.bac"
__b2c__assign = (char*)"XSetIOErrorHandler(__b2c_xt_close);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4127 "bacon.bac"
__b2c__assign = (char*)"#ifdef __b2c__gui_uil"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4128 "bacon.bac"
__b2c__assign = (char*)"MrmHierarchy hierarchy;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4129 "bacon.bac"
__b2c__assign = (char*)"MrmType class_code;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4130 "bacon.bac"
__b2c__assign = (char*)"Widget main_object;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4131 "bacon.bac"
__b2c__assign = (char*)"static MrmRegisterArg callback_list[] = {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4132 "bacon.bac"
if( LEN(map__b2c__string_var) ){
#line 4133 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, map__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4134 "bacon.bac"
__b2c__forin_func__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_func__b2c__string_var_string, item__b2c__string_var); __b2c__forin_func__b2c__string_var_string_org = __b2c__forin_func__b2c__string_var_string;
__b2c__forin_func__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_func__b2c__string_var_step, ",");
__b2c__forin_func__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_func__b2c__string_var_string, __b2c__forin_func__b2c__string_var_step);
for(; __b2c__forin_func__b2c__string_var_ptr > 0; __b2c__forin_func__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_func__b2c__string_var_string_org, __b2c__forin_func__b2c__string_var_step, &func__b2c__string_var);
#line 4135 "bacon.bac"
__b2c__assign = (char*)"{ \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) func__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", (XtPointer)__b2c_xt_callback },"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4136 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4137 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4138 "bacon.bac"
} else {
#line 4139 "bacon.bac"
__b2c__assign = (char*)" NULL "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4140 "bacon.bac"
}
#line 4141 "bacon.bac"
__b2c__assign = (char*)"};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4142 "bacon.bac"
__b2c__assign = (char*)"static String uid_file_list[] = {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4143 "bacon.bac"
if( AMOUNT(uid__b2c__string_var) ){
#line 4144 "bacon.bac"
__b2c__assign = (char*)"\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) HEAD__b2c__string_var(uid__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4145 "bacon.bac"
if( (AMOUNT(uid__b2c__string_var) )> 1 ){
#line 4146 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, LAST__b2c__string_var(uid__b2c__string_var)); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4147 "bacon.bac"
__b2c__assign = (char*)", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) item__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\" "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4148 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4149 "bacon.bac"
}
#line 4150 "bacon.bac"
} else {
#line 4151 "bacon.bac"
__b2c__assign = (char*)" NULL "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4152 "bacon.bac"
}
#line 4153 "bacon.bac"
__b2c__assign = (char*)"};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4154 "bacon.bac"
__b2c__assign = (char*)"MrmInitialize();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4155 "bacon.bac"
__b2c__assign = (char*)"MrmOpenHierarchyPerDisplay(dpy, XtNumber(uid_file_list), uid_file_list, NULL, &hierarchy);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4156 "bacon.bac"
__b2c__assign = (char*)"MrmRegisterNames(callback_list, XtNumber(callback_list));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4157 "bacon.bac"
__b2c__assign = (char*)"MrmFetchWidget(hierarchy, \"main\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", &main_object, &class_code);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4158 "bacon.bac"
__b2c__assign = (char*)"MrmCloseHierarchy(hierarchy);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4159 "bacon.bac"
__b2c__assign = (char*)"XtManageChild(main_object);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4160 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4161 "bacon.bac"
__b2c__assign = (char*)"free(argv[0]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4162 "bacon.bac"
} else {
#line 4163 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(type__b2c__string_var, 5) ,  "shell") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(type__b2c__string_var, 10) ,  "simpleMenu") == 0  OR  INSTR(type__b2c__string_var, "Shell") ){
#line 4164 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " = XtCreatePopupShell(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) parent__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", args, n);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4165 "bacon.bac"
if( INSTR(LCASE__b2c__string_var(type__b2c__string_var), "shell") ){
#line 4166 "bacon.bac"
__b2c__assign = (char*)"XtVaGetValues("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XtNwidth, &w, XtNheight, &h, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4167 "bacon.bac"
__b2c__assign = (char*)"XtVaSetValues("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", XtNx, WidthOfScreen(scr)/2-(w/2), XtNy, HeightOfScreen(scr)/2-(h/2), NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4168 "bacon.bac"
}
#line 4169 "bacon.bac"
} else {
#line 4170 "bacon.bac"
__b2c__assign = (char*)name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) " = XtCreateManagedWidget(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) parent__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", args, n);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4171 "bacon.bac"
}
#line 4172 "bacon.bac"
if( LEN(callback__b2c__string_var) ){
#line 4173 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, callback__b2c__string_var); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 4174 "bacon.bac"
if( HASDELIM(item__b2c__string_var, ",") ){
#line 4175 "bacon.bac"
__b2c__assign = (char*)"XtAddCallback("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", __b2c_xt_callback, \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) TOKEN__b2c__string_var(item__b2c__string_var, 2, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) "\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4176 "bacon.bac"
} else {
#line 4177 "bacon.bac"
__b2c__assign = (char*)"XtAddCallback("; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) item__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
__b2c__assign = (char*) ", __b2c_xt_callback, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4178 "bacon.bac"
}
#line 4179 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4180 "bacon.bac"
}
#line 4181 "bacon.bac"
}
#line 4182 "bacon.bac"
__b2c__assign = (char*)"n = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4183 "bacon.bac"
}
#line 4184 "bacon.bac"
}
#line 4186 "bacon.bac"
if( g_WHICH_GUI == 2 ){
#line 4187 "bacon.bac"
__b2c__assign = (char*)"refreshCDKScreen(__main_window); setCDKFocusFirst(__main_window); resetCDKScreen(__main_window); return((uintptr_t)__main_window); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4188 "bacon.bac"
} else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
#line 4189 "bacon.bac"
__b2c__assign = (char*)"return((uintptr_t)widget_list); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4190 "bacon.bac"
} else if( g_WHICH_GUI == 0 ){
#line 4191 "bacon.bac"
__b2c__assign = (char*)"return((uintptr_t)__main_window); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, gui); }
fputs("\n", gui);
#line 4192 "bacon.bac"
}
#line 4193 "bacon.bac"
fclose(gui);
#line 4195 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_item__b2c__string_var_string); __b2c__forin_item__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_item__b2c__string_var_step); __b2c__forin_item__b2c__string_var_step = NULL; __b2c__STRFREE(__b2c__forin_func__b2c__string_var_string); __b2c__forin_func__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_func__b2c__string_var_step); __b2c__forin_func__b2c__string_var_step = NULL;
__b2c__STRFREE(data__b2c__string_var);
__b2c__STRFREE(widget__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(name__b2c__string_var);
__b2c__STRFREE(parent__b2c__string_var);
__b2c__STRFREE(callback__b2c__string_var);
__b2c__STRFREE(uid__b2c__string_var);
__b2c__STRFREE(resource__b2c__string_var);
__b2c__STRFREE(icon__b2c__string_var);
__b2c__STRFREE(map__b2c__string_var);
__b2c__STRFREE(func__b2c__string_var);
__b2c__STRFREE(prop__b2c__string_var);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(__b2c__select_4016__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
