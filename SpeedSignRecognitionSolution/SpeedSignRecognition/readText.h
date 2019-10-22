#pragma once

#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class ReadText
{
public:
    ReadText(cv::Mat input);
    
    int readSpeedLimit();

private:
    cv::Mat _source;
    
};

