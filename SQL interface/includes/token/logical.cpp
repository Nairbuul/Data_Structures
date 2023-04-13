#include "logical.h"

Logical::Logical(){
    //empty
}

Logical::Logical(const string AndOr){
    _AndOr = AndOr;
}

 void Logical::Print(ostream &outs) const{
    outs << "[" << _AndOr << "]";
 }

const string Logical::token_string() const{
    return _AndOr;
 }