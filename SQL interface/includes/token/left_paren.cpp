#include "left_paren.h"

LeftParen::LeftParen(){

}
LeftParen::LeftParen(string LParen){
    _LParen = LParen;
}

void LeftParen::Print(ostream &outs) const{
    outs << "[" << _LParen << "]";
}