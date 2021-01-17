/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** 4081
*/

#include <Components/Chipset.hpp>
#include <Components/Nand.hpp>
#include <Components/And.hpp>

nts::Tristate compute4011(std::size_t pin, Chipset *chipset)
{
    nts::Tristate state = nts::Tristate::UNDEFINED;
    std::unordered_map<int, nts::AComponent *> tmp = chipset->getInside();

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        state = tmp[getAndNumber(pin)]->compute(3);
    }
    else if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        state = tmp[getAndNumber(pin)]->compute(1);
    }
    else {
        state = tmp[getAndNumber(pin)]->compute(2);
    }
    return (state);
}

void newSetLink4011(std::size_t pin, nts::IComponent &other, std::size_t otherPin, Chipset *chipset)
{
    nts::AComponent *tmpOther = dynamic_cast<nts::AComponent *>(&other);
    std::unordered_map<int, nts::AComponent *> tmp = chipset->getInside();

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        tmp[getAndNumber(pin)]->setLink(3, other, otherPin);
    }
    else if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        tmp[getAndNumber(pin)]->setLink(1, other, otherPin);
    }
    else {
        tmp[getAndNumber(pin)]->setLink(2, other, otherPin);
    }
    chipset->setInside(tmp);
}

nts::IComponent *nts::Factory::Create4011(const std::string &name)
{
    Chipset *chipset4011 = new Chipset(compute4011, newSetLink4011);
    std::unordered_map<int, nts::AComponent *> tmp = chipset4011->getInside();

    tmp[1] = new Nand();
    tmp[2] = new Nand();
    tmp[3] = new Nand();
    tmp[4] = new Nand();
    chipset4011->setInside(tmp);
    return (chipset4011);
}