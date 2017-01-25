//
// Created by Pierre-Antoine on 14/11/2015.
//

#ifndef BLAZING_SUN_POLYGON_HPP
#define BLAZING_SUN_POLYGON_HPP

#include <vector>

#include "point.hpp"
#include "functions.h"

namespace pag
{
    namespace bs
    {
        namespace math
        {

            template <typename T, unsigned char D>
            class polygon
            {
            public:
                typedef T value_type;

                template <typename U, unsigned char E>
                friend void swap (polygon<U,E> & first,polygon<U,E> & second);
                polygon ();
                polygon (std::initializer_list<pag::bs::math::geometric_point<T,D>> initializer_list);
                polygon (const polygon & lvalue);
                polygon (polygon && prvalue);

                polygon& operator= (polygon other);

                ~polygon();

                typename std::vector<pag::bs::math::geometric_point<T,D>>::iterator begin ();
                typename std::vector<pag::bs::math::geometric_point<T,D>>::const_iterator begin () const;
                typename std::vector<pag::bs::math::geometric_point<T,D>>::iterator end ();
                typename std::vector<pag::bs::math::geometric_point<T,D>>::const_iterator end () const;

                pag::bs::math::geometric_point<T,D>& get_center () const;
                double & get_radius () const;

            private:
                std::vector<pag::bs::math::geometric_point<T,D>> points;

                volatile pag::bs::math::geometric_point<T,D> center;
                volatile double radius;
                volatile bool should_update_center;
                volatile bool should_update_radius;
            protected:

            };

            template <typename U, unsigned char E>
            void swap (polygon<U,E> & first,polygon<U,E> & second)
            {
                using std::swap;
                swap (first.points,second.points);
                swap (first.center,second.center);
                swap (first.radius,second.radius);
            }

            template <typename T, unsigned char D>
            pag::bs::math::geometric_point<T,D>& polygon<T,D>::get_center () const
            {
                if (should_update_center)
                {
                    center *=0;
                    for (const auto & i:points)
                    {
                        center += i;
                    }
                    center /= points.size();
                }
                return center;
            }

            template <typename T, unsigned char D>
            double& polygon<T,D>::get_radius () const
            {
                if (should_update_radius)
                {
                    get_center ();
                    double radii = 0;
                    for (const auto &i : points)
                    {
                        radii = max(radii,pag::bs::math::pythagora<T*>(i.begin(),i.end(),center.begin()));
                    }
                }
                return radius;
            }

            template <typename T, unsigned char D>
            polygon<T,D>::polygon()
            {
                points.operator = ({pag::bs::math::geometric_point<T,D>(),pag::bs::math::geometric_point<T,D>(),
                                    pag::bs::math::geometric_point<T,D>(),pag::bs::math::geometric_point<T,D>()});
                center = pag::bs::math::geometric_point<T,D>();
                radius=0;
            }

            template <typename T, unsigned char D>
            polygon<T,D>::polygon (std::initializer_list<pag::bs::math::geometric_point<T, D>> initializer_list)
                    : points (initializer_list)
            {}

            template <typename T, unsigned char D>
            polygon<T,D>::polygon (const polygon & lvalue)
            {
                std::copy (lvalue.points.begin(),lvalue.points.end(),points.begin());
            }

            template <typename T, unsigned char D>
            polygon<T,D>::polygon (polygon && prvalue) : points (std::move(prvalue.points))
            {

            }


            template <typename T, unsigned char D>
            polygon<T,D>::~polygon()
            {

            }


            template <typename T, unsigned char D>
            polygon<T,D>& polygon<T,D>::operator = (polygon<T,D> other)
            {
                swap (*this,other);
                return *this;
            }

            //<editor-fold desc="typedefs">
            template <typename T>
            using polygon_2d = polygon<T,2>;
            template <typename T>
            using polygon_3d = polygon<T,3>;
            //</editor-fold>

            template <typename T, unsigned char D>
            typename std::vector<pag::bs::math::geometric_point<T,D>>::iterator  polygon<T,D>::begin ()
            {
                return points.begin ();
            }
            template <typename T, unsigned char D>
            typename std::vector<pag::bs::math::geometric_point<T,D>>::const_iterator  polygon<T,D>::begin () const
            {
                return points.begin ();
            }
            template <typename T, unsigned char D>
            typename std::vector<pag::bs::math::geometric_point<T,D>>::iterator  polygon<T,D>::end ()
            {
                return points.end ();
            }
            template <typename T, unsigned char D>
            typename std::vector<pag::bs::math::geometric_point<T,D>>::const_iterator polygon<T,D>::end () const
            {
                return points.end ();
            }


        }//math
    }
}
namespace std
{
#include "constants.h"


    template <>
    template <typename T, unsigned char D>
    struct hash<pag::bs::math::polygon<T,D>>
    {
        size_t operator ()(const pag::bs::math::polygon<T,D>& target) const
        {
            size_t hash_val = pag::bs::math::FNV_prime;
            for (const auto &i: target) {hash_val ^= hash<pag::bs::math::geometric_point<T,D>>(i); hash_val*= pag::bs::math::FNV_offset_value; }
            return hash_val;
        }
    };
}
#endif //BLAZING_SUN_POLYGON_HPP
