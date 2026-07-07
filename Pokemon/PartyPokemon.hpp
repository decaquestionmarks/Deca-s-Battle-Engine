#pragma once
#include "Pokemon.hpp"

class PartyPokemon{
    private:
    //Main Data
    std::string species;
    int level;
    std::string nickname;
    int exp;
    std::string nature;
    std::string effectiveNature;
    std::string ability;
    std::string heldItem;
    int friendship;
    //std::string Language; uneccessary
    bool isEgg;
    bool isShiny;
    bool pkrsinfected;
    bool pkrscured;
    int PID;
    //Met Data
    //std::string metGame; uneccessary
    //std::string battleversion; uneccessary
    std::string metLocation;
    std::string caughtBall;
    int metLevel;
    //int obediencelevel; not sure what this does, so leaving out
    bool metAsEgg;
    //Stats
    int hpIV;
    int atkIV;
    int defIV;
    int spaIV;
    int spdIV;
    int speIV;
    int hpEV;
    int atkEV;
    int defEV;
    int spaEV;
    int spdEV;
    int speEV;
    //Moves
    
    //Cosmetic Data
        //Nah
    //OT
    int OTID;
    int SID;
    std::string OTName;
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