#include "readSpeedLimit.h"

ReadSpeedLimit::ReadSpeedLimit()
{
}

std::string ReadSpeedLimit::execute(std::vector<cv::Mat> input)
{
	for (auto image : input) {
		DetectCircles circles(image);
		cv::Mat m = circles.findCircle().clone();
		
		ReadText read;
		return read.readSpeedLimit(m);
	}
}
