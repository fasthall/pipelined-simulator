#ifndef PIPELINE_HAZARD_DETECTION_H
#define PIPELINE_HAZARD_DETECTION_H

// to return whether forwarded
unsigned char is_Forward_fEXDM( unsigned int pIndex, unsigned int *pContent );
unsigned char is_Forward_fDMWB( unsigned int pIndex, unsigned int *pContent );

// to return whether stalled
unsigned char is_Stall_forBranchJr( unsigned int pIndex );
unsigned char is_Stall_forRI( unsigned int pIndex );

#endif

