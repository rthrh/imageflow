#ifndef ICOMPONENTFACTORY_H
#define ICOMPONENTFACTORY_H

#include "component.h"

struct IComponentFactory
{
        virtual Component* createComponent () = 0;
        //virtual ViewerComp* createViewerComp () = 0;
        //virtual OpenCvComp* createOpenCvComp () = 0;
        //virtual ExternalComp* createExternalComp () = 0;
        //virtual UserDefinedComp* createUserDefinedComp () = 0;
        //virtual StatComp* createStatComp () = 0;
        //virtual MachineLearnComp* createMachineLearnComp () = 0;
};

#endif // ICOMPONENTFACTORY_H
