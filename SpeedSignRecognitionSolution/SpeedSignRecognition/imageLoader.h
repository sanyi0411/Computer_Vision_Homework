#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class ImageLoader
{
private:
	std::vector<cv::Mat> images;
public:
	ImageLoader();
	~ImageLoader();

	std::vector<cv::Mat> loadImagesFromFolder(std::string folderPath);
};

