#ifndef SLIBTOOL_ARBITS_H
#define SLIBTOOL_ARBITS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#ifndef AR_COMMON_DEFS
#define AR_COMMON_DEFS

#define AR_SIGNATURE            "!<arch>\n"

#define AR_MEMBER_ATTR_DEFAULT  (0x00)
#define AR_MEMBER_ATTR_ASCII    (0x01)
#define AR_MEMBER_ATTR_UTF8     (0x02)
#define AR_MEMBER_ATTR_OBJECT   (0x04)
#define AR_MEMBER_ATTR_ARCHIVE  (0x08)
#define AR_MEMBER_ATTR_ARMAP    (0x10)
#define AR_MEMBER_ATTR_NAMESTRS (0x20)
#define AR_MEMBER_ATTR_LINKINFO (0x40)

#define AR_HEADER_ATTR_DEFAULT  (0x00)
#define AR_HEADER_ATTR_FILE_ID  (0x01)
#define AR_HEADER_ATTR_NAME_REF (0x02)
#define AR_HEADER_ATTR_BSD      (0x10)
#define AR_HEADER_ATTR_SYSV     (0x20)

#define AR_ARMAP_ATTR_PLAIN     (0x0000)
#define AR_ARMAP_ATTR_SORTED    (0x0001)
#define AR_ARMAP_ATTR_BSD       (0x0010)
#define AR_ARMAP_ATTR_SYSV      (0x0020)
#define AR_ARMAP_ATTR_COFF      (0x0040)
#define AR_ARMAP_ATTR_LE_32     (0x0100)
#define AR_ARMAP_ATTR_LE_64     (0x0200)
#define AR_ARMAP_ATTR_BE_32     (0x0400)
#define AR_ARMAP_ATTR_BE_64     (0x0800)

#define AR_OBJECT_ATTR_NONE     (0X0000)
#define AR_OBJECT_ATTR_ELF      (0x0001)
#define AR_OBJECT_ATTR_COFF     (0x0002)
#define AR_OBJECT_ATTR_MACHO    (0x0004)
#define AR_OBJECT_ATTR_LE_32    (0x0100)
#define AR_OBJECT_ATTR_LE_64    (0x0200)
#define AR_OBJECT_ATTR_BE_32    (0x0400)
#define AR_OBJECT_ATTR_BE_64    (0x0800)

struct ar_raw_signature {
	char    ar_signature                    [0x08];         /* 0x00 */
};

struct ar_raw_file_header {
	char    ar_file_id                      [0x10];         /* 0x00 */
	char    ar_time_date_stamp              [0x0c];         /* 0x10 */
	char    ar_uid                          [0x06];         /* 0x1c */
	char    ar_gid                          [0x06];         /* 0x22 */
	char    ar_file_mode                    [0x08];         /* 0x28 */
	char    ar_file_size                    [0x0a];         /* 0x30 */
	char    ar_end_tag                      [0x02];         /* 0x3a */
};

struct ar_raw_armap_ref_32 {
	unsigned char   ar_name_offset          [0x04];         /* 0x00 */
	unsigned char   ar_member_offset        [0x04];         /* 0x04 */
};

struct ar_raw_armap_ref_64 {
	unsigned char   ar_name_offset          [0x08];         /* 0x00 */
	unsigned char   ar_member_offset        [0x08];         /* 0x08 */
};

struct ar_raw_armap_bsd_32 {
	unsigned char   (*ar_size_of_refs)      [0x04];
	unsigned char   (*ar_first_name_offset) [0x04];
	unsigned char   (*ar_size_of_strs)      [0x04];
	const char *    (*ar_string_table);
};

struct ar_raw_armap_bsd_64 {
	unsigned char   (*ar_size_of_refs)      [0x08];
	unsigned char   (*ar_first_name_offset) [0x08];
	unsigned char   (*ar_size_of_strs)      [0x08];
	const char *    (*ar_string_table);
};

struct ar_raw_armap_sysv_32 {
	unsigned char   (*ar_num_of_syms)       [0x04];
	unsigned char   (*ar_first_ref_offset)  [0x04];
	const char *    (*ar_string_table);
};

struct ar_raw_armap_sysv_64 {
	unsigned char   (*ar_num_of_syms)       [0x08];
	unsigned char   (*ar_first_ref_offset)  [0x08];
	const char *    (*ar_string_table);
};

struct ar_raw_armap_xcoff_32 {
	unsigned char   (*ar_num_of_members)      [0x04];
	unsigned char   (*ar_first_member_offset) [0x04];
	unsigned char   (*ar_num_of_symbols)      [0x04];
	unsigned char   (*ar_sym_member_indices)  [0x02];
	char            (*ar_string_table)        [];
};

struct ar_meta_signature {
	const char *    ar_signature;
};

struct ar_meta_file_header {
	const char *    ar_member_name;
	uint32_t        ar_header_attr;
	uint32_t        ar_uid;
	uint32_t        ar_gid;
	uint32_t        ar_file_mode;
	uint64_t        ar_file_size;
	uint64_t        ar_time_date_stamp;
};

struct ar_meta_member_info {
	struct ar_meta_file_header      ar_file_header;
	struct ar_raw_file_header *     ar_member_data;
	uint32_t                        ar_member_attr;
	uint32_t                        ar_object_attr;
	uint64_t                        ar_object_size;
	void *                          ar_object_data;
};

struct ar_meta_armap_ref_32 {
	uint32_t                        ar_name_offset;
	uint32_t                        ar_member_offset;
};

struct ar_meta_armap_ref_64 {
	uint64_t                        ar_name_offset;
	uint64_t                        ar_member_offset;
};

struct ar_meta_armap_common_32 {
	struct ar_meta_member_info *    ar_member;
	struct ar_meta_armap_ref_32 *   ar_symrefs;
	struct ar_raw_armap_bsd_32 *    ar_armap_bsd;
	struct ar_raw_armap_sysv_32 *   ar_armap_sysv;
	struct ar_raw_armap_xcoff_32 *  ar_armap_xcoff;
	uint32_t                        ar_armap_attr;
	uint32_t                        ar_num_of_symbols;
	uint32_t                        ar_num_of_members;
	uint32_t                        ar_first_member_offset;
	uint32_t                        ar_size_of_refs;
	uint32_t                        ar_size_of_strs;
	uint16_t *                      ar_sym_member_indices;
	const char *                    ar_string_table;
};

struct ar_meta_armap_common_64 {
	struct ar_meta_member_info *    ar_member;
	struct ar_meta_armap_ref_64 *   ar_symrefs;
	struct ar_raw_armap_bsd_64 *    ar_armap_bsd;
	struct ar_raw_armap_sysv_64 *   ar_armap_sysv;
	void *                          ar_armap_xcoff;
	uint32_t                        ar_armap_attr;
	uint64_t                        ar_num_of_symbols;
	uint64_t                        ar_num_of_members;
	uint64_t                        ar_first_member_offset;
	uint64_t                        ar_size_of_refs;
	uint64_t                        ar_size_of_strs;
	uint16_t *                      ar_sym_member_indices;
	const char *                    ar_string_table;
};

struct ar_meta_symbol_info {
	const char *                    ar_archive_name;
	const char *                    ar_object_name;
	const char *                    ar_symbol_name;
	const char *                    ar_symbol_type;
	uint64_t                        ar_symbol_value;
	uint64_t                        ar_symbol_size;
};

struct ar_meta_armap_info {
	const struct ar_meta_armap_common_32 *  ar_armap_common_32;
	const struct ar_meta_armap_common_64 *  ar_armap_common_64;
};

#endif

#ifdef __cplusplus
}
#endif

#endif
