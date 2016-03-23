#include "simulate.h"
#include "instruction.h"
#include "memory.h"
#include "regfile.h"
#include "pipereg.h"
#include "piperpt.h"

#include <stdio.h>
#include <stdlib.h>

#define PIPELINE_WB 3
#define PIPELINE_DM 2
#define PIPELINE_EX 1
#define PIPELINE_ID 0

Instr *g_pipeline_stage[4];
int g_cycle;
unsigned int g_bitstream_fetched;

void init( void )
{
    FILE *image = NULL;
    unsigned int regValue;
    int i;
    unsigned char c;

    g_cycle = 0;
    initInstrs();
    init_PipelineStages();
    clear_Report();

    image = fopen( "iimage.bin", "rb" );

    // initial PC
    regValue = 0;
    for( i = 0; i < 4; ++i ) {
	    c = fgetc( image );
	    regValue += c << ( 8 * i );
    }

    init_PipelineRegs( regValue );
    init_IM( image, regValue );
    fclose( image );

    image = fopen( "dimage.bin", "rb" );

    // initial $sp
    regValue = 0;
    for( i = 0; i < 4; ++i ) {
	    c = fgetc( image );
	    regValue += c << ( 8 * i );
    }

    init_RegFile( regValue );
    init_DM( image );
    fclose( image );
}

void init_PipelineStages( void )
{
    int i;

    for( i = 0; i < 4; ++i ) {
        g_pipeline_stage[i] = &instruction[NOP];
    }
}

void simulate( void )
{
    FILE *snp = NULL;

    snp = fopen( "snapshot.rpt", "w" );

    while( g_pipeline_stage[PIPELINE_WB]->mnc != HALT ) {
        // dump the contents of regs before execution
        dump_Regs( snp );

        // execute the whole pipeline from the end to the beginning
        (*(g_pipeline_stage[PIPELINE_WB]->WB))();
        (*(g_pipeline_stage[PIPELINE_DM]->DM))();
        (*(g_pipeline_stage[PIPELINE_EX]->EX))();
        decode();
        fetch();

        // report all the hazards encountered
        report_Hazards( snp );

        // flow the pipeline for the next cycle
        update_Pipeline();
        clear_Report();
        g_cycle++;
    } // end while

    // For final state
    dump_Regs( snp );
    report_Hazards( snp );

//    dump_DM();

    fclose( snp );
}

void dump_Regs( FILE *pOut )
{
    int i;

    fprintf( pOut, "cycle %d\n", g_cycle );

    for( i = 0; i < NUM_REG; ++i ) {
        fprintf( pOut, "$%02d: 0x%08X\n", i, read_Reg(i) );
    }

    fprintf( pOut, "PC: 0x%08X\n", read_PC() );
}

void decode( void )
{
    Instr_mnc instr_SN;
    unsigned char opcode, func;
    unsigned int bitstream;

    /* Take the bitstream from pipeline register and decode it */

    /* Insert code here */
    bitstream = read_IFID_Bitstream();
	opcode = (bitstream >> 26) % 64; /* 6 bits */
	if (opcode == 0x00)
	{
		funct = bitstream % 64; /* 6 bits */
        switch (func)
        {
            case 0x20: /* ADD */
                instr_SN = ADD;
                break;
            case 0x22: /* SUB */
                instr_SN = SUB;
                break;
            case 0x24: /* AND */
                instr_SN = AND;
                break;
            case 0x25: /* OR */
                instr_SN = OR;
                break;
            case 0x26: /* XOR */
                instr_SN = XOR;
                break;
            case 0x27: /* NOR */
                instr_SN = NOR;
                break;
            case 0x2A: /* SLT */
                instr_SN = SLT;
                break;
            case 0x00: /* SLL */
                instr_SN = SLL;
                break;
            case 0x02: /* SRL */
                instr_SN = SRL;
                break;
            case 0x03: /* SRA */
                instr_SN = SRA;
                break;
            case 0x08: /* JR */
                instr_SN = JR;
                break;
            default:
                instr_SN = NOP;
                break;
        }
	}
	else if (opcode == 0x3F)
	{
		instr_SN = HALT;
		/*g_pipeline_stage[PIPELINE_WB]->mnc = HALT;*/
	}
	else
	{
        switch (opcode)
        {
            case 0x08: /* ADDI */
                instr_SN = ADDI;
                break;
            case 0x21: /* LH */
                instr_SN = LH;
                break;
            case 0x20: /* LB */
                instr_SN = LB;
                break;
            case 0x0A: /* SLTI */
                instr_SN = SLTI;
                break;
            case 0x25: /* LHU */
                instr_SN = LHU;
                break;
            case 0x24: /* LBU */
                instr_SN = LBU;
                break;
            case 0x0C: /* ANDI */
                instr_SN = ANDI;
                break;
            case 0x0D: /* ORI */
                instr_SN = ORI;
                break;
            case 0x23: /* LW */
                instr_SN = LW;
                break;
            case 0x2B: /* SW */
                instr_SN = SW;
                break;
            case 0x2B: /* SH */
                instr_SN = SH;
                break;
            case 0x2B: /* SB */
                instr_SN = SB;
                break;
            case 0x0F: /* LUI */
                instr_SN = LUI;
                break;
            case 0x04: /* BEQ */
                instr_SN = BEQ;
                break;
            case 0x05: /* BNE */
                instr_SN = BNE;
                break;
            case 0x02: /* J */
                instr_SN = J;
                break;
            case 0x03: /* JAL */
                instr_SN = JAL;
                break;
            default:
                instr_SN = NOP;
                break;
        }
	}

    g_pipeline_stage[PIPELINE_ID] = &instruction[instr_SN];
    (*(g_pipeline_stage[PIPELINE_ID]->ID))( bitstream );
}

void fetch( void )
{
    unsigned int PC;

    /*fetch bitstream from IM indicated by PC*/

    /* insert code here */
    PC = read_PC(); /* uncertain */
    g_bitstream_fetched = read_IM( PC );

    if( g_pipe_rpt.is_stalled ) { // frozen PC and IF/ID
        /* insert code here */
    }
    else if( g_pipe_rpt.is_flushed ) { // flush IF/ID
        /* insert code here */
    }
    else { // update IF/ID by fetched instruction
        /* insert code here */
    }
}

void report_Hazards( FILE *pOut )
{
    fprintf( pOut, "IF: 0x%08X", g_bitstream_fetched );
    if( g_pipe_rpt.is_stalled ) {
        fprintf( pOut, " to_be_stalled" );
    }
    else if( g_pipe_rpt.is_flushed ) {
        fprintf( pOut, " to_be_flushed" );
    }
    fprintf( pOut, "\n" );

    fprintf( pOut, "ID: %s", g_pipeline_stage[PIPELINE_ID]->mnemonic );
    if( g_pipe_rpt.is_stalled ) {
        fprintf( pOut, " to_be_stalled" );
    }
    else {
        if( g_pipe_rpt.is_forward_ID_rs ) {
            fprintf( pOut, " fwd_%s_rs_$%d",
                    g_pipeline_stage_name[g_pipe_rpt.ID_rs_from],
                    g_pipe_rpt.ID_rs );
        }
        if( g_pipe_rpt.is_forward_ID_rt ) {
            fprintf( pOut, " fwd_%s_rt_$%d",
                    g_pipeline_stage_name[g_pipe_rpt.ID_rt_from],
                    g_pipe_rpt.ID_rt );
        }
    }
    fprintf( pOut, "\n" );

    fprintf( pOut, "EX: %s", g_pipeline_stage[PIPELINE_EX]->mnemonic );
    if( g_pipe_rpt.is_forward_EX_rs ) {
        fprintf( pOut, " fwd_%s_rs_$%d",
                g_pipeline_stage_name[g_pipe_rpt.EX_rs_from],
                g_pipe_rpt.EX_rs );
        }
    if( g_pipe_rpt.is_forward_EX_rt ) {
        fprintf( pOut, " fwd_%s_rt_$%d",
                g_pipeline_stage_name[g_pipe_rpt.EX_rt_from],
                g_pipe_rpt.EX_rt );
    }
    fprintf( pOut, "\n" );

    fprintf( pOut, "DM: %s\n", g_pipeline_stage[PIPELINE_DM]->mnemonic );

    fprintf( pOut, "WB: %s\n\n\n", g_pipeline_stage[PIPELINE_WB]->mnemonic );
}

/***************************************************************************
* To mimic the arrival of positive clock edge.
* Advance instructions in pipeline if possible, or take proper procedures
* to stall.
* Update pipeline registers and PC.
***************************************************************************/
void update_Pipeline( void )
{
    /* insert code here */
}
