#pragma once

#include <torch/arg.h>
#include <torch/csrc/WindowsTorchApiMacro.h>
#include <torch/types.h>

namespace torch {
namespace nn {

/// Options for the `Linear` module.
struct TORCH_API LinearOptions {
  LinearOptions(int64_t in, int64_t out);
  /// The number of input features (columns of the input matrix).
  TORCH_ARG(int64_t, in);
  /// The number of output features to produce (columns of the output matrix).
  TORCH_ARG(int64_t, out);
  /// Whether to learn and add a bias after the linear transformation.
  TORCH_ARG(bool, with_bias) = true;
};

// ============================================================================

/// Options for the `Bilinear` module.
struct TORCH_API BilinearOptions {
  BilinearOptions(int64_t in1_features, int64_t in2_features, int64_t out_features);
  /// The number of features in input 1 (columns of the input1 matrix).
  TORCH_ARG(int64_t, in1_features);
  /// The number of features in input 2 (columns of the input2 matrix).
  TORCH_ARG(int64_t, in2_features);
  /// The number of output features to produce (columns of the output matrix).
  TORCH_ARG(int64_t, out_features);
  /// Whether to learn and add a bias after the bilinear transformation.
  TORCH_ARG(bool, bias) = true;
};

} // namespace nn
} // namespace torch
