#ifndef OUTPUTCOMP_H
#define OUTPUTCOMP_H

#include <QObject>
#include "../icomponent.h"
//#include <opencv2/highgui/highgui.hpp>

template <class... T>
class OutputComp : public Component<T...> {
 public:
  OutputComp();
  virtual bool displayImage() = 0;
  virtual bool setImage(cv::Mat &_image) = 0;

 private:
  cv::Mat image;
};

#endif  // OUTPUTCOMP_H
