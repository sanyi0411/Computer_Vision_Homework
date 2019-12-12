#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "clParser.h"
#include "detectCircles.h"
#include "readSpeedLimit.h"

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

    cv::Mat frame;

    cv::VideoCapture cap;
    cap.open(0);

    if (cap.isOpened() == false)
    {
        std::cout << "Cannot open the video camera" << std::endl;
        std::cin.get();
        return -1;
    }

    ReadSpeedLimit *operation = new ReadSpeedLimit;

    while (true)
    {
        cap >> frame;
        if (frame.empty())
        {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get();
            break;
        }
        cv::imshow("Webcam", frame);

        std::string limit = operation->execute(frame);
        std::cout << limit << std::endl;
        cv::waitKey(20);
    }


    return 0;
}