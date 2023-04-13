#ifndef TOKEN_H
#define TOKEN_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "constants.h"

using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type);
    friend ostream& operator <<(ostream& outs, const Token& t);
    int type() const;

    string type_string() const;
    string token_str() const;
private:
    string _token;
    int _type;
};

#endif