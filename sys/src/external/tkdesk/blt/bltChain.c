/*
 * bltChain.c --
 *
 *	The module implements a generic linked list package.
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
#include "bltChain.h"
/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainCreate --
 *
 *	Creates a new linked list structure and initializes its pointers
 *
 * Results:
 *	Returns a pointer to the newly created list structure.
 *
 *----------------------------------------------------------------------
 */
Blt_Chain *
Blt_ChainCreate()
{
    Blt_Chain *chainPtr;

    chainPtr = (Blt_Chain *) malloc(sizeof(Blt_Chain));
    if (chainPtr != NULL) {
	Blt_ChainInit(chainPtr);
    }
    return (chainPtr);
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainNewLink --
 *
 *	Creates a list entry holder.  This routine does not insert
 *	the entry into the chain, nor does it no attempt to maintain
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
Blt_ChainLink *
Blt_ChainNewLink()
{
    Blt_ChainLink *linkPtr;

    linkPtr = (Blt_ChainLink *) malloc(sizeof(Blt_ChainLink));
    assert(linkPtr);
    linkPtr->clientData = (ClientData)NULL;
    linkPtr->nextPtr = linkPtr->prevPtr = NULL;
    return linkPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainReset --
 *
 *	Removes all the entries from a chain, removing pointers to the
 *	objects and keys (not the objects or keys themselves).  The
 *	entry counter is reset to zero.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainReset(chainPtr)
    Blt_Chain *chainPtr;	/* Chain to clear */
{
    if (chainPtr != NULL) {
	Blt_ChainLink *oldPtr;
	Blt_ChainLink *linkPtr = chainPtr->headPtr;

	while (linkPtr != NULL) {
	    oldPtr = linkPtr;
	    linkPtr = linkPtr->nextPtr;
	    free((char *)oldPtr);
	}
	Blt_ChainInit(chainPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainDestroy
 *
 *     Frees all chain structures
 *
 * Results:
 *	Returns a pointer to the newly created chain structure.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainDestroy(chainPtr)
    Blt_Chain *chainPtr;
{
    if (chainPtr != NULL) {
	Blt_ChainReset(chainPtr);
	free((char *)chainPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainInit --
 *
 *	Initializes a linked list.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainInit(chainPtr)
    Blt_Chain *chainPtr;
{
    chainPtr->nLinks = 0;
    chainPtr->headPtr = chainPtr->tailPtr = NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainLinkAfter --
 *
 *	Inserts an entry following a given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainLinkAfter(chainPtr, linkPtr, afterPtr)
    Blt_Chain *chainPtr;
    Blt_ChainLink *linkPtr, *afterPtr;
{
    if (chainPtr->headPtr == NULL) {
	chainPtr->tailPtr = chainPtr->headPtr = linkPtr;
    } else {
	if (afterPtr == NULL) {
	    /* Prepend to the front of the chain */
	    linkPtr->nextPtr = chainPtr->headPtr;
	    linkPtr->prevPtr = NULL;
	    chainPtr->headPtr->prevPtr = linkPtr;
	    chainPtr->headPtr = linkPtr;
	} else {
	    linkPtr->nextPtr = afterPtr->nextPtr;
	    linkPtr->prevPtr = afterPtr;
	    if (afterPtr == chainPtr->tailPtr) {
		chainPtr->tailPtr = linkPtr;
	    } else {
		afterPtr->nextPtr->prevPtr = linkPtr;
	    }
	    afterPtr->nextPtr = linkPtr;
	}
    }
    chainPtr->nLinks++;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainLinkBefore --
 *
 *	Inserts an entry preceding a given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainLinkBefore(chainPtr, linkPtr, beforePtr)
    Blt_Chain *chainPtr;	/* Chain to contain new entry */
    Blt_ChainLink *linkPtr;	/* New entry to be inserted */
    Blt_ChainLink *beforePtr;	/* Entry to link before */
{
    if (chainPtr->headPtr == NULL) {
	chainPtr->tailPtr = chainPtr->headPtr = linkPtr;
    } else {
	if (beforePtr == NULL) {
	    /* Append onto the end of the chain */
	    linkPtr->nextPtr = NULL;
	    linkPtr->prevPtr = chainPtr->tailPtr;
	    chainPtr->tailPtr->nextPtr = linkPtr;
	    chainPtr->tailPtr = linkPtr;
	} else {
	    linkPtr->prevPtr = beforePtr->prevPtr;
	    linkPtr->nextPtr = beforePtr;
	    if (beforePtr == chainPtr->headPtr) {
		chainPtr->headPtr = linkPtr;
	    } else {
		beforePtr->prevPtr->nextPtr = linkPtr;
	    }
	    beforePtr->prevPtr = linkPtr;
	}
    }
    chainPtr->nLinks++;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainUnlinkLink --
 *
 *	Unlinks an entry from the given chain. The entry itself is
 *	not deallocated, but only removed from the chain.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainUnlinkLink(chainPtr, linkPtr)
    Blt_Chain *chainPtr;
    Blt_ChainLink *linkPtr;
{
    if (chainPtr->headPtr == linkPtr) {
	chainPtr->headPtr = linkPtr->nextPtr;
    }
    if (chainPtr->tailPtr == linkPtr) {
	chainPtr->tailPtr = linkPtr->prevPtr;
    }
    if (linkPtr->nextPtr != NULL) {
	linkPtr->nextPtr->prevPtr = linkPtr->prevPtr;
    }
    if (linkPtr->prevPtr != NULL) {
	linkPtr->prevPtr->nextPtr = linkPtr->nextPtr;
    }
    chainPtr->nLinks--;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainDeleteLink --
 *
 *	Unlinks and deletes the given entry.
 *
 * Results:
 *	None.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainDeleteLink(chainPtr, linkPtr)
    Blt_Chain *chainPtr;
    Blt_ChainLink *linkPtr;
{
    Blt_ChainUnlinkLink(chainPtr, linkPtr);
    free((char *)linkPtr);
}

Blt_ChainLink *
Blt_ChainAppend(chainPtr, clientData)
    Blt_Chain *chainPtr;
    ClientData clientData;
{
    Blt_ChainLink *linkPtr;

    linkPtr = Blt_ChainNewLink();
    Blt_ChainSetValue(linkPtr, clientData);
    Blt_ChainAppendLink(chainPtr, linkPtr);
    return linkPtr;
}

Blt_ChainLink *
Blt_ChainPrepend(chainPtr, clientData)
    Blt_Chain *chainPtr;
    ClientData clientData;
{
    Blt_ChainLink *linkPtr;

    linkPtr = Blt_ChainNewLink();
    Blt_ChainSetValue(linkPtr, clientData);
    Blt_ChainPrependLink(chainPtr, linkPtr);
    return linkPtr;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainGetNthLink --
 *
 *	Find the entry based upon a given position in chain.
 *
 * Results:
 *	Returns the pointer to the link, if that numbered element
 *	exists. Otherwise NULL.
 *
 *----------------------------------------------------------------------
 */
Blt_ChainLink *
Blt_ChainGetNthLink(chainPtr, position)
    Blt_Chain *chainPtr;	/* Chain to traverse */
    int position;		/* Index of link to select from front
				 * or back of the chain. */
{
    Blt_ChainLink *linkPtr;

    if (chainPtr != NULL) {
	for (linkPtr = chainPtr->headPtr; linkPtr != NULL;
	    linkPtr = linkPtr->nextPtr) {
	    if (position == 0) {
		return linkPtr;
	    }
	    position--;
	}
    }
    return NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_ChainSort --
 *
 *	Find the entry based upon a given position in chain.
 *
 * Results:
 *	Returns the pointer to the link, if that numbered element
 *	exists. Otherwise NULL.
 *
 *----------------------------------------------------------------------
 */
void
Blt_ChainSort(chainPtr, proc)
    Blt_Chain *chainPtr;	/* Chain to traverse */
    Blt_ChainCompareProc *proc;
{
    Blt_ChainLink **linkArr;
    register Blt_ChainLink *linkPtr;
    register int i;

    if (chainPtr->nLinks < 2) {
	return;
    }
    linkArr = (Blt_ChainLink **)
	malloc(sizeof(Blt_ChainLink *) * (chainPtr->nLinks + 1));
    if (linkArr == NULL) {
	return;			/* Out of memory. */
    }
    i = 0;
    for (linkPtr = chainPtr->headPtr; linkPtr != NULL; linkPtr = linkPtr->nextPtr) {
	linkArr[i++] = linkPtr;
    }
    qsort((char *)linkArr, chainPtr->nLinks, sizeof(Blt_ChainLink *),
	(QSortCompareProc *)proc);

    /* Rethread the chain. */
    linkPtr = linkArr[0];
    chainPtr->headPtr = linkPtr;
    linkPtr->prevPtr = NULL;
    for (i = 1; i < chainPtr->nLinks; i++) {
	linkPtr->nextPtr = linkArr[i];
	linkPtr->nextPtr->prevPtr = linkPtr;
	linkPtr = linkPtr->nextPtr;
    }
    chainPtr->tailPtr = linkPtr;
    linkPtr->nextPtr = NULL;
    free((char *)linkArr);
}
