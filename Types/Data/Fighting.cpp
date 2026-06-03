#include "Type.hpp"

class Fighting: public Type {
    public:
    Fighting(){
        Type();
        name = "Fighting";
        TypeChart["Rock"] = 0.5;    
        TypeChart["Bug"] = 0.5;
        TypeChart["Dark"] = 0.5;
        TypeChart["Ice"] = 2;
        TypeChart["Psychic"] = 2;
        TypeChart["Fairy"] = 2;
    }
    ~Fighting();
};