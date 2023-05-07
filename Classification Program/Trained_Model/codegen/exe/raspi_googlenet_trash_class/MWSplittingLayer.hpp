/* Copyright 2017 The MathWorks, Inc. */

#ifndef __SPLITTING_LAYER_HPP
#define __SPLITTING_LAYER_HPP

#include "cnn_api.hpp"

/**
  *  Codegen class for Splitting layer
  *  Splitting a tensor across channels
**/
class MWSplittingLayer : public MWCNNLayer
{
  public:
    MWSplittingLayer();
    ~MWSplittingLayer();

    void createSplittingLayer(MWTargetNetworkImpl* , MWTensorBase* tensorInput, ...);
    void propagateSize();

  private:
    int* channelSizes;
};

#endif
