
#ifndef BLAZING_SUN_FUNCTIONS_H
#define BLAZING_SUN_FUNCTIONS_H

#include <cmath>
#include "constants.h"

namespace pag
{

    namespace bs
    {
        namespace math
        {
            template <typename iter_t>
            double pythagora (const iter_t begin, const iter_t & end, iter_t dopple)
            {

                double eax = 0;
                for(;begin<end;begin+=1,dopple+=1)
                {
                    eax += pow(*dopple - *begin,2);
                }
                return sqrt (eax);
            }

            double zipf_law (size_t pool_size, const size_t number_of_chucks, size_t chunck_index);

        }//math

    }//bs
}//pag




#endif //BLAZING_SUN_FUNCTIONS_H