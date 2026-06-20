#pragma once
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "../Conditions/Condition.hpp"

class Type{
protected:
    std::unordered_map<std::string, double> TypeChart; //key by name of type
    std::unordered_set<std::string> ConditionImmunities; //key by name of condition, assumed to always be an immunity, also use for tags (sry powder)
    std::string name;
    public:
    Type();
    ~Type();
    virtual double onEffectiveness(const Type& t) const;
    virtual bool onCondition(const Condition& c) const;
    std::string getName() const {return name;}
    bool operator==(const Type b) const {return this->name == b.name;} 
};

namespace std {
    template<>
    struct hash<Type> {
        size_t operator()(const Type& t) const {
            return hash<string>()(t.getName());
        }
    };
}