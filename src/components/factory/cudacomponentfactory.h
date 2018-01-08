#ifndef CUDACOMPONENTFACTORY_H
#define CUDACOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class CudaComponentFactory : public IComponentFactory
{
public:
    CudaComponentFactory();

    Component* createComponent(int);

};

#endif // CUDACOMPONENTFACTORY_H
