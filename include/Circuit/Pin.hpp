/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Pin : public nts::AComponent {
    public :
        Pin();
        ~Pin();
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        nts::AComponent *linked = nullptr;
        void setState();
        void dump() const;
        nts::Tristate getState() const {return _state;};
        nts::IComponent *getLink() const {return linked;};
    private:
};

#endif /* !PIN_HPP_ */
