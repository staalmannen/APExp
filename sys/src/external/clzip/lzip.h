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

#ifndef max
  #define max(x,y) ((x) >= (y) ? (x) : (y))
#endif
#ifndef min
  #define min(x,y) ((x) <= (y) ? (x) : (y))
#endif

typedef int State;

enum { states = 12 };
static inline bool St_is_char( const State st ) { return st < 7; }

static inline State St_set_char( const State st )
  {
  static const State next[states] = { 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 4, 5 };
  return next[st];
  }
static inline State St_set_char_rep() { return 8; }
static inline State St_set_match( const State st )
  { return ( st < 7 ) ? 7 : 10; }
static inline State St_set_rep( const State st )
  { return ( st < 7 ) ? 8 : 11; }
static inline State St_set_short_rep( const State st )
  { return ( st < 7 ) ? 9 : 11; }


enum {
  min_dictionary_bits = 12,
  min_dictionary_size = 1 << min_dictionary_bits,	/* >= modeled_distances */
  max_dictionary_bits = 29,
  max_dictionary_size = 1 << max_dictionary_bits,
  min_member_size = 36,
  literal_context_bits = 3,
  literal_pos_state_bits = 0,				/* not used */
  pos_state_bits = 2,
  pos_states = 1 << pos_state_bits,
  pos_state_mask = pos_states - 1,

  len_states = 4,
  dis_slot_bits = 6,
  start_dis_model = 4,
  end_dis_model = 14,
  modeled_distances = 1 << ( end_dis_model / 2 ),	/* 128 */
  dis_align_bits = 4,
  dis_align_size = 1 << dis_align_bits,

  len_low_bits = 3,
  len_mid_bits = 3,
  len_high_bits = 8,
  len_low_symbols = 1 << len_low_bits,
  len_mid_symbols = 1 << len_mid_bits,
  len_high_symbols = 1 << len_high_bits,
  max_len_symbols = len_low_symbols + len_mid_symbols + len_high_symbols,

  min_match_len = 2,					/* must be 2 */
  max_match_len = min_match_len + max_len_symbols - 1,	/* 273 */
  min_match_len_limit = 5 };

static inline int get_len_state( const int len )
  { return min( len - min_match_len, len_states - 1 ); }

static inline int get_lit_state( const uint8_t prev_byte )
  { return prev_byte >> ( 8 - literal_context_bits ); }


enum { bit_model_move_bits = 5,
       bit_model_total_bits = 11,
       bit_model_total = 1 << bit_model_total_bits };

typedef int Bit_model;

static inline void Bm_init( Bit_model * const probability )
  { *probability = bit_model_total / 2; }

static inline void Bm_array_init( Bit_model bm[], const int size )
  { int i; for( i = 0; i < size; ++i ) Bm_init( &bm[i] ); }

struct Len_model
  {
  Bit_model choice1;
  Bit_model choice2;
  Bit_model bm_low[pos_states][len_low_symbols];
  Bit_model bm_mid[pos_states][len_mid_symbols];
  Bit_model bm_high[len_high_symbols];
  };

static inline void Lm_init( struct Len_model * const lm )
  {
  Bm_init( &lm->choice1 );
  Bm_init( &lm->choice2 );
  Bm_array_init( lm->bm_low[0], pos_states * len_low_symbols );
  Bm_array_init( lm->bm_mid[0], pos_states * len_mid_symbols );
  Bm_array_init( lm->bm_high, len_high_symbols );
  }


typedef uint32_t CRC32[256];	/* Table of CRCs of all 8-bit messages. */

extern CRC32 crc32;

static inline void CRC32_init( void )
  {
  unsigned n;
  for( n = 0; n < 256; ++n )
    {
    unsigned c = n;
    int k;
    for( k = 0; k < 8; ++k )
      { if( c & 1 ) c = 0xEDB88320U ^ ( c >> 1 ); else c >>= 1; }
    crc32[n] = c;
    }
  }

static inline void CRC32_update_byte( uint32_t * const crc, const uint8_t byte )
  { *crc = crc32[(*crc^byte)&0xFF] ^ ( *crc >> 8 ); }

/* about as fast as it is possible without messing with endianness */
static inline void CRC32_update_buf( uint32_t * const crc,
                                     const uint8_t * const buffer,
                                     const int size )
  {
  int i;
  uint32_t c = *crc;
  for( i = 0; i < size; ++i )
    c = crc32[(c^buffer[i])&0xFF] ^ ( c >> 8 );
  *crc = c;
  }


static inline bool isvalid_ds( const unsigned dictionary_size )
  { return dictionary_size >= min_dictionary_size &&
           dictionary_size <= max_dictionary_size; }


static inline int real_bits( unsigned value )
  {
  int bits = 0;
  while( value > 0 ) { value >>= 1; ++bits; }
  return bits;
  }


static const uint8_t lzip_magic[4] = { 0x4C, 0x5A, 0x49, 0x50 }; /* "LZIP" */

enum { Lh_size = 6 };
typedef uint8_t Lzip_header[Lh_size];	/* 0-3 magic bytes */
					/*   4 version */
					/*   5 coded dictionary size */

static inline void Lh_set_magic( Lzip_header data )
  { memcpy( data, lzip_magic, 4 ); data[4] = 1; }

static inline bool Lh_check_magic( const Lzip_header data )
  { return memcmp( data, lzip_magic, 4 ) == 0; }

/* detect (truncated) header */
static inline bool Lh_check_prefix( const Lzip_header data, const int sz )
  {
  int i; for( i = 0; i < sz && i < 4; ++i )
    if( data[i] != lzip_magic[i] ) return false;
  return sz > 0;
  }

/* detect corrupt header */
static inline bool Lh_check_corrupt( const Lzip_header data )
  {
  int matches = 0;
  int i; for( i = 0; i < 4; ++i )
    if( data[i] == lzip_magic[i] ) ++matches;
  return matches > 1 && matches < 4;
  }

static inline uint8_t Lh_version( const Lzip_header data )
  { return data[4]; }

static inline bool Lh_check_version( const Lzip_header data )
  { return data[4] == 1; }

static inline unsigned Lh_get_dictionary_size( const Lzip_header data )
  {
  unsigned sz = 1 << ( data[5] & 0x1F );
  if( sz > min_dictionary_size )
    sz -= ( sz / 16 ) * ( ( data[5] >> 5 ) & 7 );
  return sz;
  }

static inline bool Lh_set_dictionary_size( Lzip_header data, const unsigned sz )
  {
  if( !isvalid_ds( sz ) ) return false;
  data[5] = real_bits( sz - 1 );
  if( sz > min_dictionary_size )
    {
    const unsigned base_size = 1 << data[5];
    const unsigned fraction = base_size / 16;
    unsigned i;
    for( i = 7; i >= 1; --i )
      if( base_size - ( i * fraction ) >= sz )
        { data[5] |= i << 5; break; }
    }
  return true;
  }

static inline bool Lh_check( const Lzip_header data )
  {
  return Lh_check_magic( data ) && Lh_check_version( data ) &&
         isvalid_ds( Lh_get_dictionary_size( data ) );
  }


enum { Lt_size = 20 };
typedef uint8_t Lzip_trailer[Lt_size];
			/*  0-3  CRC32 of the uncompressed data */
			/*  4-11 size of the uncompressed data */
			/* 12-19 member size including header and trailer */

static inline unsigned Lt_get_data_crc( const Lzip_trailer data )
  {
  unsigned tmp = 0;
  int i; for( i = 3; i >= 0; --i ) { tmp <<= 8; tmp += data[i]; }
  return tmp;
  }

static inline void Lt_set_data_crc( Lzip_trailer data, unsigned crc )
  { int i; for( i = 0; i <= 3; ++i ) { data[i] = (uint8_t)crc; crc >>= 8; } }

static inline unsigned long long Lt_get_data_size( const Lzip_trailer data )
  {
  unsigned long long tmp = 0;
  int i; for( i = 11; i >= 4; --i ) { tmp <<= 8; tmp += data[i]; }
  return tmp;
  }

static inline void Lt_set_data_size( Lzip_trailer data, unsigned long long sz )
  { int i; for( i = 4; i <= 11; ++i ) { data[i] = (uint8_t)sz; sz >>= 8; } }

static inline unsigned long long Lt_get_member_size( const Lzip_trailer data )
  {
  unsigned long long tmp = 0;
  int i; for( i = 19; i >= 12; --i ) { tmp <<= 8; tmp += data[i]; }
  return tmp;
  }

static inline void Lt_set_member_size( Lzip_trailer data, unsigned long long sz )
  { int i; for( i = 12; i <= 19; ++i ) { data[i] = (uint8_t)sz; sz >>= 8; } }

/* check internal consistency */
static inline bool Lt_check_consistency( const Lzip_trailer data )
  {
  const unsigned crc = Lt_get_data_crc( data );
  const unsigned long long dsize = Lt_get_data_size( data );
  if( ( crc == 0 ) != ( dsize == 0 ) ) return false;
  const unsigned long long msize = Lt_get_member_size( data );
  if( msize < min_member_size ) return false;
  const unsigned long long mlimit = ( 9 * dsize + 7 ) / 8 + min_member_size;
  if( mlimit > dsize && msize > mlimit ) return false;
  const unsigned long long dlimit = 7090 * ( msize - 26 ) - 1;
  if( dlimit > msize && dsize > dlimit ) return false;
  return true;
  }


struct Cl_options		/* command-line options */
  {
  bool ignore_empty;
  bool ignore_marking;
  bool ignore_trailing;
  bool loose_trailing;
  };

static inline void Cl_options_init( struct Cl_options * cl_opts )
  { cl_opts->ignore_empty = true; cl_opts->ignore_marking = true;
    cl_opts->ignore_trailing = true; cl_opts->loose_trailing = false; }


static inline void set_retval( int * retval, const int new_val )
  { if( *retval < new_val ) *retval = new_val; }

static const char * const bad_magic_msg = "Bad magic number (file not in lzip format).";
static const char * const bad_dict_msg = "Invalid dictionary size in member header.";
static const char * const corrupt_mm_msg = "Corrupt header in multimember file.";
static const char * const empty_msg = "Empty member not allowed.";
static const char * const marking_msg = "Marking data not allowed.";
static const char * const trailing_msg = "Trailing data not allowed.";
static const char * const mem_msg = "Not enough memory.";

/* defined in decoder.c */
int readblock( const int fd, uint8_t * const buf, const int size );
int writeblock( const int fd, const uint8_t * const buf, const int size );

/* defined in list.c */
int list_files( const char * const filenames[], const int num_filenames,
                const struct Cl_options * const cl_opts );

/* defined in main.c */
struct stat;
struct Pretty_print;
extern int verbosity;
void * resize_buffer( void * buf, const unsigned min_size );
void Pp_show_msg( struct Pretty_print * const pp, const char * const msg );
const char * bad_version( const unsigned version );
const char * format_ds( const unsigned dictionary_size );
void show_header( const unsigned dictionary_size );
int open_instream( const char * const name, struct stat * const in_statsp,
                   const bool one_to_one, const bool reg_only );
void cleanup_and_fail( const int retval );
void show_error( const char * const msg, const int errcode, const bool help );
void show_file_error( const char * const filename, const char * const msg,
                      const int errcode );
void internal_error( const char * const msg );
struct Matchfinder_base;
void show_cprogress( const unsigned long long cfile_size,
                     const unsigned long long partial_size,
                     const struct Matchfinder_base * const m,
                     struct Pretty_print * const p );
struct Range_decoder;
void show_dprogress( const unsigned long long cfile_size,
                     const unsigned long long partial_size,
                     const struct Range_decoder * const d,
                     struct Pretty_print * const p );
