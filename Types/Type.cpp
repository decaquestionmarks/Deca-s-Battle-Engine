#include "Type.hpp"

Type::Type() {
    name = "Type";
    TypeChart = std::unordered_map<std::string, double>();
    ConditionImmunities = std::unordered_set<std::string>();
}

Type::~Type() {
    // nothing to do lol
}

double Type::onEffectiveness(const Type t) const{
    auto it = TypeChart.find(t.name);
    if (it != TypeChart.end()) return it->second;
    return 1.0; // neutral if not found
}

bool Type::onCondition(const Condition c) const{
    return !(ConditionImmunities.find(c.name) != ConditionImmunities.end()); //false if immune, true if not immune
}
