#include "readSpeedLimit.h"

ReadSpeedLimit::ReadSpeedLimit()
{
}

std::vector<std::string> ReadSpeedLimit::execute(cv::Mat image)
{
    DetectCircles detectCircles;
    std::vector<cv::Mat> foundCircles = detectCircles.findCircles(image);
       
    ReadText read;
    return read.readSpeedLimit(foundCircles);
}
