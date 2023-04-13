#include "right_paren.h"

RightParen::RightParen(){
    //empty
}

RightParen::RightParen(string value){
    rParen = value;
}

void RightParen::Print(ostream &outs) const{
    outs << "[" << rParen << "]";
}