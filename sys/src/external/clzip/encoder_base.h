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

enum { price_shift_bits = 6,
       price_step_bits = 2,
       price_step = 1 << price_step_bits };

typedef uint8_t Dis_slots[1<<10];

extern Dis_slots dis_slots;

static inline void Dis_slots_init( void )
  {
  int i, size, slot;
  for( slot = 0; slot < 4; ++slot ) dis_slots[slot] = slot;
  for( i = 4, size = 2, slot = 4; slot < 20; slot += 2 )
    {
    memset( &dis_slots[i], slot, size );
    memset( &dis_slots[i+size], slot + 1, size );
    size <<= 1;
    i += size;
    }
  }

static inline uint8_t get_slot( const unsigned dis )
  {
  if( dis < (1 << 10) ) return dis_slots[dis];
  if( dis < (1 << 19) ) return dis_slots[dis>> 9] + 18;
  if( dis < (1 << 28) ) return dis_slots[dis>>18] + 36;
  return dis_slots[dis>>27] + 54;
  }


typedef short Prob_prices[bit_model_total >> price_step_bits];

extern Prob_prices prob_prices;

static inline void Prob_prices_init( void )
  {
  int i, j;
  for( i = 0; i < bit_model_total >> price_step_bits; ++i )
    {
    unsigned val = ( i * price_step ) + ( price_step / 2 );
    int bits = 0;				/* base 2 logarithm of val */
    for( j = 0; j < price_shift_bits; ++j )
      {
      val = val * val;
      bits <<= 1;
      while( val >= 1 << 16 ) { val >>= 1; ++bits; }
      }
    bits += 15;					/* remaining bits in val */
    prob_prices[i] = ( bit_model_total_bits << price_shift_bits ) - bits;
    }
  }

static inline int get_price( const int probability )
  { return prob_prices[probability >> price_step_bits]; }


static inline int price0( const Bit_model probability )
  { return get_price( probability ); }

static inline int price1( const Bit_model probability )
  { return get_price( bit_model_total - probability ); }

static inline int price_bit( const Bit_model bm, const bool bit )
  { return bit ? price1( bm ) : price0( bm ); }


static inline int price_symbol3( const Bit_model bm[], int symbol )
  {
  bool bit = symbol & 1;
  symbol |= 8; symbol >>= 1;
  int price = price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  return price + price_bit( bm[1], symbol & 1 );
  }


static inline int price_symbol6( const Bit_model bm[], unsigned symbol )
  {
  bool bit = symbol & 1;
  symbol |= 64; symbol >>= 1;
  int price = price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  return price + price_bit( bm[1], symbol & 1 );
  }


static inline int price_symbol8( const Bit_model bm[], int symbol )
  {
  bool bit = symbol & 1;
  symbol |= 0x100; symbol >>= 1;
  int price = price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  bit = symbol & 1; symbol >>= 1; price += price_bit( bm[symbol], bit );
  return price + price_bit( bm[1], symbol & 1 );
  }


static inline int price_symbol_reversed( const Bit_model bm[], int symbol,
                                         const int num_bits )
  {
  int price = 0;
  int model = 1;
  int i;
  for( i = num_bits; i > 0; --i )
    {
    const bool bit = symbol & 1;
    symbol >>= 1;
    price += price_bit( bm[model], bit );
    model <<= 1; model |= bit;
    }
  return price;
  }


static inline int price_matched( const Bit_model bm[], unsigned symbol,
                                 unsigned match_byte )
  {
  int price = 0;
  unsigned mask = 0x100;
  symbol |= mask;
  while( true )
    {
    const unsigned match_bit = ( match_byte <<= 1 ) & mask;
    const bool bit = ( symbol <<= 1 ) & 0x100;
    price += price_bit( bm[(symbol>>9)+match_bit+mask], bit );
    if( symbol >= 0x10000 ) return price;
    mask &= ~(match_bit ^ symbol);	/* if( match_bit != bit ) mask = 0; */
    }
  }


struct Matchfinder_base
  {
  unsigned long long partial_data_pos;
  uint8_t * buffer;		/* input buffer */
  int32_t * prev_positions;	/* 1 + last seen position of key. else 0 */
  int32_t * pos_array;		/* may be tree or chain */
  int before_size;		/* bytes to keep in buffer before dictionary */
  int buffer_size;
  int dictionary_size;		/* bytes to keep in buffer before pos */
  int pos;			/* current pos in buffer */
  int cyclic_pos;		/* cycles through [0, dictionary_size] */
  int stream_pos;		/* first byte not yet read from file */
  int pos_limit;		/* when reached, a new block must be read */
  int key4_mask;
  int num_prev_positions23;
  int num_prev_positions;	/* size of prev_positions */
  int pos_array_size;
  int infd;			/* input file descriptor */
  bool at_stream_end;		/* stream_pos shows real end of file */
  };

bool Mb_read_block( struct Matchfinder_base * const mb );
void Mb_normalize_pos( struct Matchfinder_base * const mb );

bool Mb_init( struct Matchfinder_base * const mb, const int before_size,
              const int dict_size, const int after_size,
              const int dict_factor, const int num_prev_positions23,
              const int pos_array_factor, const int ifd );

static inline void Mb_free( struct Matchfinder_base * const mb )
  { free( mb->prev_positions ); free( mb->buffer ); }

static inline uint8_t Mb_peek( const struct Matchfinder_base * const mb,
                               const int distance )
  { return mb->buffer[mb->pos-distance]; }

static inline int Mb_available_bytes( const struct Matchfinder_base * const mb )
  { return mb->stream_pos - mb->pos; }

static inline unsigned long long
Mb_data_position( const struct Matchfinder_base * const mb )
  { return mb->partial_data_pos + mb->pos; }

static inline bool Mb_data_finished( const struct Matchfinder_base * const mb )
  { return mb->at_stream_end && mb->pos >= mb->stream_pos; }

static inline const uint8_t *
Mb_ptr_to_current_pos( const struct Matchfinder_base * const mb )
  { return mb->buffer + mb->pos; }

static inline int Mb_true_match_len( const struct Matchfinder_base * const mb,
                                     const int index, const int distance )
  {
  const uint8_t * const data = mb->buffer + mb->pos;
  int i = index;
  const int len_limit = min( Mb_available_bytes( mb ), max_match_len );
  while( i < len_limit && data[i-distance] == data[i] ) ++i;
  return i;
  }

static inline void Mb_move_pos( struct Matchfinder_base * const mb )
  {
  if( ++mb->cyclic_pos > mb->dictionary_size ) mb->cyclic_pos = 0;
  if( ++mb->pos >= mb->pos_limit ) Mb_normalize_pos( mb );
  }

void Mb_reset( struct Matchfinder_base * const mb );


enum { re_buffer_size = 65536 };

struct Range_encoder
  {
  uint64_t low;
  unsigned long long partial_member_pos;
  uint8_t * buffer;		/* output buffer */
  int pos;			/* current pos in buffer */
  uint32_t range;
  unsigned ff_count;
  int outfd;			/* output file descriptor */
  uint8_t cache;
  Lzip_header header;
  };

void Re_flush_data( struct Range_encoder * const renc );

static inline void Re_put_byte( struct Range_encoder * const renc,
                                const uint8_t b )
  {
  renc->buffer[renc->pos] = b;
  if( ++renc->pos >= re_buffer_size ) Re_flush_data( renc );
  }

static inline void Re_shift_low( struct Range_encoder * const renc )
  {
  if( renc->low >> 24 != 0xFF )
    {
    const bool carry = ( renc->low > 0xFFFFFFFFU );
    Re_put_byte( renc, renc->cache + carry );
    for( ; renc->ff_count > 0; --renc->ff_count )
      Re_put_byte( renc, 0xFF + carry );
    renc->cache = renc->low >> 24;
    }
  else ++renc->ff_count;
  renc->low = ( renc->low & 0x00FFFFFFU ) << 8;
  }

static inline void Re_reset( struct Range_encoder * const renc,
                             const unsigned dictionary_size )
  {
  renc->low = 0;
  renc->partial_member_pos = 0;
  renc->pos = 0;
  renc->range = 0xFFFFFFFFU;
  renc->ff_count = 0;
  renc->cache = 0;
  Lh_set_dictionary_size( renc->header, dictionary_size );
  int i; for( i = 0; i < Lh_size; ++i ) Re_put_byte( renc, renc->header[i] );
  }

static inline bool Re_init( struct Range_encoder * const renc,
                            const unsigned dictionary_size, const int ofd )
  {
  renc->buffer = (uint8_t *)malloc( re_buffer_size );
  if( !renc->buffer ) return false;
  renc->outfd = ofd;
  Lh_set_magic( renc->header );
  Re_reset( renc, dictionary_size );
  return true;
  }

static inline void Re_free( struct Range_encoder * const renc )
  { free( renc->buffer ); }

static inline unsigned long long
Re_member_position( const struct Range_encoder * const renc )
  { return renc->partial_member_pos + renc->pos + renc->ff_count; }

static inline void Re_flush( struct Range_encoder * const renc )
  { int i; for( i = 0; i < 5; ++i ) Re_shift_low( renc ); }

static inline void Re_encode( struct Range_encoder * const renc,
                              const int symbol, const int num_bits )
  {
  unsigned mask;
  for( mask = 1 << ( num_bits - 1 ); mask > 0; mask >>= 1 )
    {
    renc->range >>= 1;
    if( symbol & mask ) renc->low += renc->range;
    if( renc->range <= 0x00FFFFFFU ) { renc->range <<= 8; Re_shift_low( renc ); }
    }
  }

static inline void Re_encode_bit( struct Range_encoder * const renc,
                                  Bit_model * const probability, const bool bit )
  {
  const uint32_t bound = ( renc->range >> bit_model_total_bits ) * *probability;
  if( !bit )
    {
    renc->range = bound;
    *probability += (bit_model_total - *probability) >> bit_model_move_bits;
    }
  else
    {
    renc->low += bound;
    renc->range -= bound;
    *probability -= *probability >> bit_model_move_bits;
    }
  if( renc->range <= 0x00FFFFFFU ) { renc->range <<= 8; Re_shift_low( renc ); }
  }

static inline void Re_encode_tree3( struct Range_encoder * const renc,
                                    Bit_model bm[], const int symbol )
  {
  bool bit = ( symbol >> 2 ) & 1;
  Re_encode_bit( renc, &bm[1], bit );
  int model = 2 | bit;
  bit = ( symbol >> 1 ) & 1;
  Re_encode_bit( renc, &bm[model], bit ); model <<= 1; model |= bit;
  Re_encode_bit( renc, &bm[model], symbol & 1 );
  }

static inline void Re_encode_tree6( struct Range_encoder * const renc,
                                    Bit_model bm[], const unsigned symbol )
  {
  bool bit = ( symbol >> 5 ) & 1;
  Re_encode_bit( renc, &bm[1], bit );
  int model = 2 | bit;
  bit = ( symbol >> 4 ) & 1;
  Re_encode_bit( renc, &bm[model], bit ); model <<= 1; model |= bit;
  bit = ( symbol >> 3 ) & 1;
  Re_encode_bit( renc, &bm[model], bit ); model <<= 1; model |= bit;
  bit = ( symbol >> 2 ) & 1;
  Re_encode_bit( renc, &bm[model], bit ); model <<= 1; model |= bit;
  bit = ( symbol >> 1 ) & 1;
  Re_encode_bit( renc, &bm[model], bit ); model <<= 1; model |= bit;
  Re_encode_bit( renc, &bm[model], symbol & 1 );
  }

static inline void Re_encode_tree8( struct Range_encoder * const renc,
                                    Bit_model bm[], const int symbol )
  {
  int model = 1;
  int i;
  for( i = 7; i >= 0; --i )
    {
    const bool bit = ( symbol >> i ) & 1;
    Re_encode_bit( renc, &bm[model], bit );
    model <<= 1; model |= bit;
    }
  }

static inline void Re_encode_tree_reversed( struct Range_encoder * const renc,
                     Bit_model bm[], int symbol, const int num_bits )
  {
  int model = 1;
  int i;
  for( i = num_bits; i > 0; --i )
    {
    const bool bit = symbol & 1;
    symbol >>= 1;
    Re_encode_bit( renc, &bm[model], bit );
    model <<= 1; model |= bit;
    }
  }

static inline void Re_encode_matched( struct Range_encoder * const renc,
                                      Bit_model bm[], unsigned symbol,
                                      unsigned match_byte )
  {
  unsigned mask = 0x100;
  symbol |= mask;
  while( true )
    {
    const unsigned match_bit = ( match_byte <<= 1 ) & mask;
    const bool bit = ( symbol <<= 1 ) & 0x100;
    Re_encode_bit( renc, &bm[(symbol>>9)+match_bit+mask], bit );
    if( symbol >= 0x10000 ) break;
    mask &= ~(match_bit ^ symbol);	/* if( match_bit != bit ) mask = 0; */
    }
  }

static inline void Re_encode_len( struct Range_encoder * const renc,
                                  struct Len_model * const lm,
                                  int symbol, const int pos_state )
  {
  bool bit = ( ( symbol -= min_match_len ) >= len_low_symbols );
  Re_encode_bit( renc, &lm->choice1, bit );
  if( !bit )
    Re_encode_tree3( renc, lm->bm_low[pos_state], symbol );
  else
    {
    bit = ( ( symbol -= len_low_symbols ) >= len_mid_symbols );
    Re_encode_bit( renc, &lm->choice2, bit );
    if( !bit )
      Re_encode_tree3( renc, lm->bm_mid[pos_state], symbol );
    else
      Re_encode_tree8( renc, lm->bm_high, symbol - len_mid_symbols );
    }
  }


enum { max_marker_size = 16,
       num_rep_distances = 4 };		/* must be 4 */

struct LZ_encoder_base
  {
  struct Matchfinder_base mb;
  uint32_t crc;

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
  struct Range_encoder renc;
  };

void LZeb_reset( struct LZ_encoder_base * const eb );

static inline bool LZeb_init( struct LZ_encoder_base * const eb,
                              const int before_size, const int dict_size,
                              const int after_size, const int dict_factor,
                              const int num_prev_positions23,
                              const int pos_array_factor,
                              const int ifd, const int outfd )
  {
  if( !Mb_init( &eb->mb, before_size, dict_size, after_size, dict_factor,
                num_prev_positions23, pos_array_factor, ifd ) ) return false;
  if( !Re_init( &eb->renc, eb->mb.dictionary_size, outfd ) ) return false;
  LZeb_reset( eb );
  return true;
  }

static inline void LZeb_free( struct LZ_encoder_base * const eb )
  { Re_free( &eb->renc ); Mb_free( &eb->mb ); }

static inline unsigned LZeb_crc( const struct LZ_encoder_base * const eb )
  { return eb->crc ^ 0xFFFFFFFFU; }

static inline int LZeb_price_literal( const struct LZ_encoder_base * const eb,
                            const uint8_t prev_byte, const uint8_t symbol )
  { return price_symbol8( eb->bm_literal[get_lit_state(prev_byte)], symbol ); }

static inline int LZeb_price_matched( const struct LZ_encoder_base * const eb,
  const uint8_t prev_byte, const uint8_t symbol, const uint8_t match_byte )
  { return price_matched( eb->bm_literal[get_lit_state(prev_byte)], symbol,
                          match_byte ); }

static inline void LZeb_encode_literal( struct LZ_encoder_base * const eb,
                            const uint8_t prev_byte, const uint8_t symbol )
  { Re_encode_tree8( &eb->renc, eb->bm_literal[get_lit_state(prev_byte)], symbol ); }

static inline void LZeb_encode_matched( struct LZ_encoder_base * const eb,
  const uint8_t prev_byte, const uint8_t symbol, const uint8_t match_byte )
  { Re_encode_matched( &eb->renc, eb->bm_literal[get_lit_state(prev_byte)],
                       symbol, match_byte ); }

static inline void LZeb_encode_pair( struct LZ_encoder_base * const eb,
                                     const unsigned dis, const int len,
                                     const int pos_state )
  {
  Re_encode_len( &eb->renc, &eb->match_len_model, len, pos_state );
  const unsigned dis_slot = get_slot( dis );
  Re_encode_tree6( &eb->renc, eb->bm_dis_slot[get_len_state(len)], dis_slot );

  if( dis_slot >= start_dis_model )
    {
    const int direct_bits = ( dis_slot >> 1 ) - 1;
    const unsigned base = ( 2 | ( dis_slot & 1 ) ) << direct_bits;
    const unsigned direct_dis = dis - base;

    if( dis_slot < end_dis_model )
      Re_encode_tree_reversed( &eb->renc, eb->bm_dis + ( base - dis_slot ),
                               direct_dis, direct_bits );
    else
      {
      Re_encode( &eb->renc, direct_dis >> dis_align_bits,
                 direct_bits - dis_align_bits );
      Re_encode_tree_reversed( &eb->renc, eb->bm_align, direct_dis, dis_align_bits );
      }
    }
  }

void LZeb_full_flush( struct LZ_encoder_base * const eb, const State state );
