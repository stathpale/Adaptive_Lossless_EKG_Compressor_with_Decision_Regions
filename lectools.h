#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#ifndef __LECTOOLS_H__
#define __LECTOOLS_H__

#define BUFF_SIZE 2
typedef struct{
	FILE* in;
	FILE* out;
	char const* in_id;
	char const* out_id;
	char const* in_mode;
	char const* out_mode;
	size_t nsamples;
}f_io;

typedef struct{
	uint32_t b_ctr;	
	uint32_t data[BUFF_SIZE];	
	uint32_t const b_max;
	uint32_t const word32size;
}cmp_buf ;

/**
 ** @name File Input and Output
 ** @{
 **/
 
/** @brief Open input and output files
 ** which are included in the typedef f_io  @a files.
 **
 ** Only use this function with a partly intialised f_io struct
 ** @a .in_id and @a .outid  aswell @a in_mode  and @a out.mode must
 ** be well defined or else the program will have undefined behavior.
 **
 ** Returns in each input and output @a .in , @a .out a valid FILE* value
 ** upon success or it exits the program upon fopen failure.
 **
 ** Each @a f_io type struct that opens with f_open must be 
 ** closed with f_close.
 **/
f_io f_open(f_io files);

void f_close(f_io files);

size_t f_get_len(FILE* fptr);

int16_t f_fetch_sample(FILE* fptr);

void f_write(FILE* fout, cmp_buf* buf);


// encoding par

int32_t lec (f_io, char const huf_opt, size_t, cmp_buf*);
int32_t encode_init(int16_t d, char const huf_opt, cmp_buf* buf);
uint16_t two2one_cmpl(int16_t dta, uint32_t dta_ordr);
int32_t encode( cmp_buf* buf, uint32_t len, uint16_t dta);
uint32_t define_n(int16_t d);
void padding(FILE* fout, cmp_buf* buf );
#endif