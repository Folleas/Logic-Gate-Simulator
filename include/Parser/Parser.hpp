/*
** EPITECH PROJECT, 2018
** Nano
** File description:
** Parser header
*/

#ifndef PARSER_H
# define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Parser/Utils/utils.hpp"

typedef struct chipsets_s {
    std::string type;
    std::string value;
    struct chipsets_s *next;
} chipsets_t;

typedef struct links_s {
    std::string input;
    std::string inputPin;
    std::string output;
    std::string outputPin;
    struct links_s *next;
} links_t;

class Parser: public Utils {
    public:
        Parser(const std::string &filename): Utils() {
            _filename = filename;
            chips = nullptr;
            links = nullptr;
            this->getFileAsVector();
            this->removeComments();
            this->processChipsets();
            this->processLinks();
        };
        virtual ~Parser() {
            this->deleteChip();
            this->deleteLink();
        };

        void getFileAsVector();
        void displayContent();
        void getInputs();
        void processChipsets();
        void processLinks();
        void addChipsetNode(std::string, std::string);
        void addLinksNode(std::string, std::string, std::string, std::string);

        void removeComments();
        void checkConfigFile();
        void deleteChip();
        void deleteLink();

    private:
        std::string _filename;
        int linkStartpoint;
        std::vector<std::string> content;

    protected:
        chipsets_t *chips;
        links_t *links;
};

#endif
