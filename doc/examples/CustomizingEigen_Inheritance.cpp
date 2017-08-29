#include <Eigen/Core>
#include <iostream>

class MyVectorType : public Eigen_tf::VectorXd
{
public:
    MyVectorType(void):Eigen_tf::VectorXd() {}

    // This constructor allows you to construct MyVectorType from Eigen expressions
    template<typename OtherDerived>
    MyVectorType(const Eigen_tf::MatrixBase<OtherDerived>& other)
        : Eigen_tf::VectorXd(other)
    { }

    // This method allows you to assign Eigen expressions to MyVectorType
    template<typename OtherDerived>
    MyVectorType& operator=(const Eigen_tf::MatrixBase <OtherDerived>& other)
    {
        this->Eigen_tf::VectorXd::operator=(other);
        return *this;
    }
};

int main()
{
  MyVectorType v = MyVectorType::Ones(4);
  v(2) += 10;
  v = 2 * v;
  std::cout << v.transpose() << std::endl;
}
