//Pokemon Base Class all Pokemon Inherit from
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Learnset.hpp"
#include "GrowthRate.hpp"

class Pokemon{
    protected:
    int num;
    std::string name;
    std::vector<const std::string> types;
    //Stats
    int hp;
    int atk;
    int def;
    int spa;
    int spd;
    int spe;
    std::unordered_map<const std::string, const std::string> abilities; //key by ability slot, value is ability name
    double height; //meters
    double weight; //kilograms
    std::string color;
    double genderRatio;//0.0 = all male, 1.0 = all female, -1. = genderless
    std::vector<const std::string> eggGroups;
    std::vector<const std::string> evolutions;
    std::string prevo;
    Learnset learnset;
    int baseFriendship;
    int catchRate;
    int EggSteps;
    std::string_view growthRate;
    //EVs
    int evHp;
    int evAtk;
    int evDef;
    int evSpa;
    int evSpd;
    int evSpe;
    int expYield;
    public:
    Pokemon();
    ~Pokemon();
    std::string getName() const {return name;}
    int getHp() const {return hp;}
    int getAtk() const {return atk;}
    int getDef() const {return def;}
    int getSpa() const {return spa;}
    int getSpd() const {return spd;}
    int getSpe() const {return spe;}
    int getBST() const {return hp + atk + def + spa + spd + spe;}
    std::vector<const std::string> getTypes() const {return types;}
    std::unordered_map<const std::string, const std::string> getAbilities() const {return abilities;}
    double getHeight() const {return height;}
    double getWeight() const {return weight;}
    std::string getColor() const {return color;}
    double getGenderRatio() const {return genderRatio;}
    std::vector<const std::string> getEggGroups() const {return eggGroups;}
    std::vector<const std::string> getEvolutions() const {return evolutions;}
    std::string getPrevo() const {return prevo;}
    Learnset getLearnset() const {return learnset;}
    int getEvHp() const {return evHp;}
    int getEvAtk() const {return evAtk;}
    int getEvDef() const {return evDef;}
    int getEvSpa() const {return evSpa;}
    int getEvSpd() const {return evSpd;}
    int getEvSpe() const {return evSpe;}
    int getExpYield() const {return expYield;}
};