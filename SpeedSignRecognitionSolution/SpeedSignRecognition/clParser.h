#pragma once

#include <iostream>
#include "opencv2/core/utility.hpp"

class CLParser
{
public:
    CLParser(int argc, char **argv);

    bool getCommand() const;
    std::string getPath() const;
    bool getShow() const;

    std::string keys =
        "{help h usage ? |      | print this message   }"
        "{path           |      | path to the folder containing images   }"
        "{dev            |      | run in developer mode   }"
        "{show           |      | show intermediate images   }";

private:
    cv::CommandLineParser parser;
};

