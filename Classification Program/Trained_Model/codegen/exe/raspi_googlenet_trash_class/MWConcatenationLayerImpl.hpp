/* Copyright 2019 The MathWorks, Inc. */

#ifndef __CONCAT_LAYER_IMPL_HPP
#define __CONCAT_LAYER_IMPL_HPP

#include "MWCNNLayerImpl.hpp"
#include <unordered_map>


#if MW_CONCATENATE_TAP
extern void mw_interm_tap(arm_compute::Tensor& armTensor, int size, int count);
extern int tap_count;
#endif

/**
 *  Codegen class for Concat Layer
 *  Concatenates inputs along three dimensions (height dimension, width dimension, channel
 *dimension)
 **/
#include "MWTargetNetworkImpl.hpp"
class MWConcatenationLayerImpl : public MWCNNLayerImpl {
  public:
    MWConcatenationLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWConcatenationLayerImpl();

  private:
#if defined(USE_18_05_LIBRARY)
    std::unique_ptr<arm_compute::NEDepthConcatenateLayer> m_depthConcatenateLayer;
#else
#if defined(USE_19_05_LIBRARY)
    const std::unordered_map<int, size_t> concatdimensionmap{{1, 1}, {2, 0}, { 3, 2 }};
#else
    const std::unordered_map<int, arm_compute::DataLayoutDimension> concatdimensionmap{
        {2, arm_compute::DataLayoutDimension::WIDTH},
        {3, arm_compute::DataLayoutDimension::CHANNEL}};
#endif
    std::unique_ptr<arm_compute::NEConcatenateLayer> m_concatenateLayer;
    std::unique_ptr<arm_compute::NEDepthConcatenateLayer> m_depthConcatenateLayer;
#endif
    std::vector<std::unique_ptr<arm_compute::NEReshapeLayer>> m_reshapeKernel;

    std::vector<bool> m_isIpArmTensorReshaped;
    std::vector<std::shared_ptr<arm_compute::Tensor>> m_layerInputArmTensor;
    int reshapeCount = 0;
    void propagateSize();
    void predict();
    void allocate();
    void deallocate();
};

#endif
