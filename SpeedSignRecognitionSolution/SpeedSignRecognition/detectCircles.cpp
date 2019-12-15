#include "detectCircles.h"

DetectCircles::DetectCircles()
{
}

std::vector<cv::Mat> DetectCircles::findCircles(cv::Mat image)
{
    if (image.empty()) {
        std::cerr << "Could not open image\\frame" << std::endl;
        return cv::Mat();
    }
    /*
    cv::Mat grayScale;
    cvtColor(_source, grayScale, cv::COLOR_BGR2GRAY);

    cv::Mat blackandwhite;
    cv::Canny(grayScale, blackandwhite, 50, 100, 3);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(blackandwhite.clone(), contours, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

    std::vector<cv::Point> approx;
    cv::Mat dest = _source.clone();

    cv::Mat croppedImage;

    for (int i = 0; i < contours.size(); ++i) {
        cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true) * 0.02, true);

        if (std::fabs(cv::contourArea(contours[i])) < 2000 || !cv::isContourConvex(approx))
            continue;

        cv::Rect r = cv::boundingRect(contours[i]);

        if (approx.size() > 7 && std::abs(1 - ((double)r.width / r.height)) <= 0.2) {
            croppedImage = grayScale(r);

            return croppedImage;
        }
    }

    return croppedImage;
    */

    // Convert input image to HSV
    cv::Mat imageHSV;
    cv::cvtColor(image, imageHSV, cv::COLOR_BGR2HSV);

    // Threshold the HSV image, keep only the red pixels
    cv::Mat lowerRedHueRange;
    cv::Mat upperRedHueRange;
    cv::inRange(imageHSV, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), lowerRedHueRange);
    cv::inRange(imageHSV, cv::Scalar(160, 100, 100), cv::Scalar(179, 255, 255), upperRedHueRange);
    
    // Combine the above two images
    cv::Mat redHueImage;
    cv::addWeighted(lowerRedHueRange, 1.0, upperRedHueRange, 1.0, 0.0, redHueImage);
    
    // Use the Hough transform to detect circles in the combined threshold image
    std::vector<cv::Vec3f> circles;
    std::vector<cv::Mat> croppedImages;
    cv::HoughCircles(redHueImage, circles, cv::HOUGH_GRADIENT, 1, redHueImage.rows / 8, 100, 20, 0, 0);
    for (size_t currentCircle = 0; currentCircle < circles.size(); ++currentCircle) {
        cv::Point center(std::round(circles[currentCircle][0]), std::round(circles[currentCircle][1]));
        int radius = std::round(circles[currentCircle][2]);

        cv::circle(imageHSV, center, radius, cv::Scalar(0, 255, 0), 5);
    
        const cv::Rect r(std::max(center.x - radius, 0), std::max(center.y - radius, 0), std::min(radius * 2, image.cols), std::min(radius * 2, image.rows));
        cv::Mat croppedImage;
        try {
            croppedImage = image(r).clone();
            croppedImages.push_back(croppedImage);
        }
        catch (cv::Exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return croppedImages;

}

