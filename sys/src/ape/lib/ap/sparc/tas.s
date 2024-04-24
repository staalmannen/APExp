/*
 *	tas uses LDSTUB
 */
	TEXT	tas(SB),1,$-4

	TAS	(R7),R7
	RETURN
