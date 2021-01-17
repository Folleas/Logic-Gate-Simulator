/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** main
*/

#include "Circuit/NanoTekSpice.hpp"
#include "Components/Input.hpp"
#include "Components/Output.hpp"
#include "Components/And.hpp"
#include "Circuit/Pin.hpp"
#include "Circuit/Circuit.hpp"
#include "Shell/Shell.hpp"
#include "Parser/Parser.hpp"
#include "Components/Chipset.hpp"
#include "Components/Factory.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Error: no such arguments.\n";
        return (84);
    } else {
        Shell sh(av[1]);
        sh.readComponent();
        sh.checkArguments(av);
        sh.checkCommands("simulate");
        sh.checkCommands("display");
        sh.runShell();
    }
    return (0);
}