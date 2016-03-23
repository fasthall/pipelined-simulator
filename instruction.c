#include "instruction.h"
#include "arithmetic.h"
#include "piperpt.h"
#include "memory.h"
#include "regfile.h"
#include "hazard.h"

Instr instruction[NUM_INSTR];

void initInstrs()
{
    sprintf(instruction[ADD].mnemonic,"ADD");
    instruction[ADD].mnc = ADD;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Add;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SUB].mnemonic,"SUB");
	instruction[SUB].mnc = SUB;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Sub;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[AND].mnemonic,"AND");
	instruction[AND].mnc = AND;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_And;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[OR].mnemonic,"OR");
	instruction[OR].mnc = OR;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Or;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[XOR].mnemonic,"XOR");
	instruction[XOR].mnc = XOR;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Xor;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[NOR].mnemonic,"NOR");
	instruction[NOR].mnc = NOR;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Nor;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SLT].mnemonic,"SLT");
	instruction[SLT].mnc = SLT;
	instruction[ADD].ID = MIPS_ID_RTypeArithmetic;
	instruction[ADD].EX = MIPS_EX_Slt;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SLL].mnemonic,"SLL");
	instruction[SLL].mnc = SLL;
	instruction[ADD].ID = MIPS_ID_RTypeBitShift;
	instruction[ADD].EX = MIPS_EX_Sll;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SRL].mnemonic,"SRL");
	instruction[SRL].mnc = SRL;
	instruction[ADD].ID = MIPS_ID_RTypeBitShift;
	instruction[ADD].EX = MIPS_EX_Srl;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SRA].mnemonic,"SRA");
	instruction[SRA].mnc = SRA;
	instruction[ADD].ID = MIPS_ID_RTypeBitShift;
	instruction[ADD].EX = MIPS_EX_Sra;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[JR].mnemonic,"JR");
	instruction[JR].mnc = JR;
	instruction[ADD].ID = MIPS_ID_RTypeJR;
	instruction[ADD].EX = MIPS_NoAction;
	instruction[ADD].DM = MIPS_NoAction;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[ADDI].mnemonic,"ADDI");
	instruction[ADDI].mnc = ADDI;
	instruction[ADD].ID = MIPS_ID_ITypeArithmeticSigned;
	instruction[ADD].EX = MIPS_EX_Addi;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[SLTI].mnemonic,"SLTI"); /* start */
	instruction[SLTI].mnc = SLTI;
	instruction[ADD].ID = MIPS_ID_ITypeArithmeticSigned;
	instruction[ADD].EX = MIPS_EX_Slti;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[ANDI].mnemonic,"ANDI");
	instruction[ANDI].mnc = ANDI;
	instruction[ADD].ID = MIPS_ID_ITypeArithmeticUnsigned;
	instruction[ADD].EX = MIPS_EX_Andi;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[ORI].mnemonic,"ORI");
	instruction[ORI].mnc = ORI;
	instruction[ADD].ID = MIPS_ID_ITypeArithmeticUnsigned;
	instruction[ADD].EX = MIPS_EX_Ori;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[LW].mnemonic,"LW");
	instruction[LW].mnc = LW;
	instruction[ADD].ID = MIPS_ID_ITypeLoad;
	instruction[ADD].EX = MIPS_EX_Load;
	instruction[ADD].DM = MIPS_DM_Lw;
	instruction[ADD].WB = MIPS_WB_Load;

	sprintf(instruction[LH].mnemonic,"LH");
	instruction[LH].mnc = LH;
	instruction[ADD].ID = MIPS_ID_ITypeLoad;
	instruction[ADD].EX = MIPS_EX_Load;
	instruction[ADD].DM = MIPS_DM_Lh;
	instruction[ADD].WB = MIPS_WB_Load;

	sprintf(instruction[LHU].mnemonic,"LHU");
	instruction[LHU].mnc = LHU;
	instruction[ADD].ID = MIPS_ID_ITypeLoad;
	instruction[ADD].EX = MIPS_EX_Load;
	instruction[ADD].DM = MIPS_DM_Lhu;
	instruction[ADD].WB = MIPS_WB_Load;

	sprintf(instruction[LB].mnemonic,"LB");
	instruction[LB].mnc = LB;
	instruction[ADD].ID = MIPS_ID_ITypeLoad;
	instruction[ADD].EX = MIPS_EX_Load;
	instruction[ADD].DM = MIPS_DM_Lb;
	instruction[ADD].WB = MIPS_WB_Load;

	sprintf(instruction[LBU].mnemonic,"LBU");
	instruction[LBU].mnc = LBU;
	instruction[ADD].ID = MIPS_ID_ITypeLoad;
	instruction[ADD].EX = MIPS_EX_Load;
	instruction[ADD].DM = MIPS_DM_Lbu;
	instruction[ADD].WB = MIPS_WB_Load;

	sprintf(instruction[SW].mnemonic,"SW");
    instruction[SW].mnc = SW;
    instruction[ADD].ID = MIPS_ID_ITypeStore;
	instruction[ADD].EX = MIPS_EX_Store;
	instruction[ADD].DM = MIPS_DM_Sw;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[SH].mnemonic,"SH");
	instruction[SH].mnc = SH;
	instruction[ADD].ID = MIPS_ID_ITypeStore;
	instruction[ADD].EX = MIPS_EX_Store;
	instruction[ADD].DM = MIPS_DM_Sh;
	instruction[ADD].WB = MIPS_ID_NoAction;

	sprintf(instruction[SB].mnemonic,"SB");
	instruction[SB].mnc = SB;
	instruction[ADD].ID = MIPS_ID_ITypeStore;
	instruction[ADD].EX = MIPS_EX_Store;
	instruction[ADD].DM = MIPS_DM_Sb;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[LUI].mnemonic,"LUI");
	instruction[LUI].mnc = LUI;
	instruction[ADD].ID = MIPS_ID_ITypeLUI;
	instruction[ADD].EX = MIPS_EX_Lui;
	instruction[ADD].DM = MIPS_DM_ALU;
	instruction[ADD].WB = MIPS_WB_ALU;

	sprintf(instruction[BEQ].mnemonic,"BEQ");
	instruction[BEQ].mnc = BEQ;
	instruction[ADD].ID = MIPS_ID_ITypeBEQ;
	instruction[ADD].EX = MIPS_NoAction;
	instruction[ADD].DM = MIPS_NoAction;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[BNE].mnemonic,"BNE");
	instruction[BNE].mnc = BNE;
	instruction[ADD].ID = MIPS_ID_ITypeBNE;
	instruction[ADD].EX = MIPS_NoAction;
	instruction[ADD].DM = MIPS_NoAction;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[J].mnemonic,"J");
	instruction[J].mnc = J;
	instruction[ADD].ID = MIPS_ID_JTypeJ;
	instruction[ADD].EX = MIPS_NoAction;
	instruction[ADD].DM = MIPS_NoAction;
	instruction[ADD].WB = MIPS_NoAction;

	sprintf(instruction[JAL].mnemonic,"JAL");
	instruction[JAL].mnc = JAL;
	instruction[ADD].ID = MIPS_ID_JTypeJAL;
	instruction[ADD].EX = MIPS_EX_Jal;
	instruction[ADD].DM = MIPS_DM_Jal;
	instruction[ADD].WB = MIPS_WB_Jal;

	sprintf(instruction[HALT].mnemonic,"HALT");
	instruction[HALT].mnc = HALT;
	instruction[HALT].ID = MIPS_ID_NoAction;
	instruction[HALT].EX = MIPS_NoAction;
	instruction[HALT].DM = MIPS_NoAction;
	instruction[HALT].WB = MIPS_NoAction;

	sprintf(instruction[NOP].mnemonic,"NOP");
	instruction[NOP].mnc = NOP;
	instruction[NOP].ID = MIPS_ID_NoAction;
	instruction[NOP].EX = MIPS_NoAction;
	instruction[NOP].DM = MIPS_NoAction;
	instruction[NOP].WB = MIPS_NoAction;
}

void MIPS_ID_NoAction( unsigned int pBitStream )
{
}

void MIPS_ID_RTypeArithmetic( unsigned int pBitStream )
{
    unsigned int Rs, Rt, Rd;
    /* insert code here */
    unsigned int Rs_content, Rt_content;
    Rs = (pBitStream >> 21) % 32;
    Rt = (pBitStream >> 16) % 32;
	Rd = (pBitStream >> 11) % 32;
	if (is_Forward_fEXDM(Rs, &Rs_content)) {
        report_Hazard_Forward_EX_Rs(Rs, EX_DM);
        write_IDEX_RsContent(Rs_content);
    }
    else
        write_IDEX_RsContent(read_Reg(Rs));

    if (is_Forward_fEXDM(Rt, &Rt_content)) {
        report_Hazard_Forward_EX_Rs(Rt, EX_DM);
        write_IDEX_RsContent(Rt_content);
    }

    write_IDEX_Rs(Rs);
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rd);
}

void MIPS_ID_RTypeBitShift( unsigned int pBitStream )
{
    unsigned int Rt, Rd, shamt;
    /* insert code here */
    Rt = (pBitStream >> 16) % 32;
    Rd = (pBitStream >> 11) % 32;
    shamt = (pBitStream >> 6) % 32;
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rd);
    write_IDEX_RtContent(read_Reg(Rt));
    write_IDEX_Imme(shamt);
}

void MIPS_ID_RTypeJR( unsigned int pBitStream )
{
    unsigned int Rs;
    unsigned int Rs_content;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
    Rs_content = read_Reg(Rs);
    write_PC(Rs_content);
}

void MIPS_ID_ITypeArithmeticSigned( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
    write_IDEX_Rs(Rs);
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rt);
    write_IDEX_Imme(imme);
}

void MIPS_ID_ITypeArithmeticUnsigned( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = pBitStream % 65536; /* 16 bits */
    write_IDEX_Rs(Rs);
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rt);
    write_IDEX_Imme(imme);
}

void MIPS_ID_ITypeLoad( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
    write_IDEX_Rs(Rs);
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rt);
    write_IDEX_Imme(imme);
}

void MIPS_ID_ITypeStore( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
    write_IDEX_Rs(Rs);
    write_IDEX_Rt(Rt);
    write_IDEX_Imme(imme);
}

void MIPS_ID_ITypeLUI( unsigned int pBitStream )
{
    unsigned int Rt, imme;
    /* insert code here */
    Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
    write_IDEX_Rt(Rt);
    write_IDEX_Rw(Rt);
    write_IDEX_Imme(imme);
}

void MIPS_ID_ITypeBEQ( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    unsigned int Rs_content, Rt_content;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
	Rs_content = read_Reg(Rs);
    Rt_content = read_Reg(Rt);
    if (Rs_content == Rt_content) {
        write_PC(read_PC() + 4 * imme);
    }
}

void MIPS_ID_ITypeBNE( unsigned int pBitStream )
{
    unsigned int Rs, Rt, imme;
    unsigned int Rs_content, Rt_content;
    /* insert code here */
    Rs = (pBitStream >> 21) % 32;
	Rt = (pBitStream >> 16) % 32;
	imme = signExtend(pBitStream % 65536, 16); /* 16 bits */
	Rs_content = read_Reg(Rs);
    Rt_content = read_Reg(Rt);
    if (Rs_content != Rt_content) {
        write_PC(read_PC() + 4 * imme);
    }
}

void MIPS_ID_JTypeJ( unsigned int pBitStream )
{
    unsigned int address;
    /* insert code here */
    address = pBitStream % 65536; /* 16 bits */
    write_PC(address * 4);
}

void MIPS_ID_JTypeJAL( unsigned int pBitStream )
{
    unsigned int address;
    /* insert code here */
    address = pBitStream % 65536; /* 16 bits */
    write_IDEX_Imme(address);
    write_IDEX_PCAdvanced(read_PC());
    write_IDEX_Rw(31);
}

void MIPS_NoAction( void )
{
}

void MIPS_EX_Add( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content + Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Sub( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content - Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_And( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content & Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Or( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content | Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Xor( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content ^ Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Nor( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(~(Rs_content + Rt_content));
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Slt( void )
{
    unsigned int Rs_content, Rt_content;
    unsigned int Rs, Rt;
    /* insert code here */
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    write_EXDM_ALUout(Rs_content < Rt_content);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Sll( void )
{
    unsigned int Rt_content, imme;
    unsigned int Rt;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rt_content = read_IDEX_RtContent();
    Rt = read_IDEX_Rt();
    write_EXDM_ALUout(Rt_content << imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Srl( void )
{
    unsigned int Rt_content, imme;
    unsigned int Rt;
    /* insert code here */
    imme = read_IDEX_Imme() % 65536;
    Rt_content = read_IDEX_RtContent();
    Rt = read_IDEX_Rt();
    write_EXDM_ALUout(Rt_content >> imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Sra( void )
{
    unsigned int Rt_content, imme;
    unsigned int Rt;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rt_content = read_IDEX_RtContent();
    Rt = read_IDEX_Rt();
    write_EXDM_ALUout(Rt_content >> imme); /* ??? */
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Addi( void )
{
    unsigned int Rs_content, imme;
    unsigned int Rs;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    Rs = read_IDEX_Rs();
    write_EXDM_ALUout(Rs_content + imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Load( void )
{
    unsigned int Rs_content, imme;
    unsigned int Rs;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    write_EXDM_ALUout(Rs_content + 4 * imme);
    write_EXDM_Rw(read_IDEX_Rw());
    write_EXDM_RtContent(read_IDEX_RtContent());
}

void MIPS_EX_Store( void )
{
    unsigned int Rs_content, Rt_content, imme;
    unsigned int Rs, Rt;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    Rt_content = read_IDEX_RtContent();
    Rs = read_IDEX_Rs();
    Rt = read_IDEX_Rt();
    write_EXDM_Rw(read_IDEX_Rw() + 4 * imme);
    write_EXDM_RtContent(Rt_content);
}

void MIPS_EX_Lui( void )
{
    unsigned int imme;
    /* insert code here */
    imme = read_IDEX_Imme();
    write_EXDM_ALUout(imme << 16); /* ??? */
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Andi( void )
{
    unsigned int Rs_content, imme;
    unsigned int Rs;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    Rs = read_IDEX_Rs();
    write_EXDM_ALUout(Rs_content & imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Ori( void )
{
    unsigned int Rs_content, imme;
    unsigned int Rs;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    Rs = read_IDEX_Rs();
    write_EXDM_ALUout(Rs_content | imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Slti( void )
{
    unsigned int Rs_content, imme;
    unsigned int Rs;
    /* insert code here */
    imme = read_IDEX_Imme();
    Rs_content = read_IDEX_RsContent();
    Rs = read_IDEX_Rs();
    write_EXDM_ALUout(Rs_content < imme);
    write_EXDM_Rw(read_IDEX_Rw());
}

void MIPS_EX_Jal( void )
{
    /* insert code here */
    write_EXDM_Rw(read_IDEX_Rw());
    write_EXDM_ALUout(4 * read_IDEX_imme());
    write_EXDM_PCAdvanced(read_IDEX_PCAdvanced()); /* ??? */
}

void MIPS_DM_ALU( void )
{
    /* insert code here */
    write_DMWB_ALUout(read_EXDM_ALUout());
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Lw( void )
{
    /* insert code here */
    unsigned int address;
    address = read_EXDM_ALUout();
    write_DMWB_DMout(read_WordDM(address));
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Lh( void )
{
    /* insert code here */
    unsigned int address;
    address = read_EXDM_ALUout();
    write_DMWB_DMout(read_HalfDM(address));
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Lhu( void )
{
    /* insert code here */
    unsigned int address;
    address = read_EXDM_ALUout() % 65536;
    write_DMWB_DMout(address);
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Lb( void )
{
    /* insert code here */
    unsigned int address;
    address = read_EXDM_ALUout();
    write_DMWB_DMout(read_ByteDM(address));
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Lbu( void )
{
    /* insert code here */
    unsigned int address;
    address = read_EXDM_ALUout() % 65536;
    write_DMWB_DMout(read_ByteDM(address));
    write_DMWB_Rw(read_EXDM_Rw());
}

void MIPS_DM_Sw( void )
{
    /* insert code here */
    write_WordDM(read_EXDM_Rw(), read_EXDM_RtContent());
}

void MIPS_DM_Sh( void )
{
    /* insert code here */
    write_HalfDM(read_EXDM_Rw(), read_EXDM_RtContent());
}

void MIPS_DM_Sb( void )
{
    /* insert code here */
    write_ByteDM(read_EXDM_Rw(), read_EXDM_RtContent());
}

void MIPS_DM_Jal( void )
{
    /* insert code here */
    write_PC(read_EXDM_ALUout());
    write_DMWB_Rw(read_EXDM_Rw());
    write_DMWB_PCAdvanced(read_EXDM_PCAdvanced());
}

void MIPS_WB_ALU( void )
{
    /* insert code here */
    write_Reg(read_DMWB_Rw(), read_DMWB_ALUout());
}

void MIPS_WB_Load( void )
{
    /* insert code here */
    write_Reg(read_DMWB_Rw(), read_DMWB_DMout());
}

void MIPS_WB_Jal( void )
{
    /* insert code here */
    write_Reg(read_DMWB_Rw(), read_DMWB_PCAdvanced());
    write_PC(read_EXDM_PCAdvanced());
}
