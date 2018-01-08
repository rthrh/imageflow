#ifndef MACHINELEARNCOMPONENTFACTORY_H
#define MACHINELEARNCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class MachineLearnComponentFactory : public IComponentFactory
{
public:
    MachineLearnComponentFactory();

    Component* createComponent(int);

};

#endif // MACHINELEARNCOMPONENTFACTORY_H
