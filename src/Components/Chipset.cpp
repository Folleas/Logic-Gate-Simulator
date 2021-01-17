/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Pin
*/

#include "Components/Chipset.hpp"

Chipset::Chipset(nts::Tristate (*compute)(std::size_t pin, Chipset *chipset4081), void (*setLink)(std::size_t pin, nts::IComponent &other, std::size_t otherPin, Chipset *chipset))
{
    this->newCompute = compute;
    this->newSetLink = setLink;
}

Chipset::~Chipset()
{
    std::unordered_map<int, nts::AComponent *>components = this->getInside();
    std::unordered_map<int, nts::AComponent *>::iterator it = components.begin();

    while(it != components.end()) {
        delete (it->second);
        it++;
    }
}

void Chipset::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate Chipset::compute(std::size_t pin)
{
    this->newCompute(pin, this);
}

void Chipset::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->newSetLink(pin, other, otherPin, this);
}