/*
** EPITECH PROJECT, 2019
** Nanotekspice
** File description:
** Shell file
*/

#ifndef SHELL_HPP
#define SHELL_HPP

#define BUILTIN_NUM 5
#include <iostream>
#include "Circuit/Circuit.hpp"

class Shell: public nts::Circuit {
    public:
        Shell(const std::string &);
        virtual ~Shell() {};

        void runShell();
        void checkCommands(const std::string);
        bool checkPin(const std::string &);
        void checkArguments(char **);

        // Builtins commands
        void exit();
        void dump();
        void display();
        void simulate();


    private:
        std::string input;
        void (Shell::*commands[5])();
};

#endif
