#ifndef TOKENSTR_H
#define TOKENSTR_H

#include "token.h"

class TokenStr: public Token{
public:
    TokenStr();
    TokenStr(string symbol);

    void Print(ostream &outs=cout) const;
    const TOKEN_TYPES TypeOf() const{return TOKENSTRING;}
    virtual const string token_string() const;

private:
    string _symbol;
};

#endif