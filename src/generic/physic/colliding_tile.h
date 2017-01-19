//
// Created by Pierre-Antoine on 18/01/2017.
//

#ifndef BLAZING_SUN_COLLIDING_TILE_H
#define BLAZING_SUN_COLLIDING_TILE_H

#include <memory>
#include <vector>

#include "../math/point.hpp"

namespace pag
{
    namespace bs
    {
        namespace physic
        {

            template <typename T, unsigned char U>
            class colliding_tile
            {
                typedef typename pag::bs::math::geometric_point<T,U>    geo_pt;
                typedef typename pag::bs::math::polygon<T,U>            poly;
                typedef typename std::shared_ptr<poly>                  poly_ptr;


                const geo_pt first;
                const geo_pt last;

                std::vector<poly_ptr> polygons;

            public:


            };
        }
    }
}

#endif //BLAZING_SUN_COLLIDING_TILE_H
