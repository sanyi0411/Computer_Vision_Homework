#include "clParser.h"

CLParser::CLParser(int argc, char **argv)
    :parser(argc, argv, keys)
{
}

bool CLParser::getCommand() const
{
    bool command = parser.has("dev");

    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    return command;
}

std::string CLParser::getPath() const
{
    std::string imgPath = parser.get<std::string>("path");

    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    return imgPath;
}

bool CLParser::getShow() const
{
    bool show = parser.has("show");

    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    return show;}
