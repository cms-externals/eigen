// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2016 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.


#ifndef EIGEN_SPECIALFUNCTIONS_ARRAYAPI_H
#define EIGEN_SPECIALFUNCTIONS_ARRAYAPI_H

namespace Eigen_tf {

/** \cpp11 \returns an expression of the coefficient-wise igamma(\a a, \a x) to the given arrays.
  *
  * This function computes the coefficient-wise incomplete gamma function.
  *
  * \note This function supports only float and double scalar types in c++11 mode. To support other scalar types,
  * or float/double in non c++11 mode, the user has to provide implementations of igammac(T,T) for any scalar
  * type T to be supported.
  *
  * \sa Eigen_tf::igammac(), Eigen_tf::lgamma()
  */
template<typename Derived,typename ExponentDerived>
inline const Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_igamma_op<typename Derived::Scalar>, const Derived, const ExponentDerived>
igamma(const Eigen_tf::ArrayBase<Derived>& a, const Eigen_tf::ArrayBase<ExponentDerived>& x)
{
  return Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_igamma_op<typename Derived::Scalar>, const Derived, const ExponentDerived>(
    a.derived(),
    x.derived()
  );
}

/** \cpp11 \returns an expression of the coefficient-wise igammac(\a a, \a x) to the given arrays.
  *
  * This function computes the coefficient-wise complementary incomplete gamma function.
  *
  * \note This function supports only float and double scalar types in c++11 mode. To support other scalar types,
  * or float/double in non c++11 mode, the user has to provide implementations of igammac(T,T) for any scalar
  * type T to be supported.
  *
  * \sa Eigen_tf::igamma(), Eigen_tf::lgamma()
  */
template<typename Derived,typename ExponentDerived>
inline const Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_igammac_op<typename Derived::Scalar>, const Derived, const ExponentDerived>
igammac(const Eigen_tf::ArrayBase<Derived>& a, const Eigen_tf::ArrayBase<ExponentDerived>& x)
{
  return Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_igammac_op<typename Derived::Scalar>, const Derived, const ExponentDerived>(
    a.derived(),
    x.derived()
  );
}

/** \cpp11 \returns an expression of the coefficient-wise polygamma(\a n, \a x) to the given arrays.
  *
  * It returns the \a n -th derivative of the digamma(psi) evaluated at \c x.
  *
  * \note This function supports only float and double scalar types in c++11 mode. To support other scalar types,
  * or float/double in non c++11 mode, the user has to provide implementations of polygamma(T,T) for any scalar
  * type T to be supported.
  *
  * \sa Eigen_tf::digamma()
  */
// * \warning Be careful with the order of the parameters: x.polygamma(n) is equivalent to polygamma(n,x)
// * \sa ArrayBase::polygamma()
template<typename DerivedN,typename DerivedX>
inline const Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_polygamma_op<typename DerivedX::Scalar>, const DerivedN, const DerivedX>
polygamma(const Eigen_tf::ArrayBase<DerivedN>& n, const Eigen_tf::ArrayBase<DerivedX>& x)
{
  return Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_polygamma_op<typename DerivedX::Scalar>, const DerivedN, const DerivedX>(
    n.derived(),
    x.derived()
  );
}

/** \cpp11 \returns an expression of the coefficient-wise betainc(\a x, \a a, \a b) to the given arrays.
  *
  * This function computes the regularized incomplete beta function (integral).
  *
  * \note This function supports only float and double scalar types in c++11 mode. To support other scalar types,
  * or float/double in non c++11 mode, the user has to provide implementations of betainc(T,T,T) for any scalar
  * type T to be supported.
  *
  * \sa Eigen_tf::betainc(), Eigen_tf::lgamma()
  */
template<typename ArgADerived, typename ArgBDerived, typename ArgXDerived>
inline const Eigen_tf::CwiseTernaryOp<Eigen_tf::internal::scalar_betainc_op<typename ArgXDerived::Scalar>, const ArgADerived, const ArgBDerived, const ArgXDerived>
betainc(const Eigen_tf::ArrayBase<ArgADerived>& a, const Eigen_tf::ArrayBase<ArgBDerived>& b, const Eigen_tf::ArrayBase<ArgXDerived>& x)
{
  return Eigen_tf::CwiseTernaryOp<Eigen_tf::internal::scalar_betainc_op<typename ArgXDerived::Scalar>, const ArgADerived, const ArgBDerived, const ArgXDerived>(
    a.derived(),
    b.derived(),
    x.derived()
  );
}


/** \returns an expression of the coefficient-wise zeta(\a x, \a q) to the given arrays.
  *
  * It returns the Riemann zeta function of two arguments \a x and \a q:
  *
  * \param x is the exposent, it must be > 1
  * \param q is the shift, it must be > 0
  *
  * \note This function supports only float and double scalar types. To support other scalar types, the user has
  * to provide implementations of zeta(T,T) for any scalar type T to be supported.
  *
  * \sa ArrayBase::zeta()
  */
template<typename DerivedX,typename DerivedQ>
inline const Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_zeta_op<typename DerivedX::Scalar>, const DerivedX, const DerivedQ>
zeta(const Eigen_tf::ArrayBase<DerivedX>& x, const Eigen_tf::ArrayBase<DerivedQ>& q)
{
  return Eigen_tf::CwiseBinaryOp<Eigen_tf::internal::scalar_zeta_op<typename DerivedX::Scalar>, const DerivedX, const DerivedQ>(
    x.derived(),
    q.derived()
  );
}

} // end namespace Eigen_tf

#endif // EIGEN_SPECIALFUNCTIONS_ARRAYAPI_H
