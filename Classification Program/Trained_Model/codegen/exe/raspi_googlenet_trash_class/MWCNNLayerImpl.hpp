/* Copyright 2017-2020 The MathWorks, Inc. */
#ifndef CNN_API_IMPL
#define CNN_API_IMPL

#include <map>
#include <vector>
#include <omp.h>

#include "cnn_api.hpp"
#include "MWACLUtils.hpp"

class MWTargetNetworkImpl;


/* ARM Compute Library related header files */
#include "arm_compute/runtime/NEON/NEFunctions.h"
#include "arm_compute/core/Types.h"
#include "arm_compute/runtime/SubTensor.h"
#include "arm_compute/core/SubTensorInfo.h"
#include "arm_compute/runtime/Memory.h"

#define MW_LAYERS_TAP 0

#if MW_LAYERS_TAP
#define MW_INPUT_TAP 1
#define MW_CONV_TAP 1
#define MW_RELU_TAP 1
#define MW_NORM_TAP 1
#define MW_BNORM_TAP 1
#define MW_ADDITION_TAP 1
#define MW_POOL_TAP 1
#define MW_AVG_POOL_TAP 1
#define MW_FC_TAP 1
#define MW_SFMX_TAP 1
#define MW_CONCATENATE_TAP 1
#define MW_YOLOEXTRACT_TAP 1
#define MW_REORG_TAP 1
#define MW_SIGMOID_TAP 1
#define MW_EXP_TAP 1
#define MW_YOLOSOFTMAX_TAP 1
#define MW_TRANSPOSEDCONV_TAP 1
#define MW_FLATTEN_TAP 1
#define MW_ZEROPAD_TAP 1
#define MW_SPLIT_TAP 1
#define MW_AFFINE_TAP 1
#define MW_CROP2D_TAP 1
#define MW_SEQIP_TAP 1
#define MW_LSTM_TAP 1
#define MW_SCALE_TAP 1
#define MW_SSDMERGE_TAP 1
#define MW_ELU_TAP 1
#define MW_WORDEMBED_TAP 1
#else
#define MW_INPUT_TAP 0
#define MW_CONV_TAP 0
#define MW_RELU_TAP 0
#define MW_AVG_POOL_TAP 0
#define MW_NORM_TAP 0
#define MW_BNORM_TAP 0
#define MW_ADDITION_TAP 0
#define MW_POOL_TAP 0
#define MW_FC_TAP 0
#define MW_SFMX_TAP 0
#define MW_CONCATENATE_TAP 0
#define MW_YOLOEXTRACT_TAP 0
#define MW_REORG_TAP 0
#define MW_SIGMOID_TAP 0
#define MW_EXP_TAP 0
#define MW_YOLOSOFTMAX_TAP 0
#define MW_TRANSPOSEDCONV_TAP 0
#define MW_FLATTEN_TAP 0
#define MW_ZEROPAD_TAP 0
#define MW_SPLIT_TAP 0
#define MW_AFFINE_TAP 0
#define MW_CROP2D_TAP 0
#define MW_SEQIP_TAP 0
#define MW_LSTM_TAP 0
#define MW_SCALE_TAP 0
#define MW_SSDMERGE_TAP 0
#define MW_ELU_TAP 0
#define MW_WORDEMBED_TAP 0
#endif

class MWCNNLayerImpl {
  public:
    MWCNNLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* ntwk_impl);
    virtual ~MWCNNLayerImpl() {
    }
    virtual void predict() {
    }
    virtual void cleanup() {
    }
    virtual void propagateSize() = 0;
    virtual void allocate() {
    }
    virtual void deallocate() {
    }
    
    template <class T>
    void allocateOutputData(int);
    
    template <class T>
    void allocateACLLayerOpData(int);
    
    template <class T>
    void allocateHandCodedLayerOpData(int);
    
    template <class T>
    void deallocateOutputData(int);
    
    void allocateInputData(int);
	
    template <class T>
    void allocateInputDataImpl(int);

    void deallocateInputData(int);
    
    template <class T>
    void deallocateInputDataImpl(int);

    template <class T>
    void setUnpaddedIpData(MWTensorBase* , T*);

    void* getUnpaddedIpData(MWTensorBase*);

    virtual void postSetup() {
    }

    MWCNNLayer* getLayer() {
        return bOrQjJTNlssnrexxbHdi;
    }

    void setCurrentLayerOpArmTensor(std::shared_ptr<arm_compute::Tensor>, int index = 0);
    arm_compute::Tensor* getCurrentLayerOpArmTensor(int index = 0);
	std::shared_ptr<arm_compute::Tensor> getCurrentLayerOpArmTensorSharedPtr(int index=0);

    void setCurrentLayerIpArmTensor(std::shared_ptr<arm_compute::Tensor>, int index = 0);
    arm_compute::Tensor* getCurrentLayerIpArmTensor(int index = 0);
    std::shared_ptr<arm_compute::Tensor> getCurrentLayerIpArmTensorSharedPtr(int index=0);

    bool isHandCodedLayer() const {
        return bERCRkGjpaKXMNComoYl;
    }
    
    void setupIpArmTensors();
    void configureIpArmTensors();
    void prepareIpArmTensorsForPredict();

  protected:
      // map of output arm tensors of current layer
      std::map<int, std::shared_ptr<arm_compute::Tensor>>
              lHtftnmGBvlSSoGOXVui;

      std::map<MWTensorBase*, void*> YNDVziqpDddiXQKYZZhX;

      // map of input arm tensors of current layer
      std::map<int, std::shared_ptr<arm_compute::Tensor>>
              VenwEUlYwOBrwLVUhgUH;

      bool m_useIpUnPaddedMemForOp{false};
      bool bERCRkGjpaKXMNComoYl{false}; // To differentiate between hand coded and ACL layers.

      MWCNNLayer* bOrQjJTNlssnrexxbHdi;
      MWTargetNetworkImpl* edQOkUJIZbwzEeIcCLzG;
      std::string getLinuxPath(const char*);
};

class MWInputLayerImpl : public MWCNNLayerImpl {

  private:
 
    void predict();
    void propagateSize(){};

    void cleanup() {
    }

  public:
    MWInputLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* ntwk_impl);
    ~MWInputLayerImpl() {
    }
};

// ReLULayer
class MWReLULayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NEActivationLayer> m_actLayer;

    void predict();
    void propagateSize();

  public:
    MWReLULayerImpl(MWCNNLayer* , MWTargetNetworkImpl*);
    ~MWReLULayerImpl();
};


// CrossChannelNormalizationLayer
class MWNormLayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NENormalizationLayer> m_normLayer;
    std::unique_ptr<arm_compute::NEReshapeLayer> m_reshapeKernel;
    std::shared_ptr<arm_compute::Tensor> m_layerInputArmTensor = nullptr;

    unsigned GZGFVDrXwFLJleoTDywO;
    double AVeZfqOFypgpiqfRYlKc;
    double AdmgfUbRAfzFeYHxSnQr;
    double BlRIQPyqJZORKENzSdYf;
    bool m_isIpArmTensorReshaped{false};

    void propagateSize();
    void predict();
    void allocate();

  public:
    MWNormLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*, unsigned, double, double, double);
    ~MWNormLayerImpl();
};

// maxpoolingLayer
class MWMaxPoolingLayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NEPoolingLayer> m_maxPoolLayer;
    int GFggoMvRWucDMqzlWzCl;
    int GIbahSoBBDrvvZduPEqU;
    int GLovsOhUpzOJhKgXUAJY;
    int GLpnVFeGjOSrhNqnkdCu;
    int DRzwhbNPpftRRIXXfHzd;
    int DCdZnqpcBnvXVgEsLBnz;
    int FshVHIJMRAhtQirYPlZd;
    int GDRXdUDklKFEYEfifhIH;

    void propagateSize();
    void predict();

  public:
    MWMaxPoolingLayerImpl(MWCNNLayer*,
                          MWTargetNetworkImpl*,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int,
                          bool,
                          int);
    ~MWMaxPoolingLayerImpl();
    float* getIndexData();
};

// FullyConnectedLayer
class MWFCLayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NEFullyConnectedLayer> m_fcLayer;
    arm_compute::Tensor m_fcLayerWgtTensor;
    arm_compute::Tensor m_fcLayerBiasTensor;
    bool isWgtsPadded = false;
    bool isBiasPadded = false;
#if defined(USE_18_05_LIBRARY) | defined(USE_18_08_LIBRARY)
    arm_compute::MemoryRegion* vpXxoeEhdEosLSsYXkNG;
    arm_compute::MemoryRegion* KHjdvykTFbUxdfZTFbqy;
#else
    float* vpXxoeEhdEosLSsYXkNG;
    float* KHjdvykTFbUxdfZTFbqy;
#endif

    void loadWeights(const char*, int);
    void loadBias(const char*, int);
    void prepareWeights();
    void propagateSize();
    void predict();
    void cleanup();
    void allocate();
    void deallocate();

  public:
    MWFCLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*, int, int, const char*, const char*);
    ~MWFCLayerImpl();
};

// SoftmaxLayer
class MWSoftmaxLayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NESoftmaxLayer> m_softmaxLayer;
    arm_compute::Tensor inputNHWCArmTensor, tmpSfmaxNHWCArmTensor;
    std::unique_ptr<arm_compute::NEPermute> permuteToNHWC;
    std::unique_ptr<arm_compute::NEPermute> permuteToNCHW;
    bool m_doesChannelwiseSoftmax;

    void propagateSize();
    void predict();
    void allocate();
    void deallocate();


  public:
    MWSoftmaxLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWSoftmaxLayerImpl();
};

// AvgPoolingLayer
class MWAvgPoolingLayerImpl : public MWCNNLayerImpl {
  private:
    std::unique_ptr<arm_compute::NEPoolingLayer> m_avgPoolLayer;
    int GFggoMvRWucDMqzlWzCl;
    int GIbahSoBBDrvvZduPEqU;
    int GLovsOhUpzOJhKgXUAJY;
    int GLpnVFeGjOSrhNqnkdCu;
    int DRzwhbNPpftRRIXXfHzd;
    int DCdZnqpcBnvXVgEsLBnz;
    int FshVHIJMRAhtQirYPlZd;
    int GDRXdUDklKFEYEfifhIH;

    void propagateSize();
    void predict();

  public:
    MWAvgPoolingLayerImpl(MWCNNLayer*,
                          MWTargetNetworkImpl*,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int,
                          int);
    ~MWAvgPoolingLayerImpl();
};

class MWOutputLayerImpl : public MWCNNLayerImpl {
  private:

    void propagateSize(){};
    void predict();

  public:
    MWOutputLayerImpl(MWCNNLayer*, MWTargetNetworkImpl*);
    ~MWOutputLayerImpl();
};

#endif
