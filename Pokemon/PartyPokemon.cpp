#pragma once
#include "PartyPokemon.hpp"
#include <cmath>
#include "GrowthRateFactory.cpp"
#include "PokemonFactory.cpp"
#include "NatureFactory.cpp"

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
    if(level==100){
        return false;
    }
    GrowthRate* growthRate = GrowthRateFactory::getGrowthRate(getPokemon().getGrowthRate());
    return exp >= growthRate->getLevel(level+1);

}

bool PartyPokemon::willLearnMove() const {
    //get back to, make Pokemon canlearnmove method that is virtual.
}

bool PartyPokemon::doLevelUp() {
    if(level==100){
        return false;
    }
    //EXP case
    if(willLevelUp()){
        level++;
        return true;
    }
    //Rare Candy Case/Force Level Up
    else{
        GrowthRate* growthRate = GrowthRateFactory::getGrowthRate(getPokemon().getGrowthRate());
        exp = growthRate->getExp(level+1);
        level++;
        return true;
    }
    return false;
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

int PartyPokemon::calculateHP() const {
    // Implementation for calculating HP
    Pokemon pokemon = getPokemon();
    if (pokemon.getHp() == 1) { //Shedinja Case
        return 1;
    }
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(0) ? 31 : hpIV;
    return (int) nature->onModifyHP(((2 * pokemon.getHp() + iv + hpEV / 4) * level )/ 100 + level + 10);
}

int PartyPokemon::calculateAtk() const {
    // Implementation for calculating Atk
    Pokemon pokemon =getPokemon();
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(1) ? 31 : atkIV;
    return (int) nature->onModifyAttack(((2* pokemon.getAtk() + iv + atkEV / 4) * level )/ 100 + 5);
}

int PartyPokemon::calculateDef() const {
    // Implementation for calculating Def
    Pokemon pokemon =getPokemon();
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(2) ? 31 : defIV;
    return (int) nature->onModifyDefense(((2* pokemon.getDef() + iv + defEV / 4) * level )/ 100 + 5);
}

int PartyPokemon::calculateSpa() const {
    // Implementation for calculating Spa
    Pokemon pokemon =getPokemon();
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(3) ? 31 : spaIV;
    return (int) nature->onModifySpAttack(((2* pokemon.getSpa() + iv + spaEV / 4) * level )/ 100 + 5);
}

int PartyPokemon::calculateSpd() const {
    // Implementation for calculating Spd
    Pokemon pokemon =getPokemon();
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(4) ? 31 : spdIV;
    return (int) nature->onModifySpDefense(((2* pokemon.getSpd() + iv + spdEV / 4) * level )/ 100 + 5);
}

int PartyPokemon::calculateSpe() const {
    // Implementation for calculating Spe
    Pokemon pokemon =getPokemon();
    Nature* nature = NatureFactory::getNature(getNature());
    int iv = isBottleCapped(5) ? 31 : speIV;
    return (int) nature->onModifySpeed(((2* pokemon.getSpe() + iv + speEV / 4) * level )/ 100 + 5);
}
