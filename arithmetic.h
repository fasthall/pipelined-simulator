
unsigned int signExtend( unsigned int bitstream, unsigned int src_len ){
    unsigned int signbit;
    unsigned int mask = 0xFFFFFFFF;
    
    signbit = bitstream >> (src_len-1);
    if( signbit ){
        bitstream |= ( ( mask >> src_len ) << src_len );
    }
    return bitstream;
}
