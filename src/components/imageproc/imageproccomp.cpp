#include "imageproccomp.h"

template <class ...T>
ImageProcComp<T...>::ImageProcComp()
{

    auto tuple = std::make_tuple(1, 2.0, "dupa");
    decltype(tuple) j = 12;



}
