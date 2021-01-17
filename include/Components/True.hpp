/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Circuit/NanoTekSpice.hpp"

class True : public nts::AComponent{
    public :
        True();
        ~True();
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void setInput();
        nts::Tristate getInput(void) const {return _input;};
    private :
        nts::Tristate _input = nts::Tristate::UNDEFINED;
};

#endif /* !TRUE_HPP_ */
