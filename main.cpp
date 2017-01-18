#include <iostream>

#include "src/generic/math/polygon.hpp"
#include "src/generic/math/matrix.hpp"

int main ()
{
    pag::bs::math::geometric_point<int,3> test_point {1,1,1};
    pag::bs::math::geometric_point<int,3> vector {0,0,8};
    pag::bs::math::matrix<int,3> mat(vector);
    std::cout << "matrix multiplication : ";

    display_ar (mat * test_point,std::cout);

    std::endl(std::cout);




    return 0;
}