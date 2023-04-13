#ifndef RELATIONAL_H
#define RELATIONAL_H

#include "token.h"

class Relational: public Token{
public:
    Relational();
    Relational(string relation);

    void Print(ostream &outs=cout) const;
    TOKEN_TYPES TypeOf(){return RELATIONAL;}
    const TOKEN_TYPES TypeOf() const{return RELATIONAL;}
    virtual const string token_string() const;
private:
    string _relation;
};

#endif