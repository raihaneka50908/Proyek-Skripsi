/* Copyright 2017 The MathWorks, Inc. */

#include "MWSplittingLayer.hpp"
#include "MWSplittingLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"

#include <stdarg.h>
#include <cassert>

MWSplittingLayer::MWSplittingLayer()
{
}

MWSplittingLayer::~MWSplittingLayer()
{    
}

void MWSplittingLayer::createSplittingLayer(MWTargetNetworkImpl* ntwk_impl, MWTensorBase* tensorInput, ...)
{
#if defined(MW_TARGET_TYPE_CUDNN) || defined(MW_TARGET_TYPE_MKLDNN) || defined(MW_TARGET_TYPE_ARMNEON)
    setInputTensor(tensorInput);

    va_list args;
    va_start(args, tensorInput);
    
    int numOutputs = va_arg(args, int);
    int* channelWidths = new int[numOutputs];
    
    for (int i = 0; i < numOutputs; i++)
    {
        channelWidths[i] = va_arg(args, int);
    }

    channelSizes = channelWidths;

    //Why is numoutputs appended instead of prepended
    int numOutputs_blah = va_arg(args,int);
    
    //Adding this check which should always be true to avoid MSVC warning about unreferenced local variable
    assert(numOutputs == numOutputs_blah);
    
    std::vector<int> bufIndices(numOutputs, -1);
    //bufIndices points to memory buffer used by corresponding output port after buffer reuse transform
    for (int i = 0; i < numOutputs; i++)
    {
        bufIndices[i] = va_arg(args,int);        
    }

    for(int i = 0; i < numOutputs; i++)
    {
        allocateOutputTensor<float>(-1, -1, -1, -1, -1, NULL, i);
        getOutputTensor(i)->setopBufIndex(bufIndices[i]);
    }
    
    m_impl = new MWSplittingLayerImpl(this, ntwk_impl, numOutputs, channelWidths);
    
#else
    va_list args;
    va_start(args, tensorInput);
    
    int numOutputs = va_arg(args, int);
    int* channelWidths = new int[numOutputs];
    
    for (int i = 0; i < numOutputs; i++)
    {
        channelWidths[i] = va_arg(args, int);
    }

    //Why is numoutputs appended instead of prepended
    int numOutputs_blah = va_arg(args,int);
    
    //Adding this check which should always be true to avoid MSVC warning about unreferenced local variable
    assert(numOutputs == numOutputs_blah);
    
    std::vector<int> bufIndices(numOutputs, -1);
    //bufIndices points to memory buffer used by corresponding output port after buffer reuse transform
    for (int i = 0; i < numOutputs;i++)
    {
        bufIndices[i] = va_arg(args,int);        
    }
    
    
    setInputTensor(tensorInput);
    
    for(int i = 0; i < numOutputs; i++)
    {
        int numOutputFeatures = channelWidths[i]; 
        allocateOutputTensor<float>(getInputTensor(0)->getHeight(),
                                    getInputTensor(0)->getWidth(),
                                    numOutputFeatures,
                                    getInputTensor(0)->getBatchSize(),
                                    getInputTensor(0)->getSequenceLength(),
                                    NULL,
                                    i);
        assert(getOutputTensor(i)->getSequenceLength() == 1);
    }
                                                                                                      
    m_impl = new MWSplittingLayerImpl(this, ntwk_impl, numOutputs, channelWidths, bufIndices);
#endif
}

void MWSplittingLayer::propagateSize()
{
#if defined(MW_TARGET_TYPE_CUDNN) || defined(MW_TARGET_TYPE_MKLDNN) || defined(MW_TARGET_TYPE_ARMNEON)
    assert(getInputTensor()->getSequenceLength() == 1);

    for(int i = 0; i < getNumOutputs(); i++)
    {
        int numOutputFeatures = channelSizes[i]; 
        resizeOutputTensor(getInputTensor(0)->getHeight(),
                           getInputTensor(0)->getWidth(),
                           numOutputFeatures,
                           getInputTensor(0)->getBatchSize(),
                           getInputTensor(0)->getSequenceLength(),
                           i);
    }

    m_impl->propagateSize();
#endif
}
