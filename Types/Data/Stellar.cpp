#include "Type.hpp"

class Stellar: public Type {
    public:
    Stellar(){
        Type();
        name = "Stellar";
    }
    ~Stellar();
};