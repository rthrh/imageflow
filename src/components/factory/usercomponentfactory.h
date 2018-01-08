#ifndef USERCOMPONENTFACTORY_H
#define USERCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class UserComponentFactory : public IComponentFactory
{
public:
    UserComponentFactory();

    Component* createComponent(int);

};

#endif // USERCOMPONENTFACTORY_H
