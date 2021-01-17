/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Input
*/

#include "Components/Output.hpp"
#include "Circuit/Pin.hpp"
#include "Components/Factory.hpp"

void Output::setState(nts::Tristate newState)
{
    this->_state = newState;
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    _connectedPin = otherPin;
    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}

void Output::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

Output::Output()
{
    Pin *output = new Pin;

    this->_pins[1] = output;
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    nts::Tristate returnState = this->_pins[1]->linked->getState();

    if (returnState == nts::Tristate::UNDEFINED) {
        returnState = this->_pins[1]->linked->compute(pin);
    }
    this->setState(returnState);
    // std::cout << this->getName() << "=" << returnState << "\n";
    return (returnState);
}

nts::IComponent *nts::Factory::CreateOutput(const std::string &name)
{
    Output *output = new Output();

    return (output);
}