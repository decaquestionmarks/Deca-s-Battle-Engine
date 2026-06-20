//Pokemon Base Class all Pokemon Inherit from

#pragma once
#include "Pokemon.hpp"

Pokemon::Pokemon() {
    num = -1;
    name = "???";
    types = std::vector<const std::string>();
    hp = 1;
    atk = 1;
    def = 1;
    spa = 1;
    spd = 1;
    spe = 1;
    abilities = std::unordered_map<const std::string, const std::string>();
    height = 1;
    weight = 1;
    color = "unknown";
    eggGroups = std::vector<const std::string>();
    evolutions = std::vector<const std::string>();
    prevo = "";
    learnset = Learnset();
}