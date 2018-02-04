#ifndef IMAGEPROCCOMP_H
#define IMAGEPROCCOMP_H

#include "../icomponent.h"
#include <QObject>

template < class ... T >
class ImageProcComp : public Component<T...>
{
public:
    ImageProcComp();

};

#endif // IMAGEPROCCOMP_H
