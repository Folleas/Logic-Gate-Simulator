/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "Circuit/NanoTekSpice.hpp"

nts::Tristate andGate(nts::Tristate first, nts::Tristate second);
nts::Tristate xorGate(nts::Tristate first, nts::Tristate second);
nts::Tristate nandGate(nts::Tristate first, nts::Tristate second);
nts::Tristate norGate(nts::Tristate first, nts::Tristate second);
nts::Tristate orGate(nts::Tristate first, nts::Tristate second);

#endif /* !GATES_HPP_ */
