//
// Created by Pierre-Antoine on 17/01/2017.
//

#ifndef BLAZING_SUN_TEST_ENABLE_IF_H
#define BLAZING_SUN_TEST_ENABLE_IF_H

#include <type_traits>

    template <typename T,typename = typename std::enable_if<std::is_arithmetic<T>::value,T>::type>
    class foo
    {
    public:
        void bar();
    };

    template <typename T, typename U>
    void foo<T, U>::bar ()
    {
    }




#endif //BLAZING_SUN_TEST_ENABLE_IF_H