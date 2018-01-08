#ifndef OUTPUTCOMPONENTFACTORY_H
#define OUTPUTCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class OutputComponentFactory : public IComponentFactory
{
public:
    OutputComponentFactory();

    Component* createComponent(int);

};

#endif // OUTPUTCOMPONENTFACTORY_H
