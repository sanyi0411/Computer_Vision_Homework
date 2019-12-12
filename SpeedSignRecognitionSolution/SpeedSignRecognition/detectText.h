#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class DetectText
{
public:
    DetectText(cv::Mat input);

    cv::Mat detect();

private:
    cv::Mat _source;
};

