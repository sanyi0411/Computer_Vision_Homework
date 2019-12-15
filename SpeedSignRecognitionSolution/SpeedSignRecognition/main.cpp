#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "clParser.h"
#include "detectCircles.h"
#include "readSpeedLimit.h"
#include "imageLoader.h"

int main(int argc, char **argv)
{
    //Read command
    CLParser clParser(argc, argv);
    std::string path;
    bool mode, show;
    try { 
        path = clParser.getPath();
        mode = clParser.getCommand();
        show = clParser.getShow();
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    //Load images
    std::unique_ptr<ImageLoader> loader = std::make_unique<ImageLoader>();
    std::vector<cv::Mat> inputImages;
    try {
        inputImages = loader->loadImagesFromFolder(path);
    }
    catch (cv::Exception &e) {
        std::cerr << e.what() << std::endl;
    }

    //Read sign
    std::unique_ptr<ReadSpeedLimit> operation = std::make_unique<ReadSpeedLimit>();
    int found = 0;
    for (auto image : inputImages) {
        std::vector<std::string> results = operation->execute(image);
        for (auto result : results) {
            if (result.find("30") != std::string::npos) {
                found++;
            }
        }
    }

    std::cout << "Correctly detected: " << found << std::endl;
    std::cout << "We were " << (double)found / (double)inputImages.size() * 100 << "% effective" << std::endl;

    return 0;
}