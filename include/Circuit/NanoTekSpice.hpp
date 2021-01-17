/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <iostream>
#include <unordered_map>

class Pin;

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public :
            virtual ~IComponent() = default;
        public :
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
    };
    class AComponent : public IComponent {
        public :
            ~AComponent();
            std::string getName() const {return (_name);};
            std::string getType() const {return (_type);};
            nts::Tristate getState() const {return _state;};
            std::unordered_map<int, Pin *> getPins() const {return _pins;};

            virtual void dump() const = 0;
            void setPins(std::unordered_map<int, Pin *> pins) {this->_pins = pins;}
            void setName(std::string newName) {_name = newName;};
            void setState(nts::Tristate newState) {_state = newState;};
            void setType(std::string newType) {_type = newType;};
        protected :
            std::unordered_map<int, Pin *> _pins;
            nts::Tristate _state = nts::Tristate::UNDEFINED;
            std::string _name;
            std::string _type;
    };
};

#include "Pin.hpp"

#endif /* !NANOTEKSPICE_HPP_ */
