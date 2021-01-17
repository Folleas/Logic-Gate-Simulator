/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "Circuit/NanoTekSpice.hpp"

class Output : public nts::AComponent{
    public :
        Output();
        ~Output();
        void dump() const;
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        void setState(nts::Tristate newState);
        void setPin(std::size_t newConnectedPin) {_connectedPin = newConnectedPin;};

        nts::Tristate getState(void) const {return _state;};
        std::size_t getPin(void) const {return _connectedPin;};
    private :
        std::size_t _connectedPin;
};

#endif /* !OUTPUT_HPP_ */