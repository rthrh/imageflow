#ifndef COMPONENT_H
#define COMPONENT_H

#include <QVariant>

struct Component
{
    // Component class should hold function pointer to be executed and list of parameters (will by varying).
    // Should also be connected to gui graphs and able to update visual display information about name, parameters etc.


    virtual bool setParameters() = 0; //s
    virtual bool getParameters() = 0;
    virtual bool pushDataToPipeline() = 0;
    virtual bool getName() = 0;

private:
    std::string compName;
    std::function<void ()> fooPointer = 0;
    std::vector < QVariant > paramList; //TODO: change QVariant to std::variant
    bool inPlace = false; //indicates if foo can be executed in-place (on single memory unit)
    //enum compType; -> (Input, Output, ImageProc, MachineLearn, Plot, User Defined...) -> create enum in namespace


};

#endif // COMPONENT_H
