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

enum { rd_buffer_size = 16384 };

struct Range_decoder
  {
  unsigned long long partial_member_pos;
  uint8_t * buffer;		/* input buffer */
  int pos;			/* current pos in buffer */
  int stream_pos;		/* when reached, a new block must be read */
  uint32_t code;
  uint32_t range;
  int infd;			/* input file descriptor */
  bool at_stream_end;
  };

bool Rd_read_block( struct Range_decoder * const rdec );

static inline bool Rd_init( struct Range_decoder * const rdec, const int ifd )
  {
  rdec->partial_member_pos = 0;
  rdec->buffer = (uint8_t *)malloc( rd_buffer_size );
  if( !rdec->buffer ) return false;
  rdec->pos = 0;
  rdec->stream_pos = 0;
  rdec->code = 0;
  rdec->range = 0xFFFFFFFFU;
  rdec->infd = ifd;
  rdec->at_stream_end = false;
  return true;
  }

static inline void Rd_free( struct Range_decoder * const rdec )
  { free( rdec->buffer ); }

static inline bool Rd_finished( struct Range_decoder * const rdec )
  { return rdec->pos >= rdec->stream_pos && !Rd_read_block( rdec ); }

static inline unsigned long long
Rd_member_position( const struct Range_decoder * const rdec )
  { return rdec->partial_member_pos + rdec->pos; }

static inline void Rd_reset_member_position( struct Range_decoder * const rdec )
  { rdec->partial_member_pos = 0; rdec->partial_member_pos -= rdec->pos; }

static inline uint8_t Rd_get_byte( struct Range_decoder * const rdec )
  {
  /* 0xFF avoids decoder error if member is truncated at EOS marker */
  if( Rd_finished( rdec ) ) return 0xFF;
  return rdec->buffer[rdec->pos++];
  }

static inline int Rd_read_data( struct Range_decoder * const rdec,
                                uint8_t * const outbuf, const int size )
  {
  int sz = 0;
  while( sz < size && !Rd_finished( rdec ) )
    {
    const int rd = min( size - sz, rdec->stream_pos - rdec->pos );
    memcpy( outbuf + sz, rdec->buffer + rdec->pos, rd );
    rdec->pos += rd;
    sz += rd;
    }
  return sz;
  }

static inline bool Rd_load( struct Range_decoder * const rdec,
                            const bool ignore_marking )
  {
  int i;
  rdec->code = 0;
  rdec->range = 0xFFFFFFFFU;
  /* check and discard first byte of the LZMA stream */
  if( Rd_get_byte( rdec ) != 0 && !ignore_marking ) return false;
  for( i = 0; i < 4; ++i ) rdec->code = (rdec->code << 8) | Rd_get_byte( rdec );
  return true;
  }

static inline void Rd_normalize( struct Range_decoder * const rdec )
  {
  if( rdec->range <= 0x00FFFFFFU )
    { rdec->range <<= 8; rdec->code = (rdec->code << 8) | Rd_get_byte( rdec ); }
  }

static inline unsigned Rd_decode( struct Range_decoder * const rdec,
                                  const int num_bits )
  {
  unsigned symbol = 0;
  int i;
  for( i = num_bits; i > 0; --i )
    {
    Rd_normalize( rdec );
    rdec->range >>= 1;
/*    symbol <<= 1; */
/*    if( rdec->code >= rdec->range ) { rdec->code -= rdec->range; symbol |= 1; } */
    const bool bit = ( rdec->code >= rdec->range );
    symbol <<= 1; symbol += bit;
    rdec->code -= rdec->range & ( 0U - bit );
    }
  return symbol;
  }

static inline unsigned Rd_decode_bit( struct Range_decoder * const rdec,
                                      Bit_model * const probability )
  {
  Rd_normalize( rdec );
  const uint32_t bound = ( rdec->range >> bit_model_total_bits ) * *probability;
  if( rdec->code < bound )
    {
    rdec->range = bound;
    *probability += ( bit_model_total - *probability ) >> bit_model_move_bits;
    return 0;
    }
  else
    {
    rdec->code -= bound;
    rdec->range -= bound;
    *probability -= *probability >> bit_model_move_bits;
    return 1;
    }
  }

static inline void Rd_decode_symbol_bit( struct Range_decoder * const rdec,
                         Bit_model * const probability, unsigned * symbol )
  {
  Rd_normalize( rdec );
  *symbol <<= 1;
  const uint32_t bound = ( rdec->range >> bit_model_total_bits ) * *probability;
  if( rdec->code < bound )
    {
    rdec->range = bound;
    *probability += ( bit_model_total - *probability ) >> bit_model_move_bits;
    }
  else
    {
    rdec->code -= bound;
    rdec->range -= bound;
    *probability -= *probability >> bit_model_move_bits;
    *symbol |= 1;
    }
  }

static inline void Rd_decode_symbol_bit_reversed( struct Range_decoder * const rdec,
                         Bit_model * const probability, unsigned * model,
                         unsigned * symbol, const int i )
  {
  Rd_normalize( rdec );
  *model <<= 1;
  const uint32_t bound = ( rdec->range >> bit_model_total_bits ) * *probability;
  if( rdec->code < bound )
    {
    rdec->range = bound;
    *probability += ( bit_model_total - *probability ) >> bit_model_move_bits;
    }
  else
    {
    rdec->code -= bound;
    rdec->range -= bound;
    *probability -= *probability >> bit_model_move_bits;
    *model |= 1;
    *symbol |= 1 << i;
    }
  }

static inline unsigned Rd_decode_tree6( struct Range_decoder * const rdec,
                                        Bit_model bm[] )
  {
  unsigned symbol = 1;
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  return symbol & 0x3F;
  }

static inline unsigned Rd_decode_tree8( struct Range_decoder * const rdec,
                                        Bit_model bm[] )
  {
  unsigned symbol = 1;
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  return symbol & 0xFF;
  }

static inline unsigned
Rd_decode_tree_reversed( struct Range_decoder * const rdec,
                         Bit_model bm[], const int num_bits )
  {
  unsigned model = 1;
  unsigned symbol = 0;
  int i;
  for( i = 0; i < num_bits; ++i )
    Rd_decode_symbol_bit_reversed( rdec, &bm[model], &model, &symbol, i );
  return symbol;
  }

static inline unsigned
Rd_decode_tree_reversed4( struct Range_decoder * const rdec, Bit_model bm[] )
  {
  unsigned model = 1;
  unsigned symbol = 0;
  Rd_decode_symbol_bit_reversed( rdec, &bm[model], &model, &symbol, 0 );
  Rd_decode_symbol_bit_reversed( rdec, &bm[model], &model, &symbol, 1 );
  Rd_decode_symbol_bit_reversed( rdec, &bm[model], &model, &symbol, 2 );
  Rd_decode_symbol_bit_reversed( rdec, &bm[model], &model, &symbol, 3 );
  return symbol;
  }

static inline unsigned Rd_decode_matched( struct Range_decoder * const rdec,
                                          Bit_model bm[], unsigned match_byte )
  {
  unsigned symbol = 1;
  unsigned mask = 0x100;
  while( true )
    {
    const unsigned match_bit = ( match_byte <<= 1 ) & mask;
    const unsigned bit = Rd_decode_bit( rdec, &bm[symbol+match_bit+mask] );
    symbol <<= 1; symbol += bit;
    if( symbol > 0xFF ) return symbol & 0xFF;
    mask &= ~(match_bit ^ (bit << 8));	/* if( match_bit != bit ) mask = 0; */
    }
  }

static inline unsigned Rd_decode_len( struct Range_decoder * const rdec,
                                      struct Len_model * const lm,
                                      const int pos_state )
  {
  Bit_model * bm;
  unsigned mask, offset, symbol = 1;

  if( Rd_decode_bit( rdec, &lm->choice1 ) == 0 )
    { bm = lm->bm_low[pos_state]; mask = 7; offset = 0; goto len3; }
  if( Rd_decode_bit( rdec, &lm->choice2 ) == 0 )
    { bm = lm->bm_mid[pos_state]; mask = 7; offset = len_low_symbols; goto len3; }
  bm = lm->bm_high; mask = 0xFF; offset = len_low_symbols + len_mid_symbols;
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
len3:
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  Rd_decode_symbol_bit( rdec, &bm[symbol], &symbol );
  return ( symbol & mask ) + min_match_len + offset;
  }


struct LZ_decoder
  {
  unsigned long long partial_data_pos;
  struct Range_decoder * rdec;
  unsigned dictionary_size;
  uint8_t * buffer;		/* output buffer */
  unsigned pos;			/* current pos in buffer */
  unsigned stream_pos;		/* first byte not yet written to file */
  uint32_t crc;
  int outfd;			/* output file descriptor */
  bool pos_wrapped;
  };

void LZd_flush_data( struct LZ_decoder * const d );

static inline uint8_t LZd_peek_prev( const struct LZ_decoder * const d )
  { return d->buffer[((d->pos > 0) ? d->pos : d->dictionary_size)-1]; }

static inline uint8_t LZd_peek( const struct LZ_decoder * const d,
                                const unsigned distance )
  {
  const unsigned i = ( ( d->pos > distance ) ? 0 : d->dictionary_size ) +
                     d->pos - distance - 1;
  return d->buffer[i];
  }

static inline void LZd_put_byte( struct LZ_decoder * const d, const uint8_t b )
  {
  d->buffer[d->pos] = b;
  if( ++d->pos >= d->dictionary_size ) LZd_flush_data( d );
  }

static inline void LZd_copy_block( struct LZ_decoder * const d,
                                   const unsigned distance, unsigned len )
  {
  unsigned lpos = d->pos, i = lpos - distance - 1;
  bool fast, fast2;
  if( lpos > distance )
    {
    fast = ( len < d->dictionary_size - lpos );
    fast2 = ( fast && len <= lpos - i );
    }
  else
    {
    i += d->dictionary_size;
    fast = ( len < d->dictionary_size - i );	/* (i == pos) may happen */
    fast2 = ( fast && len <= i - lpos );
    }
  if( fast )					/* no wrap */
    {
    d->pos += len;
    if( fast2 )					/* no wrap, no overlap */
      memcpy( d->buffer + lpos, d->buffer + i, len );
    else
      for( ; len > 0; --len ) d->buffer[lpos++] = d->buffer[i++];
    }
  else for( ; len > 0; --len )
    {
    d->buffer[d->pos] = d->buffer[i];
    if( ++d->pos >= d->dictionary_size ) LZd_flush_data( d );
    if( ++i >= d->dictionary_size ) i = 0;
    }
  }

static inline bool LZd_init( struct LZ_decoder * const d,
                             struct Range_decoder * const rde,
                             const unsigned dict_size, const int ofd )
  {
  d->partial_data_pos = 0;
  d->rdec = rde;
  d->dictionary_size = dict_size;
  d->buffer = (uint8_t *)malloc( d->dictionary_size );
  if( !d->buffer ) return false;
  d->pos = 0;
  d->stream_pos = 0;
  d->crc = 0xFFFFFFFFU;
  d->outfd = ofd;
  d->pos_wrapped = false;
  /* prev_byte of first byte; also for LZd_peek( 0 ) on corrupt file */
  d->buffer[d->dictionary_size-1] = 0;
  return true;
  }

static inline void LZd_free( struct LZ_decoder * const d )
  { free( d->buffer ); }

static inline unsigned LZd_crc( const struct LZ_decoder * const d )
  { return d->crc ^ 0xFFFFFFFFU; }

static inline unsigned long long
LZd_data_position( const struct LZ_decoder * const d )
  { return d->partial_data_pos + d->pos; }

int LZd_decode_member( struct LZ_decoder * const d,
                       const struct Cl_options * const cl_opts,
                       struct Pretty_print * const pp );
