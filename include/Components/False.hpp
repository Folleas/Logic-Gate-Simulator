/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Circuit/NanoTekSpice.hpp"

class False : public nts::AComponent{
    public :
        False();
        ~False();
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void setInput();
        nts::Tristate getInput(void) const {return _input;};
    private :
        nts::Tristate _input = nts::Tristate::UNDEFINED;
};


#endif /* !FALSE_HPP_ */