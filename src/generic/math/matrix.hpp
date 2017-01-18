
#ifndef BLAZING_SUN_MATRIX_H
#define BLAZING_SUN_MATRIX_H

#include <type_traits>

#include "point.hpp"

namespace pag
{
    namespace bs
    {
        namespace math
        {
            template <typename T,unsigned char D,
                    typename = typename std::enable_if<std::is_arithmetic<T>::value,T>::type>
            class matrix
            {
                std::array<std::array<T,D+1>,D+1> grid;
            public:

                matrix (const pag::bs::math::geometric_point<T,D>& point=pag::bs::math::geometric_point<T,D>());
                matrix (const matrix & other); //copy constructor
//                matrix (matrix && other); //move constructor

                pag::bs::math::geometric_point<T,D> operator * (const pag::bs::math::geometric_point<T,D> & other);

                template <typename K, unsigned char L>
                friend void swap(matrix<K,L> & first,matrix<K,L> & second);

                const std::array<T,D+1>* begin();
                const std::array<T,D+1>* begin() const;
                const std::array<T,D+1>* end ();
                const std::array<T,D+1>* end () const;
            private:
            protected:
            };

            template <typename T, unsigned char E>
            void swap (matrix<T,E>& first, matrix<T,E>& second)
            {
                using std::swap;
                swap(first.grid,second.grid);
            }

            template <typename T,unsigned char D, typename E>
            matrix<T,D,E> ::matrix (const pag::bs::math::geometric_point<T,D> & point)
            {

                for (std::size_t i = 0;i< grid.size();++i)
                {
                    grid[i].fill(0);
                    grid[i][i] = 1;
                }
                for (std::size_t i =0;i< grid.size();++i)
                {
                    grid[i][grid.size ()-1] = point[i];
                }
            }

            template <typename T,unsigned char D, typename E>
            matrix<T,D,E>::matrix (const matrix & other)
            {
                std::copy(other.grid.begin (),other.grid.end (),this->grid.begin ());
            }

//            template <typename T,unsigned char D, typename E>
//            matrix<T,D,E>::matrix (matrix && other)
//            {
//                swap(other,*this);
//            }

            template <typename T,unsigned char D, typename E>
            pag::bs::math::geometric_point<T,D> matrix<T,D,E>::operator * (const pag::bs::math::geometric_point<T, D> & other)
            {
                pag::bs::math::geometric_point<T,D> eax = other;
                for (unsigned i =0;i<grid.size ();++i)
                {
                    T sum =0;
                    for (unsigned j =0;j<grid.size ();++j)
                    {
                        sum += grid[i][j] * other[j];
                    }
                    eax[i] = sum;
                }
                return eax;
            }
            template <typename T,unsigned char D, typename E>
            const std::array<T,D+1>* matrix<T,D,E>::begin()
            {
                return grid.begin ();
            }
            template <typename T,unsigned char D, typename E>
            const std::array<T,D+1>* matrix<T,D,E>::begin() const
            {
                return grid.begin ();
            }
            template <typename T,unsigned char D, typename E>
            const std::array<T,D+1>* matrix<T,D,E>::end ()
            {
                return grid.end ();
            }
            template <typename T,unsigned char D, typename E>
            const std::array<T,D+1>* matrix<T,D,E>::end () const
            {
                return grid.end ();
            }


        }//ns math
    }//ns bs
}//ns pag

#endif //BLAZING_SUN_MATRIX_H