#ifndef PIPELINE_SIMULATION_H
#define PIPELINE_SIMULATION_H

#include "instruction.h"
#include <stdio.h>

extern Instr *g_pipeline_stage[4];	// indicates instructions in ID|EX|DM|WB

void init( void );
void init_PipelineStages( void );	// for init() to call

void simulate( void );			// main body of simulation.

void decode( void );			// decode bitstream and execute according ID functions
void fetch( void );			// IF function & write pipe_reg_IFID
void update_Pipeline( void );		// update pipeline regs & array for Instr *

//To generate output
void dump_Regs( FILE *pOut );		// dump RegFile & PC
void report_Hazards( FILE *pOut );	// report pipeline contents & hazards

#endif
