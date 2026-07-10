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
    genderRatio = 0.5; //0.0 = all male, 1.0 = all female, -1. = genderless
    eggGroups = std::vector<const std::string>();
    evolutions = std::vector<const std::string>();
    prevo = "";
    learnset = Learnset();
    baseFriendship = 70;
    catchRate = 255;
    EggSteps = 0;
    growthRate = "Medium Fast";
    //EVs
    evHp = 0;
    evAtk = 0;
    evDef = 0;
    evSpa = 0;
    evSpd = 0;
    evSpe = 0;
    expYield = 0;
}
    bool Pokemon::canLearnEggMove(std::string move) const {
        return learnset.canLearnEggMove(move);
    }
    bool Pokemon::canLearnTM(std::string move) const {
        return learnset.canLearnTM(move);
    }
    std::vector<const std::string_view> Pokemon::getMovesAtLevel(int level) const {
        return learnset.getLevelMove(level);
    }