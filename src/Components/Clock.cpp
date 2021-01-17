/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Clock
*/

#include "Components/Clock.hpp"
#include "Circuit/Pin.hpp"
#include "Components/Factory.hpp"

void Clock::setInput(nts::Tristate newState)
{
    this->_input = newState;
    this->_state = newState;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}

Clock::Clock()
{
    Pin *output = new Pin;

    this->_pins[1] = output;
}

Clock::~Clock()
{
}

void Clock::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (this->_state == nts::Tristate::TRUE)
        this->_state = nts::Tristate::FALSE;
    else
        this->_state = nts::Tristate::TRUE;
    return(this->getState());
}

nts::IComponent *nts::Factory::CreateClock(const std::string &name)
{
    Clock *clock = new Clock();

    clock->setName(name);
    return (clock);
}