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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "lzip.h"
#include "lzip_index.h"


static void list_line( const unsigned long long uncomp_size,
                       const unsigned long long comp_size,
                       const char * const input_filename )
  {
  if( uncomp_size > 0 )
    printf( "%14llu %14llu %6.2f%%  %s\n", uncomp_size, comp_size,
            100.0 - ( ( 100.0 * comp_size ) / uncomp_size ),
            input_filename );
  else
    printf( "%14llu %14llu   -INF%%  %s\n", uncomp_size, comp_size,
            input_filename );
  }


int list_files( const char * const filenames[], const int num_filenames,
                const struct Cl_options * const cl_opts )
  {
  unsigned long long total_comp = 0, total_uncomp = 0;
  int files = 0, retval = 0;
  int i;
  bool first_post = true;
  bool stdin_used = false;

  for( i = 0; i < num_filenames; ++i )
    {
    const bool from_stdin = ( strcmp( filenames[i], "-" ) == 0 );
    if( from_stdin ) { if( stdin_used ) continue; else stdin_used = true; }
    const char * const input_filename = from_stdin ? "(stdin)" : filenames[i];
    struct stat in_stats;				/* not used */
    const int infd = from_stdin ? STDIN_FILENO :
      open_instream( input_filename, &in_stats, false, true );
    if( infd < 0 ) { set_retval( &retval, 1 ); continue; }

    struct Lzip_index lzip_index;
    Li_init( &lzip_index, infd, cl_opts );
    close( infd );
    if( lzip_index.retval != 0 )
      {
      show_file_error( input_filename, lzip_index.error, 0 );
      set_retval( &retval, lzip_index.retval );
      Li_free( &lzip_index ); continue;
      }
    if( verbosity < 0 ) { Li_free( &lzip_index ); continue; }
    const unsigned long long udata_size = Li_udata_size( &lzip_index );
    const unsigned long long cdata_size = Li_cdata_size( &lzip_index );
    total_comp += cdata_size; total_uncomp += udata_size; ++files;
    const long members = lzip_index.members;
    if( first_post )
      {
      first_post = false;
      if( verbosity >= 1 ) fputs( "   dict   memb  trail ", stdout );
      fputs( "  uncompressed     compressed   saved  name\n", stdout );
      }
    if( verbosity >= 1 )
      printf( "%s %5ld %6lld ", format_ds( lzip_index.dictionary_size ),
              members, Li_file_size( &lzip_index ) - cdata_size );
    list_line( udata_size, cdata_size, input_filename );

    if( verbosity >= 2 && members > 1 )
      {
      long i;
      fputs( " member      data_pos      data_size     member_pos    member_size\n", stdout );
      for( i = 0; i < members; ++i )
        {
        const struct Block * db = Li_dblock( &lzip_index, i );
        const struct Block * mb = Li_mblock( &lzip_index, i );
        printf( "%6ld %14llu %14llu %14llu %14llu\n",
                i + 1, db->pos, db->size, mb->pos, mb->size );
        }
      first_post = true;	/* reprint heading after list of members */
      }
    fflush( stdout );
    Li_free( &lzip_index );
    }
  if( verbosity >= 0 && files > 1 )
    {
    if( verbosity >= 1 ) fputs( "                      ", stdout );
    list_line( total_uncomp, total_comp, "(totals)" );
    fflush( stdout );
    }
  return retval;
  }
