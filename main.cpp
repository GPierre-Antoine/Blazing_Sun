#include <iostream>
#include <array>

#include "src/generic/math/polygon.hpp"


int main ()
{
    pag::bs::math::polygon<int,3> blabla {{0,0,0},{0,1,0},{1,1,0},{1,0,0}};
    for (const auto& i : blabla)
    {
        for (const auto & j : i)
        {
            std::cout << j << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}