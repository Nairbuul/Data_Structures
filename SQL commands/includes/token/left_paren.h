#ifndef LEFT_PAREN_H
#define LEFT_PAREN_H

#include "token.h"

class LeftParen: public Token{
public:
    LeftParen();
    LeftParen(string LParen);

    void Print(ostream &outs=cout) const ;
    const TOKEN_TYPES TypeOf() const{return LPAREN;}
private:
    string _LParen;
};

#endif