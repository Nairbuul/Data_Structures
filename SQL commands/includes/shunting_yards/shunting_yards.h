#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <string.h>

#include "../stl_utils/typedefs.h"
#include "../stack/MyStack.h"
#include "../queue/MyQueue.h"

#include "../token/token.h"
#include "../tokenizer/stokenize.h"

#include "../token/left_paren.h"
#include "../token/right_paren.h"
#include "../token/tokenstr.h"
#include "../token/logical.h"
#include "../token/relational.h"
#include "../bplustree/map.h"

class ShuntingYard
{
public:
    ShuntingYard(const vectorstr conditions);

    
    Queue<Token*> postfix();

private:
    Queue<Token > _infix;
    Queue<Token* > _postfix;

    void token_ptr_conversion();
    void string_enum();
    map_sl relational_map;
};

#endif