#ifndef __LECTOOLS_H__



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>



/*  Temporarily, choose among the available compression tables
**  Each option corresponds to a different huffman table
*/
#define LECOPT  '1'
#define AL3OPT1 '1'
#define AL3OPT2 '2'
#define AL3OPT3 '3'
#define AL2OPT1 '4'
#define AL2OPT2 '5'

/* Unrelated with ALxOPT and LECOPT 
** Sets the unique prefix code to the compressed bit stream
** among ALEC2 and ALEC3 tables
*/
#define AL3OP1_CD 0X2U
#define AL3OP2_CD 0X3U
#define AL3OP3_CD 0X0U
#define AL3OP1_CD_LN 2U
#define AL3OP2_CD_LN 2U
#define AL3OP3_CD_LN 1U
#define AL2OP1_CD 0X1U
#define AL2OP2_CD 0X0U
#define AL2OP1_CD_LN 1U
#define AL2OP2_CD_LN 1U
#define END_TRNM_CD1 0x000DU
#define END_TRNM_CD2 0x0001U

#define END_TRNM_CD1_LEN 4U
#define END_TRNM_CD2_LEN 8U


/* Unrelated with ALxOPT / LECOPT 
** Sets the unique prefix code to the compressed bit stream
*/
#define ALDCOP1_CD 0X0U
#define ALDCOP2_CD 0X1U
#define ALDCOP1_CD_LN 1U
#define ALDCOP2_CD_LN 1U


/* Unrelated with ALxOPT / LECOPT 
** Sets the unique prefix code to the compressed bit stream
*/
#define ALDC_WND 40
#define ALEC_WND 10


#define BUFF_SIZE ALEC_WND
#define BCTRMX (BUFF_SIZE*32-1)

#define __LECTOOLS_H__

typedef void compressor_init( bool);

typedef struct{
	uint32_t b_ctr;	
	uint32_t data[BUFF_SIZE];
}cmp_buf ;

typedef struct{
	uint32_t b_ctr;
	uint32_t data;
}t_buf;

typedef struct {
	size_t  ctr;
	uint32_t* data;
}outbuf ;

typedef void compressor(outbuf*, int16_t*, bool);

/**
 ** @name File Input and Output
 ** @{
 **/
 

// encoding par

uint32_t get_buf_sum(int16_t* inbuf);
void aldc (outbuf* bufout, int16_t* inbuf,size_t inbuf_len);
void alec3(outbuf* bufout, int16_t* inbuf,bool ft );
void alec2(outbuf* bufout, int16_t* inbuf,bool ft );
void lec(outbuf* bufout, int16_t* inbuf, bool ft );
void al3_init(bool first);
void al2_init(bool first);
void lec_init(bool first);
void encode_init(int16_t d, char const huf_opt, cmp_buf* buf);
uint16_t two2one_cmpl(int16_t dta, uint32_t dta_ordr);
void encode( cmp_buf* buf, uint32_t len, uint16_t dta);
uint32_t define_n(int16_t d);
void padding(outbuf* bufout);
void f_trsmt(outbuf* bufout, cmp_buf buf);


#endif