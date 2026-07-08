#pragma once
#include "PartyPokemon.hpp"
#include <cmath>
#include "GrowthRateFactory.cpp"
#include "PokemonFactory.cpp"

int PartyPokemon::addExp(int expGain) {
    exp += expGain;

    
    if (willLevelUp()&&willLearnMove()) {
        return 3;
    }
    if (willLevelUp()) {
        return 1;
    }
    if (willLearnMove()) {
        return 2;
    }
    return 0;
}

bool PartyPokemon::willLevelUp() const {
    GrowthRate* growthRate = GrowthRateFactory::getGrowthRate(PkmnFactory::getPokemon(species).getGrowthRate());
    
}

bool PartyPokemon::willLearnMove() const {

}

bool PartyPokemon::doLevelUp() {

}

void PartyPokemon::hatch() {
    // Implementation for hatching an egg
}

bool PartyPokemon::atMaxEV() const{
    return hpEV+atkEV+defEV+spaEV+spdEV+speEV >= 510;
}

void addEVHelper(int& ev, int amount) {
    ev = std::min(ev + amount, 252);
}

void PartyPokemon::addHPEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(hpEV, amount);
    }
}

void PartyPokemon::addAtkEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(atkEV, amount);
    }
}

void PartyPokemon::addDefEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(defEV, amount);
    }
}

void PartyPokemon::addSpaEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(spaEV, amount);
    }
}

void PartyPokemon::addSpdEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(spdEV, amount);
    }
}

void PartyPokemon::addSpeEV(int amount) {
    if (!atMaxEV()) {
        addEVHelper(speEV, amount);
    }
}


