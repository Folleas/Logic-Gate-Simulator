/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "Circuit/NanoTekSpice.hpp"

std::size_t getAndNumber(std::size_t pin);

class And : public nts::AComponent {
    public:
        And();
        ~And() {};
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    private :
};

#endif /* !AND_HPP_ */
