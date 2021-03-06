#pragma once

// Complex number math operations that act as no-ops for other dtypes.
#include <complex>

namespace at { namespace native {
namespace {

template <typename TYPE>
struct ztype {
  using value_t = TYPE;
};

template <>
struct ztype<std::complex<double>> {
  using value_t = double;
};

template <>
struct ztype<std::complex<float>> {
  using value_t = float;
};

template <typename SCALAR_TYPE, typename VALUE_TYPE>
inline VALUE_TYPE zabs (SCALAR_TYPE z) {
  return z;
}

template<>
inline float zabs <std::complex<float>> (std::complex<float> z) {
  return std::abs(z);
}

template<>
inline double zabs <std::complex<double>> (std::complex<double> z) {
  return std::abs(z);
}

template <typename TYPE>
inline TYPE angle_impl (TYPE z) {
  return 0;
}

template<>
inline std::complex<float> angle_impl <std::complex<float>> (std::complex<float> z) {
  return std::complex<float>(std::arg(z), 0.0);
}

template<>
inline std::complex<double> angle_impl <std::complex<double>> (std::complex<double> z) {
  return std::complex<double>(std::arg(z), 0.0);
}

template <typename TYPE>
inline TYPE real_impl (TYPE z) {
  return z; //No-Op
}

template<>
inline std::complex<float> real_impl <std::complex<float>> (std::complex<float> z) {
  return std::complex<float>(std::real(z), 0.0);
}

template<>
inline std::complex<double> real_impl <std::complex<double>> (std::complex<double> z) {
  return std::complex<double>(std::real(z), 0.0);
}

template <typename TYPE>
inline TYPE imag_impl (TYPE z) {
  return 0;
}

template<>
inline std::complex<float> imag_impl <std::complex<float>> (std::complex<float> z) {
  return std::complex<float>(std::imag(z), 0.0);
}

template<>
inline std::complex<double> imag_impl <std::complex<double>> (std::complex<double> z) {
  return std::complex<double>(std::imag(z), 0.0);
}

template <typename TYPE>
inline TYPE conj_impl (TYPE z) {
  return z; //No-Op
}

template<>
inline std::complex<float> conj_impl <std::complex<float>> (std::complex<float> z) {
  return std::complex<float>(std::real(z), -std::imag(z));
}

template<>
inline std::complex<double> conj_impl <std::complex<double>> (std::complex<double> z) {
  return std::complex<double>(std::real(z), -std::imag(z));
}

template <typename TYPE>
inline TYPE ceil_impl (TYPE z) {
  return std::ceil(z);
}

template <>
inline std::complex<float> ceil_impl (std::complex<float> z) {
  return std::complex<float>(std::ceil(std::real(z)), std::ceil(std::imag(z)));
}

template <>
inline std::complex<double> ceil_impl (std::complex<double> z) {
  return std::complex<double>(std::ceil(std::real(z)), std::ceil(std::imag(z)));
}

template <typename TYPE>
inline TYPE floor_impl (TYPE z) {
  return std::floor(z);
}

template <>
inline std::complex<float> floor_impl (std::complex<float> z) {
  return std::complex<float>(std::floor(std::real(z)), std::floor(std::imag(z)));
}

template <>
inline std::complex<double> floor_impl (std::complex<double> z) {
  return std::complex<double>(std::floor(std::real(z)), std::floor(std::imag(z)));
}

template <typename TYPE>
inline TYPE round_impl (TYPE z) {
  return std::nearbyint(z);
}

template <>
inline std::complex<float> round_impl (std::complex<float> z) {
  return std::complex<float>(std::nearbyint(std::real(z)), std::nearbyint(std::imag(z)));
}

template <>
inline std::complex<double> round_impl (std::complex<double> z) {
  return std::complex<double>(std::nearbyint(std::real(z)), std::nearbyint(std::imag(z)));
}

template <typename TYPE>
inline TYPE trunc_impl (TYPE z) {
  return std::trunc(z);
}

template <>
inline std::complex<float> trunc_impl (std::complex<float> z) {
  return std::complex<float>(std::trunc(std::real(z)), std::trunc(std::imag(z)));
}

template <>
inline std::complex<double> trunc_impl (std::complex<double> z) {
  return std::complex<double>(std::trunc(std::real(z)), std::trunc(std::imag(z)));
}

} // end namespace
}} //end at::native
