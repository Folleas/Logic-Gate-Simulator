/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Pin
*/

#include "Circuit/Pin.hpp"

Pin::Pin()
{

}

Pin::~Pin()
{
}

nts::Tristate Pin::compute(std::size_t pin)
{
    return (nts::Tristate::TRUE);
}

void Pin::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

void Pin::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}