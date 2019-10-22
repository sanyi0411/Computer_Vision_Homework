#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "clParser.h"

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
}