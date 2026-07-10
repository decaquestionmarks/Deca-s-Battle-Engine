#pragma once
#include "Pokemon.hpp"

class PartyPokemon{
    private:
    //Main Data
    std::string species;
    int level;
    std::string nickname;
    int exp;
    int nature;
    int effectiveNature;
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
    int currHP;
    int hpIV;
    int atkIV;
    int defIV;
    int spaIV;
    int spdIV;
    int speIV;
    bool bottlecapped[6];
    int hpEV;
    int atkEV;
    int defEV;
    int spaEV;
    int spdEV;
    int speEV;
    //Moves
    std::string Moves[4];
    int MovePP[4];
    int MovePPUps[4];
    //std::vector<std::string> pastmoves; implement later
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
    bool willLearnMove() const;
    bool doLevelUp();
    int getNature() const {return nature;}
    int getEffectiveNature() const {return effectiveNature;}
    void setEffectiveNature(int newNature){effectiveNature = newNature;};
    std::string getAbility() const {return ability;}
    void setAbility(std::string newAbility){ability = newAbility;};
    std::string getHeldItem() const {return heldItem;}
    void setHeldItem(std::string newItem){heldItem = newItem;};
    int getFriendship() const {return friendship;}
    void addFriendship(int amount){friendship += amount;}
    bool isEgg() const {return isEgg;}
    void hatch(); // Stuff to generate when an egg is hatched
    bool isShiny() const {return isShiny;}
    bool isPKRSInfected() const {return pkrsinfected;}
    void infectPKRS() {pkrsinfected = true;}
    void curePKRS() {pkrscured = pkrsinfected;} // can't cure without being infected
    bool isPKRSCured() const {return pkrscured;}
    int getPID() const {return PID;}

    std::string getMetLocation() const {return metLocation;}
    std::string getCaughtBall() const {return caughtBall;}
    void setCaughtBall(std::string newBall){caughtBall = newBall;}
    int getMetLevel() const {return metLevel;}
    bool isMetAsEgg() const {return metAsEgg;}

    int getCurrHP() const {return currHP;}
    void setCurrHP(int newHP) {currHP = newHP;}
    void addHP(int amount) {currHP += amount;}
    void subtractHP(int amount) {currHP -= amount;}
    int getHPIV() const {return hpIV;}
    int getAtkIV() const {return atkIV;}
    int getDefIV() const {return defIV;}
    int getSpaIV() const {return spaIV;}
    int getSpdIV() const {return spdIV;}
    int getSpeIV() const {return speIV;}
    bool isBottleCapped(int index) const {return bottlecapped[index];}
    void setBottleCapped(int index, bool capped) {bottlecapped[index] = capped;}
    int getHPEV() const {return hpEV;}
    int getAtkEV() const {return atkEV;}
    int getDefEV() const {return defEV;}
    int getSpaEV() const {return spaEV;}
    int getSpdEV() const {return spdEV;}
    int getSpeEV() const {return speEV;}
    bool atMaxEV() const;
    void addHPEV(int amount);
    void addAtkEV(int amount);
    void addDefEV(int amount);
    void addSpaEV(int amount);
    void addSpdEV(int amount);
    void addSpeEV(int amount);
    int calculateHP() const;
    int calculateAtk() const;
    int calculateDef() const;
    int calculateSpa() const;
    int calculateSpd() const;
    int calculateSpe() const;

    std::string getMove(int index) const {return Moves[index];}
    void setMove(int index, std::string newMove) {Moves[index] = newMove;}
    int getMovePP(int index) const {return MovePP[index];}
    void setMovePP(int index, int newPP) {MovePP[index] = newPP;}
    int getMovePPUp(int index) const {return MovePPUps[index];}
    void setMovePPUp(int index, int newPPUp) {MovePPUps[index] = newPPUp;}
    void learnMove(int index, std::string newMove); //do full process
    void swapMoves(int index1, int index2); //do full process
    void forgetMove(int index); //remove move then move all moves up
    bool canLearnMove() const;

    std::string getOTName() const {return OTName;}
    int getOTID() const {return OTID;}
    int getSID() const {return SID;}

    static void serialize(std::ostream& outputStream, const PartyPokemon& pkmn);
    static void deserialize(std::istream& inputStream, PartyPokemon& pkmn);
    friend std::ostream& operator<<(std::ostream& os, const PartyPokemon& pkmn) {PartyPokemon::serialize(os, pkmn);}
    friend std::istream& operator>>(std::istream& is, PartyPokemon& pkmn) {PartyPokemon::deserialize(is, pkmn);}
    Pokemon getPokemon() const {return PkmnFactory::getPokemon(species);}
};