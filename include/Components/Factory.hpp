/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Circuit/NanoTekSpice.hpp"
#include "Components/Chipset.hpp"

class Input;
class Output;
class Chipset;
class And;

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory();
            nts::IComponent *Create4001(const std::string &name);
            nts::IComponent *Create4011(const std::string &name);
            nts::IComponent *Create4030(const std::string &name);
            nts::IComponent *Create4071(const std::string &name);
            nts::IComponent *Create4081(const std::string &name);
            nts::IComponent *CreateInput(const std::string &name);
            nts::IComponent *CreateOutput(const std::string &name);
            nts::IComponent *CreateTrue(const std::string &name);
            nts::IComponent *CreateFalse(const std::string &name);
            nts::IComponent *CreateClock(const std::string &name);
            nts::IComponent *CreateAnd(const std::string &name);
            std::unordered_map<std::string, int> getCreates() const {return _creates;};
        private:
            std::unordered_map<std::string, int> _creates;
    };
};

#endif /* !FACTORY_HPP_ */