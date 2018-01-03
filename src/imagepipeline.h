#ifndef IMAGEPIPELINE_H
#define IMAGEPIPELINE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <opencv2/core/core.hpp>


class ImagePipeline
{
public:
    ImagePipeline();

private:
    //std::function<void()> funArray[256];
    cv::Mat dupa;

};

#endif // IMAGEPIPELINE_H
