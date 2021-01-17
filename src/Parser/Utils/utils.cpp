/*
** EPITECH PROJECT, 2018
** Nano
** File description:
** Parser header
*/
#include "Parser/Utils/utils.hpp"

std::string Utils::getType(const std::string line)
{
    int end = 0;

    for (const char &c: line) {
        if (c == ' ' || c == '\t')
            break;
        end++;
    }
    return (line.substr(0, end));
}

std::string Utils::getValue(const std::string &line)
{
    unsigned int splitType = getType(line).size();
    unsigned int i = splitType;

    for (; line[i] && !isalnum(line[i]); i++);
    return (line.substr(i , line.size()));
}

std::string Utils::getInputLinks(const std::string line, bool firstPart)
{
    std::string newLine;
    int end = 0;
    char c;

    for (unsigned int i = 0; line[i] != '\0'; i++) {
        c = line[i];
        if (firstPart && c == ':') {
            this->position = end;
            break;
        }
        if (!firstPart && (c == ' ' || c == '\t' || line[i+1] == '\0')) {
            newLine = line.substr(this->position+1, end - this->position+1);
            this->position = 0;
            return (newLine);
        }
        end++;
    }
    return (line.substr(0, end));
}

std::string Utils::getOutputLinks(const std::string line, bool firstPart)
{
    std::string output = getValue(line);

    this->getInputLinks(output.c_str());
    return (this->getInputLinks(output.c_str(), firstPart));
}