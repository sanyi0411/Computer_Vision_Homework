#pragma once

#include <iostream>
#include "opencv2/core/utility.hpp"

class CLParser
{
public:
    CLParser(int argc, char **argv);

    bool getCommand() const;

    std::string keys =
        "{help h usage ? |      | print this message   }"
        "{dev            |      | run in developer mode   }";

private:
    cv::CommandLineParser parser;
};

