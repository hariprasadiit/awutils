#ifndef IMAGEWTY_H
#define IMAGEWTY_H

#include <stdint.h>

#define IMAGEWTY_MAGIC		"IMAGEWTY"
#define IMAGEWTY_MAGIC_LEN	8
#define IMAGEWTY_VERSION	0x100234

#define IMAGEWTY_FILEHDR_LEN	1024

struct imagewty_header {
	char magic[IMAGEWTY_MAGIC_LEN];
	uint32_t header_version;	/* Image header version (seen values are 0x0100 / 0x0300) */
	uint32_t header_size;		/* Image header size (sizeof(struct imagewty_header)) */
	uint32_t ram_base;
	uint32_t version;		/* format version (IMAGEWTY_VERSION) */
	union {
		struct {
			uint32_t size;			/* total size of file headers? */
			uint32_t filehdr_len;		/* size of image (seems too large!) */
			uint32_t pid;			/* USB peripheral ID (from image.cfg) */
			uint32_t vid;			/* USB vendor ID (from image.cfg) */
			uint32_t hardware_id;		/* Hardware ID (from image.cfg) */
			uint32_t firmware_id;		/* Firmware ID (from image.cfg) */
			uint32_t val1;			/* */
			uint32_t val1024;		/* */
			uint32_t num_files;		/* Total number of files embedded */
			uint32_t val1024_2;		/* */
			uint32_t val0;			/* */
			uint32_t val0_2;		/* */
			uint32_t val0_3;		/* */
			uint32_t val0_4;		/* */
			/* 0x0050 */
		} v1;
		struct {
			uint32_t size;			/* total size of file headers? */
			uint32_t filehdr_len;		/* size of image (seems too large!) */
			uint32_t unknown;
			uint32_t pid;			/* USB peripheral ID (from image.cfg) */
			uint32_t vid;			/* USB vendor ID (from image.cfg) */
			uint32_t hardware_id;		/* Hardware ID (from image.cfg) */
			uint32_t firmware_id;		/* Firmware ID (from image.cfg) */
			uint32_t val1;			/* */
			uint32_t val1024;		/* */
			uint32_t num_files;		/* Total number of files embedded */
			uint32_t val1024_2;		/* */
			uint32_t val0;			/* */
			uint32_t val0_2;		/* */
			uint32_t val0_3;		/* */
			uint32_t val0_4;		/* */
			/* 0x0060 */
		} v3;
	};
};

#define IMAGEWTY_FHDR_MAINTYPE_LEN	8
#define IMAGEWTY_FHDR_SUBTYPE_LEN	16
#define IMAGEWTY_FHDR_FILENAME_LEN	256

struct imagewty_file_header {
	uint32_t filename_len;
	uint32_t total_header_size;
	const char maintype[IMAGEWTY_FHDR_MAINTYPE_LEN];
	const char subtype[IMAGEWTY_FHDR_SUBTYPE_LEN];
	uint32_t unknown_3;
	uint32_t stored_length;
	uint32_t original_length;
	uint32_t offset;
	uint32_t unknown;
	const char filename[IMAGEWTY_FHDR_FILENAME_LEN];
	/* 0x300 */
};

#endif /* IMAGEWTY_H */

