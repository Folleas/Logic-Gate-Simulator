/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Shell
*/

#include "Shell/Shell.hpp"
#include <vector>
#include "Circuit/Circuit.hpp"
#include "Components/Output.hpp"
#include "Circuit/Circuit.hpp"
#include "Components/Input.hpp"

Shell::Shell(const std::string &_path): nts::Circuit(_path)
{
    this->commands[0] = &Shell::exit;
    this->commands[1] = &Shell::display;
    this->commands[2] = &Shell::simulate;
    this->commands[3] = &Shell::dump;
    this->commands[4] = nullptr;
}

void Shell::exit()
{

}

void Shell::dump()
{
    std::unordered_map<std::string, nts::IComponent *>components = this->getComponents();
    std::unordered_map<std::string, nts::IComponent *>::iterator it = components.begin();

    while(it != components.end()) {
        nts::AComponent *comp = dynamic_cast<nts::AComponent *>(it->second);
        comp->dump();
        it++;
    }
}

void Shell::display()
{
    std::unordered_map<std::string, nts::IComponent *>components = this->getComponents();
    std::unordered_map<std::string, nts::IComponent *>::iterator it = components.begin();

    while(it != components.end()) {
        nts::AComponent *comp = dynamic_cast<nts::AComponent *>(it->second);
        if (comp->getType() == "output") {
            Output *output = dynamic_cast<Output *>(it->second);
            if (output->getState() == nts::UNDEFINED)
                std::cout << "U\n";
            else
                std::cout << output->getName() << "=" << output->getState() << "\n";
        }
        it++;
    }
}

void Shell::simulate()
{
    std::unordered_map<std::string, nts::IComponent *>components = this->getComponents();
    std::unordered_map<std::string, nts::IComponent *>::iterator it = components.begin();

    while(it != components.end()) {
        nts::AComponent *comp = dynamic_cast<nts::AComponent *>(it->second);
        if (comp->getType() == "output") {
            Output *output = dynamic_cast<Output *>(it->second);
            output->compute(output->getPin());
        }
        it++;
    }
}

bool Shell::checkPin(const std::string &value)
{
    chipsets_t *tmpChips = this->chips;

    while (tmpChips != nullptr) {
        if (tmpChips->value == value)
            return (true);
        else
            tmpChips = tmpChips->next;
    }
    return (false);
}

void Shell::checkArguments(char **av)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;
    std::string s;
    int pinNum;

    for (int i = 2; av[i] != nullptr; i++) {
        s = av[i];
        if (this->checkPin(s.substr(0, s.find("=")))) {
            pinNum = std::stoi(s.substr(s.find("=")+1, s.size()));
            switch (pinNum) {
                case 0: tmp = nts::Tristate::FALSE; break;
                case 1: tmp = nts::Tristate::TRUE; break;
                default : tmp = nts::Tristate::UNDEFINED; break;
            }
            // if (dynamic_cast<nts::AComponent *>((this->getComponents())[s.substr(0, s.find("="))])->getType() != "Clock") {
                dynamic_cast<Input *>((this->getComponents())[s.substr(0, s.find("="))])->setInput(tmp);
            // }
        }
    }
}


void Shell::checkCommands(const std::string cmd)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;
    int pinNum;
    const char *builtins[] = {"exit", "display", \
                                "simulate", \
                                "dump", "loop", nullptr};

    for (int i = 0; i != BUILTIN_NUM; i++) {
        if (this->checkPin(cmd.substr(0, cmd.find("=")))) {
            pinNum = std::stoi(cmd.substr(cmd.find("=")+1, cmd.size()));
            switch (pinNum) {
                case 0: tmp = nts::Tristate::FALSE; break;
                case 1: tmp = nts::Tristate::TRUE; break;
                default : tmp = nts::Tristate::UNDEFINED; break;
            }
            dynamic_cast<Input *>((this->getComponents())[cmd.substr(0, cmd.find("="))])->setInput(tmp);
            break;
        }
        if (cmd == builtins[i])
            (this->*commands[i])();
    }
}

void Shell::runShell()
{
    std::string input;

    std::cout << "> ";
    while (std::getline(std::cin, input)) {
        this->checkCommands(input);
        std::cout << "> ";
        if (input == "exit") {
            std::cout << "\rexit\n";
            return;
        }
    }
    return;
}
