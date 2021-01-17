/*
** EPITECH PROJECT, 2020
** OOP
** File description:
** Gate
*/

#include "Circuit/NanoTekSpice.hpp"

nts::Tristate andGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (first & second) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}

nts::Tristate nandGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (!(first & second)) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}
nts::Tristate orGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (first | second) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}

nts::Tristate norGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (!(first | second)) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}

nts::Tristate xorGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (first ^ second) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}

nts::Tristate xnordGate(nts::Tristate first, nts::Tristate second)
{
    nts::Tristate tmp = nts::Tristate::UNDEFINED;

    if (first == nts::Tristate::UNDEFINED || second == nts::Tristate::UNDEFINED)
        return (tmp);
    switch (!(first ^ second)) {
        case 1 :
            tmp = nts::Tristate::TRUE;
            break;
        case 0 :
            tmp = nts::Tristate::FALSE;
            break;
    }
    return (tmp);
}