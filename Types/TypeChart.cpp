#include <vector>
#include "Type.hpp"

class TypeChart{
    public:
    static double onEffectiveness(const Type t1, const std::vector<Type> types){
        double effectiveness = 1.0;
        for (const Type& t2 : types) {
            effectiveness *= t2.onEffectiveness(t1);
        }
        return effectiveness;
    }
};