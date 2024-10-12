/*
 * Header file to use Uninorm library
 *
 */

typedef unsigned int uint;

/* integer string functions                             */
uint   istrlen                  (uint * str             );
uint   istrcmp                  (uint * s1,  uint * s2  );

/* unicode data accessors                               */
uint   is_excluded              (uint   c               );
uint   get_combining_class      (uint   c               );
int    get_recombined_codepoint (uint   c1,  uint   c2  );
uint * get_decomposition        (uint * buf, uint   c   );

/* utf en/decoding functions                            */
void encode_utf8(char *buf, unsigned *str);
void decode_utf8(unsigned *buf, char *str);

/* (de)composition functions                            */
void decompose_recursive      (uint * buf, uint   c   );
void canonical_order          (uint * str             );
void canonical_composition    (uint * str             );
void canonical_decomposition  (uint * buf, uint * str );

/* normalization functions                              */
void normalize_nfd            (uint * buf, uint * str );
void normalize_nfc            (uint * buf, uint * str );
void normalize_nfd_utf8       (char * buf, char * str );
void normalize_nfc_utf8       (char * buf, char * str );
