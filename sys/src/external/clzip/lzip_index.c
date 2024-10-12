/* Clzip - LZMA lossless data compressor
   Copyright (C) 2010-2024 Antonio Diaz Diaz.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define _FILE_OFFSET_BITS 64

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lzip.h"
#include "lzip_index.h"


static int seek_read( const int fd, uint8_t * const buf, const int size,
                      const long long pos )
  {
  if( lseek( fd, pos, SEEK_SET ) == pos )
    return readblock( fd, buf, size );
  return 0;
  }


static bool add_error( struct Lzip_index * const li, const char * const msg )
  {
  const int len = strlen( msg );
  void * tmp = resize_buffer( li->error, li->error_size + len + 1 );
  if( !tmp ) return false;
  li->error = (char *)tmp;
  strncpy( li->error + li->error_size, msg, len + 1 );
  li->error_size += len;
  return true;
  }


static bool push_back_member( struct Lzip_index * const li,
                              const long long dp, const long long ds,
                              const long long mp, const long long ms,
                              const unsigned dict_size )
  {
  struct Member * p;
  void * tmp = resize_buffer( li->member_vector,
               ( li->members + 1 ) * sizeof li->member_vector[0] );
  if( !tmp ) { add_error( li, mem_msg ); li->retval = 1; return false; }
  li->member_vector = (struct Member *)tmp;
  p = &(li->member_vector[li->members]);
  init_member( p, dp, ds, mp, ms, dict_size );
  ++li->members;
  return true;
  }


static void Li_free_member_vector( struct Lzip_index * const li )
  {
  if( li->member_vector )
    { free( li->member_vector ); li->member_vector = 0; }
  li->members = 0;
  }


static void Li_reverse_member_vector( struct Lzip_index * const li )
  {
  struct Member tmp;
  long i;
  for( i = 0; i < li->members / 2; ++i )
    {
    tmp = li->member_vector[i];
    li->member_vector[i] = li->member_vector[li->members-i-1];
    li->member_vector[li->members-i-1] = tmp;
    }
  }


static bool Li_check_header( struct Lzip_index * const li,
                             const Lzip_header header )
  {
  if( !Lh_check_magic( header ) )
    { add_error( li, bad_magic_msg ); li->retval = 2; return false; }
  if( !Lh_check_version( header ) )
    { add_error( li, bad_version( Lh_version( header ) ) ); li->retval = 2;
      return false; }
  if( !isvalid_ds( Lh_get_dictionary_size( header ) ) )
    { add_error( li, bad_dict_msg ); li->retval = 2; return false; }
  return true;
  }

static void Li_set_errno_error( struct Lzip_index * const li,
                                const char * const msg )
  {
  add_error( li, msg ); add_error( li, strerror( errno ) );
  li->retval = 1;
  }

static void Li_set_num_error( struct Lzip_index * const li,
                              const char * const msg, unsigned long long num )
  {
  char buf[80];
  snprintf( buf, sizeof buf, "%s%llu", msg, num );
  add_error( li, buf );
  li->retval = 2;
  }


static bool Li_read_header( struct Lzip_index * const li, const int fd,
            Lzip_header header, const long long pos, const bool ignore_marking )
  {
  if( seek_read( fd, header, Lh_size, pos ) != Lh_size )
    { Li_set_errno_error( li, "Error reading member header: " ); return false; }
  uint8_t byte;
  if( !ignore_marking && readblock( fd, &byte, 1 ) == 1 && byte != 0 )
    { add_error( li, marking_msg ); li->retval = 2; return false; }
  return true;
  }


/* If successful, push last member and set pos to member header. */
static bool Li_skip_trailing_data( struct Lzip_index * const li, const int fd,
                                   unsigned long long * const pos,
                                   const struct Cl_options * const cl_opts )
  {
  if( *pos < min_member_size ) return false;
  enum { block_size = 16384,
         buffer_size = block_size + Lt_size - 1 + Lh_size };
  uint8_t buffer[buffer_size];
  int bsize = *pos % block_size;		/* total bytes in buffer */
  if( bsize <= buffer_size - block_size ) bsize += block_size;
  int search_size = bsize;			/* bytes to search for trailer */
  int rd_size = bsize;				/* bytes to read from file */
  unsigned long long ipos = *pos - rd_size;	/* aligned to block_size */

  while( true )
    {
    if( seek_read( fd, buffer, rd_size, ipos ) != rd_size )
      { Li_set_errno_error( li, "Error seeking member trailer: " ); return false; }
    const uint8_t max_msb = ( ipos + search_size ) >> 56;
    int i;
    for( i = search_size; i >= Lt_size; --i )
      if( buffer[i-1] <= max_msb )	/* most significant byte of member_size */
        {
        const Lzip_trailer * const trailer =
          (const Lzip_trailer *)( buffer + i - Lt_size );
        const unsigned long long member_size = Lt_get_member_size( *trailer );
        if( member_size == 0 )			/* skip trailing zeros */
          { while( i > Lt_size && buffer[i-9] == 0 ) --i; continue; }
        if( member_size > ipos + i || !Lt_check_consistency( *trailer ) )
          continue;
        Lzip_header header;
        if( !Li_read_header( li, fd, header, ipos + i - member_size,
                             cl_opts->ignore_marking ) ) return false;
        if( !Lh_check( header ) ) continue;
        const Lzip_header * header2 = (const Lzip_header *)( buffer + i );
        const bool full_h2 = bsize - i >= Lh_size;
        if( Lh_check_prefix( *header2, bsize - i ) )	/* last member */
          {
          if( !full_h2 ) add_error( li, "Last member in input file is truncated." );
          else if( Li_check_header( li, *header2 ) )
            add_error( li, "Last member in input file is truncated or corrupt." );
          li->retval = 2; return false;
          }
        if( !cl_opts->loose_trailing && full_h2 && Lh_check_corrupt( *header2 ) )
          { add_error( li, corrupt_mm_msg ); li->retval = 2; return false; }
        if( !cl_opts->ignore_trailing )
          { add_error( li, trailing_msg ); li->retval = 2; return false; }
        const unsigned long long data_size = Lt_get_data_size( *trailer );
        if( !cl_opts->ignore_empty && data_size == 0 )
          { add_error( li, empty_msg ); li->retval = 2; return false; }
        *pos = ipos + i - member_size;			/* good member */
        const unsigned dictionary_size = Lh_get_dictionary_size( header );
        if( li->dictionary_size < dictionary_size )
          li->dictionary_size = dictionary_size;
        return push_back_member( li, 0, data_size, *pos, member_size,
                                 dictionary_size );
        }
    if( ipos == 0 )
      { Li_set_num_error( li, "Bad trailer at pos ", *pos - Lt_size );
        return false; }
    bsize = buffer_size;
    search_size = bsize - Lh_size;
    rd_size = block_size;
    ipos -= rd_size;
    memcpy( buffer + rd_size, buffer, buffer_size - rd_size );
    }
  }


bool Li_init( struct Lzip_index * const li, const int infd,
              const struct Cl_options * const cl_opts )
  {
  li->member_vector = 0;
  li->error = 0;
  li->insize = lseek( infd, 0, SEEK_END );
  li->members = 0;
  li->error_size = 0;
  li->retval = 0;
  li->dictionary_size = 0;
  if( li->insize < 0 )
    { Li_set_errno_error( li, "Input file is not seekable: " ); return false; }
  if( li->insize < min_member_size )
    { add_error( li, "Input file is too short." ); li->retval = 2;
      return false; }
  if( li->insize > INT64_MAX )
    { add_error( li, "Input file is too long (2^63 bytes or more)." );
      li->retval = 2; return false; }

  Lzip_header header;
  if( !Li_read_header( li, infd, header, 0, cl_opts->ignore_marking ) ||
      !Li_check_header( li, header ) ) return false;

  unsigned long long pos = li->insize;	/* always points to a header or to EOF */
  while( pos >= min_member_size )
    {
    Lzip_trailer trailer;
    if( seek_read( infd, trailer, Lt_size, pos - Lt_size ) != Lt_size )
      { Li_set_errno_error( li, "Error reading member trailer: " ); break; }
    const unsigned long long member_size = Lt_get_member_size( trailer );
    if( member_size > pos || !Lt_check_consistency( trailer ) )
      {							/* bad trailer */
      if( li->members <= 0 )
        { if( Li_skip_trailing_data( li, infd, &pos, cl_opts ) ) continue;
          return false; }
      Li_set_num_error( li, "Bad trailer at pos ", pos - Lt_size ); break;
      }
    if( !Li_read_header( li, infd, header, pos - member_size,
                         cl_opts->ignore_marking ) ) break;
    if( !Lh_check( header ) )				/* bad header */
      {
      if( li->members <= 0 )
        { if( Li_skip_trailing_data( li, infd, &pos, cl_opts ) ) continue;
          return false; }
      Li_set_num_error( li, "Bad header at pos ", pos - member_size ); break;
      }
    const unsigned long long data_size = Lt_get_data_size( trailer );
    if( !cl_opts->ignore_empty && data_size == 0 )
      { add_error( li, empty_msg ); li->retval = 2; break; }
    pos -= member_size;					/* good member */
    const unsigned dictionary_size = Lh_get_dictionary_size( header );
    if( li->dictionary_size < dictionary_size )
      li->dictionary_size = dictionary_size;
    if( !push_back_member( li, 0, data_size, pos, member_size,
                           dictionary_size ) ) return false;
    }
  if( pos != 0 || li->members <= 0 || li->retval != 0 )
    {
    Li_free_member_vector( li );
    if( li->retval == 0 )
      { add_error( li, "Can't create file index." ); li->retval = 2; }
    return false;
    }
  Li_reverse_member_vector( li );
  long i;
  for( i = 0; ; ++i )
    {
    const long long end = block_end( li->member_vector[i].dblock );
    if( end < 0 || end > INT64_MAX )
      {
      Li_free_member_vector( li );
      add_error( li, "Data in input file is too long (2^63 bytes or more)." );
      li->retval = 2; return false;
      }
    if( i + 1 >= li->members ) break;
    li->member_vector[i+1].dblock.pos = end;
    }
  return true;
  }


void Li_free( struct Lzip_index * const li )
  {
  Li_free_member_vector( li );
  if( li->error ) { free( li->error ); li->error = 0; }
  li->error_size = 0;
  }
