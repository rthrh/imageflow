#ifndef ICOMPONENTFACTORY_H
#define ICOMPONENTFACTORY_H

#include "../icomponent.h"

struct IComponentFactory
{
        virtual Component* createComponent (int) = 0;
};

#endif // ICOMPONENTFACTORY_H
