#pragma once
#include "GrowthRate.hpp"

class GrowthRateFactory{
    public:
    static GrowthRate* getGrowthRate(const std::string_view name){
        if(name == "Medium Fast") return new MediumFast();
        else if(name == "Erratic") return new Erratic();
        else if(name == "Fluctuating") return new Fluctuating();
        else if(name == "Medium Slow") return new MediumSlow();
        else if(name == "Fast") return new Fast();
        else if(name == "Slow") return new Slow();
        else return new MediumFast();
    }
};