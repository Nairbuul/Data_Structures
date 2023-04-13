#include "tokenstr.h"

TokenStr::TokenStr(){

}
TokenStr::TokenStr(string symbol){
    _symbol = symbol;
}

void TokenStr::Print(ostream &outs) const{
    outs << "[" << _symbol << "]";
}

const string TokenStr::token_string() const{
    return _symbol;
}