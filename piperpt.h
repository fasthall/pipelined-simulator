#ifndef PIPELINE_PIPELINE_REPORT_H
#define PIPELINE_PIPELINE_REPORT_H

typedef enum pipeline_stage_name
{
    EX_DM, 
    DM_WB
} Pipeline_StgName;

typedef struct pipieline_report
{
    unsigned char is_stalled;
    unsigned char is_flushed;
    unsigned char is_forward_ID_rs;
    unsigned int ID_rs;
    Pipeline_StgName ID_rs_from;
    unsigned char is_forward_ID_rt;
    unsigned int ID_rt;
    Pipeline_StgName ID_rt_from;
    unsigned char is_forward_EX_rs;
    unsigned int EX_rs;
    Pipeline_StgName EX_rs_from;
    unsigned char is_forward_EX_rt;
    unsigned int EX_rt;
    Pipeline_StgName EX_rt_from;
} Pipeline_rpt;

extern const char *g_pipeline_stage_name[];
extern Pipeline_rpt g_pipe_rpt;

// simulation use this
void report_Hazard_Flush( void );

// all except lui & J type may use this
void report_Hazard_Stall( void );

// Jr & Branches may call this
void report_Hazard_Forward_ID_Rs( unsigned int pIndex, Pipeline_StgName pStg );

// Branches may call this
void report_Hazard_Forward_ID_Rt( unsigned int pIndex, Pipeline_StgName pStg );

// I type except branches & lui, R type except JR & shifts may use this
void report_Hazard_Forward_EX_Rs( unsigned int pIndex, Pipeline_StgName pStg );

// I type except branches & lui, R type except JR may use this
void report_Hazard_Forward_EX_Rt( unsigned int pIndex, Pipeline_StgName pStg );

void clear_Report( void );

#endif
