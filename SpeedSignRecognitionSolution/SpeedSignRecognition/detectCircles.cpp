#include "detectCircles.h"

DetectCircles::DetectCircles()
{
}

std::vector<cv::Mat> DetectCircles::findCircles(cv::Mat image, bool show)
{
    if (image.empty()) {
        std::cerr << "Could not open image\\frame" << std::endl;
        return cv::Mat();
    }

    cv::medianBlur(image, image, 3);
 
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
    cv::Mat imageToShow = image.clone();
    cv::HoughCircles(redHueImage, circles, cv::HOUGH_GRADIENT, 1, redHueImage.rows / 8, 100, 20, 0, 0);
    for (size_t currentCircle = 0; currentCircle < circles.size(); ++currentCircle) {
        cv::Point center(std::round(circles[currentCircle][0]), std::round(circles[currentCircle][1]));
        int radius = std::round(circles[currentCircle][2]);

        cv::circle(imageToShow, center, radius, cv::Scalar(0, 255, 0), 5);
    
        const cv::Rect r(std::max(center.x - radius, 0), std::max(center.y - radius, 0), std::min(radius * 2, image.cols), std::min(radius * 2, image.rows));
        cv::Mat croppedImage;
        try {
            croppedImage = image(r).clone();
            croppedImages.push_back(croppedImage);
        }
        catch (cv::Exception &e) {
            //std::cout << e.what() << std::endl;
        }
    }

    if(show) {
        cv::imshow("Found circles", imageToShow);
    }

    return croppedImages;

}

