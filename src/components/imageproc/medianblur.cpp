#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H

#include <QVariant>
#include "imageproccomp.h"


class MedianBlurComp : ImageProcComp<cv::Mat, cv::Mat, int>
{
    // void medianBlur(InputArray src, OutputArray dst, int ksize)  
    public:  
        cv::Mat m1;
        cv::Mat m2;

        std::function<void (cv::Mat, cv::Mat, int)> f = std::bind(cv::medianBlur, m1, m2, 2);


};

#endif // MEDIANBLUR_H
