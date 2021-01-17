/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Clock : public nts::AComponent{
    public :
        Clock();
        ~Clock();
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void setInput(nts::Tristate newState);
        nts::Tristate getInput(void) const {return _input;};
    private :
        nts::Tristate _input = nts::Tristate::UNDEFINED;
};


#endif /* !CLOCK_HPP_ */