#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>

struct Component
{
    virtual bool setProperties() = 0;
    virtual bool getProperties() = 0;

private:
    virtual bool pushDataToPipeline() = 0;

    void* ptr;


};

#endif // COMPONENT_H
