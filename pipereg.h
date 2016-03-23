#ifndef PIPELINE_PIPELINE_REGISTERS_H
#define PIPELINE_PIPELINE_REGISTERS_H

typedef struct pipeline_pc
{
    unsigned int value[2];
} Pipeline_PC;

typedef struct pipeline_if_id
{
    unsigned int bitstream[2];
} Pipeline_IF_ID;

typedef struct pipeline_id_ex
{
    unsigned int rs_content[2];
    unsigned int rt_content[2];
    unsigned int rs[2];
    unsigned int rt[2];
    unsigned int rw[2];                // maybe rt or rd
    unsigned int imme[2];              // maybe imme for ALU/branches/load/store, shamt for shift
    unsigned int PC_advanced[2];       // for jal
} Pipeline_ID_EX;

typedef struct pipeline_ex_dm
{
    unsigned int ALUout[2];
    unsigned int rt_content[2];        // for store
    unsigned int rw[2];
    unsigned int PC_advanced[2];
} Pipeline_EX_DM;

typedef struct pipeline_dm_wb
{
    unsigned int ALUout[2];
    unsigned int DMout[2];
    unsigned int rw[2];
    unsigned int PC_advanced[2];
} Pipeline_DM_WB;

unsigned int read_PC( void );

unsigned int read_IFID_Bitstream( void );

unsigned int read_IDEX_RsContent( void );
unsigned int read_IDEX_RtContent( void );
unsigned int read_IDEX_Rs( void );
unsigned int read_IDEX_Rt( void );
unsigned int read_IDEX_Rw( void );
unsigned int read_IDEX_Imme( void );
unsigned int read_IDEX_PCAdvanced( void );

unsigned int read_EXDM_ALUout( void );
unsigned int read_EXDM_RtContent( void );
unsigned int read_EXDM_Rw( void );
unsigned int read_EXDM_PCAdvanced( void );

unsigned int read_DMWB_ALUout( void );
unsigned int read_DMWB_DMout( void );
unsigned int read_DMWB_Rw( void );
unsigned int read_DMWB_PCAdvanced( void );

void write_PC( unsigned int pValue );

void write_IFID_Bitstream( unsigned int pValue );

void write_IDEX_RsContent( unsigned int pValue );
void write_IDEX_RtContent( unsigned int pValue );
void write_IDEX_Rs( unsigned int pValue );
void write_IDEX_Rt( unsigned int pValue );
void write_IDEX_Rw( unsigned int pValue );
void write_IDEX_Imme( unsigned int pValue );
void write_IDEX_PCAdvanced( unsigned int pValue );

void write_EXDM_ALUout( unsigned int pValue );
void write_EXDM_RtContent( unsigned int pValue );
void write_EXDM_Rw( unsigned int pValue );
void write_EXDM_PCAdvanced( unsigned int pValue );

void write_DMWB_ALUout( unsigned int pValue );
void write_DMWB_DMout( unsigned int pValue );
void write_DMWB_Rw( unsigned int pValue );
void write_DMWB_PCAdvanced( unsigned int pValue );

void update_PC( void );
void update_IFID( void );
void update_IDEX( void );
void update_EXDM( void );
void update_DMWB( void );

void init_PipelineRegs( unsigned int pInitPC );

#endif
