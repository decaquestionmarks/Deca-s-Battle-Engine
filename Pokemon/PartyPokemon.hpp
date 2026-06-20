#pragma once
#include "Pokemon.hpp"

class PartyPokemon{
    private:
    int level;
    std::string species;
    public:
    PartyPokemon();
    ~PartyPokemon();
    int getLevel() const {return level;}
    std::string getSpecies() const {return species;}

};