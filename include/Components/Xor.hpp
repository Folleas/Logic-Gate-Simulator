/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** XOR
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Xor : public nts::AComponent {
    public:
        Xor();
        ~Xor() {};
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    private :
};

#endif /* !XOR_HPP_ */
