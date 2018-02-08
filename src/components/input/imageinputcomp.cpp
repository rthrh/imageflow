#ifndef IMAGEINPUTCOMP_H
#define IMAGEINPUTCOMP_H

#include <QVariant>
#include "inputcomp.h"


class ImageInputComp : InputComp<cv::Mat, cv::Mat, int>
{
    public:
        bool openFile(std::string filename)
        {
            //TODO: Check first if input image is grayscale or rgb
            _src = cv::imread(filename, CV_LOAD_IMAGE_COLOR);

            if(!_src.data)
            {
                std::cout <<  "Could not open or find the image" << std::endl ;
                return false;
            }

        }

    private:
        cv::Mat _src;
        std::string _imgPath;


};

#endif // IMAGEINPUTCOMP_H
