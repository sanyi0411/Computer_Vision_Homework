#include "imageLoader.h"

ImageLoader::ImageLoader()
{
}


ImageLoader::~ImageLoader()
{
}

std::vector<cv::Mat> ImageLoader::loadImagesFromFolder(std::string folderPath)
{
	std::vector<cv::Mat> results;
	std::vector<std::string> files;
	cv::glob(folderPath, files);

	for (auto file : files) {
		cv::Mat image = cv::imread(file);
		if (image.empty()) {
			std::cout << file << " is invalid!" << std::endl;
			continue;
		}
		results.push_back(image);
	}

	return results;
}
