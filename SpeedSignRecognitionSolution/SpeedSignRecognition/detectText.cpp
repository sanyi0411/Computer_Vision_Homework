#include "detectText.h"

DetectText::DetectText(cv::Mat input)
    :_source(input)
{
}

cv::Mat DetectText::detect()
{
    cvtColor(_source, _source, cv::COLOR_BGR2GRAY);
    cv::Sobel(_source, _source, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
    cv::threshold(_source, _source, 0, 255, cv::THRESH_OTSU + cv::THRESH_BINARY);
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(17, 3));
    cv::morphologyEx(_source, _source, cv::MORPH_CLOSE, element);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(_source, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    return cv::Mat();
}
