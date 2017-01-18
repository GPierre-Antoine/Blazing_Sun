
#ifndef BLAZING_SUN_FUNCTIONS_H
#define BLAZING_SUN_FUNCTIONS_H

#include "point.hpp"
#include <cmath>


namespace pag
{

    namespace bs
    {
        namespace math
        {
            template <typename iter_t>
            double pythagore (const iter_t begin,const iter_t & end, iter_t dopple)
            {

                double eax = 0;
                for(;begin<end;begin+=1,dopple+=1)
                {
                    eax += pow(*dopple - *begin,2);
                }
                return sqrt (eax);
            }

        }//math

    }//bs
}//pag

namespace std
{
    constexpr size_t FNV_prime = 14695981039346656037u;
    constexpr size_t FNV_offset_value = 1099511628211u;

    template <>
    template <typename T, unsigned char D>
    struct hash<pag::bs::math::geometric_point<T,D>>
    {

        size_t operator ()(const pag::bs::math::geometric_point<T,D>& target)
        {
            size_t hash_val = FNV_prime;
            for (const auto &i: target) {hash_val ^= i; hash_val*= FNV_offset_value; }
            return hash_val;
        }
    };

    template <>
    template <typename T, unsigned char D>
    struct hash<pag::bs::math::polygon<T,D>>
    {
        size_t operator ()(const pag::bs::math::polygon<T,D>& target)
        {
            size_t hash_val = FNV_prime;
            for (const auto &i: target) {hash_val ^= hash<pag::bs::math::geometric_point<T,D>>(i); hash_val*= FNV_offset_value; }
            return hash_val;
        }
    };
}


#endif //BLAZING_SUN_FUNCTIONS_H