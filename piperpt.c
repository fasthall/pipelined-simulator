#include "piperpt.h"

const char *g_pipeline_stage_name[] = { "EX-DM", "DM-WB" };
Pipeline_rpt g_pipe_rpt;

// simulation use this
void report_Hazard_Flush( void )
{
    g_pipe_rpt.is_flushed = 1;
}

// all except lui & J type may use this
void report_Hazard_Stall( void )
{
    g_pipe_rpt.is_stalled = 1;
}

// Jr & Branches may call this
// Report that Rs (Register[pIndex]) is forwarded from pStg at ID
void report_Hazard_Forward_ID_Rs( unsigned int pIndex, Pipeline_StgName pStg )
{
    g_pipe_rpt.is_forward_ID_rs = 1;
    g_pipe_rpt.ID_rs = pIndex;
    g_pipe_rpt.ID_rs_from = pStg;
}

// Branches may call this
// Report that Rt (Register[pIndex]) is forwarded from pStg at ID
void report_Hazard_Forward_ID_Rt( unsigned int pIndex, Pipeline_StgName pStg )
{
    g_pipe_rpt.is_forward_ID_rt = 1;
    g_pipe_rpt.ID_rt = pIndex;
    g_pipe_rpt.ID_rt_from = pStg;
}

// I type except branches & lui, R type except JR & shifts may use this
// Report that Rs (Register[pIndex]) is forwarded from pStg at EX
void report_Hazard_Forward_EX_Rs( unsigned int pIndex, Pipeline_StgName pStg )
{
    g_pipe_rpt.is_forward_EX_rs = 1;
    g_pipe_rpt.EX_rs = pIndex;
    g_pipe_rpt.EX_rs_from = pStg;
}

// I type except branches & lui, R type except JR may use this
// Report that Rt (Register[pIndex]) is forwarded from pStg at EX
void report_Hazard_Forward_EX_Rt( unsigned int pIndex, Pipeline_StgName pStg )
{
    g_pipe_rpt.is_forward_EX_rt = 1;
    g_pipe_rpt.EX_rt = pIndex;
    g_pipe_rpt.EX_rt_from = pStg;
}

void clear_Report( void )
{
    g_pipe_rpt.is_stalled = 0;
    g_pipe_rpt.is_flushed = 0;
    g_pipe_rpt.is_forward_ID_rs = 0;
    g_pipe_rpt.ID_rs = 0;
    g_pipe_rpt.ID_rs_from = 0;
    g_pipe_rpt.is_forward_ID_rt = 0;
    g_pipe_rpt.ID_rt = 0;
    g_pipe_rpt.ID_rt_from = 0;
    g_pipe_rpt.is_forward_EX_rs = 0;
    g_pipe_rpt.EX_rs = 0;
    g_pipe_rpt.EX_rs_from = 0;
    g_pipe_rpt.is_forward_EX_rt = 0;
    g_pipe_rpt.EX_rt = 0;
    g_pipe_rpt.EX_rt_from = 0;
}
