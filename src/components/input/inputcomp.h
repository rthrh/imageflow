#ifndef INPUTCOMP_H
#define INPUTCOMP_H

#include "../icomponent.h"
#include <QObject>

class InputComp : public Component
{
public:
    InputComp();

private:
    cv::Mat image;

};

#endif // INPUTCOMP_H
