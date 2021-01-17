/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chipset
*/

#ifndef CHIPSET_HPP_
#define CHIPSET_HPP_

#include "Circuit/NanoTekSpice.hpp"
#include "Components/Factory.hpp"

class Chipset : public nts::AComponent {
    public:
        Chipset(nts::Tristate (*newCompute)(std::size_t pin, Chipset *chipset4081), void (*newSetLink)(std::size_t pin, nts::IComponent &other, std::size_t otherPin, Chipset *chipset));
        ~Chipset();
        nts::Tristate compute(std::size_t pin = 1);
        void dump() const;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        std::unordered_map<int, nts::AComponent *> getInside() {return _inside;}
        void setInside(std::unordered_map<int, nts::AComponent *> newInside) {_inside = newInside;}
    private:
        nts::Tristate (*newCompute)(std::size_t pin, Chipset *chipset);
        void (*newSetLink)(std::size_t pin, nts::IComponent &other, std::size_t otherPin, Chipset *chipset);
        std::unordered_map<int, nts::AComponent *> _inside;
};

#endif /* !CHIPSET_HPP_ */
