#include "simulate.h"
#include "instruction.h"
#include "pipereg.h"
#include "hazard.h"

#define PIPE_WB 3
#define PIPE_DM 2
#define PIPE_EX 1

/**************************************************************************
* Check if register[pIndex] should be forwarded from EX/DM.
* If yes, extract the forwarded value from proper field into *pContent and
* return 1. Else return 0.
***************************************************************************/
unsigned char is_Forward_fEXDM( unsigned int pIndex, unsigned int *pContent )
{
    Instr_mnc mnc;
    unsigned int rw;
    unsigned int result;
    
    if( pIndex == 0 ) {
        result = 0;
    }
    else {
        rw = read_EXDM_Rw();
        mnc = g_pipeline_stage[PIPE_DM]->mnc;
        /* insert code here */
    } // end else( pIndex )
    
    return result;
}

/**************************************************************************
* Check if register[pIndex] should be forwarded from DM/WB.
* If yes, extract the forwarded value from proper field into *pContent and
* return 1. Else return 0.
***************************************************************************/
unsigned char is_Forward_fDMWB( unsigned int pIndex, unsigned int *pContent )
{
    Instr_mnc mnc;
    unsigned int rw;
    unsigned int result;
    
    if( pIndex == 0 ) {
        result = 0;
    }
    else {
        rw = read_DMWB_Rw();
        mnc = g_pipeline_stage[PIPE_WB]->mnc;
        /* insert code here */
    } // end else( pIndex )
    
    return result;
}

/**************************************************************************
* Check if conditional branches or jr will be stalled due to register[pIndex].
* If yes, return 1. Else return 0.
***************************************************************************/
unsigned char is_Stall_forBranchJr( unsigned int pIndex )
{
    Instr_mnc mnc;
    unsigned int rw;
    unsigned char result;
    
    // if to be evaluated is reg 0, no stall occurs
    if( pIndex == 0 ) {
        result = 0;
    }
    else {
        /* insert code here */
    } // end else( pIndex )
    
    return result;
}

/**************************************************************************
* Check if R/I type instructions, except conditional branches and jr,
* will be stalled due to register[pIndex].
* If yes, return 1. Else return 0.
***************************************************************************/
unsigned char is_Stall_forRI( unsigned int pIndex )
{
    Instr_mnc mnc;
    unsigned int rw;
    unsigned char result;
    
    // if to be evaluated is reg 0, no stall occurs
    if( pIndex == 0 ) {
        result = 0;
    }
    else {
        /* insert code here */
    }
    
    return result;
}
