#ifndef TOKEN_H
#define TOKEN_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "../tokenizer/constants.h"

using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type);
    
    friend ostream& operator <<(ostream& outs, const Token& t);
    virtual void Print(ostream& outs=cout) const;

    int type() const;
    virtual const TOKEN_TYPES TypeOf() const{}

    string type_string() const;
    string token_str() const;
    virtual const string token_string() const;
private:
    string _token;
    int _type;
};

#endif