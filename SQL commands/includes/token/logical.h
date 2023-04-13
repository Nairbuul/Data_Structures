#ifndef LOGICAL_H
#define LOGICAL_H

#include "token.h"

class Logical: public Token{
public:
    Logical();
    Logical(const string AndOr);

    void Print(ostream &outs=cout) const;
    const TOKEN_TYPES TypeOf() const{return LOGICAL;}
    virtual const string token_string() const;
private:
    string _AndOr;
};

#endif