#pragma once

#include "detectCircles.h"
#include "readText.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class ReadSpeedLimit
{
public:
    ReadSpeedLimit();
    std::string execute(std::vector<cv::Mat> input);
};

