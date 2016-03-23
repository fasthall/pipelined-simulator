#include "regfile.h"
#include <stdio.h>

unsigned int reg[NUM_REG];
unsigned int reg_PC;

void init_RegFile( unsigned int pInitSp ){
    unsigned int i;

    for( i = 0; i < NUM_REG; i++ ){
        reg[i] = 0;
    }
    
    reg[sp] = pInitSp;
}

unsigned int read_Reg( unsigned int regNO ){
	return reg[regNO];
}

void write_Reg( unsigned int regNO, unsigned int bitstream ){
    if( regNO != 0 ) {
        reg[regNO] = bitstream;
    }
}
