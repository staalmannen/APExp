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

struct FLZ_encoder
  {
  struct LZ_encoder_base eb;
  unsigned key4;			/* key made from latest 4 bytes */
  };

static inline void FLZe_reset_key4( struct FLZ_encoder * const fe )
  {
  int i;
  fe->key4 = 0;
  for( i = 0; i < 3 && i < Mb_available_bytes( &fe->eb.mb ); ++i )
    fe->key4 = ( fe->key4 << 4 ) ^ fe->eb.mb.buffer[i];
  }

int FLZe_longest_match_len( struct FLZ_encoder * const fe, int * const distance );

static inline void FLZe_update_and_move( struct FLZ_encoder * const fe, int n )
  {
  struct Matchfinder_base * const mb = &fe->eb.mb;
  while( --n >= 0 )
    {
    if( Mb_available_bytes( mb ) >= 4 )
      {
      fe->key4 = ( ( fe->key4 << 4 ) ^ mb->buffer[mb->pos+3] ) & mb->key4_mask;
      mb->pos_array[mb->cyclic_pos] = mb->prev_positions[fe->key4];
      mb->prev_positions[fe->key4] = mb->pos + 1;
      }
    Mb_move_pos( mb );
    }
  }

static inline bool FLZe_init( struct FLZ_encoder * const fe,
                              const int ifd, const int outfd )
  {
  enum { before_size = 0,
         dict_size = 65536,
         /* bytes to keep in buffer after pos */
         after_size = max_match_len,
         dict_factor = 16,
         num_prev_positions23 = 0,
         pos_array_factor = 1 };

  return LZeb_init( &fe->eb, before_size, dict_size, after_size, dict_factor,
                    num_prev_positions23, pos_array_factor, ifd, outfd );
  }

static inline void FLZe_reset( struct FLZ_encoder * const fe )
  { LZeb_reset( &fe->eb ); }

bool FLZe_encode_member( struct FLZ_encoder * const fe,
                         const unsigned long long member_size );
