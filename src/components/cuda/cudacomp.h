#ifndef CUDACOMP_H
#define CUDACOMP_H

#include "../icomponent.h"

#include <QObject>

template <typename ... T>
class CudaComp : public Component<T...>
{
public:
    CudaComp();

};

#endif // CUDACOMP_H
