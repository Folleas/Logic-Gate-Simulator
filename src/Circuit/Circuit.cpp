/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit
*/

#include "Circuit/Circuit.hpp"

nts::Circuit::Circuit(const std::string &path) : Parser(path)
{
    create[0] = &nts::Factory::CreateInput;
    create[1] = &nts::Factory::CreateOutput;
    create[2] = &nts::Factory::Create4081;
    create[3] = &nts::Factory::Create4001;
    create[4] = &nts::Factory::Create4011;
    create[5] = &nts::Factory::Create4030;
    create[6] = &nts::Factory::Create4071;
    create[7] = &nts::Factory::CreateTrue;
    create[8] = &nts::Factory::CreateFalse;
    create[9] = &nts::Factory::CreateClock;
}

void nts::Circuit::readComponent()
{
    chipsets_t *chipsets = this->chips;
    links_t *link = this->links;

    while (chipsets != nullptr) {
        this->AddComponent(chipsets->type, chipsets->value);
        chipsets = chipsets->next;
    }
    while (link != nullptr) {
        dynamic_cast<nts::AComponent *>((this->getComponents())[link->input])->setLink(std::stoi(link->inputPin, nullptr), *(this->getComponents())[link->output], std::stoi(link->outputPin, nullptr));
        link = link->next;
    }
}

nts::Circuit::~Circuit()
{
    std::unordered_map<std::string, nts::IComponent *>components = this->getComponents();
    std::unordered_map<std::string, nts::IComponent *>::iterator it = components.begin();

    while(it != components.end()) {
        nts::AComponent *comp = dynamic_cast<nts::AComponent *>(it->second);
        delete (comp);
        it++;
    }
}

nts::IComponent *nts::Circuit::AddComponent(std::string type, std::string name)
{
    nts::AComponent *component = dynamic_cast<nts::AComponent *>((this->*create[(this->getCreates())[type]])(name));

    component->setName(name);
    component->setType(type);
    this->_components[name] = component;
    return (component);
}

nts::AComponent::~AComponent()
{
    std::unordered_map<int, Pin *>components = this->getPins();
    std::unordered_map<int, Pin *>::iterator it = components.begin();

    while(it != components.end()) {
        delete (dynamic_cast<nts::AComponent *>(it->second));
        it++;
    }
}