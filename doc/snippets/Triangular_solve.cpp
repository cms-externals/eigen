Matrix3d m = Matrix3d::Zero();
m.triangularView<Eigen_tf::Upper>().setOnes();
cout << "Here is the matrix m:\n" << m << endl;
Matrix3d n = Matrix3d::Ones();
n.triangularView<Eigen_tf::Lower>() *= 2;
cout << "Here is the matrix n:\n" << n << endl;
cout << "And now here is m.inverse()*n, taking advantage of the fact that"
        " m is upper-triangular:\n"
     << m.triangularView<Eigen_tf::Upper>().solve(n) << endl;
cout << "And this is n*m.inverse():\n"
     << m.triangularView<Eigen_tf::Upper>().solve<Eigen_tf::OnTheRight>(n);
