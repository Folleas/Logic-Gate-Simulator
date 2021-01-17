/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Nor
*/

#ifndef NOR_HPP_
#define NOR_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Nor : public nts::AComponent {
    public:
        Nor();
        ~Nor() {};
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    private :
};

#endif /* !NOR_HPP_ */
