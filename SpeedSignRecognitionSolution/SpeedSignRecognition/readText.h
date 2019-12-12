#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>

class ReadText
{
public:
    ReadText();
    
    std::string readSpeedLimit(cv::Mat input);

    void setThresholdValue(int input);
private:
    int _thresholdValue = 110;
};

