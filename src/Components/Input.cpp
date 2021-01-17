/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Input
*/

#include "Components/Input.hpp"
#include "Circuit/Pin.hpp"
#include "Components/Factory.hpp"

void Input::setInput(nts::Tristate newState)
{
    this->_input = newState;
    this->_state = newState;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::AComponent *tmpThis = dynamic_cast<nts::AComponent *>(this);
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);

    (tmpThis->getPins())[pin]->linked = tmpOther;
    other.setLink(otherPin, *this, pin);
}

Input::Input()
{
    Pin *output = new Pin;

    this->_pins[1] = output;
}

Input::~Input()
{
}

void Input::dump() const
{
    std::cout << "Name : " << _name << "\t" << "Type : " << _type << "\n";
}

nts::Tristate Input::compute(std::size_t pin)
{
    return(this->getState());
}

nts::IComponent *nts::Factory::CreateInput(const std::string &name)
{
    Input *input = new Input();

    input->setName(name);
    return (input);
}