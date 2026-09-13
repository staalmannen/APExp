/*
 * bltList.h --
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.
 */
#ifndef _BLT_LIST_H
#define _BLT_LIST_H

typedef struct Blt_List Blt_List;

/*
 * A Blt_ListEntry is the container structure for the Blt_List.
 */
typedef struct Blt_ListEntry {
    struct Blt_ListEntry *prevPtr;	/* Link to the previous entry */
    struct Blt_ListEntry *nextPtr;	/* Link to the next entry */
    ClientData clientData;	/* Pointer to the data object */
    struct Blt_List *listPtr;	/* List to eventually insert entry */
    union {			/* Key has one of these forms: */
	char *oneWordValue;	/* One-word value for key. */
	int *words[1];		/* Multiple integer words for key.
				 * The actual size will be as large
				 * as necessary for this table's
				 * keys. */
	char string[4];		/* String for key.  The actual size
				 * will be as large as needed to hold
				 * the key. */
    } key;			/* MUST BE LAST FIELD IN RECORD!! */
} *Blt_ListEntry;

typedef int (Blt_ListCompareProc) _ANSI_ARGS_((Blt_ListEntry *entry1Ptr, 
	Blt_ListEntry *entry2Ptr));

/*
 * A Blt_List is a doubly chained list structure.
 */
struct Blt_List {
    struct Blt_ListEntry *headPtr;	/* Pointer to first element in list */
    struct Blt_ListEntry *tailPtr;	/* Pointer to last element in list */
    int nEntries;		/* Number of elements in list */
    int type;			/* Type of keys in list */
};

extern void Blt_InitList _ANSI_ARGS_((Blt_List *listPtr, int type));
extern Blt_List *Blt_ListCreate _ANSI_ARGS_((int type));
extern void Blt_ListDestroy _ANSI_ARGS_((Blt_List *listPtr));
extern Blt_ListEntry Blt_ListNewEntry _ANSI_ARGS_((Blt_List *listPtr, 
	char *key));
extern Blt_ListEntry Blt_ListAppend _ANSI_ARGS_((Blt_List *listPtr, char *key,
	ClientData clientData));
extern Blt_ListEntry Blt_ListPrepend _ANSI_ARGS_((Blt_List *listPtr, char *key,
	ClientData clientData));
extern void Blt_ListReset _ANSI_ARGS_((Blt_List *listPtr));
extern void Blt_ListLinkAfter _ANSI_ARGS_((Blt_List *listPtr, 
	Blt_ListEntry entry, Blt_ListEntry afterEntry));
extern void Blt_ListLinkBefore _ANSI_ARGS_((Blt_List *listPtr,
	Blt_ListEntry entry, Blt_ListEntry beforeEntry));
extern void Blt_ListUnlinkEntry _ANSI_ARGS_((Blt_ListEntry entry));
extern Blt_ListEntry Blt_ListFind _ANSI_ARGS_((Blt_List *listPtr, char *name));
extern void Blt_ListDeleteEntry _ANSI_ARGS_((Blt_ListEntry entry));
extern void Blt_ListDelete _ANSI_ARGS_((Blt_List *listPtr, char *name));
extern Blt_ListEntry Blt_ListGetNthEntry _ANSI_ARGS_((Blt_List *listPtr,
	int position, int direction));
extern void Blt_ListSort _ANSI_ARGS_((Blt_List *listPtr,
	Blt_ListCompareProc * proc));

#define Blt_ListGetLength(list) (((list) == NULL) ? 0 : (list)->nEntries)
#define Blt_ListFirstEntry(list) (((list) == NULL) ? NULL : (list)->headPtr)
#define Blt_ListLastEntry(list)	(((list) == NULL) ? NULL : (list)->tailPtr)
#define Blt_ListPrevEntry(entry)	((entry)->prevPtr)
#define Blt_ListNextEntry(entry) 	((entry)->nextPtr)
#define Blt_ListGetKey(entry)	(((entry)->listPtr->type == TCL_STRING_KEYS) \
		 ? (entry)->key.string : (entry)->key.oneWordValue)
#define Blt_ListGetValue(entry)  	((entry)->clientData)
#define Blt_ListSetValue(entry, value) \
	((entry)->clientData = (ClientData)(value))
#define Blt_ListAppendEntry(list, entry) \
	(Blt_ListLinkBefore((list), (entry), (Blt_ListEntry)NULL))
#define Blt_ListPrependEntry(list, entry) \
	(Blt_ListLinkAfter((list), (entry), (Blt_ListEntry)NULL))

#endif /* _BLT_LIST_H */
