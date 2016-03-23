#include "pipereg.h"

#define FRONT 0
#define REAR  1

Pipeline_PC g_pc;
Pipeline_IF_ID g_if_id;
Pipeline_ID_EX g_id_ex;
Pipeline_EX_DM g_ex_dm;
Pipeline_DM_WB g_dm_wb;

unsigned int read_PC( void )
{
    return g_pc.value[FRONT];
}

unsigned int read_IFID_Bitstream( void )
{
    return g_if_id.bitstream[FRONT];
}

unsigned int read_IDEX_RsContent( void )
{
    return g_id_ex.rs_content[FRONT];
}

unsigned int read_IDEX_RtContent( void )
{
    return g_id_ex.rt_content[FRONT];
}

unsigned int read_IDEX_Rs( void )
{
    return g_id_ex.rs[FRONT];
}

unsigned int read_IDEX_Rt( void )
{
    return g_id_ex.rt[FRONT];
}

unsigned int read_IDEX_Rw( void )
{
    return g_id_ex.rw[FRONT];
}

unsigned int read_IDEX_Imme( void )
{
    return g_id_ex.imme[FRONT];
}

unsigned int read_IDEX_PCAdvanced( void )
{
    return g_id_ex.PC_advanced[FRONT];
}

unsigned int read_EXDM_ALUout( void )
{
    return g_ex_dm.ALUout[FRONT];
}

unsigned int read_EXDM_RtContent( void )
{
    return g_ex_dm.rt_content[FRONT];
}

unsigned int read_EXDM_Rw( void )
{
    return g_ex_dm.rw[FRONT];
}

unsigned int read_EXDM_PCAdvanced( void )
{
    return g_ex_dm.PC_advanced[FRONT];
}

unsigned int read_DMWB_ALUout( void )
{
    return g_dm_wb.ALUout[FRONT];
}

unsigned int read_DMWB_DMout( void )
{
    return g_dm_wb.DMout[FRONT];
}

unsigned int read_DMWB_Rw( void )
{
    return g_dm_wb.rw[FRONT];
}

unsigned int read_DMWB_PCAdvanced( void )
{
    return g_dm_wb.PC_advanced[FRONT];
}

void write_PC( unsigned int pValue )
{
    g_pc.value[REAR] = pValue;
}

void write_IFID_Bitstream( unsigned int pValue )
{
    g_if_id.bitstream[REAR] = pValue;
}

void write_IDEX_RsContent( unsigned int pValue )
{
    g_id_ex.rs_content[REAR] = pValue;
}

void write_IDEX_RtContent( unsigned int pValue )
{
    g_id_ex.rt_content[REAR] = pValue;
}

void write_IDEX_Rs( unsigned int pValue )
{
    g_id_ex.rs[REAR] = pValue;
}

void write_IDEX_Rt( unsigned int pValue )
{
    g_id_ex.rt[REAR] = pValue;
}

void write_IDEX_Rw( unsigned int pValue )
{
    g_id_ex.rw[REAR] = pValue;
}

void write_IDEX_Imme( unsigned int pValue )
{
    g_id_ex.imme[REAR] = pValue;
}

void write_IDEX_PCAdvanced( unsigned int pValue )
{
    g_id_ex.PC_advanced[REAR] = pValue;
}

void write_EXDM_ALUout( unsigned int pValue )
{
    g_ex_dm.ALUout[REAR] = pValue;
}

void write_EXDM_RtContent( unsigned int pValue )
{
    g_ex_dm.rt_content[REAR] = pValue;
}

void write_EXDM_Rw( unsigned int pValue )
{
    g_ex_dm.rw[REAR] = pValue;
}

void write_EXDM_PCAdvanced( unsigned int pValue )
{
    g_ex_dm.PC_advanced[REAR] = pValue;
}

void write_DMWB_ALUout( unsigned int pValue )
{
    g_dm_wb.ALUout[REAR] = pValue;
}

void write_DMWB_DMout( unsigned int pValue )
{
    g_dm_wb.DMout[REAR] = pValue;
}

void write_DMWB_Rw( unsigned int pValue )
{
    g_dm_wb.rw[REAR] = pValue;
}

void write_DMWB_PCAdvanced( unsigned int pValue )
{
    g_dm_wb.PC_advanced[REAR] = pValue;
}

void update_PC( void )
{
    g_pc.value[FRONT] = g_pc.value[REAR];
    g_pc.value[REAR] = g_pc.value[FRONT] + 4;
}

void update_IFID( void )
{
    g_if_id.bitstream[FRONT] = g_if_id.bitstream[REAR];
}

void update_IDEX( void )
{
    g_id_ex.rs_content[FRONT] = g_id_ex.rs_content[REAR];
    g_id_ex.rt_content[FRONT] = g_id_ex.rt_content[REAR];
    g_id_ex.rs[FRONT] = g_id_ex.rs[REAR];
    g_id_ex.rt[FRONT] = g_id_ex.rt[REAR];
    g_id_ex.rw[FRONT] = g_id_ex.rw[REAR];
    g_id_ex.imme[FRONT] = g_id_ex.imme[REAR];
    g_id_ex.PC_advanced[FRONT] = g_id_ex.PC_advanced[REAR];
}

void update_EXDM( void )
{
    g_ex_dm.ALUout[FRONT] = g_ex_dm.ALUout[REAR];
    g_ex_dm.rt_content[FRONT] = g_ex_dm.rt_content[REAR];
    g_ex_dm.rw[FRONT] = g_ex_dm.rw[REAR];
    g_ex_dm.PC_advanced[FRONT] = g_ex_dm.PC_advanced[REAR];
}

void update_DMWB( void )
{
    g_dm_wb.ALUout[FRONT] = g_dm_wb.ALUout[REAR];
    g_dm_wb.DMout[FRONT] = g_dm_wb.DMout[REAR];
    g_dm_wb.rw[FRONT] = g_dm_wb.rw[REAR];
    g_dm_wb.PC_advanced[FRONT] = g_dm_wb.PC_advanced[REAR];
}

void init_PipelineRegs( unsigned int pInitPC )
{
    int i;
    
    g_pc.value[FRONT] = pInitPC;
    g_pc.value[REAR] = pInitPC + 4;

    for( i = 0; i < 2; ++i ) {    
        g_if_id.bitstream[i] = 0;
        
        g_id_ex.rs_content[i] = 0;
        g_id_ex.rt_content[i] = 0;
        g_id_ex.rs[i] = 0;
        g_id_ex.rt[i] = 0;
        g_id_ex.rw[i] = 0;
        g_id_ex.imme[i] = 0;
        g_id_ex.PC_advanced[i] = 0;
        
        g_ex_dm.ALUout[i] = 0;
        g_ex_dm.rt_content[i] = 0;
        g_ex_dm.rw[i] = 0;
        g_ex_dm.PC_advanced[i] = 0;
        
        g_dm_wb.ALUout[i] = 0;
        g_dm_wb.DMout[i] = 0;
        g_dm_wb.rw[i] = 0;
        g_dm_wb.PC_advanced[i] = 0;
    } // end for i
}
