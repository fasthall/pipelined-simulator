#include "memory.h"

#include <stdio.h>

#define SIZE_IM 0x1000
#define SIZE_DM 0x1000

unsigned char IMem[SIZE_IM];
unsigned char DMem[SIZE_DM];

void dump_DM(){
	unsigned int i;
	FILE* ptr;
	ptr = fopen("dimage_snp.txt","w");

	for( i = 0; i < SIZE_DM; i+=4 ){
		fprintf(ptr,"%08X\n",read_WordDM(i));	
	}
	fclose(ptr);
}

void init_IM( FILE *pIM, unsigned int pPC ){
    unsigned int i,j;
    unsigned int readIn, num_instr;
    unsigned int tmp;
    unsigned char a;
    
    readIn = 4;
    
    tmp = 0;
    for( i = 0; i < readIn; i++ ) {
          a = fgetc( pIM );
          tmp = tmp + ( (unsigned int)a << ( 8 * i ) );
    }
    num_instr = tmp;
    
    for( j = 0; j < num_instr; j++ ){
        for( i = 0; i < readIn; i++ ){
            a = fgetc( pIM );
            IMem[pPC+4*j+i] = a;
        }
    }
}

void init_DM( FILE *pDM ){
    unsigned int i, j;
    unsigned int readIn;
    unsigned int tmp;
    unsigned int num_word;
    unsigned char a;
    
    readIn = 4;
    
    tmp = 0;
    for( i = 0; i < readIn; i++ ) {
          a = fgetc( pDM );
          tmp = tmp + ( (unsigned int)a << ( 8 * i ) );
    }
    num_word = tmp;
    
    for( j = 0; j < num_word; j++ ){
        for( i = 0; i < readIn; i++ ){
            a = fgetc( pDM );
            //printf("%02x\n",a);
            DMem[4*j+i] = a;
        }
    }
}

unsigned int read_IM( unsigned int address ){
    unsigned int b0,b1,b2,b3;
    unsigned int bitstream;
    
    b0 = IMem[address];
    b1 = IMem[address+1];
    b2 = IMem[address+2];
    b3 = IMem[address+3];
    
    bitstream = ( b3 << 24 ) | ( b2 << 16 ) | ( b1 << 8 ) | b0;
    
    return bitstream;
}

unsigned int read_ByteDM( unsigned int address ){
    return (unsigned int)DMem[address];
}

unsigned int read_HalfDM( unsigned int address ){
    return (unsigned int)( ( DMem[address] & 0x000000FF ) | 
            ( ( DMem[address+1] & 0x000000FF ) << 8 ) );
}

unsigned int read_WordDM( unsigned int address ){
    return (unsigned int)( ( DMem[address] & 0x000000FF ) |
            ( ( DMem[address+1] & 0x000000FF ) << 8 ) |
            ( ( DMem[address+2] & 0x000000FF ) << 16 ) |
            ( ( DMem[address+3] & 0x000000FF ) << 24 ) );
}

void write_ByteDM( unsigned int address, unsigned int bitstream ){
    DMem[address] = (unsigned char)( bitstream & 0x000000FF );
}

void write_HalfDM( unsigned int address, unsigned int bitstream ){
    DMem[address] = (unsigned char)( bitstream & 0x000000FF );
    DMem[address+1] = (unsigned char)( ( bitstream & 0x0000FF00 ) >> 8 );
}

void write_WordDM( unsigned int address, unsigned int bitstream ){
    DMem[address] = (unsigned char)( bitstream & 0x000000FF );
    DMem[address+1] = (unsigned char)( ( bitstream & 0x0000FF00 ) >> 8 );
    DMem[address+2] = (unsigned char)( ( bitstream & 0x00FF0000 ) >> 16 );
    DMem[address+3] = (unsigned char)( ( bitstream & 0xFF000000 ) >> 24 );
}
