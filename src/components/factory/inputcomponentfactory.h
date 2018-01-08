#ifndef INPUTCOMPONENTFACTORY_H
#define INPUTCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class InputComponentFactory : public IComponentFactory
{
public:
    InputComponentFactory();

    Component* createComponent(int);

};

#endif // INPUTCOMPONENTFACTORY_H
