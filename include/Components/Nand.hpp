/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Nand
*/

#ifndef NAND_HPP_
#define NAND_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Nand : public nts::AComponent {
    public:
        Nand();
        ~Nand() {};
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    private :
};

#endif /* !Nand_HPP_ */
