#pragma once

#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class DetectCircles
{
public:
    DetectCircles();

    std::vector<cv::Mat> findCircles(cv::Mat image, bool show);

private:
    cv::Mat _source;
   
};

