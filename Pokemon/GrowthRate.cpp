#include "GrowthRate.hpp"
#include <cmath>

int MediumFast::getExp(int level) const {
    return level * level * level;
}

int MediumFast::getLevel(int exp) const {
    return static_cast<int>(std::cbrt(exp));
}

int Erratic::getExp(int level) const {
    if(level < 50){
        return level * level * level * (100 - level) / 50;
    } else if(level <= 68){
        return level * level * level * (150 - level) / 100;
    } else if(level < 98){
        return level * level * level * ((1911 - 10 * level) / 3) / 500;
    } else {
        return level * level * level * (160 - level) / 100;
    }
}

int Erratic::getLevel(int exp) const {
    int level = 1;
    while(getExp(level) < exp && level < 100){
        level++;
    }
    return level;
}

int Fluctuating::getExp(int level) const {
    if(level < 15){
        return level * level * level * ((level + 1) / 3 + 24) / 50;
    } else if(level < 36){
        return level * level * level * ((level + 14)) / 50;
    } else {
        return level * level * level * ((level / 2) + 32) / 50;
    }
}

int Fluctuating::getLevel(int exp) const {
    int level = 1;
    while(getExp(level) < exp && level < 100){
        level++;
    }
    return level;
}

int MediumSlow::getExp(int level) const {
    return (level * level * level * 6 / 5) - (15 * level * level) + (100 * level) - 140;
}

int MediumSlow::getLevel(int exp) const {
    int level = 1;
    while(getExp(level) < exp && level < 100){
        level++;
    }
    return level;
}

int Fast::getExp(int level) const {
    return level * level * level * 4 / 5;
}

int Fast::getLevel(int exp) const {
    return static_cast<int>(std::cbrt(exp * 5 / 4));
}

int Slow::getExp(int level) const {
    return level * level * level * 5 / 4;
}

int Slow::getLevel(int exp) const {
    return static_cast<int>(std::cbrt(exp * 4 / 5));
}