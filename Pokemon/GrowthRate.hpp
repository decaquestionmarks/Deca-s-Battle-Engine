#pragma once
#include <string>

class GrowthRate {
    private:
    std::string name;
    public:
    GrowthRate();
    ~GrowthRate();
    std::string getName() const {return name;}
    virtual int getExp(int level) const = 0;
    virtual int getLevel(int exp) const = 0;
};

class MediumFast: public GrowthRate {
    private:
    std::string name = "Medium Fast";
    public:
    MediumFast();
    ~MediumFast();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};

class Erratic: public GrowthRate {
    private:
    std::string name = "Erratic";
    public:
    Erratic();
    ~Erratic();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};

class Fluctuating: public GrowthRate {
    private:
    std::string name = "Fluctuating";
    public:
    Fluctuating();
    ~Fluctuating();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};

class MediumSlow: public GrowthRate {
    private:
    std::string name = "Medium Slow";
    public:
    MediumSlow();
    ~MediumSlow();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};

class Fast: public GrowthRate {
    private:
    std::string name = "Fast";
    public:
    Fast();
    ~Fast();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};

class Slow: public GrowthRate {
    private:
    std::string name = "Slow";
    public:
    Slow();
    ~Slow();
    int getExp(int level) const override;
    int getLevel(int exp) const override;
};