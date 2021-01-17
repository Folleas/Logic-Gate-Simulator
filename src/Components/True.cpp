/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** True
*/

#include "Components/True.hpp"
#include "Circuit/Pin.hpp"
#include "Components/Factory.hpp"

void True::setInput()
{
    this->_input = nts::Tristate::TRUE;
    this->_state = nts::Tristate::TRUE;
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}

True::True()
{
    Pin *output = new Pin;

    this->_pins[1] = output;
}

True::~True()
{
}

void True::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate True::compute(std::size_t pin)
{
    return(this->getState());
}

nts::IComponent *nts::Factory::CreateTrue(const std::string &name)
{
    True *true_c = new True();

    true_c->setName(name);
    return (true_c);
}