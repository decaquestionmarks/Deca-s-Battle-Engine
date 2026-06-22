#pragma once
#include <string>

class Nature{
    private:
    std::string name;
    double hpMod = 0;
    double atkMod = 0;
    double defMod = 0;
    double spaMod = 0;
    double spdMod = 0;
    double speMod = 0;
    public:
    Nature();
    ~Nature();
    std::string getName() const {return name;}
    double onModifyHP(double hp) const {return hp * (1 + hpMod);}
    double onModifyAttack(double atk) const {return atk * (1 + atkMod);}
    double onModifyDefense(double def) const {return def * (1 + defMod);}
    double onModifySpAttack(double spa) const {return spa * (1 + spaMod);}
    double onModifySpDefense(double spd) const {return spd * (1 + spdMod);}
    double onModifySpeed(double spe) const {return spe * (1 + speMod);}
};

class Hardy: public Nature {
    private:
    std::string name = "Hardy";
    public:
    Hardy();
    ~Hardy();
};

class Lonely: public Nature {
    private:
    std::string name = "Lonely";
    double atkMod = 0.1;
    double defMod = -0.1;
    public:
    Lonely();
    ~Lonely();
};

class Brave: public Nature {
    private:
    std::string name = "Brave";
    double atkMod = 0.1;
    double speMod = -0.1;
    public:
    Brave();
    ~Brave();
};

class Adamant: public Nature {
    private:
    std::string name = "Adamant";
    double atkMod = 0.1;
    double spaMod = -0.1;
    public:
    Adamant();
    ~Adamant();
};

class Naughty: public Nature {
    private:
    std::string name = "Naughty";
    double atkMod = 0.1;
    double spdMod = -0.1;
    public:
    Naughty();
    ~Naughty();
};

class Bold: public Nature {
    private:
    std::string name = "Bold";
    double defMod = 0.1;
    double atkMod = -0.1;
    public:
    Bold();
    ~Bold();
};

class Docile: public Nature {
    private:
    std::string name = "Docile";
    public:
    Docile();
    ~Docile();
};

class Relaxed: public Nature {
    private:
    std::string name = "Relaxed";
    double defMod = 0.1;
    double speMod = -0.1;
    public:
    Relaxed();
    ~Relaxed();
};

class Impish: public Nature {
    private:
    std::string name = "Impish";
    double defMod = 0.1;
    double spaMod = -0.1;
    public:
    Impish();
    ~Impish();
};

class Lax: public Nature {
    private:
    std::string name = "Lax";
    double defMod = 0.1;
    double spdMod = -0.1;
    public:
    Lax();
    ~Lax();
};

class Timid: public Nature {
    private:
    std::string name = "Timid";
    double speMod = 0.1;
    double atkMod = -0.1;
    public:
    Timid();
    ~Timid();
};

class Hasty: public Nature {
    private:
    std::string name = "Hasty";
    double speMod = 0.1;
    double defMod = -0.1;
    public:
    Hasty();
    ~Hasty();
};

class Serious: public Nature {
    private:
    std::string name = "Serious";
    public:
    Serious();
    ~Serious();
};

class Jolly: public Nature {
    private:
    std::string name = "Jolly";
    double speMod = 0.1;
    double spaMod = -0.1;
    public:
    Jolly();
    ~Jolly();
};

class Naive: public Nature {
    private:
    std::string name = "Naive";
    double speMod = 0.1;
    double spdMod = -0.1;
    public:
    Naive();
    ~Naive();
};

class Modest: public Nature {
    private:
    std::string name = "Modest";
    double spaMod = 0.1;
    double atkMod = -0.1;
    public:
    Modest();
    ~Modest();
};

class Mild: public Nature {
    private:
    std::string name = "Mild";
    double spaMod = 0.1;
    double defMod = -0.1;
    public:
    Mild();
    ~Mild();
};

class Quiet: public Nature {
    private:
    std::string name = "Quiet";
    double spaMod = 0.1;
    double speMod = -0.1;
    public:
    Quiet();
    ~Quiet();
};

class Bashful: public Nature {
    private:
    std::string name = "Bashful";
    public:
    Bashful();
    ~Bashful();
};

class Rash: public Nature {
    private:
    std::string name = "Rash";
    double spaMod = 0.1;
    double spdMod = -0.1;
    public:
    Rash();
    ~Rash();
};

class Calm: public Nature {
    private:
    std::string name = "Calm";
    double spdMod = 0.1;
    double atkMod = -0.1;
    public:
    Calm();
    ~Calm();
};

class Gentle: public Nature {
    private:
    std::string name = "Gentle";
    double spdMod = 0.1;
    double defMod = -0.1;
    public:
    Gentle();
    ~Gentle();
};

class Sassy: public Nature {
    private:
    std::string name = "Sassy";
    double spdMod = 0.1;
    double speMod = -0.1;
    public:
    Sassy();
    ~Sassy();
};

class Careful: public Nature {
    private:
    std::string name = "Careful";
    double spdMod = 0.1;
    double spaMod = -0.1;
    public:
    Careful();
    ~Careful();
};

class Quirky: public Nature {
    private:
    std::string name = "Quirky";
    public:
    Quirky();
    ~Quirky();
};