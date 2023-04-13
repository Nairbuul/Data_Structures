#include "parser.h"
#include <typeinfo>
#include <cstring>
// #include <bits/stdc++.h>

int Parser::STM[MAX_ROWS][MAX_COLUMNS];

string to_lower(string &s){
    transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return std::tolower(c);});
    return s;
}

Parser::Parser(char* input){
    initialize_table();
    initialize_keywords();
    set_string(input);
}

void Parser::initialize_keywords(){
   //Commands
    keyword_map.insert(string("select"), 2);
    keyword_map.insert(string("make"), 3);
    keyword_map.insert(string("insert"), 4);

    //tables
    keyword_map.insert(string("from"), 5);

    //fields
    keyword_map.insert(string("*"), 6);
    keyword_map.insert(string("fields"), 7);

    //condition
    keyword_map.insert(string("where"), 8);

    //values
    keyword_map.insert(string("values"), 9);
}

void Parser::initialize_table(){
    init_table(STM);
    
    mark_cell(0, STM, SELECT, 1);
    mark_cell(0, STM, MAKE, 7);
    mark_cell(0, STM, INSERT, 7);
    mark_cell(1, STM, SYMBOL, 2);
    mark_cell(1, STM, STAR, 2);
    mark_cell(2, STM, SYMBOL, 2);
    mark_cell(2, STM, FROM, 3);
    mark_cell(3, STM, SYMBOL, 4);
    mark_cell(4, STM, WHERE, 5);
    mark_cell(5, STM, SYMBOL, 6);
    mark_cell(6, STM, SYMBOL, 6);
    mark_cell(7, STM,  SYMBOL, 8);

    mark_cell(8, STM, FIELDS, 9);
    mark_cell(8, STM, VALUES, 11);

    mark_cell(9, STM, SYMBOL, 10);
    mark_cell(10, STM, SYMBOL, 10);
    mark_cell(11, STM, SYMBOL, 12);
    mark_cell(12, STM, SYMBOL, 12);

    mark_success(STM, 4);
    mark_success(STM, 6);
    mark_success(STM, 10);
    mark_success(STM, 12);
}

void Parser::set_string(char* input){
    const bool debug = false;
    _tokens.clear();
    PTree.clear();
    
    STokenizer stk(input);
    Token t;

    while(!stk.done()){
        stk >> t;
        if(t.type() != TOKEN_SPACE && t.type() != TOKEN_PUNC){
            if(t.token_str() != string("table") && t.token_str() != string("into") && t.token_str() != (",")){
                _tokens.push_back(t.token_str());
            }
        }
    }
    if(debug){
        cout << "_tokens: -----" << endl;
        for(int i = 0; i < _tokens.size(); i++){
            cout << "|" << _tokens[i] << "|" << endl;
        }
    }

    get_parse_tree();
}

int Parser::get_column(string token){
    const bool debug = false;
    
    if(!keyword_map.contains(to_lower(token))){
        if(debug){cout << token << endl;}
        return SYMBOL; //defaults to symbol.
    }
    else{
        return keyword_map[to_lower(token)];
    }
}

bool Parser::fail(int state){
    const bool debug = false;
    if(STM[state][0] == 1){
        if(debug){cout << "true"  << endl;}
        return true;
    }
    else{
        if(debug){cout << "false" << endl;}
        return false;
    }
    return true;
}

bool Parser::get_parse_tree(){
    const bool debug = false;
    int current_state = 0;

    for(int i = 0; i < _tokens.size()-1; i++){
        // assert(current_state >= 0 && "invalid commands");
        if(current_state < 0){
            PTree.clear();
            return false;
        }
        current_state = STM[current_state][get_column(_tokens[i])];
        if(debug){cout << _tokens[i] << ':' << current_state << endl;}
        switch(current_state){
            case 1:{
                if(debug){cout << "state: 1: (Select): " << _tokens[i] << endl;}
                PTree[string("command")] += _tokens[i];
                break;
            }
            case 2:{
                if(debug){cout << "state: 2: (Fields): " << _tokens[i] << endl;}
                PTree[string("fields")] += _tokens[i];
                break;
            }
            case 3:{
                if(debug){cout << "state: 3 (FROM): " <<_tokens[i] << endl;}
                break;
            }
            case 4:{
                if(debug){cout << "state: 4 (Table): " << _tokens[i] << endl;}
                PTree[string("table")] += _tokens[i];
                break; 
            }
            case 5:{
                if(debug){cout << "state: 5 (Where): " << _tokens[i] << endl;}
                PTree[string("where")] += string("yes");
                break;   
            }
            case 6:{
                if(debug){cout << "state: 6 (condition): " << _tokens[i] << endl;}
                PTree[string("condition")] += _tokens[i];
                break;
            }
            case 7:{
                if(debug){cout << "state: 7 (command): " << _tokens[i] << endl;}
                PTree[string("command")] += _tokens[i];
                break;
            }
            case 8:{
                if(debug){cout << "state: 8 (table): " << _tokens[i] << endl;}
                PTree[string("table")] += _tokens[i];
                break;
            }
            case 9:{
                if(debug){cout << "state: 9 fields" << _tokens[i] << endl;}
                break;
            }
            case 10:{
                if(debug){cout << "state: 10 (field symbol): " << _tokens[i] << endl;}
                PTree[string("fields")] +=_tokens[i];
                break;
            }
            case 11:{
                if(debug){cout << "state: 11 (value): " << _tokens[i] << endl;}
                break;
            }
            case 12:{
                if(debug){cout << "state: 12 (value symbols): " << _tokens[i] << endl;}
                PTree[string("values")] += _tokens[i];
                break;
            }
        }
    }

    return fail(current_state);
}

 MMap<string, string> Parser::parse_tree(){
    return PTree;
 }
