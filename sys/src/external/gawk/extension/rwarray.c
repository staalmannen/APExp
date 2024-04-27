/*
 * rwarray.c - Builtin functions to binary read / write arrays to a file.
 *
 * Arnold Robbins
 * May 2009
 */

/*
 * Copyright (C) 2009, 2010, 2011 the Free Software Foundation, Inc.
 * 
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 * 
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "awk.h"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAGIC "awkrulz\n"
#define MAJOR 1
#define MINOR 0

int plugin_is_GPL_compatible;

static int write_array(int fd, NODE *array);
static int write_elem(int fd, int index, NODE *item);
static int write_chain(int fd, int index, NODE *item);
static int write_value(int fd, NODE *val);

static int read_array(int fd, NODE *array);
static NODE *read_elem(int fd, int *index, NODE *array);
static NODE *read_value(int fd);

/*
 * Format of array info:
 *
 * MAGIC	8 bytes
 * Major version	4 bytes - network order
 * Minor version	4 bytes - network order
 * Element count	4 bytes - network order
 * Array size		4 bytes - network order
 * Elements
 * 
 * For each element:
 * Bucket number:	4 bytes - network order
 * Hash of index val:	4 bytes - network order
 * Length of index val:	4 bytes - network order
 * Index val as characters (N bytes)
 * Value type		1 byte (0 = string, 1 = number, 2 = array)
 * IF string:
 * 	Length of value	4 bytes
 * 	Value as characters (N bytes)
 * ELSE
 * 	8 bytes as native double
 */

/* do_writea --- write an array */

static NODE *
do_writea(int nargs)
{
	NODE *file, *array;
	int ret;
	int fd;
	uint32_t major = MAJOR;
	uint32_t minor = MINOR;

	if (do_lint && get_curfunc_arg_count() > 2)
		lintwarn("writea: called with too many arguments");

	/* directory is first arg, array to dump is second */
	file = get_scalar_argument(0, FALSE);
	array = get_array_argument(1, FALSE);

	/* open the file, if error, set ERRNO and return */
	(void) force_string(file);
	fd = creat(file->stptr, 0600);
	if (fd < 0) {
		goto done1;
	}

	if (write(fd, MAGIC, strlen(MAGIC)) != strlen(MAGIC))
		goto done1;

	major = htonl(major);
	if (write(fd, & major, sizeof(major)) != sizeof(major))
		goto done1;

	minor = htonl(minor);
	if (write(fd, & minor, sizeof(minor)) != sizeof(minor))
		goto done1;

	ret = write_array(fd, array);
	if (ret != 0)
		goto done1;
	ret = 0;
	goto done0;

done1:
	ret = -1;
	update_ERRNO();
	unlink(file->stptr);

done0:
	close(fd);

	/* Set the return value */
	return make_number((AWKNUM) ret);
}


/* write_array --- write out an array or a sub-array */

static int
write_array(int fd, NODE *array)
{
	int ret;
	uint32_t count;
	uint32_t array_sz;
	int i;

	count = htonl(array->table_size);
	if (write(fd, & count, sizeof(count)) != sizeof(count))
		return -1;

	array_sz = htonl(array->array_size);
	if (write(fd, & array_sz, sizeof(array_sz)) != sizeof(array_sz))
		return -1;

	for (i = 0; i < array->array_size; i++) {
		ret = write_chain(fd, i, array->var_array[i]);
		if (ret != 0)
			return ret;
	}
	return 0;
}


/* write_chain --- write out a whole hash chain */

/*
 * Write elements in the chain in reverse order so that
 * when we read the elements back in we can just push them
 * onto the front and thus recreate the array as it was.
 */

static int
write_chain(int fd, int index, NODE *bucket)
{
	int ret;

	if (bucket == NULL)
		return 0;

	ret = write_chain(fd, index, bucket->ahnext);
	if (ret != 0)
		return ret;

	return write_elem(fd, index, bucket);
}

/* write_elem --- write out a single element */

static int
write_elem(int fd, int index, NODE *item)
{
	uint32_t hashval, indexval_len;

	index = htonl(index);
	if (write(fd, & index, sizeof(index)) != sizeof(index))
		return -1;

	hashval = htonl(item->ahcode);
	if (write(fd, & hashval, sizeof(hashval)) != sizeof(hashval))
		return -1;

	indexval_len = htonl(item->ahname_len);
	if (write(fd, & indexval_len, sizeof(indexval_len)) != sizeof(indexval_len))
		return -1;

	if (write(fd, item->ahname_str, item->ahname_len) != item->ahname_len)
		return -1;

	return write_value(fd, item->ahvalue);
}

/* write_value --- write a number or a string or a array */

static int
write_value(int fd, NODE *val)
{
	int code, len;

	if (val->type == Node_var_array) {
		code = htonl(2);
		if (write(fd, & code, sizeof(code)) != sizeof(code))
			return -1;
		return write_array(fd, val);
	}

	if ((val->flags & NUMBER) != 0) {
		code = htonl(1);
		if (write(fd, & code, sizeof(code)) != sizeof(code))
			return -1;

		if (write(fd, & val->numbr, sizeof(val->numbr)) != sizeof(val->numbr))
			return -1;
	} else {
		code = 0;
		if (write(fd, & code, sizeof(code)) != sizeof(code))
			return -1;

		len = htonl(val->stlen);
		if (write(fd, & len, sizeof(len)) != sizeof(len))
			return -1;

		if (write(fd, val->stptr, val->stlen) != val->stlen)
			return -1;
	}

	return 0;
}

/* do_reada --- read an array */

static NODE *
do_reada(int nargs)
{
	NODE *file, *array;
	int ret;
	int fd;
	uint32_t major;
	uint32_t minor;
	char magic_buf[30];

	if (do_lint && get_curfunc_arg_count() > 2)
		lintwarn("reada: called with too many arguments");

	/* directory is first arg, array to dump is second */
	file = get_scalar_argument(0, FALSE);
	array = get_array_argument(1, FALSE);

	(void) force_string(file);
	fd = open(file->stptr, O_RDONLY);
	if (fd < 0) {
		goto done1;
	}

	memset(magic_buf, '\0', sizeof(magic_buf));
	if (read(fd, magic_buf, strlen(MAGIC)) != strlen(MAGIC)) {
		goto done1;
	}

	if (strcmp(magic_buf, MAGIC) != 0) {
		goto done1;
	}

	if (read(fd, & major, sizeof(major)) != sizeof(major)) {
		goto done1;
	}
	major = ntohl(major);

	if (major != MAJOR) {
		goto done1;
	}

	if (read(fd, & minor, sizeof(minor)) != sizeof(minor)) {
		goto done1;
	}
	minor = ntohl(minor);
	if (minor != MINOR) {
		goto done1;
	}

	assoc_clear(array);

	ret = read_array(fd, array);
	if (ret == 0)
		goto done0;

done1:
	ret = -1;
	update_ERRNO();

done0:
	close(fd);

	/* Set the return value */
	return make_number((AWKNUM) ret);
}


/* read_array --- read in an array or sub-array */

static int
read_array(int fd, NODE *array)
{
	int i;
	uint32_t count;
	uint32_t array_sz;
	int index;
	NODE *new_elem;

	if (read(fd, & count, sizeof(count)) != sizeof(count)) {
		return -1;
	}
	array->table_size = ntohl(count);

	if (read(fd, & array_sz, sizeof(array_sz)) != sizeof(array_sz)) {
		return -1;
	}
	array->array_size = ntohl(array_sz);

	/* malloc var_array */
	array->var_array = (NODE **) malloc(array->array_size * sizeof(NODE *));
	memset(array->var_array, '\0', array->array_size * sizeof(NODE *));

	for (i = 0; i < array->table_size; i++) {
		if ((new_elem = read_elem(fd, & index, array)) != NULL) {
			new_elem->ahnext = array->var_array[index];
			array->var_array[index] = new_elem;
		} else
			break;
	}
	if (i != array->table_size)
		return -1; 
	return 0;
}


/* read_elem --- read in a single element */

static NODE *
read_elem(int fd, int *the_index, NODE *array)
{
	uint32_t hashval, indexval_len, index;
	NODE *item;
	NODE *val;
	int ret;

	*the_index = 0;

	if ((ret = read(fd, & index, sizeof(index))) != sizeof(index)) {
		return NULL;
	}
	*the_index = index = ntohl(index);

	getnode(item);
	memset(item, 0, sizeof(*item));
	item->type = Node_ahash;
	item->flags = MALLOC;

	if (read(fd, & hashval, sizeof(hashval)) != sizeof(hashval)) {
		return NULL;
	}

	item->ahcode = ntohl(hashval);

	if (read(fd, & indexval_len, sizeof(indexval_len)) != sizeof(indexval_len)) {
		return NULL;
	}
	item->ahname_len = ntohl(indexval_len);

	item->ahname_str = malloc(item->ahname_len + 2);
	if (read(fd, item->ahname_str, item->ahname_len) != item->ahname_len) {
		return NULL;
	}
	item->ahname_str[item->ahname_len] = '\0';
	item->ahname_ref = 1;

	item->ahvalue = val = read_value(fd);
	if (val == NULL) {
		return NULL;
	}
	if (val->type == Node_var_array) {
		char *aname;
		size_t aname_len;

		/* construct the sub-array name */
		aname_len = strlen(array->vname) + item->ahname_len + 4;
		emalloc(aname, char *, aname_len + 2, "read_elem");
		sprintf(aname, "%s[\"%.*s\"]", array->vname, (int) item->ahname_len, item->ahname_str);
		val->vname = aname;
	}

	return item;
}

/* read_value --- read a number or a string */

static NODE *
read_value(int fd)
{
	NODE *val;
	int code, len;

	getnode(val);
	memset(val, 0, sizeof(*val));
	val->type = Node_val;

	if (read(fd, & code, sizeof(code)) != sizeof(code)) {
		return NULL;
	}
	code = ntohl(code);

	if (code == 2) {
		val->type = Node_var_array;
		if (read_array(fd, val) != 0)
			return NULL; 
	} else if (code == 1) {
		if (read(fd, & val->numbr, sizeof(val->numbr)) != sizeof(val->numbr)) {
			return NULL;
		}

		val->flags = NUMBER|NUMCUR|MALLOC;
	} else {
		if (read(fd, & len, sizeof(len)) != sizeof(len)) {
			return NULL;
		}
		val->stlen = ntohl(len);
		val->stptr = malloc(val->stlen + 2);
		memset(val->stptr, '\0', val->stlen + 2);

		if (read(fd, val->stptr, val->stlen) != val->stlen) {
			return NULL;
		}

		val->flags = STRING|STRCUR|MALLOC;
	}

	return val;
}

/* dlload --- load new builtins in this library */

NODE *
dlload(tree, dl)
NODE *tree;
void *dl;
{
	make_builtin("writea", do_writea, 2);
	make_builtin("reada", do_reada, 2);

	return make_number((AWKNUM) 0);
}
