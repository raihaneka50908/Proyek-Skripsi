/* Copyright 2019-2020 The MathWorks, Inc. */

// ARMNEON specific header for Custom Layer Base Class
#ifndef CUSTOM_LAYER_ARMNEON_HPP
#define CUSTOM_LAYER_ARMNEON_HPP

#include "cnn_api.hpp"
#include <map>

/* forward declare classes */
class MWTargetNetworkImpl;

class MWCustomLayerForARMNEON : public MWCNNLayer {

  public:
    MWCustomLayerForARMNEON();
    ~MWCustomLayerForARMNEON();

    MWTargetNetworkImpl* m_ntwkImpl;

    void allocate();
    void deallocate();
    void cleanup();

  protected:
    void setupLayer(MWTargetNetworkImpl*);

    // reorder data to between SNCHW <--> SNCWH or SNCHW <--> SNHWC
    void reorderInputData(MWTensorBase* aTensor, int bufIndex);
    void reorderOutputData(MWTensorBase* aTensor, int bufIndex);
    void prepareUnpaddedIpData();

    virtual void cleanupLayer(){};

    void setUnpaddedIpData(MWTensorBase* aTensor, float* bufPtr);
    float* getUnpaddedIpData(MWTensorBase* aTensor);
    void allocateOutputData(int);
    void allocateInputData(int);

    void setInputDataLayout(MWTensorBase* aTensor, MWTensorBase::DIMSLABEL inputLayout[]);
    void setOutputDataLayout(MWTensorBase* aTensor, MWTensorBase::DIMSLABEL outputLayout[]);
    void setCustomImplDataLayout(MWTensorBase::DIMSLABEL custImplLayout[]);

    MWTensorBase::DIMSLABEL* getInputDataLayout(MWTensorBase* aTensor);
    MWTensorBase::DIMSLABEL* getOutputDataLayout(MWTensorBase* aTensor);
    MWTensorBase::DIMSLABEL* getCustomImplDataLayout();

    bool isSharedIpArmTensorData(MWTensorBase* aTensor);

  private:
    std::map<MWTensorBase*, float*> MW_mangled_ipUnPaddedData;

    std::map<MWTensorBase*, std::vector<MWTensorBase::DIMSLABEL>> MW_mangled_inputLayout;
    std::map<MWTensorBase*, std::vector<MWTensorBase::DIMSLABEL>> MW_mangled_outputLayout;
    std::vector<MWTensorBase::DIMSLABEL> MW_mangled_custImplLayout;
};

#endif
