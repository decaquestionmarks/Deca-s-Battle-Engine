//Generates Pokemon Actors
#pragma once
#include "Pokemon.hpp"
#include <map>
#include <string>
#include "Data/All.hpp"

class PkmnFactory {
public:
    static Pokemon getPokemon(const std::string& species){
        auto it = PokemonFactory.find(species);
        if (it != PokemonFactory.end()) return *(it->second()); // return the Pokemon
        else return Pokemon();
    };
};