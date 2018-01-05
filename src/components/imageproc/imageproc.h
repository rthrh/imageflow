#ifndef IMAGEPROCCOMP_H
#define IMAGEPROCCOMP_H

#include "../component.h"
#include <QObject>

class ImageProcComp : public Component
{
public:
    ImageProcComp();

    bool setProperties();
    bool getProperties();


};

#endif // IMAGEPROCCOMP_H
