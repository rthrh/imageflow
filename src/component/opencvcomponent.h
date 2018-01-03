#ifndef OPENCVCOMPONENT_H
#define OPENCVCOMPONENT_H

#include "component.h"
#include <QObject>

class OpenCvComponent : public Component
{
public:
    OpenCvComponent();

    bool setProperties();
    bool getProperties();


};

#endif // OPENCVCOMPONENT_H
