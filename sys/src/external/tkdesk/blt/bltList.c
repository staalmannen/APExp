/*
 * bltList.c --
 *
 *	The module implements generic linked lists.
 *
 * Copyright 1991-1998 Lucent Technologies, Inc.
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

#include "bltInt.h"
#include "bltList.h"

static struct Blt_ListEntry *
FindString(listPtr, key)
    Blt_List *listPtr;		/* List to search */
    char *key;			/* Key to match */
{
    register struct Blt_ListEntry *entryPtr;
    char c;

    c = key[0];
    for (entryPtr = listPtr->headPtr; entryPtr != NULL; 
	 entryPtr = entryPtr->nextPtr) {
	if ((c == entryPtr->key.string[0]) &&
	    (strcmp(key, entryPtr->key.string) == 0)) {
	    return entryPtr;
	}
    }
    return NULL;
}

static struct Blt_ListEntry *
FindOneWord(listPtr, key)
    Blt_List *listPtr;		/* List to search */
    char *key;			/* Key to match */
{
    register struct Blt_ListEntry *entryPtr;

    for (entryPtr = listPtr->headPtr; entryPtr != NULL; 
	 entryPtr = entryPtr->nextPtr) {
	if (key == entryPtr->key.oneWordValue) {
	    return entryPtr;
	}
    }
    return NULL;
}

static struct Blt_ListEntry *
FindArray(listPtr, key)
    Blt_List *listPtr;		/* List to search */
    char *key;			/* Key to match */
{
    register struct Blt_ListEntry *entryPtr;
    int nBytes;

    nBytes = sizeof(int) * listPtr->type;
    for (entryPtr = listPtr->headPtr; entryPtr != NULL; 
	 entryPtr = entryPtr->nextPtr) {
	if (memcmp(key, entryPtr->key.words, nBytes) == 0) {
	    return entryPtr;
	}
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListCreate --
 *
 *	Creates a new linked list structure and initializes its pointers
 *
 * Results:
 *	Returns a pointer to the newly created list structure.
 *
 *----------------------------------------------------------------------
 */
Blt_List *
Blt_ListCreate(type)
    int type;
{
    Blt_List *listPtr;

    listPtr = (Blt_List *)malloc(sizeof(Blt_List));
    if (listPtr != NULL) {
	Blt_InitList(listPtr, type);
    }
    return (listPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListNewEntry --
 *
 *	Creates a list entry holder.  This routine does not insert
 *	the entry into the list, nor does it no attempt to maintain
 *	consistency of the keys.  For example, more than one entry
 *	may use the same key.
 *
 * Results:
 *	The return value is the pointer to the newly created entry.
 *
 * Side Effects:
 *	The key is not copied, only the Uid is kept.  It is assumed
 *	this key will not change in the life of the entry.
 *
 *----------------------------------------------------------------------
 */
Blt_ListEntry
Blt_ListNewEntry(listPtr, key)
    Blt_List *listPtr;
    char *key;			/* Unique key to reference object */
{
    register struct Blt_ListEntry *entryPtr;
    int keySize;

    if (listPtr->type == TCL_STRING_KEYS) {
	keySize = strlen(key) + 1;
    } else {
	keySize = sizeof(int) * listPtr->type;
    }
    entryPtr = (struct Blt_ListEntry *)
	calloc(1, sizeof(struct Blt_ListEntry) + keySize - 4);
    assert(entryPtr);
    entryPtr->clientData = (ClientData)NULL;
    entryPtr->nextPtr = entryPtr->prevPtr = NULL;
    entryPtr->listPtr = listPtr;
    switch (listPtr->type) {
    case TCL_STRING_KEYS:
	strcpy(entryPtr->key.string, key);
	break;
    case TCL_ONE_WORD_KEYS:
	entryPtr->key.oneWordValue = key;
	break;
    default:
	memcpy(entryPtr->key.words, key, keySize);
	break;
    }
    return entryPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * FreeEntry --
 *
 *	Free the memory allocated for the entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
static void
FreeEntry(entryPtr)
    struct Blt_ListEntry *entryPtr;
{
    free((char *)entryPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListReset --
 *
 *	Removes all the entries from a list, removing pointers to the
 *	objects and keys (not the objects or keys themselves).  The
 *	entry counter is reset to zero.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListReset(listPtr)
    Blt_List *listPtr;		/* List to clear */
{
    if (listPtr != NULL) {
	register struct Blt_ListEntry *oldPtr;
	register struct Blt_ListEntry *entryPtr = listPtr->headPtr;

	while (entryPtr != NULL) {
	    oldPtr = entryPtr;
	    entryPtr = entryPtr->nextPtr;
	    FreeEntry(oldPtr);
	}
	Blt_InitList(listPtr, listPtr->type);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListDestroy
 *
 *     Frees all list structures
 *
 * Results:
 *	Returns a pointer to the newly created list structure.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListDestroy(listPtr)
    Blt_List *listPtr;
{
    if (listPtr != NULL) {
	Blt_ListReset(listPtr);
	free((char *)listPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_InitList --
 *
 *	Initializes a linked list.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_InitList(listPtr, type)
    Blt_List *listPtr;
    int type;
{
    listPtr->nEntries = 0;
    listPtr->headPtr = listPtr->tailPtr = NULL;
    listPtr->type = type;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListLinkAfter --
 *
 *	Inserts an entry following a given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListLinkAfter(listPtr, entryPtr, afterPtr)
    Blt_List *listPtr;
    struct Blt_ListEntry *entryPtr;
    struct Blt_ListEntry *afterPtr;
{
    if (listPtr->headPtr == NULL) {
	listPtr->tailPtr = listPtr->headPtr = entryPtr;
    } else {
	if (afterPtr == NULL) {
	    /* Prepend to the front of the list */
	    entryPtr->nextPtr = listPtr->headPtr;
	    entryPtr->prevPtr = NULL;
	    listPtr->headPtr->prevPtr = entryPtr;
	    listPtr->headPtr = entryPtr;
	} else {
	    entryPtr->nextPtr = afterPtr->nextPtr;
	    entryPtr->prevPtr = afterPtr;
	    if (afterPtr == listPtr->tailPtr) {
		listPtr->tailPtr = entryPtr;
	    } else {
		afterPtr->nextPtr->prevPtr = entryPtr;
	    }
	    afterPtr->nextPtr = entryPtr;
	}
    }
    entryPtr->listPtr = listPtr;
    listPtr->nEntries++;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListLinkBefore --
 *
 *	Inserts an entry preceding a given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListLinkBefore(listPtr, entryPtr, beforePtr)
    Blt_List *listPtr;		/* List to contain new entry */
    struct Blt_ListEntry *entryPtr;	/* New entry to be inserted */
    struct Blt_ListEntry *beforePtr;	/* Entry to link before */
{
    if (listPtr->headPtr == NULL) {
	listPtr->tailPtr = listPtr->headPtr = entryPtr;
    } else {
	if (beforePtr == NULL) {
	    /* Append onto the end of the list */
	    entryPtr->nextPtr = NULL;
	    entryPtr->prevPtr = listPtr->tailPtr;
	    listPtr->tailPtr->nextPtr = entryPtr;
	    listPtr->tailPtr = entryPtr;
	} else {
	    entryPtr->prevPtr = beforePtr->prevPtr;
	    entryPtr->nextPtr = beforePtr;
	    if (beforePtr == listPtr->headPtr) {
		listPtr->headPtr = entryPtr;
	    } else {
		beforePtr->prevPtr->nextPtr = entryPtr;
	    }
	    beforePtr->prevPtr = entryPtr;
	}
    }
    entryPtr->listPtr = listPtr;
    listPtr->nEntries++;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListUnlinkEntry --
 *
 *	Unlinks an entry from the given list. The entry itself is
 *	not deallocated, but only removed from the list.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListUnlinkEntry(entryPtr)
    struct Blt_ListEntry *entryPtr;
{
    Blt_List *listPtr;

    listPtr = entryPtr->listPtr;
    if (listPtr != NULL) {
	if (listPtr->headPtr == entryPtr) {
	    listPtr->headPtr = entryPtr->nextPtr;
	}
	if (listPtr->tailPtr == entryPtr) {
	    listPtr->tailPtr = entryPtr->prevPtr;
	}
	if (entryPtr->nextPtr != NULL) {
	    entryPtr->nextPtr->prevPtr = entryPtr->prevPtr;
	}
	if (entryPtr->prevPtr != NULL) {
	    entryPtr->prevPtr->nextPtr = entryPtr->nextPtr;
	}
	entryPtr->listPtr = NULL;
	listPtr->nEntries--;
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListFind --
 *
 *	Find the first entry matching the key given.
 *
 * Results:
 *	Returns the pointer to the entry.  If no entry matching
 *	the key given is found, then NULL is returned.
 *
 *----------------------------------------------------------------------
 */

Blt_ListEntry
Blt_ListFind(listPtr, key)
    Blt_List *listPtr;		/* List to search */
    char *key;			/* Key to match */
{
    if (listPtr != NULL) {
	switch (listPtr->type) {
	case TCL_STRING_KEYS:
	    return FindString(listPtr, key);
	case TCL_ONE_WORD_KEYS:
	    return FindOneWord(listPtr, key);
	default:
	    return FindArray(listPtr, key);
	}
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListDeleteEntry --
 *
 *	Unlinks and deletes the given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListDeleteEntry(entryPtr)
    struct Blt_ListEntry *entryPtr;
{
    Blt_ListUnlinkEntry(entryPtr);
    FreeEntry(entryPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListDelete --
 *
 *	Find the entry and free the memory allocated for the entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListDelete(listPtr, key)
    Blt_List *listPtr;
    char *key;
{
    struct Blt_ListEntry *entryPtr;

    entryPtr = Blt_ListFind(listPtr, key);
    if (entryPtr != NULL) {
	Blt_ListDeleteEntry(entryPtr);
    }
}

Blt_ListEntry
Blt_ListAppend(listPtr, key, clientData)
    Blt_List *listPtr;
    char *key;
    ClientData clientData;
{
    struct Blt_ListEntry *entryPtr;

    entryPtr = Blt_ListNewEntry(listPtr, key);
    Blt_ListSetValue(entryPtr, clientData);
    Blt_ListAppendEntry(listPtr, entryPtr);
    return entryPtr;
}

Blt_ListEntry
Blt_ListPrepend(listPtr, key, clientData)
    Blt_List *listPtr;
    char *key;
    ClientData clientData;
{
    struct Blt_ListEntry *entryPtr;

    entryPtr = Blt_ListNewEntry(listPtr, key);
    Blt_ListSetValue(entryPtr, clientData);
    Blt_ListPrependEntry(listPtr, entryPtr);
    return entryPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListGetNthEntry --
 *
 *	Find the entry based upon a given position in list.
 *
 * Results:
 *	Returns the pointer to the entry, if that numbered element
 *	exists. Otherwise NULL.
 *
 *----------------------------------------------------------------------
 */
Blt_ListEntry
Blt_ListGetNthEntry(listPtr, position, direction)
    Blt_List *listPtr;		/* List to traverse */
    int position;		/* Index of entry to select from front
				 * or back of the list. */
    int direction;
{
    register struct Blt_ListEntry *entryPtr;

    if (listPtr != NULL) {
	if (direction > 0) {
	    for (entryPtr = listPtr->headPtr; entryPtr != NULL; 
		 entryPtr = entryPtr->nextPtr) {
		if (position == 0) {
		    return entryPtr;
		}
		position--;
	    }
	} else {
	    for (entryPtr = listPtr->tailPtr; entryPtr != NULL; 
		 entryPtr = entryPtr->prevPtr) {
		if (position == 0) {
		    return entryPtr;
		}
		position--;
	    }
	}
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ListSort --
 *
 *	Find the entry based upon a given position in list.
 *
 * Results:
 *	Returns the pointer to the entry, if that numbered element
 *	exists. Otherwise NULL.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ListSort(listPtr, proc)
    Blt_List *listPtr;		/* List to traverse */
    Blt_ListCompareProc *proc;
{
    struct Blt_ListEntry **entryArr;
    register struct Blt_ListEntry *entryPtr;
    register int i;

    if (listPtr->nEntries < 2) {
	return;
    }
    entryArr = (struct Blt_ListEntry **)
	malloc(sizeof(struct Blt_ListEntry *) * (listPtr->nEntries + 1));
    if (entryArr == NULL) {
	return;			/* Out of memory. */
    }
    i = 0;
    for (entryPtr = listPtr->headPtr; entryPtr != NULL; 
	 entryPtr = entryPtr->nextPtr) {
	entryArr[i++] = entryPtr;
    }
    qsort((char *)entryArr, listPtr->nEntries, sizeof(struct Blt_ListEntry *),
	             (QSortCompareProc *)proc);

    /* Rethread the list. */
    entryPtr = entryArr[0];
    listPtr->headPtr = entryPtr;
    entryPtr->prevPtr = NULL;
    for (i = 1; i < listPtr->nEntries; i++) {
	entryPtr->nextPtr = entryArr[i];
	entryPtr->nextPtr->prevPtr = entryPtr;
	entryPtr = entryPtr->nextPtr;
    }
    listPtr->tailPtr = entryPtr;
    entryPtr->nextPtr = NULL;
    free((char *)entryArr);
}
