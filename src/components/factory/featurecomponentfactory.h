#ifndef FEATURECOMPONENTFACTORY_H
#define FEATURECOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class FeatureComponentFactory : public IComponentFactory
{
public:
    FeatureComponentFactory();

    Component* createComponent(int);

};

#endif // FEATURECOMPONENTFACTORY_H
