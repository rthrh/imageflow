#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H

#include <QVariant>
#include "imageproccomp.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class MedianBlurComp : ImageProcComp<int,int,int> //types for testing purposes
{
    
    // void medianBlur(InputArray src, OutputArray dst, int ksize)
    

    //auto foo = std::bind (cv::medianBlur(InputArray src, OutputArray dst, int ksize));




};

#endif // MEDIANBLUR_H
