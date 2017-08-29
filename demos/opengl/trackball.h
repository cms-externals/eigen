// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2008 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_TRACKBALL_H
#define EIGEN_TRACKBALL_H

#include <Eigen/Geometry>

class Camera;

class Trackball
{
  public:

    enum Mode {Around, Local};

    Trackball() : mpCamera(0) {}

    void start(Mode m = Around) { mMode = m; mLastPointOk = false; }

    void setCamera(Camera* pCam) { mpCamera = pCam; }

    void track(const Eigen_tf::Vector2i& newPoint2D);

  protected:

    bool mapToSphere( const Eigen_tf::Vector2i& p2, Eigen_tf::Vector3f& v3);

    Camera* mpCamera;
    Eigen_tf::Vector3f mLastPoint3D;
    Mode mMode;
    bool mLastPointOk;

};

#endif // EIGEN_TRACKBALL_H
