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

#ifndef INT64_MAX
#define INT64_MAX 0x7FFFFFFFFFFFFFFFLL
#endif


struct Block
  {
  long long pos, size;		/* pos >= 0, size >= 0, pos + size <= INT64_MAX */
  };

static inline void init_block( struct Block * const b,
                               const long long p, const long long s )
  { b->pos = p; b->size = s; }

static inline long long block_end( const struct Block b )
  { return b.pos + b.size; }


struct Member
  {
  struct Block dblock, mblock;		/* data block, member block */
  unsigned dictionary_size;
  };

static inline void init_member( struct Member * const m,
                                const long long dpos, const long long dsize,
                                const long long mpos, const long long msize,
                                const unsigned dict_size )
  { init_block( &m->dblock, dpos, dsize ); init_block( &m->mblock, mpos, msize );
    m->dictionary_size = dict_size; }

struct Lzip_index
  {
  struct Member * member_vector;
  char * error;
  long long insize;
  long members;
  int error_size;
  int retval;
  unsigned dictionary_size;	/* largest dictionary size in the file */
  };

bool Li_init( struct Lzip_index * const li, const int infd,
              const struct Cl_options * const cl_opts );

void Li_free( struct Lzip_index * const li );

static inline long long Li_udata_size( const struct Lzip_index * const li )
  {
  if( li->members <= 0 ) return 0;
  return block_end( li->member_vector[li->members-1].dblock );
  }

static inline long long Li_cdata_size( const struct Lzip_index * const li )
  {
  if( li->members <= 0 ) return 0;
  return block_end( li->member_vector[li->members-1].mblock );
  }

  /* total size including trailing data (if any) */
static inline long long Li_file_size( const struct Lzip_index * const li )
  { if( li->insize >= 0 ) return li->insize; else return 0; }

static inline const struct Block * Li_dblock( const struct Lzip_index * const li,
                                              const long i )
  { return &li->member_vector[i].dblock; }

static inline const struct Block * Li_mblock( const struct Lzip_index * const li,
                                              const long i )
  { return &li->member_vector[i].mblock; }

static inline unsigned Li_dictionary_size( const struct Lzip_index * const li,
                                           const long i )
  { return li->member_vector[i].dictionary_size; }
