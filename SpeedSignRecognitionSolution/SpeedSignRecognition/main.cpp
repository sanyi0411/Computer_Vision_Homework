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
    CLParser clParser(argc, argv);

    try 
    { 
        bool mode = clParser.getCommand();
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::unique_ptr<ImageLoader> loader(new ImageLoader);
	std::vector<cv::Mat> inputImages = loader->loadImagesFromFolder("D:/Kepek/OpenCV/30");

	std::unique_ptr<ReadSpeedLimit> operation(new ReadSpeedLimit);
	operation->execute(inputImages);

    return 0;
}