/*
** EPITECH PROJECT, 2018
** Nano
** File description:
** Utils header
*/

#ifndef UTILS_HPP
 #define UTILS_HPP

#include <iostream>

class Utils {
    public:
        Utils() {
            position = 0;
        };
        virtual ~Utils() {};

        // Utils functions prototypes
        std::string getType(const std::string);
        std::string getValue(const std::string &);
        std::string getInputLinks(const std::string, bool firstPart = true);
        std::string getOutputLinks(const std::string, bool firstPart = true);

    private:
        int position;

};

#endif