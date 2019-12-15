#pragma once

#include <iostream>
#include "opencv2/core/utility.hpp"

class CLParser
{
public:
    CLParser(int argc, char **argv);

    bool getMode() const;
    std::string getPath() const;
    bool getShow() const;
    std::string getLimit() const;

    std::string keys =
        "{help h usage ? |      | print this message   }"
        "{path           |      | path to the folder containing images   }"
        "{dev            |      | run in developer mode   }"
        "{show           |      | show intermediate images   }"
        "{limit          |      | what number should the program find   }";

private:
    cv::CommandLineParser parser;
};

