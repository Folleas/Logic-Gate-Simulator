/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** False
*/

#include "Components/False.hpp"
#include "Circuit/Pin.hpp"
#include "Components/Factory.hpp"

void False::setInput()
{
    this->_input = nts::Tristate::FALSE;
    this->_state = nts::Tristate::FALSE;
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}

False::False()
{
    Pin *output = new Pin;

    this->_pins[1] = output;
}

False::~False()
{
}

void False::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate False::compute(std::size_t pin)
{
    return(this->getState());
}

nts::IComponent *nts::Factory::CreateFalse(const std::string &name)
{
    False *false_c = new False();

    false_c->setName(name);
    return (false_c);
}