#include "readSpeedLimit.h"

ReadSpeedLimit::ReadSpeedLimit()
{
}

std::vector<std::string> ReadSpeedLimit::execute(cv::Mat image, bool show)
{
    DetectCircles detectCircles;
    std::vector<cv::Mat> foundCircles = detectCircles.findCircles(image, show);
       
    ReadText read;
    return read.readSpeedLimit(foundCircles, show);
}
