#ifndef IMAGEPROCCOMPONENTFACTORY_H
#define IMAGEPROCCOMPONENTFACTORY_H

#include "icomponentfactory.h"
#include "../icomponent.h"

class ImageProcComponentFactory : public IComponentFactory
{
public:
    ImageProcComponentFactory();

    Component* createComponent(int);

};

#endif // IMAGEPROCCOMPONENTFACTORY_H
