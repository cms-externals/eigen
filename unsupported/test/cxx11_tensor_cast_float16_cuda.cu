// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2016 Benoit Steiner <benoit.steiner.goog@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#define EIGEN_TEST_NO_LONGDOUBLE
#define EIGEN_TEST_NO_COMPLEX
#define EIGEN_TEST_FUNC cxx11_tensor_cast_float16_cuda
#define EIGEN_DEFAULT_DENSE_INDEX_TYPE int
#define EIGEN_USE_GPU

#if defined __CUDACC_VER__ && __CUDACC_VER__ >= 70500
#include <cuda_fp16.h>
#endif
#include "main.h"
#include <unsupported/Eigen/CXX11/Tensor>

using Eigen_tf::Tensor;

void test_cuda_conversion() {
  Eigen_tf::CudaStreamDevice stream;
  Eigen_tf::GpuDevice gpu_device(&stream);
  int num_elem = 101;

  Tensor<float, 1> floats(num_elem);
  floats.setRandom();

  float* d_float = (float*)gpu_device.allocate(num_elem * sizeof(float));
  Eigen_tf::half* d_half = (Eigen_tf::half*)gpu_device.allocate(num_elem * sizeof(Eigen_tf::half));
  float* d_conv = (float*)gpu_device.allocate(num_elem * sizeof(float));

  Eigen_tf::TensorMap<Eigen_tf::Tensor<float, 1>, Eigen_tf::Aligned> gpu_float(
      d_float, num_elem);
  Eigen_tf::TensorMap<Eigen_tf::Tensor<Eigen_tf::half, 1>, Eigen_tf::Aligned> gpu_half(
      d_half, num_elem);
  Eigen_tf::TensorMap<Eigen_tf::Tensor<float, 1>, Eigen_tf::Aligned> gpu_conv(
      d_conv, num_elem);

  gpu_device.memcpyHostToDevice(d_float, floats.data(), num_elem*sizeof(float));

  gpu_half.device(gpu_device) = gpu_float.cast<Eigen_tf::half>();
  gpu_conv.device(gpu_device) = gpu_half.cast<float>();

  Tensor<float, 1> initial(num_elem);
  Tensor<float, 1> final(num_elem);
  gpu_device.memcpyDeviceToHost(initial.data(), d_float, num_elem*sizeof(float));
  gpu_device.memcpyDeviceToHost(final.data(), d_conv, num_elem*sizeof(float));
  gpu_device.synchronize();

  for (int i = 0; i < num_elem; ++i) {
    VERIFY_IS_APPROX(initial(i), final(i));
  }

  gpu_device.deallocate(d_float);
  gpu_device.deallocate(d_half);
  gpu_device.deallocate(d_conv);
}


void test_fallback_conversion() {
  int num_elem = 101;
  Tensor<float, 1> floats(num_elem);
  floats.setRandom();

  Eigen_tf::Tensor<Eigen_tf::half, 1> halfs = floats.cast<Eigen_tf::half>();
  Eigen_tf::Tensor<float, 1> conv = halfs.cast<float>();

  for (int i = 0; i < num_elem; ++i) {
    VERIFY_IS_APPROX(floats(i), conv(i));
  }
}


void test_cxx11_tensor_cast_float16_cuda()
{
  CALL_SUBTEST(test_cuda_conversion());
  CALL_SUBTEST(test_fallback_conversion());
}
