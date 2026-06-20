#include "pokemon.hpp"

class Magikarp: public Pokemon{
    public:
    Magikarp(){
        Pokemon();
        num = 129;
        name = "Magikarp";
        types = {"Water"};
        hp = 20;
        atk = 10;
        def = 55;
        spa = 15;
        spd = 20;
        spe = 80;
        abilities.emplace("0", "Swift Swim");
        abilities.emplace("H", "Rattled");
        height = 0.9;
        weight = 10;
        color = "Red";
        eggGroups = {"Water 2", "Dragon"};
        evolutions = {"Gyarados"};
        learnset<<1<<"Splash"<<15<<"Tackle"<<25<<"Flail";
        learnset<<"Bounce"<<"Hydro Pump";
    }
    ~Magikarp();
};