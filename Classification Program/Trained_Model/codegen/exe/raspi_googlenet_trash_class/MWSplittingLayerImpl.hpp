/* Copyright 2018-2019 The MathWorks, Inc. */

#ifndef __SPLITTING_LAYET_IMPL_HPP
#define __SPLITTING_LAYET_IMPL_HPP

#include "MWCNNLayerImpl.hpp"

#if MW_SPLIT_TAP
extern void mw_interm_tap(float* memBuf int size, int count);
extern int tap_count;
#endif

/**
 *  Codegen class for Splitting Layer
 **/
class MWCNNLayer;
class MWTargetNetworkImpl;
class MWSplittingLayerImpl  : public MWCNNLayerImpl {
  public:
    MWSplittingLayerImpl (MWCNNLayer*, MWTargetNetworkImpl*, int, int*);
    ~MWSplittingLayerImpl ();

  private:
    void propagateSize(){};
    void predict();
    
    
    int gNROjwaqhxDPvBWUCUcQ;

};



#endif
