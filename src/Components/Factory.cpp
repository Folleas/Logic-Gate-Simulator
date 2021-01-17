/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "Components/Factory.hpp"

nts::Factory::Factory()
{
    _creates["input"] = 0;
    _creates["output"] = 1;
    _creates["4081"] = 2;
    _creates["4001"] = 3;
    _creates["4011"] = 4;
    _creates["4030"] = 5;
    _creates["4071"] = 6;
    _creates["and"] = 7;
}

nts::Factory::~Factory()
{
}