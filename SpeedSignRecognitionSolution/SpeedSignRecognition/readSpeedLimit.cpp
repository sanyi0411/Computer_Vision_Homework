#include "readSpeedLimit.h"

ReadSpeedLimit::ReadSpeedLimit()
{

}

std::string ReadSpeedLimit::execute(cv::Mat input)
{
    DetectCircles circles(input);
    cv::Mat m = circles.findCircle().clone();

    ReadText read;
    return read.readSpeedLimit(m);
}
