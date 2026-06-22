#pragma once
#include "Pokemon.hpp"

class PartyPokemon{
    private:
    std::string species;
    int level;
    std::string nickname;
    int exp;
    std::string nature;
    public:
    PartyPokemon();
    ~PartyPokemon();
    int getLevel() const {return level;}
    std::string getSpecies() const {return species;}
    std::string getNickname() const {return nickname.empty() ? species : nickname;}
    int getExp() const {return exp;}
    int addExp(int expGain);
    bool willLevelUp() const;
    bool doLevelUp();
};