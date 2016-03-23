#ifndef PIPELINE_INSTRUCTION_H
#define PIPELINE_INSTRUCTION_H

#define NUM_INSTR 30

enum instr_mnemonic{
ADD, SUB, AND, OR, XOR, 
NOR, SLT, SLL, SRL, SRA, 
JR, ADDI,LW, LH, LHU, 
LB, LBU,SW, SH, SB, 
LUI, ANDI, ORI, SLTI, BEQ, 
BNE, J, JAL, HALT, NOP
};
typedef enum instr_mnemonic Instr_mnc;
typedef void (*FuncPtr_rv_uint)( unsigned int );
typedef void (*FuncPtr_rv_v)( void );

typedef struct instr{
	unsigned char mnemonic[5];
	Instr_mnc mnc;
	FuncPtr_rv_uint ID;
	FuncPtr_rv_v EX;
	FuncPtr_rv_v DM;
	FuncPtr_rv_v WB;
} Instr;

extern Instr instruction[NUM_INSTR];

// if the instr takes no actions at ID stage, connect to this
void MIPS_ID_NoAction( unsigned int pBitStream );

void MIPS_ID_RTypeArithmetic( unsigned int pBitStream );
void MIPS_ID_RTypeBitShift( unsigned int pBitStream );
void MIPS_ID_RTypeJR( unsigned int pBitStream );
void MIPS_ID_ITypeArithmeticSigned( unsigned int pBitStream );
void MIPS_ID_ITypeArithmeticUnsigned( unsigned int pBitStream );
void MIPS_ID_ITypeLoad( unsigned int pBitStream );
void MIPS_ID_ITypeStore( unsigned int pBitStream );
void MIPS_ID_ITypeLUI( unsigned int pBitStream );
void MIPS_ID_ITypeBEQ( unsigned int pBitStream );
void MIPS_ID_ITypeBNE( unsigned int pBitStream );
void MIPS_ID_JTypeJ( unsigned int pBitStream );
void MIPS_ID_JTypeJAL( unsigned int pBitStream );

// if the instr takes no action at EX/DM/WB stage, connect to this
void MIPS_NoAction( void );

void MIPS_EX_Add( void );
void MIPS_EX_Sub( void );
void MIPS_EX_And( void );
void MIPS_EX_Or( void );
void MIPS_EX_Xor( void );
void MIPS_EX_Nor( void );
void MIPS_EX_Slt( void );
void MIPS_EX_Sll( void );
void MIPS_EX_Srl( void );
void MIPS_EX_Sra( void );
void MIPS_EX_Addi( void );
void MIPS_EX_Load( void );
void MIPS_EX_Store( void );
void MIPS_EX_Lui( void );
void MIPS_EX_Andi( void );
void MIPS_EX_Ori( void );
void MIPS_EX_Slti( void );
void MIPS_EX_Jal( void );

void MIPS_DM_ALU( void );
void MIPS_DM_Lw( void );
void MIPS_DM_Lh( void );
void MIPS_DM_Lhu( void );
void MIPS_DM_Lb( void );
void MIPS_DM_Lbu( void );
void MIPS_DM_Sw( void );
void MIPS_DM_Sh( void );
void MIPS_DM_Sb( void );
void MIPS_DM_Jal( void );

void MIPS_WB_ALU( void );
void MIPS_WB_Load( void );
void MIPS_WB_Jal( void );

void initInstrs();

#endif
