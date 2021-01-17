/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Input
*/

#include "Circuit/NanoTekSpice.hpp"

class Input : public nts::AComponent {
    public :
        Input();
        ~Input();
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void setInput(nts::Tristate newState);
        nts::Tristate getInput(void) const {return _input;};
    private :
        nts::Tristate _input = nts::Tristate::UNDEFINED;
};