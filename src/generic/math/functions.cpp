//
// Created by Pierre-Antoine on 18/01/2017.
//
#include <iostream>

#include "functions.h"


double pag::bs::math::zipf_law (size_t pool_size, const size_t number_of_chucks, size_t chunck_index)
{
    using std::cout;
    using std::endl;

    double *lookup = new double[number_of_chucks];
    double value = 0;
    for (unsigned i{1};i<number_of_chucks+1;++i)
    {
        value +=(1./i);
        lookup[i-1] = value;
    }
    double eax = 0;
    if (chunck_index)
    {
        eax = lookup[chunck_index] - lookup[chunck_index-1];
    }
    else
        eax=1;
    delete[] lookup;
    return (eax/value)*pool_size;
}