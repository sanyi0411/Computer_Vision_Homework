#pragma once

#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class DetectCircles
{
public:
    DetectCircles(cv::Mat image);

    cv::Mat findCircle();

private:
    cv::Mat _source;
   
};

