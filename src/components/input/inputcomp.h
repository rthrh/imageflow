#ifndef INPUTCOMP_H
#define INPUTCOMP_H

#include "../icomponent.h"
#include <QObject>

template < class ... T >
class InputComp : public Component<T...>
{
public:
    InputComp();
    virtual bool openFile() = 0;

private:
    cv::Mat image;

};

#endif // INPUTCOMP_H
