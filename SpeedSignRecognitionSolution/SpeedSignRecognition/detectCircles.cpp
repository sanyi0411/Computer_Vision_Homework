#include "detectCircles.h"

DetectCircles::DetectCircles(cv::Mat image)
    :_source(image)
{

}

cv::Mat DetectCircles::findCircle()
{
    if (_source.empty()) {
        std::cerr << "Could not open image\\frame" << std::endl;
        return cv::Mat();
    }

    cv::Mat grayScale;
    cvtColor(_source, grayScale, cv::COLOR_BGR2GRAY);

    cv::Mat blackandwhite;
    cv::Canny(grayScale, blackandwhite, 50, 100, 3);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(blackandwhite.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<cv::Point> approx;
    cv::Mat dest = _source.clone();

    for (int i = 0; i < contours.size(); ++i) {
        cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true) * 0.02, true);

        if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
            continue;

        cv::Rect r = cv::boundingRect(contours[i]);

        if (approx.size() > 7 && std::abs(1 - ((double)r.width / r.height)) <= 0.2) {
            cv::Mat croppedImage = _source(r);
            cv::imshow("Cropped",croppedImage);
            cv::waitKey(0);
        }
    }

    return cv::Mat();
}

