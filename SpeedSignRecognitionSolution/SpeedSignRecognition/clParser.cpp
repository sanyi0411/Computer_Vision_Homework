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
