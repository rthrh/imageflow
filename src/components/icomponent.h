#ifndef COMPONENT_H
#define COMPONENT_H

#include <QVariant>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "functor.cpp"

template < typename retType, class ... Args >
struct Component
{
    // Component class should hold function pointer to be executed and list of parameters (will by varying).
    // Should also be connected to gui graphs and able to update visual display information about name, parameters etc.
    //Component(T...);

    virtual bool setParameters() = 0;
    virtual bool getParameters() = 0;

    virtual bool setName() = 0;
    virtual bool getName() = 0;

    virtual bool bindToFunctor() = 0;    
    virtual bool pushDataToPipeline() = 0;

    virtual size_t getInputWidth() = 0;
    virtual size_t getInputHeight() = 0;
    virtual size_t getOutputWidth() = 0;
    virtual size_t getOutputHeight() = 0;

private:
    std::string compName;

    std::tuple<Args ...> argsList;

    Functor<retType,Args ...> foo(retType,Args ...); //default constructor to be removed

    size_t inputWidth;
    size_t inputHeight;
    size_t outputWidth;
    size_t outputHeight;

    std::vector < QVariant > paramList; //TODO: change QVariant to std::variant
    bool inPlace = false; //indicates if foo can be executed in-place (on single memory unit)


};

#endif // COMPONENT_H
