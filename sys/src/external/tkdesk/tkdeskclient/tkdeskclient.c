/* ============================================================================
 *
 * File:	tkdeskclient.c
 * Project:	TkDesk
 * Started:	03.05.97
 * Changed:	03.05.97
 *
 * Description:	Implements a client to connect to TkDesk's server socket.
 *
 * Copyright (C) 1996, 1997  Christian Bolik
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * See the file "COPYING" in the base directory of this distribution
 * for more.
 *
 * ========================================================================= */

#include "config.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>


int get_port (key)
char *key;
{
    DIR *dp;
    struct dirent *dir;
    int port = 0;
    char fpath[64], buf[80];
    FILE *fp;
    struct stat st;
    time_t mtime = 0, mt;

    /* open /tmp */
    if ((dp = opendir ("/tmp")) == NULL) {
	fprintf (stderr, "couldn't open /tmp\n");
	exit (4);
    }

    while ((dir = readdir (dp))) {
	/* skip removed files */
	if (dir->d_ino == 0)
	    continue;

	/* check files starting with "tkdesks" */
	if (strncmp (dir->d_name, "tkdesks", 7) == 0) {
	    strcpy (fpath, "/tmp/");
	    strcat (fpath, dir->d_name);

	    /* check if we can read the file */
	    if (access (fpath, R_OK) == 0) {
		
		/* make sure we read the latest readable tkdesks* file */
		stat (fpath, &st);
		mt = st.st_mtime;
		
		if (mt > mtime) {
		    mtime = mt;
		    /* read port from file */
		    fp = fopen (fpath, "r");
		    if (fgets (buf, 78, fp) != NULL) {
			port = atoi (buf);
		    }
		    if (fgets (buf, 78, fp) != NULL) {
			strcpy (key, buf);
		    }
		    fclose (fp);
		}
	    }
	}
    }

    return port;
}

int main (argc, argv)
int argc;
char *argv[];
{
    char hostname[80], c, buf[256+1], key[40];
    struct hostent *hp;
    struct sockaddr_in sin;
    int s, port = 1234, rc;

    /* obtain port from /tmp/tkdesks* */
    if ((port = get_port(key)) == 0) {
	fprintf (stderr, "Couldn't determine server port!\n");
	fprintf (stderr, "Maybe the server hasn't been started yet?\n");
	return 4;
    }

    /* get our hostname */
    /* for now, the server must run on the same machine */
    /*gethostname (hostname, sizeof(hostname));*/
    strcpy (hostname, "localhost");

    /* look up our network address */
    if ((hp = gethostbyname (hostname)) == NULL) {
	fprintf (stderr, "%s: unknown host\n", hostname);
	return 1;
    }

    /* get a socket */
    if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
	fprintf (stderr, "error opening socket\n");
	return 2;
    }

    /* create destination address */
    sin.sin_family = AF_INET;
    sin.sin_port = htons (port);
    memcpy (&sin.sin_addr, hp->h_addr, hp->h_length);

    /* try to connect */
    if (connect (s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
	fprintf (stderr, "Couldn't connect to server!\n");
	fprintf (stderr, "Maybe it hasn't been started yet?\n");
	return 3;
    }

    /* send key */
    write (s, key, strlen(key));
    write (s, "\n", 1);
    if ((rc = read (s, buf, 256)) < 0) {
	fprintf (stderr, "Oops, server rejected our key...\n");
	return 4;
    }

    /* send command to server (either command line or stdin) */
    if (argc > 1) {
	int i;

	for (i = 1; i < argc; i++) {
	    write (s, argv[i], strlen (argv[i]));
	}
	
	write (s, "\n", 1);
    } else {

	while ((c = fgetc (stdin)) != EOF)
	    putchar (c);
	putchar ('\n');
    }

    /* collect response from server */
    while ((rc = read(s, buf, 256)) == 256)
	printf("%s", buf);
    if (rc > 0)
	printf("%s", buf);

    close (s);

    return 0;
}


