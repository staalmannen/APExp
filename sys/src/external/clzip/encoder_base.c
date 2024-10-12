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
#include <stdlib.h>
#include <string.h>

#include "lzip.h"
#include "encoder_base.h"


Dis_slots dis_slots;
Prob_prices prob_prices;


bool Mb_read_block( struct Matchfinder_base * const mb )
  {
  if( !mb->at_stream_end && mb->stream_pos < mb->buffer_size )
    {
    const int size = mb->buffer_size - mb->stream_pos;
    const int rd = readblock( mb->infd, mb->buffer + mb->stream_pos, size );
    mb->stream_pos += rd;
    if( rd != size && errno )
      { show_error( "Read error", errno, false ); cleanup_and_fail( 1 ); }
    if( rd < size ) { mb->at_stream_end = true; mb->pos_limit = mb->buffer_size; }
    }
  return mb->pos < mb->stream_pos;
  }


void Mb_normalize_pos( struct Matchfinder_base * const mb )
  {
  if( mb->pos > mb->stream_pos )
    internal_error( "pos > stream_pos in Mb_normalize_pos." );
  if( !mb->at_stream_end )
    {
    int i;
    /* offset is int32_t for the min below */
    const int32_t offset = mb->pos - mb->before_size - mb->dictionary_size;
    const int size = mb->stream_pos - offset;
    memmove( mb->buffer, mb->buffer + offset, size );
    mb->partial_data_pos += offset;
    mb->pos -= offset;		/* pos = before_size + dictionary_size */
    mb->stream_pos -= offset;
    for( i = 0; i < mb->num_prev_positions; ++i )
      mb->prev_positions[i] -= min( mb->prev_positions[i], offset );
    for( i = 0; i < mb->pos_array_size; ++i )
      mb->pos_array[i] -= min( mb->pos_array[i], offset );
    Mb_read_block( mb );
    }
  }


bool Mb_init( struct Matchfinder_base * const mb, const int before_size,
              const int dict_size, const int after_size,
              const int dict_factor, const int num_prev_positions23,
              const int pos_array_factor, const int ifd )
  {
  const int buffer_size_limit =
    ( dict_factor * dict_size ) + before_size + after_size;
  int i;

  mb->partial_data_pos = 0;
  mb->before_size = before_size;
  mb->pos = 0;
  mb->cyclic_pos = 0;
  mb->stream_pos = 0;
  mb->num_prev_positions23 = num_prev_positions23;
  mb->infd = ifd;
  mb->at_stream_end = false;

  mb->buffer_size = max( 65536, dict_size );
  mb->buffer = (uint8_t *)malloc( mb->buffer_size );
  if( !mb->buffer ) return false;
  if( Mb_read_block( mb ) && !mb->at_stream_end &&
      mb->buffer_size < buffer_size_limit )
    {
    uint8_t * const tmp = (uint8_t *)realloc( mb->buffer, buffer_size_limit );
    if( !tmp ) { free( mb->buffer ); return false; }
    mb->buffer = tmp;
    mb->buffer_size = buffer_size_limit;
    Mb_read_block( mb );
    }
  if( mb->at_stream_end && mb->stream_pos < dict_size )
    mb->dictionary_size = max( min_dictionary_size, mb->stream_pos );
  else
    mb->dictionary_size = dict_size;
  mb->pos_limit = mb->buffer_size;
  if( !mb->at_stream_end ) mb->pos_limit -= after_size;
  unsigned size = 1 << max( 16, real_bits( mb->dictionary_size - 1 ) - 2 );
  if( mb->dictionary_size > 1 << 26 ) size >>= 1;	/* 64 MiB */
  mb->key4_mask = size - 1;		/* increases with dictionary size */
  size += num_prev_positions23;
  mb->num_prev_positions = size;

  mb->pos_array_size = pos_array_factor * ( mb->dictionary_size + 1 );
  size += mb->pos_array_size;
  if( size * sizeof mb->prev_positions[0] <= size ) mb->prev_positions = 0;
  else mb->prev_positions =
    (int32_t *)malloc( size * sizeof mb->prev_positions[0] );
  if( !mb->prev_positions ) { free( mb->buffer ); return false; }
  mb->pos_array = mb->prev_positions + mb->num_prev_positions;
  for( i = 0; i < mb->num_prev_positions; ++i ) mb->prev_positions[i] = 0;
  return true;
  }


void Mb_reset( struct Matchfinder_base * const mb )
  {
  int i;
  if( mb->stream_pos > mb->pos )
    memmove( mb->buffer, mb->buffer + mb->pos, mb->stream_pos - mb->pos );
  mb->partial_data_pos = 0;
  mb->stream_pos -= mb->pos;
  mb->pos = 0;
  mb->cyclic_pos = 0;
  Mb_read_block( mb );
  if( mb->at_stream_end && mb->stream_pos < mb->dictionary_size )
    {
    mb->dictionary_size = max( min_dictionary_size, mb->stream_pos );
    int size = 1 << max( 16, real_bits( mb->dictionary_size - 1 ) - 2 );
    if( mb->dictionary_size > 1 << 26 ) size >>= 1;	/* 64 MiB */
    mb->key4_mask = size - 1;
    size += mb->num_prev_positions23;
    mb->num_prev_positions = size;
    mb->pos_array = mb->prev_positions + mb->num_prev_positions;
    }
  for( i = 0; i < mb->num_prev_positions; ++i ) mb->prev_positions[i] = 0;
  }


void Re_flush_data( struct Range_encoder * const renc )
  {
  if( renc->pos > 0 )
    {
    if( renc->outfd >= 0 &&
        writeblock( renc->outfd, renc->buffer, renc->pos ) != renc->pos )
      { show_error( "Write error", errno, false ); cleanup_and_fail( 1 ); }
    renc->partial_member_pos += renc->pos;
    renc->pos = 0;
    show_cprogress( 0, 0, 0, 0 );
    }
  }


/* End Of Stream marker => (dis == 0xFFFFFFFFU, len == min_match_len) */
void LZeb_full_flush( struct LZ_encoder_base * const eb, const State state )
  {
  const int pos_state = Mb_data_position( &eb->mb ) & pos_state_mask;
  Re_encode_bit( &eb->renc, &eb->bm_match[state][pos_state], 1 );
  Re_encode_bit( &eb->renc, &eb->bm_rep[state], 0 );
  LZeb_encode_pair( eb, 0xFFFFFFFFU, min_match_len, pos_state );
  Re_flush( &eb->renc );
  Lzip_trailer trailer;
  Lt_set_data_crc( trailer, LZeb_crc( eb ) );
  Lt_set_data_size( trailer, Mb_data_position( &eb->mb ) );
  Lt_set_member_size( trailer, Re_member_position( &eb->renc ) + Lt_size );
  int i; for( i = 0; i < Lt_size; ++i ) Re_put_byte( &eb->renc, trailer[i] );
  Re_flush_data( &eb->renc );
  }


void LZeb_reset( struct LZ_encoder_base * const eb )
  {
  Mb_reset( &eb->mb );
  eb->crc = 0xFFFFFFFFU;
  Bm_array_init( eb->bm_literal[0], (1 << literal_context_bits) * 0x300 );
  Bm_array_init( eb->bm_match[0], states * pos_states );
  Bm_array_init( eb->bm_rep, states );
  Bm_array_init( eb->bm_rep0, states );
  Bm_array_init( eb->bm_rep1, states );
  Bm_array_init( eb->bm_rep2, states );
  Bm_array_init( eb->bm_len[0], states * pos_states );
  Bm_array_init( eb->bm_dis_slot[0], len_states * (1 << dis_slot_bits) );
  Bm_array_init( eb->bm_dis, modeled_distances - end_dis_model + 1 );
  Bm_array_init( eb->bm_align, dis_align_size );
  Lm_init( &eb->match_len_model );
  Lm_init( &eb->rep_len_model );
  Re_reset( &eb->renc, eb->mb.dictionary_size );
  }
