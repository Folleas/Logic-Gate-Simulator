/*
** EPITECH PROJECT, 2019
** Nano
** File description:
** Parser main file
*/

#include "Parser/Parser.hpp"
#include "Parser/Utils/utils.hpp"
#include <string>
#include <vector>

void Parser::displayContent()
{
    for (std::string line: this->content)
        std::cout << line << "\n";
}

void Parser::deleteChip()
{
    chipsets_t *chip = this->chips;
    chipsets_t *tmp;

    while (chip->next != nullptr) {
        tmp = chip->next;
        delete (chip);
        chip = tmp;
    }
    delete (tmp);
}

void Parser::deleteLink()
{
    links_t *link = this->links;
    links_t *tmp;

    while (link->next != nullptr) {
        tmp = link->next;
        delete (link);
        link = tmp;
    }
    delete (tmp);
}

void Parser::checkConfigFile()
{
    for (unsigned int i = 0; i < this->content.size(); i++) {
        if (i == 0 && this->content.at(i) != ".chipsets:") {
            std::cout << "Error: wrong first part.\n";
            return;
        }
        else if (i == 0 && this->content.at(i) == ".chipsets:" && \
                this->content.at(i+1).find("input") != std::string::npos) {
            std::cout << "Error: chipsets needs inputs\n";
            return;
        }
    }
}

void Parser::removeComments()
{
    for (unsigned int i = 0; i < this->content.size(); i++) {
        if (this->content.at(i)[0] == '#') {
            this->content.erase(this->content.begin() + i);
            i--;
        }
    }
}

void Parser::addChipsetNode(std::string type, std::string value)
{
    chipsets_t *newNode = new chipsets_t();

    newNode->type = type;
    newNode->value = value;
    newNode->next = nullptr;
    if (this->chips == nullptr)
        this->chips = newNode;
    else {
        chipsets_t *tmp = this->chips;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

void Parser::addLinksNode(std::string input,
                        std::string inputPin,
                        std::string output,
                        std::string outputPin)
{
    links_t *newNode = new links_t();

    newNode->input = input;
    newNode->inputPin = inputPin;
    newNode->output = output;
    newNode->outputPin = outputPin;
    newNode->next = nullptr;
    if (this->links == nullptr)
        this->links = newNode;
    else {
        links_t *tmp = this->links;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

void Parser::processChipsets()
{
    std::string type;
    std::string value;

    for (unsigned int i = 1; i < this->content.size(); i++) {
        if (this->content.at(i).find(".links:") != std::string::npos) {
            this->linkStartpoint = i;
            break;
        }
        type = this->getType(this->content.at(i));
        value = this->getValue(this->content.at(i));
        this->addChipsetNode(type, value);
    }
}

// TODO: Fix bug on input names !
void Parser::processLinks()
{
    std::string input;
    std::string inputPin;
    std::string output;
    std::string outputPin;

    for (int i = this->linkStartpoint + 1; i < this->content.size(); i++) {
        input = this->getInputLinks(this->content.at(i));
        inputPin = this->getInputLinks(
                                            this->content.at(i),
                                            false
                                );
        output = this->getOutputLinks(this->content.at(i));
        outputPin = this->getOutputLinks(this->content.at(i), false);
        this->addLinksNode(input, inputPin, output, outputPin);
    };
}

void Parser::getFileAsVector()
{
    std::ifstream file(this->_filename.c_str());
    std::string line;

    if (!file) {
        std::cout << "Cannot open the file\n";
        return;
    }
    while (std::getline(file, line)) {
        if (line.size() > 0)
            this->content.push_back(line);
    }
    file.close();
    return;
}

void checkErrors()
{

}
