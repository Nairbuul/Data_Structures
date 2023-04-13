#ifndef RIGHT_PAREN_H
#define RIGHT_PAREN_H

#include "token.h"

class RightParen: public Token{
public:
    RightParen();
    RightParen(string value);

    void Print(ostream &outs=cout) const ;
    const TOKEN_TYPES TypeOf() const{return RPAREN;}
private:
    string rParen;
};

#endif