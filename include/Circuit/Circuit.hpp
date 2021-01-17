/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "NanoTekSpice.hpp"
#include <vector>
#include "Components/Factory.hpp"
#include "Parser/Parser.hpp"

namespace nts {
    class Circuit : public nts::Factory, public Parser {
        public:
            Circuit(const std::string &path);
            ~Circuit();
            void readComponent();
            nts::IComponent *AddComponent(std::string type, std::string name);
            IComponent *createComponent(const std::string &type, const std::string &name);
            std::unordered_map<std::string, nts::IComponent *> getComponents(void) const {return _components;};
        private:
            std::unordered_map<std::string, nts::IComponent *> _components;
            nts::IComponent *(Factory::*create[7])(const std::string &name);
    };
};
#endif /* !CIRCUIT_HPP_ */
