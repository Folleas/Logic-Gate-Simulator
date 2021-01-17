/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Or : public nts::AComponent {
    public:
        Or();
        ~Or() {};
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    private :
};

#endif /* !OR_HPP_ */
