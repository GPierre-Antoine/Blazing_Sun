#include <iostream>
#include <array>
#include <numeric>
#include "src/generic/math/polygon.hpp"
#include "src/generic/math/matrix.hpp"


typedef pag::bs::math::matrix<int,3> normatrix;

template <typename T>
std::ostream& display_ar(const T& sec, std::ostream& i)
{
    for (const auto&e : sec)
    {
        std::cout << e << ", ";
    }
    return i;
}
template <typename T>
std::ostream& display_mat (const T& a,std::ostream&i)
{
    for (const auto&sec : a)
    {
        display_ar (sec,i);
        std::endl(std::cout);
    }
    return i;
}
normatrix&& test()
{
    pag::bs::math::geometric_point<int,3> pt{8,8,8};
    normatrix t(pt);
    normatrix t2(pt);

    return std::move(t);
}


int main ()
{
    pag::bs::math::geometric_point<int,3> test_point {1,1,1};
    pag::bs::math::geometric_point<int,3> vector {0,0,8};
    pag::bs::math::matrix<int,3> mat(vector);
    std::cout << "matrix multiplication : ";

    display_ar (mat * test_point,std::cout);

    std::endl(std::cout);

    std::cout << "matrix swap" << std::endl;
    normatrix n = test ();

    std::cout << "matrix swaped" << std::endl;

    display_mat (n,std::cout);



    return 0;
}