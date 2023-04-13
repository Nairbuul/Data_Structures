#include "relational.h"

Relational::Relational(){
    //empty
}   

Relational::Relational(string relation){
    _relation = relation;
}

void Relational::Print(ostream &outs) const{
    outs << "[" << _relation << "]";
}

const string Relational::token_string() const{
    return _relation;
}