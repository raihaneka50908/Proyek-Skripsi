//
//  Student License - for use by students to meet course requirements and
//  perform academic research at degree granting institutions only.  Not
//  for government, commercial, or other organizational use.
//
//  DeepLearningNetwork.cpp
//
//  Code generation for function 'DeepLearningNetwork'
//


// Include files
#include "DeepLearningNetwork.h"
#include "raspi_googlenet_trash_class_internal_types.h"
#include "rt_nonfinite.h"
#include "MWConcatenationLayer.hpp"
#include "MWElementwiseAffineLayer.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWSplittingLayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"

// Function Definitions
void Googlenet_Trained_Network0_0::allocate()
{
  this->targetImpl->allocate(5, this->layers, this->numLayers);
  for (int idx = 0; idx < 78; idx++) {
    this->layers[idx]->allocate();
  }

  (static_cast<MWTensor<float> *>(this->inputTensors[0]))->setData(this->layers
    [0]->getLayerOutput(0));
}

void Googlenet_Trained_Network0_0::cleanup()
{
  this->deallocate();
  for (int idx = 0; idx < 78; idx++) {
    this->layers[idx]->cleanup();
  }

  if (this->targetImpl) {
    this->targetImpl->cleanup();
  }
}

void Googlenet_Trained_Network0_0::deallocate()
{
  this->targetImpl->deallocate();
  for (int idx = 0; idx < 78; idx++) {
    this->layers[idx]->deallocate();
  }
}

void Googlenet_Trained_Network0_0::postsetup()
{
  this->targetImpl->postSetup();
}

void Googlenet_Trained_Network0_0::resetState()
{
}

void Googlenet_Trained_Network0_0::setSize()
{
  for (int idx = 0; idx < 78; idx++) {
    this->layers[idx]->propagateSize();
  }

  this->allocate();
  this->postsetup();
}

void Googlenet_Trained_Network0_0::setup()
{
  if (this->isInitialized) {
    this->resetState();
  } else {
    this->isInitialized = true;
    this->targetImpl->preSetup();
    (static_cast<MWInputLayer *>(this->layers[0]))->createInputLayer
      (this->targetImpl, this->inputTensors[0], 224, 224, 3, 0, "", 0);
    (static_cast<MWElementwiseAffineLayer *>(this->layers[1]))
      ->createElementwiseAffineLayer(this->targetImpl, this->layers[0]
      ->getOutputTensor(0), 1, 1, 3, 1, 1, 3, false, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_data_scale.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_data_offset.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[2]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[1]
      ->getOutputTensor(0), 7, 7, 3, 64, 2, 2, 3, 3, 3, 3, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv1-7x7_s2_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv1-7x7_s2_b.bin",
      1);
    (static_cast<MWMaxPoolingLayer *>(this->layers[3]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[2]->getOutputTensor(0), 3, 3, 2, 2, 0, 1,
       0, 1, 0, 1, 0);
    (static_cast<MWNormLayer *>(this->layers[4]))->createNormLayer
      (this->targetImpl, this->layers[3]->getOutputTensor(0), 5, 0.0001, 0.75,
       1.0, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[5]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[4]
      ->getOutputTensor(0), 1, 1, 64, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv2-3x3_reduce_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv2-3x3_reduce_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[6]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[5]
      ->getOutputTensor(0), 3, 3, 64, 192, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv2-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_conv2-3x3_b.bin",
      1);
    (static_cast<MWNormLayer *>(this->layers[7]))->createNormLayer
      (this->targetImpl, this->layers[6]->getOutputTensor(0), 5, 0.0001, 0.75,
       1.0, 0);
    (static_cast<MWMaxPoolingLayer *>(this->layers[8]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[7]->getOutputTensor(0), 3, 3, 2, 2, 0, 1,
       0, 1, 0, 1, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[9]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[8]
      ->getOutputTensor(0), 1, 1, 192, 176, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[10]))->createSplittingLayer
      (this->targetImpl, this->layers[9]->getOutputTensor(0), 3, 16, 96, 64, 3,
       2, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[11]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[10]
      ->getOutputTensor(1), 3, 3, 96, 128, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[12]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[10]
      ->getOutputTensor(0), 5, 5, 16, 32, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[13]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[8]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[14]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[13]
      ->getOutputTensor(0), 1, 1, 192, 32, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3a-pool_proj_b.bin",
      1);
    (static_cast<MWConcatenationLayer *>(this->layers[15]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[10]
      ->getOutputTensor(2), this->layers[11]->getOutputTensor(0), this->layers
      [12]->getOutputTensor(0), this->layers[14]->getOutputTensor(0), 3, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[16]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[15]
      ->getOutputTensor(0), 1, 1, 256, 288, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[17]))->createSplittingLayer
      (this->targetImpl, this->layers[16]->getOutputTensor(0), 3, 32, 128, 128,
       3, 1, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[18]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[17]
      ->getOutputTensor(1), 3, 3, 128, 192, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[19]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[17]
      ->getOutputTensor(0), 5, 5, 32, 96, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[20]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[15]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[21]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[20]
      ->getOutputTensor(0), 1, 1, 256, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_3b-pool_proj_b.bin",
      2);
    (static_cast<MWConcatenationLayer *>(this->layers[22]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[17]
      ->getOutputTensor(2), this->layers[18]->getOutputTensor(0), this->layers
      [19]->getOutputTensor(0), this->layers[21]->getOutputTensor(0), 3, 1);
    (static_cast<MWMaxPoolingLayer *>(this->layers[23]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[22]->getOutputTensor(0), 3, 3, 2, 2, 0, 1,
       0, 1, 0, 1, 0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[24]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[23]
      ->getOutputTensor(0), 1, 1, 480, 304, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-5x5_reduce_b_fused.bin",
      1);
    (static_cast<MWSplittingLayer *>(this->layers[25]))->createSplittingLayer
      (this->targetImpl, this->layers[24]->getOutputTensor(0), 3, 16, 96, 192, 3,
       2, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[26]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[25]
      ->getOutputTensor(1), 3, 3, 96, 208, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-3x3_b.bin",
      1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[27]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[25]
      ->getOutputTensor(0), 5, 5, 16, 48, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[28]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[23]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[29]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[28]
      ->getOutputTensor(0), 1, 1, 480, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4a-pool_proj_b.bin",
      0);
    (static_cast<MWConcatenationLayer *>(this->layers[30]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[25]
      ->getOutputTensor(2), this->layers[26]->getOutputTensor(0), this->layers
      [27]->getOutputTensor(0), this->layers[29]->getOutputTensor(0), 3, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[31]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[30]
      ->getOutputTensor(0), 1, 1, 512, 296, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[32]))->createSplittingLayer
      (this->targetImpl, this->layers[31]->getOutputTensor(0), 3, 24, 112, 160,
       3, 1, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[33]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[32]
      ->getOutputTensor(1), 3, 3, 112, 224, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[34]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[32]
      ->getOutputTensor(0), 5, 5, 24, 64, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[35]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[30]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[36]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[35]
      ->getOutputTensor(0), 1, 1, 512, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4b-pool_proj_b.bin",
      2);
    (static_cast<MWConcatenationLayer *>(this->layers[37]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[32]
      ->getOutputTensor(2), this->layers[33]->getOutputTensor(0), this->layers
      [34]->getOutputTensor(0), this->layers[36]->getOutputTensor(0), 3, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[38]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[37]
      ->getOutputTensor(0), 1, 1, 512, 280, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[39]))->createSplittingLayer
      (this->targetImpl, this->layers[38]->getOutputTensor(0), 3, 24, 128, 128,
       3, 2, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[40]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[39]
      ->getOutputTensor(1), 3, 3, 128, 256, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[41]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[39]
      ->getOutputTensor(0), 5, 5, 24, 64, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[42]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[37]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[43]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[42]
      ->getOutputTensor(0), 1, 1, 512, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4c-pool_proj_b.bin",
      1);
    (static_cast<MWConcatenationLayer *>(this->layers[44]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[39]
      ->getOutputTensor(2), this->layers[40]->getOutputTensor(0), this->layers
      [41]->getOutputTensor(0), this->layers[43]->getOutputTensor(0), 3, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[45]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[44]
      ->getOutputTensor(0), 1, 1, 512, 288, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[46]))->createSplittingLayer
      (this->targetImpl, this->layers[45]->getOutputTensor(0), 3, 32, 144, 112,
       3, 1, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[47]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[46]
      ->getOutputTensor(1), 3, 3, 144, 288, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[48]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[46]
      ->getOutputTensor(0), 5, 5, 32, 64, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[49]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[44]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[50]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[49]
      ->getOutputTensor(0), 1, 1, 512, 64, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4d-pool_proj_b.bin",
      2);
    (static_cast<MWConcatenationLayer *>(this->layers[51]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[46]
      ->getOutputTensor(2), this->layers[47]->getOutputTensor(0), this->layers
      [48]->getOutputTensor(0), this->layers[50]->getOutputTensor(0), 3, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[52]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[51]
      ->getOutputTensor(0), 1, 1, 528, 448, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[53]))->createSplittingLayer
      (this->targetImpl, this->layers[52]->getOutputTensor(0), 3, 32, 160, 256,
       3, 2, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[54]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[53]
      ->getOutputTensor(1), 3, 3, 160, 320, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[55]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[53]
      ->getOutputTensor(0), 5, 5, 32, 128, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[56]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[51]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[57]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[56]
      ->getOutputTensor(0), 1, 1, 528, 128, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_4e-pool_proj_b.bin",
      1);
    (static_cast<MWConcatenationLayer *>(this->layers[58]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[53]
      ->getOutputTensor(2), this->layers[54]->getOutputTensor(0), this->layers
      [55]->getOutputTensor(0), this->layers[57]->getOutputTensor(0), 3, 2);
    (static_cast<MWMaxPoolingLayer *>(this->layers[59]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[58]->getOutputTensor(0), 3, 3, 2, 2, 0, 1,
       0, 1, 0, 1, 0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[60]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[59]
      ->getOutputTensor(0), 1, 1, 832, 448, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-5x5_reduce_b_fused.bin",
      1);
    (static_cast<MWSplittingLayer *>(this->layers[61]))->createSplittingLayer
      (this->targetImpl, this->layers[60]->getOutputTensor(0), 3, 32, 160, 256,
       3, 2, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[62]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[61]
      ->getOutputTensor(1), 3, 3, 160, 320, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-3x3_b.bin",
      1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[63]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[61]
      ->getOutputTensor(0), 5, 5, 32, 128, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[64]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[59]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[65]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[64]
      ->getOutputTensor(0), 1, 1, 832, 128, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5a-pool_proj_b.bin",
      0);
    (static_cast<MWConcatenationLayer *>(this->layers[66]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[61]
      ->getOutputTensor(2), this->layers[62]->getOutputTensor(0), this->layers
      [63]->getOutputTensor(0), this->layers[65]->getOutputTensor(0), 3, 2);
    (static_cast<MWFusedConvReLULayer *>(this->layers[67]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[66]
      ->getOutputTensor(0), 1, 1, 832, 624, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-5x5_reduce_w_fused.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-5x5_reduce_b_fused.bin",
      0);
    (static_cast<MWSplittingLayer *>(this->layers[68]))->createSplittingLayer
      (this->targetImpl, this->layers[67]->getOutputTensor(0), 3, 48, 192, 384,
       3, 1, 3, 4);
    (static_cast<MWFusedConvReLULayer *>(this->layers[69]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[68]
      ->getOutputTensor(1), 3, 3, 192, 384, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-3x3_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-3x3_b.bin",
      0);
    (static_cast<MWFusedConvReLULayer *>(this->layers[70]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[68]
      ->getOutputTensor(0), 5, 5, 48, 128, 1, 1, 2, 2, 2, 2, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-5x5_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-5x5_b.bin",
      3);
    (static_cast<MWMaxPoolingLayer *>(this->layers[71]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[66]->getOutputTensor(0), 3, 3, 1, 1, 1, 1,
       1, 1, 0, 1, 1);
    (static_cast<MWFusedConvReLULayer *>(this->layers[72]))
      ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[71]
      ->getOutputTensor(0), 1, 1, 832, 128, 1, 1, 0, 0, 0, 0, 1, 1, 1,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-pool_proj_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_inception_5b-pool_proj_b.bin",
      2);
    (static_cast<MWConcatenationLayer *>(this->layers[73]))
      ->createConcatenationLayer(this->targetImpl, 4, this->layers[68]
      ->getOutputTensor(2), this->layers[69]->getOutputTensor(0), this->layers
      [70]->getOutputTensor(0), this->layers[72]->getOutputTensor(0), 3, 1);
    (static_cast<MWAvgPoolingLayer *>(this->layers[74]))->createAvgPoolingLayer
      (this->targetImpl, this->layers[73]->getOutputTensor(0), -1, -1, 1, 1, 0,
       0, 0, 0, 0);
    (static_cast<MWFCLayer *>(this->layers[75]))->createFCLayer(this->targetImpl,
      this->layers[74]->getOutputTensor(0), 1024, 2,
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_fc_w.bin",
      "./codegen/exe/raspi_googlenet_trash_class/cnn_Googlenet_Trained_Network0_0_fc_b.bin",
      1);
    (static_cast<MWSoftmaxLayer *>(this->layers[76]))->createSoftmaxLayer
      (this->targetImpl, this->layers[75]->getOutputTensor(0), 0);
    (static_cast<MWOutputLayer *>(this->layers[77]))->createOutputLayer
      (this->targetImpl, this->layers[76]->getOutputTensor(0), 0);
    this->outputTensors[0] = this->layers[77]->getOutputTensor(0);
    this->setSize();
  }
}

Googlenet_Trained_Network0_0::Googlenet_Trained_Network0_0()
{
  this->numLayers = 78;
  this->isInitialized = false;
  this->targetImpl = 0;
  this->layers[0] = new MWInputLayer;
  this->layers[0]->setName("data");
  this->layers[1] = new MWElementwiseAffineLayer;
  this->layers[1]->setName("data_normalization");
  this->layers[1]->setInPlaceIndex(0, 0);
  this->layers[2] = new MWFusedConvReLULayer;
  this->layers[2]->setName("conv1-7x7_s2_conv1-relu_7x7");
  this->layers[3] = new MWMaxPoolingLayer;
  this->layers[3]->setName("pool1-3x3_s2");
  this->layers[4] = new MWNormLayer;
  this->layers[4]->setName("pool1-norm1");
  this->layers[5] = new MWFusedConvReLULayer;
  this->layers[5]->setName("conv2-3x3_reduce_conv2-relu_3x3_reduce");
  this->layers[6] = new MWFusedConvReLULayer;
  this->layers[6]->setName("conv2-3x3_conv2-relu_3x3");
  this->layers[7] = new MWNormLayer;
  this->layers[7]->setName("conv2-norm2");
  this->layers[8] = new MWMaxPoolingLayer;
  this->layers[8]->setName("pool2-3x3_s2");
  this->layers[9] = new MWFusedConvReLULayer;
  this->layers[9]->setName(
    "inception_3a-5x5_reduce_inception_3a-relu_5x5_reduce_fused");
  this->layers[10] = new MWSplittingLayer;
  this->layers[10]->setName("ChannelWiseSplittingLayer");
  this->layers[11] = new MWFusedConvReLULayer;
  this->layers[11]->setName("inception_3a-3x3_inception_3a-relu_3x3");
  this->layers[12] = new MWFusedConvReLULayer;
  this->layers[12]->setName("inception_3a-5x5_inception_3a-relu_5x5");
  this->layers[13] = new MWMaxPoolingLayer;
  this->layers[13]->setName("inception_3a-pool");
  this->layers[14] = new MWFusedConvReLULayer;
  this->layers[14]->setName("inception_3a-pool_proj_inception_3a-relu_pool_proj");
  this->layers[15] = new MWConcatenationLayer;
  this->layers[15]->setName("inception_3a-output");
  this->layers[16] = new MWFusedConvReLULayer;
  this->layers[16]->setName(
    "inception_3b-5x5_reduce_inception_3b-relu_5x5_reduce_fused");
  this->layers[17] = new MWSplittingLayer;
  this->layers[17]->setName("ChannelWiseSplittingLayer");
  this->layers[18] = new MWFusedConvReLULayer;
  this->layers[18]->setName("inception_3b-3x3_inception_3b-relu_3x3");
  this->layers[19] = new MWFusedConvReLULayer;
  this->layers[19]->setName("inception_3b-5x5_inception_3b-relu_5x5");
  this->layers[20] = new MWMaxPoolingLayer;
  this->layers[20]->setName("inception_3b-pool");
  this->layers[21] = new MWFusedConvReLULayer;
  this->layers[21]->setName("inception_3b-pool_proj_inception_3b-relu_pool_proj");
  this->layers[22] = new MWConcatenationLayer;
  this->layers[22]->setName("inception_3b-output");
  this->layers[23] = new MWMaxPoolingLayer;
  this->layers[23]->setName("pool3-3x3_s2");
  this->layers[24] = new MWFusedConvReLULayer;
  this->layers[24]->setName(
    "inception_4a-5x5_reduce_inception_4a-relu_5x5_reduce_fused");
  this->layers[25] = new MWSplittingLayer;
  this->layers[25]->setName("ChannelWiseSplittingLayer");
  this->layers[26] = new MWFusedConvReLULayer;
  this->layers[26]->setName("inception_4a-3x3_inception_4a-relu_3x3");
  this->layers[27] = new MWFusedConvReLULayer;
  this->layers[27]->setName("inception_4a-5x5_inception_4a-relu_5x5");
  this->layers[28] = new MWMaxPoolingLayer;
  this->layers[28]->setName("inception_4a-pool");
  this->layers[29] = new MWFusedConvReLULayer;
  this->layers[29]->setName("inception_4a-pool_proj_inception_4a-relu_pool_proj");
  this->layers[30] = new MWConcatenationLayer;
  this->layers[30]->setName("inception_4a-output");
  this->layers[31] = new MWFusedConvReLULayer;
  this->layers[31]->setName(
    "inception_4b-5x5_reduce_inception_4b-relu_5x5_reduce_fused");
  this->layers[32] = new MWSplittingLayer;
  this->layers[32]->setName("ChannelWiseSplittingLayer");
  this->layers[33] = new MWFusedConvReLULayer;
  this->layers[33]->setName("inception_4b-3x3_inception_4b-relu_3x3");
  this->layers[34] = new MWFusedConvReLULayer;
  this->layers[34]->setName("inception_4b-5x5_inception_4b-relu_5x5");
  this->layers[35] = new MWMaxPoolingLayer;
  this->layers[35]->setName("inception_4b-pool");
  this->layers[36] = new MWFusedConvReLULayer;
  this->layers[36]->setName("inception_4b-pool_proj_inception_4b-relu_pool_proj");
  this->layers[37] = new MWConcatenationLayer;
  this->layers[37]->setName("inception_4b-output");
  this->layers[38] = new MWFusedConvReLULayer;
  this->layers[38]->setName(
    "inception_4c-5x5_reduce_inception_4c-relu_5x5_reduce_fused");
  this->layers[39] = new MWSplittingLayer;
  this->layers[39]->setName("ChannelWiseSplittingLayer");
  this->layers[40] = new MWFusedConvReLULayer;
  this->layers[40]->setName("inception_4c-3x3_inception_4c-relu_3x3");
  this->layers[41] = new MWFusedConvReLULayer;
  this->layers[41]->setName("inception_4c-5x5_inception_4c-relu_5x5");
  this->layers[42] = new MWMaxPoolingLayer;
  this->layers[42]->setName("inception_4c-pool");
  this->layers[43] = new MWFusedConvReLULayer;
  this->layers[43]->setName("inception_4c-pool_proj_inception_4c-relu_pool_proj");
  this->layers[44] = new MWConcatenationLayer;
  this->layers[44]->setName("inception_4c-output");
  this->layers[45] = new MWFusedConvReLULayer;
  this->layers[45]->setName(
    "inception_4d-5x5_reduce_inception_4d-relu_5x5_reduce_fused");
  this->layers[46] = new MWSplittingLayer;
  this->layers[46]->setName("ChannelWiseSplittingLayer");
  this->layers[47] = new MWFusedConvReLULayer;
  this->layers[47]->setName("inception_4d-3x3_inception_4d-relu_3x3");
  this->layers[48] = new MWFusedConvReLULayer;
  this->layers[48]->setName("inception_4d-5x5_inception_4d-relu_5x5");
  this->layers[49] = new MWMaxPoolingLayer;
  this->layers[49]->setName("inception_4d-pool");
  this->layers[50] = new MWFusedConvReLULayer;
  this->layers[50]->setName("inception_4d-pool_proj_inception_4d-relu_pool_proj");
  this->layers[51] = new MWConcatenationLayer;
  this->layers[51]->setName("inception_4d-output");
  this->layers[52] = new MWFusedConvReLULayer;
  this->layers[52]->setName(
    "inception_4e-5x5_reduce_inception_4e-relu_5x5_reduce_fused");
  this->layers[53] = new MWSplittingLayer;
  this->layers[53]->setName("ChannelWiseSplittingLayer");
  this->layers[54] = new MWFusedConvReLULayer;
  this->layers[54]->setName("inception_4e-3x3_inception_4e-relu_3x3");
  this->layers[55] = new MWFusedConvReLULayer;
  this->layers[55]->setName("inception_4e-5x5_inception_4e-relu_5x5");
  this->layers[56] = new MWMaxPoolingLayer;
  this->layers[56]->setName("inception_4e-pool");
  this->layers[57] = new MWFusedConvReLULayer;
  this->layers[57]->setName("inception_4e-pool_proj_inception_4e-relu_pool_proj");
  this->layers[58] = new MWConcatenationLayer;
  this->layers[58]->setName("inception_4e-output");
  this->layers[59] = new MWMaxPoolingLayer;
  this->layers[59]->setName("pool4-3x3_s2");
  this->layers[60] = new MWFusedConvReLULayer;
  this->layers[60]->setName(
    "inception_5a-5x5_reduce_inception_5a-relu_5x5_reduce_fused");
  this->layers[61] = new MWSplittingLayer;
  this->layers[61]->setName("ChannelWiseSplittingLayer");
  this->layers[62] = new MWFusedConvReLULayer;
  this->layers[62]->setName("inception_5a-3x3_inception_5a-relu_3x3");
  this->layers[63] = new MWFusedConvReLULayer;
  this->layers[63]->setName("inception_5a-5x5_inception_5a-relu_5x5");
  this->layers[64] = new MWMaxPoolingLayer;
  this->layers[64]->setName("inception_5a-pool");
  this->layers[65] = new MWFusedConvReLULayer;
  this->layers[65]->setName("inception_5a-pool_proj_inception_5a-relu_pool_proj");
  this->layers[66] = new MWConcatenationLayer;
  this->layers[66]->setName("inception_5a-output");
  this->layers[67] = new MWFusedConvReLULayer;
  this->layers[67]->setName(
    "inception_5b-5x5_reduce_inception_5b-relu_5x5_reduce_fused");
  this->layers[68] = new MWSplittingLayer;
  this->layers[68]->setName("ChannelWiseSplittingLayer");
  this->layers[69] = new MWFusedConvReLULayer;
  this->layers[69]->setName("inception_5b-3x3_inception_5b-relu_3x3");
  this->layers[70] = new MWFusedConvReLULayer;
  this->layers[70]->setName("inception_5b-5x5_inception_5b-relu_5x5");
  this->layers[71] = new MWMaxPoolingLayer;
  this->layers[71]->setName("inception_5b-pool");
  this->layers[72] = new MWFusedConvReLULayer;
  this->layers[72]->setName("inception_5b-pool_proj_inception_5b-relu_pool_proj");
  this->layers[73] = new MWConcatenationLayer;
  this->layers[73]->setName("inception_5b-output");
  this->layers[74] = new MWAvgPoolingLayer;
  this->layers[74]->setName("pool5-7x7_s1");
  this->layers[75] = new MWFCLayer;
  this->layers[75]->setName("fc");
  this->layers[76] = new MWSoftmaxLayer;
  this->layers[76]->setName("prob");
  this->layers[77] = new MWOutputLayer;
  this->layers[77]->setName("classoutput");
  this->layers[77]->setInPlaceIndex(0, 0);
  this->targetImpl = new MWTargetNetworkImpl;
  this->inputTensors[0] = new MWTensor<float>;
  this->inputTensors[0]->setHeight(224);
  this->inputTensors[0]->setWidth(224);
  this->inputTensors[0]->setChannels(3);
  this->inputTensors[0]->setBatchSize(1);
  this->inputTensors[0]->setSequenceLength(1);
}

Googlenet_Trained_Network0_0::~Googlenet_Trained_Network0_0()
{
  this->cleanup();
  for (int idx = 0; idx < 78; idx++) {
    delete this->layers[idx];
  }

  if (this->targetImpl) {
    delete this->targetImpl;
  }

  delete this->inputTensors[0];
}

int Googlenet_Trained_Network0_0::getBatchSize()
{
  return this->inputTensors[0]->getBatchSize();
}

float *Googlenet_Trained_Network0_0::getInputDataPointer(int b_index)
{
  return (static_cast<MWTensor<float> *>(this->inputTensors[b_index]))->getData();
}

float *Googlenet_Trained_Network0_0::getInputDataPointer()
{
  return (static_cast<MWTensor<float> *>(this->inputTensors[0]))->getData();
}

float *Googlenet_Trained_Network0_0::getLayerOutput(int layerIndex, int
  portIndex)
{
  return this->targetImpl->getLayerOutput(this->layers, layerIndex, portIndex);
}

float *Googlenet_Trained_Network0_0::getOutputDataPointer(int b_index)
{
  return (static_cast<MWTensor<float> *>(this->outputTensors[b_index]))->getData
    ();
}

float *Googlenet_Trained_Network0_0::getOutputDataPointer()
{
  return (static_cast<MWTensor<float> *>(this->outputTensors[0]))->getData();
}

void Googlenet_Trained_Network0_0::predict()
{
  for (int idx = 0; idx < 78; idx++) {
    this->layers[idx]->predict();
  }
}

namespace coder
{
  void DeepLearningNetwork_setup(Googlenet_Trained_Network0_0 *obj)
  {
    obj->setup();
  }
}

// End of code generation (DeepLearningNetwork.cpp)
