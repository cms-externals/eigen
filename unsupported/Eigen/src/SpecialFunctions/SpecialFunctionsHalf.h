// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_SPECIALFUNCTIONS_HALF_H
#define EIGEN_SPECIALFUNCTIONS_HALF_H

namespace Eigen_tf {
namespace numext {

#if EIGEN_HAS_C99_MATH
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half lgamma(const Eigen_tf::half& a) {
  return Eigen_tf::half(Eigen_tf::numext::lgamma(static_cast<float>(a)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half digamma(const Eigen_tf::half& a) {
  return Eigen_tf::half(Eigen_tf::numext::digamma(static_cast<float>(a)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half zeta(const Eigen_tf::half& x, const Eigen_tf::half& q) {
  return Eigen_tf::half(Eigen_tf::numext::zeta(static_cast<float>(x), static_cast<float>(q)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half polygamma(const Eigen_tf::half& n, const Eigen_tf::half& x) {
  return Eigen_tf::half(Eigen_tf::numext::polygamma(static_cast<float>(n), static_cast<float>(x)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half erf(const Eigen_tf::half& a) {
  return Eigen_tf::half(Eigen_tf::numext::erf(static_cast<float>(a)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half erfc(const Eigen_tf::half& a) {
  return Eigen_tf::half(Eigen_tf::numext::erfc(static_cast<float>(a)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half igamma(const Eigen_tf::half& a, const Eigen_tf::half& x) {
  return Eigen_tf::half(Eigen_tf::numext::igamma(static_cast<float>(a), static_cast<float>(x)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half igammac(const Eigen_tf::half& a, const Eigen_tf::half& x) {
  return Eigen_tf::half(Eigen_tf::numext::igammac(static_cast<float>(a), static_cast<float>(x)));
}
template<> EIGEN_STRONG_INLINE EIGEN_DEVICE_FUNC Eigen_tf::half betainc(const Eigen_tf::half& a, const Eigen_tf::half& b, const Eigen_tf::half& x) {
  return Eigen_tf::half(Eigen_tf::numext::betainc(static_cast<float>(a), static_cast<float>(b), static_cast<float>(x)));
}
#endif

}  // end namespace numext
}  // end namespace Eigen_tf

#endif  // EIGEN_SPECIALFUNCTIONS_HALF_H
