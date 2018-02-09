#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H

#include <QVariant>
#include "imageproccomp.h"


class MedianBlurComp : ImageProcComp<cv::Mat, cv::Mat, int>
{
    /* void medianBlur(InputArray src, OutputArray dst, int ksize) */
public:

private:
        cv::Mat m1;
        cv::Mat m2;

        //Functor foo(void, cv:Mat, cv::Mat, int);
        std::function<void (cv::Mat, cv::Mat, int)> f = std::bind(cv::medianBlur, m1, m2, 2);




        //auto ptr =
};

#endif // MEDIANBLUR_H
