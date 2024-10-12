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
#include "decoder.h"


/* Return the number of bytes really read.
   If (value returned < size) and (errno == 0), means EOF was reached.
*/
int readblock( const int fd, uint8_t * const buf, const int size )
  {
  int sz = 0;
  errno = 0;
  while( sz < size )
    {
    const int n = read( fd, buf + sz, size - sz );
    if( n > 0 ) sz += n;
    else if( n == 0 ) break;				/* EOF */
    else if( errno != EINTR ) break;
    errno = 0;
    }
  return sz;
  }


/* Return the number of bytes really written.
   If (value returned < size), it is always an error.
*/
int writeblock( const int fd, const uint8_t * const buf, const int size )
  {
  int sz = 0;
  errno = 0;
  while( sz < size )
    {
    const int n = write( fd, buf + sz, size - sz );
    if( n > 0 ) sz += n;
    else if( n < 0 && errno != EINTR ) break;
    errno = 0;
    }
  return sz;
  }


bool Rd_read_block( struct Range_decoder * const rdec )
  {
  if( !rdec->at_stream_end )
    {
    rdec->stream_pos = readblock( rdec->infd, rdec->buffer, rd_buffer_size );
    if( rdec->stream_pos != rd_buffer_size && errno )
      { show_error( "Read error", errno, false ); cleanup_and_fail( 1 ); }
    rdec->at_stream_end = ( rdec->stream_pos < rd_buffer_size );
    rdec->partial_member_pos += rdec->pos;
    rdec->pos = 0;
    show_dprogress( 0, 0, 0, 0 );
    }
  return rdec->pos < rdec->stream_pos;
  }


void LZd_flush_data( struct LZ_decoder * const d )
  {
  if( d->pos > d->stream_pos )
    {
    const int size = d->pos - d->stream_pos;
    CRC32_update_buf( &d->crc, d->buffer + d->stream_pos, size );
    if( d->outfd >= 0 &&
        writeblock( d->outfd, d->buffer + d->stream_pos, size ) != size )
      { show_error( "Write error", errno, false ); cleanup_and_fail( 1 ); }
    if( d->pos >= d->dictionary_size )
      { d->partial_data_pos += d->pos; d->pos = 0; d->pos_wrapped = true; }
    d->stream_pos = d->pos;
    }
  }


static int LZd_check_trailer( struct LZ_decoder * const d,
                              struct Pretty_print * const pp,
                              const bool ignore_empty )
  {
  Lzip_trailer trailer;
  int size = Rd_read_data( d->rdec, trailer, Lt_size );
  bool error = false;

  if( size < Lt_size )
    {
    error = true;
    if( verbosity >= 0 )
      { Pp_show_msg( pp, 0 );
        fprintf( stderr, "Trailer truncated at trailer position %d;"
                         " some checks may fail.\n", size ); }
    while( size < Lt_size ) trailer[size++] = 0;
    }

  const unsigned td_crc = Lt_get_data_crc( trailer );
  if( td_crc != LZd_crc( d ) )
    {
    error = true;
    if( verbosity >= 0 )
      { Pp_show_msg( pp, 0 );
        fprintf( stderr, "CRC mismatch; stored %08X, computed %08X\n",
                 td_crc, LZd_crc( d ) ); }
    }
  const unsigned long long data_size = LZd_data_position( d );
  const unsigned long long td_size = Lt_get_data_size( trailer );
  if( td_size != data_size )
    {
    error = true;
    if( verbosity >= 0 )
      { Pp_show_msg( pp, 0 );
        fprintf( stderr, "Data size mismatch; stored %llu (0x%llX), computed %llu (0x%llX)\n",
                 td_size, td_size, data_size, data_size ); }
    }
  const unsigned long long member_size = Rd_member_position( d->rdec );
  const unsigned long long tm_size = Lt_get_member_size( trailer );
  if( tm_size != member_size )
    {
    error = true;
    if( verbosity >= 0 )
      { Pp_show_msg( pp, 0 );
        fprintf( stderr, "Member size mismatch; stored %llu (0x%llX), computed %llu (0x%llX)\n",
                 tm_size, tm_size, member_size, member_size ); }
    }
  if( error ) return 3;
  if( !ignore_empty && data_size == 0 ) return 5;
  if( verbosity >= 2 )
    {
    if( verbosity >= 4 ) show_header( d->dictionary_size );
    if( data_size == 0 || member_size == 0 )
      fputs( "no data compressed. ", stderr );
    else
      fprintf( stderr, "%6.3f:1, %5.2f%% ratio, %5.2f%% saved. ",
               (double)data_size / member_size,
               ( 100.0 * member_size ) / data_size,
               100.0 - ( ( 100.0 * member_size ) / data_size ) );
    if( verbosity >= 4 ) fprintf( stderr, "CRC %08X, ", td_crc );
    if( verbosity >= 3 )
      fprintf( stderr, "%9llu out, %8llu in. ", data_size, member_size );
    }
  return 0;
  }


/* Return value: 0 = OK, 1 = decoder error, 2 = unexpected EOF,
                 3 = trailer error, 4 = unknown marker found,
                 5 = empty member found, 6 = marked member found. */
int LZd_decode_member( struct LZ_decoder * const d,
                       const struct Cl_options * const cl_opts,
                       struct Pretty_print * const pp )
  {
  struct Range_decoder * const rdec = d->rdec;
  Bit_model bm_literal[1<<literal_context_bits][0x300];
  Bit_model bm_match[states][pos_states];
  Bit_model bm_rep[states];
  Bit_model bm_rep0[states];
  Bit_model bm_rep1[states];
  Bit_model bm_rep2[states];
  Bit_model bm_len[states][pos_states];
  Bit_model bm_dis_slot[len_states][1<<dis_slot_bits];
  Bit_model bm_dis[modeled_distances-end_dis_model+1];
  Bit_model bm_align[dis_align_size];
  struct Len_model match_len_model;
  struct Len_model rep_len_model;
  unsigned rep0 = 0;		/* rep[0-3] latest four distances */
  unsigned rep1 = 0;		/* used for efficient coding of */
  unsigned rep2 = 0;		/* repeated distances */
  unsigned rep3 = 0;
  State state = 0;

  Bm_array_init( bm_literal[0], (1 << literal_context_bits) * 0x300 );
  Bm_array_init( bm_match[0], states * pos_states );
  Bm_array_init( bm_rep, states );
  Bm_array_init( bm_rep0, states );
  Bm_array_init( bm_rep1, states );
  Bm_array_init( bm_rep2, states );
  Bm_array_init( bm_len[0], states * pos_states );
  Bm_array_init( bm_dis_slot[0], len_states * (1 << dis_slot_bits) );
  Bm_array_init( bm_dis, modeled_distances - end_dis_model + 1 );
  Bm_array_init( bm_align, dis_align_size );
  Lm_init( &match_len_model );
  Lm_init( &rep_len_model );

  if( !Rd_load( rdec, cl_opts->ignore_marking ) ) return 6;
  while( !Rd_finished( rdec ) )
    {
    const int pos_state = LZd_data_position( d ) & pos_state_mask;
    if( Rd_decode_bit( rdec, &bm_match[state][pos_state] ) == 0 ) /* 1st bit */
      {
      /* literal byte */
      Bit_model * const bm = bm_literal[get_lit_state(LZd_peek_prev( d ))];
      if( ( state = St_set_char( state ) ) < 4 )
        LZd_put_byte( d, Rd_decode_tree8( rdec, bm ) );
      else
        LZd_put_byte( d, Rd_decode_matched( rdec, bm, LZd_peek( d, rep0 ) ) );
      continue;
      }
    /* match or repeated match */
    int len;
    if( Rd_decode_bit( rdec, &bm_rep[state] ) != 0 )		/* 2nd bit */
      {
      if( Rd_decode_bit( rdec, &bm_rep0[state] ) == 0 )		/* 3rd bit */
        {
        if( Rd_decode_bit( rdec, &bm_len[state][pos_state] ) == 0 ) /* 4th bit */
          { state = St_set_short_rep( state );
            LZd_put_byte( d, LZd_peek( d, rep0 ) ); continue; }
        }
      else
        {
        unsigned distance;
        if( Rd_decode_bit( rdec, &bm_rep1[state] ) == 0 )	/* 4th bit */
          distance = rep1;
        else
          {
          if( Rd_decode_bit( rdec, &bm_rep2[state] ) == 0 )	/* 5th bit */
            distance = rep2;
          else
            { distance = rep3; rep3 = rep2; }
          rep2 = rep1;
          }
        rep1 = rep0;
        rep0 = distance;
        }
      state = St_set_rep( state );
      len = Rd_decode_len( rdec, &rep_len_model, pos_state );
      }
    else					/* match */
      {
      len = Rd_decode_len( rdec, &match_len_model, pos_state );
      unsigned distance = Rd_decode_tree6( rdec, bm_dis_slot[get_len_state(len)] );
      if( distance >= start_dis_model )
        {
        const unsigned dis_slot = distance;
        const int direct_bits = ( dis_slot >> 1 ) - 1;
        distance = ( 2 | ( dis_slot & 1 ) ) << direct_bits;
        if( dis_slot < end_dis_model )
          distance += Rd_decode_tree_reversed( rdec,
                      bm_dis + ( distance - dis_slot ), direct_bits );
        else
          {
          distance +=
            Rd_decode( rdec, direct_bits - dis_align_bits ) << dis_align_bits;
          distance += Rd_decode_tree_reversed4( rdec, bm_align );
          if( distance == 0xFFFFFFFFU )		/* marker found */
            {
            Rd_normalize( rdec );
            LZd_flush_data( d );
            if( len == min_match_len )		/* End Of Stream marker */
              return LZd_check_trailer( d, pp, cl_opts->ignore_empty );
            if( len == min_match_len + 1 )	/* Sync Flush marker */
              { Rd_load( rdec, true ); continue; }
            if( verbosity >= 0 )
              {
              Pp_show_msg( pp, 0 );
              fprintf( stderr, "Unsupported marker code '%d'\n", len );
              }
            return 4;
            }
          }
        }
      rep3 = rep2; rep2 = rep1; rep1 = rep0; rep0 = distance;
      state = St_set_match( state );
      if( rep0 >= d->dictionary_size || ( rep0 >= d->pos && !d->pos_wrapped ) )
        { LZd_flush_data( d ); return 1; }
      }
    LZd_copy_block( d, rep0, len );
    }
  LZd_flush_data( d );
  return 2;
  }
