#ifndef IMAGESHOWCOMP_H
#define IMAGESHOWCOMP_H

#include <QVariant>
#include "outputcomp.h"


class ImageShowComp : OutputComp<cv::Mat>
{
    public:
        bool displayImage() override
        {
            cv::imshow(_imshowString, _image);
            return true;
        }

        bool setImage(cv::Mat &image) override
        {
            _image = image;
        }

    private:

        cv::Mat _image;
        std::string _imgPath;
        std::string _imshowString = "empty";

};

#endif // IMAGESHOWCOMP_H
