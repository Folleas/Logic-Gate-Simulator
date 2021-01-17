/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Nand
*/

#include "Components/Nand.hpp"
#include "Circuit/Gates.hpp"

void Nand::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    // other.setLink(otherPin, *this, pin);
}

Nand::Nand()
{
    Pin *input0 = new Pin;
    Pin *input1 = new Pin;
    Pin *output = new Pin;

    _pins[1] = input0;
    _pins[2] = input1;
    _pins[3] = output;
}

void Nand::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate Nand::compute(std::size_t pin)
{
    nts::Tristate state = nts::Tristate::UNDEFINED;
    static bool calculated = false;

    if (pin != 3) {
        state = this->_pins[pin]->linked->getState();
        if (state == nts::Tristate::UNDEFINED && calculated == false) {
            this->_pins[pin]->linked->compute(0);
            calculated = true;
            this->compute(pin);
        }
    }
    else {
        state = nandGate((this->_pins[1]->linked->getState()), (this->_pins[2]->linked->getState()));
        if (state == nts::Tristate::UNDEFINED && calculated == false) {
            this->compute(1);
            this->compute(2);
            calculated = true;
            this->compute(3);
        }
    }
    calculated = false;
    this->setState(state);
    return (state);
}