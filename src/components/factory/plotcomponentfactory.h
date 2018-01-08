#ifndef PLOTCOMPONENTFACTORY_H
#define PLOTCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class PlotComponentFactory : public IComponentFactory
{
public:
    PlotComponentFactory();

    Component* createComponent(int);

};

#endif // PLOTCOMPONENTFACTORY_H
