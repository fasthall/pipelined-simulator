#ifndef REGFILE_H
#define REGFILE_H

#define NUM_REG 32

enum RegSN {
	zero, at, v0, v1, 
	a0, a1, a2, a3,
	t0, t1, t2, t3,
	t4, t5, t6, t7,
	s0, s1, s2, s3,
	s4, s5, s6, s7,
	t8, t9, k0, k1,
	gp, sp, fp, ra
};

void init_RegFile( unsigned int pInitSp );
unsigned int read_Reg( unsigned int regNO );
void write_Reg( unsigned int regNO, unsigned int bitstream );

#endif
