//
// Created by Pierre-Antoine on 11/10/2015.
//

#ifndef BLAZING_SUN_POINT_HPP
#define BLAZING_SUN_POINT_HPP

#include <array>

namespace math
{
    template <typename T,unsigned char D, typename = typename std::enable_if<std::is_arithmetic<T>::value,T>::type>
    class geometric_point
    {
    public:
        typedef T                                   value_type;
        typedef value_type*          		        iterator;
        typedef const value_type*			        const_iterator;


        friend void swap (geometric_point &first,geometric_point &second)
        {
            using std::swap;
            swap (first.coordinates,second.coordinates);
        }

        ~geometric_point ();

        geometric_point ();
        geometric_point (std::initializer_list<T> initializer_list);
        geometric_point (const geometric_point & lvalue);
        geometric_point (geometric_point && prvalue);

        T& operator[](const size_t & index) noexcept;
        const T& operator[](const size_t & index) const noexcept;

        geometric_point& operator+= (const geometric_point & other) noexcept;
        geometric_point& operator-= (const geometric_point & other) noexcept;

        geometric_point& operator= (geometric_point other) noexcept;

        geometric_point& operator*= (unsigned number) noexcept;
        geometric_point& operator/= (unsigned number) noexcept;

        iterator begin ();
        const_iterator begin () const;
        iterator end ();
        const_iterator end () const;

    private:
        std::array<T,D+1> coordinates;

    };

    //<editor-fold desc="stand alone functions">
    template <typename T, unsigned short D>
    math::geometric_point<T,D> operator+ (math::geometric_point<T,D> f, const math::geometric_point<T,D>& s)
    {
        f+=s;
        return f;
    }

    template <typename T, unsigned short D>
    math::geometric_point<T,D> operator- (math::geometric_point<T,D> f, const math::geometric_point<T,D>& s)
    {
        f-=s;
        return f;
    }

    template <typename T, unsigned short D>
    math::geometric_point<T,D> operator/ (math::geometric_point<T,D> f, const unsigned & s)
    {
        f/=s;
        return f;
    }

    template <typename T, unsigned short D>
    math::geometric_point<T,D> operator* (math::geometric_point<T,D> f, const unsigned & s)
    {
        f*=s;
        return f;
    }
    //</editor-fold>

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>::~geometric_point ()
    {

    }

    //<editor-fold desc="ctors">

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>::geometric_point ()
    {
        coordinates.fill (0);
    }


    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>::geometric_point (std::initializer_list<T> initializer_list)
    {
        std::copy (initializer_list.begin (),initializer_list.end (),coordinates.begin ());
    }

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>::geometric_point (const geometric_point<T,D,U> & lvalue)
    {
        std::copy (lvalue.coordinates.begin (),lvalue.coordinates.end (),coordinates.begin ());
    }

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>::geometric_point (geometric_point<T,D,U> && prvalue) :coordinates(std::move(prvalue.coordinates))
    {
    }
    //</editor-fold>

    //<editor-fold desc="operators">

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>& geometric_point<T,D,U>::operator += (const geometric_point<T,D,U> & other) noexcept
    {
        for (unsigned char i {0};i<D;++i)
        {
            coordinates[i] += other.coordinates[i];
        }
        return *this;
    }

    template <typename T, unsigned char D, typename U>
    geometric_point<T,D,U>& geometric_point<T,D,U>::operator -= (const geometric_point<T,D,U> & other) noexcept
    {
        for (unsigned char i {0};i<D;++i)
        {
            coordinates[i] -= other.coordinates[i];
        }
        return *this;
    }

    template <typename T, unsigned char D, typename U>
    geometric_point<T,D,U>& geometric_point<T,D,U>::operator = (geometric_point<T,D,U> other) noexcept
    {
        swap (*this,other);
        return *this;
    }

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>& geometric_point<T,D,U>::operator *= (unsigned number) noexcept
    {
        for (unsigned char i {0};i<D;++i)
        {
            coordinates[i] *= number;
        }
        return *this;
    }

    template <typename T,unsigned char D, typename U>
    geometric_point<T,D,U>& geometric_point<T,D,U>::operator /= (unsigned number) noexcept
    {
        for (unsigned char i {0};i<D;++i)
        {
            coordinates[i] /= number;
        }
        return *this;
    }


    template <typename T,unsigned char D, typename U>
    const T& geometric_point<T,D,U>::operator [] (const size_t & index) const noexcept
    {
        return coordinates[index];
    }

    template <typename T,unsigned char D, typename U>
    T& geometric_point<T,D,U>::operator [] (const size_t & index) noexcept
    {
        return const_cast<T&>(static_cast<const T &> (this->operator[] (index)));
    }
    //</editor-fold>


    template <typename T, unsigned char D, typename U>
    typename geometric_point<T,D,U>::iterator geometric_point<T,D,U>::begin ()
    {
        return coordinates.begin ();
    }

    template <typename T, unsigned char D, typename U>
    typename geometric_point<T,D,U>::const_iterator geometric_point<T,D,U>::begin () const
    {
        return coordinates.begin ();
    }

    template <typename T, unsigned char D, typename U>
    typename geometric_point<T,D,U>::iterator geometric_point<T,D,U>::end ()
    {
        return coordinates.end ();
    }

    template <typename T, unsigned char D, typename U>
    typename geometric_point<T,D,U>::const_iterator geometric_point<T,D,U>::end () const
    {
        return coordinates.end ();
    }




    typedef geometric_point<signed long long int,2> point_2d;
    typedef geometric_point<signed long long int,3> point_3d;



}//math

#endif //BLAZING_SUN_POINT_HPP