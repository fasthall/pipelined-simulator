#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>

void init_IM( FILE *pIM, unsigned int pPC );
void init_DM( FILE *pDM );

unsigned int read_IM( unsigned int address );
unsigned int read_ByteDM( unsigned int address );
unsigned int read_HalfDM( unsigned int address );
unsigned int read_WordDM( unsigned int address );

void write_ByteDM( unsigned int address, unsigned int bitstream );
void write_HalfDM( unsigned int address, unsigned int bitstream );
void write_WordDM( unsigned int address, unsigned int bitstream );

void dump_DM();

#endif
