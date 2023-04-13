#include "shunting_yards.h"
// #include <bits/stdc++.h>

// string to_lower1(string &s){
//     transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return std::tolower(c);});
//     return s;
// }

// string to_lower1(const string s){
//     string a = s;
//     transform(a.begin(), a.end(), a.begin(),[](unsigned char c){return std::tolower(c);});
//     return a;
// }

ShuntingYard::ShuntingYard(const vectorstr condition){
    //converting to string to fix size
    //then converting it to char for stokenizer...
    char test2[300];
    string test3;
    for(int i = 0; i < condition.size(); i++){
        strcpy(test2, condition[i].c_str());
        test3 += test2 + string(" ");
    }
    strcpy(test2, test3.c_str());
  
    //Tokenizing... and creating a queue...
    STokenizer stk(test2);
    Token t;
    stk>>t;
    while(stk.more()){ 
        if(t.type() != TOKEN_SPACE && t.type() != TOKEN_UNKNOWN){
            // cout <<'\t' << t << '\t' << t.type_string() << endl;
            _infix.push(t);
        }
        stk>>t;
    }
    string_enum();
    token_ptr_conversion();
}

void ShuntingYard::string_enum(){
    relational_map["("] += 0;
    relational_map[")"] += 1;
    relational_map["="] += 2;
    relational_map[">"] += 3;
    relational_map["<"] += 4;
    relational_map["and"] += 5;
    relational_map["or"] += 6;
}

Queue<Token* > ShuntingYard::postfix(){
    const bool debug = false;
    Stack<Token* > pringles_can;
    Queue<Token* > postfix; //<--actuall postfix bad names sorry 

    //only time it sits ontop is if it's larger... left parent and right paren largest so it
    //probably don't need a case atm... 

    while(!_postfix.empty()){
        Token* t = _postfix.pop();
        int comparison = t->TypeOf();
        switch(comparison){
            case TOKENSTRING:{
                if(debug){cout << t->token_string() << "\t" <<"Tokenstring" << endl;}
                postfix.push(t);
                break;
            }
            case LOGICAL:{
                if(debug){cout << t->token_string() << "\t" <<"Logical: "<< endl;}
                if(!pringles_can.empty()){
                    if(t->TypeOf() > pringles_can.top()->TypeOf() || pringles_can.empty()){
                        cout <<"logical1: " << t->token_string() << endl;
                        pringles_can.push(t);
                    }
                    else{
                        cout << "logical2: "<< t->token_string() << endl;
                        postfix.push(pringles_can.pop());
                        pringles_can.push(t);
                    }
                }
                else{
                    pringles_can.push(t);
                }
                break;
            }
            case RELATIONAL:{
                if(debug){cout << t->token_string() << "\t" <<"Relational" << endl;}
                if(!pringles_can.empty()){
                    if(t->TypeOf() > pringles_can.top()->TypeOf() || pringles_can.empty()){
                        pringles_can.push(t);
                    }
                    else{
                        cout << pringles_can.size() << "Relational: " << '\t' << pringles_can.top()->token_string() << endl;
                        postfix.push(pringles_can.pop());
                        pringles_can.push(t);
                    }
                }
                else{
                    pringles_can.push(t);
                }
                break;
            }
            case LPAREN:{
                if(debug){cout << "\t" << "LParen" << endl;}
                
                pringles_can.push(t);
                break;
            }
            case RPAREN:{
                if(debug){cout << "\t" << "RParen" << endl;}
                //Check for left paren first.
                bool exists = false;
                for(Stack<Token*>::Iterator walker = pringles_can.begin(); walker != pringles_can.end(); walker++){
                    if((*(*walker)).TypeOf() == LPAREN){
                        exists = true;
                    }
                }
                if(!exists){
                    cout << "Exiting! [MISSING \"(\" ]" << endl;
                    exit(0);
                }

                //Pop until we see a left paren and get rid of it.
                while(pringles_can.top()->TypeOf() != LPAREN){
                    postfix.push(pringles_can.pop());
                }
                if(pringles_can.top()->TypeOf() == LPAREN){
                    pringles_can.pop(); //getting rid of Lparen
                }
                break;
            }
        }
    }

    //clearing stack after emptying out prev queue
    while(!pringles_can.empty()){
        postfix.push(pringles_can.pop());
    }

    if(debug){
        int z = 0;
        while(!postfix.empty()){
            Token* t = postfix.pop();
            cout << z << ":" << t->token_string() << "\t" << t->TypeOf() << endl;
            z++;
        }
    }

    return postfix; 
}


void ShuntingYard::token_ptr_conversion(){
    const bool debug = false;
    int comparison = 0;

    while(!_infix.empty()){
        Token t = _infix.pop();

        //Looking for keywords or defaults to 7;
        if(relational_map.contains(t.token_str())){
            comparison = relational_map[t.token_str()];
        }
        else{
            comparison = 7;
        }
        
        switch(comparison){
            case 0:{
                _postfix.push(new LeftParen("("));
                break;
            }
            case 1:{
                _postfix.push(new RightParen(")"));
                break;
            }
            case 2:{
                _postfix.push(new Relational("="));
                break;
            }
            case 3:{
                if(_infix.front().token_str() == "="){
                    _infix.pop();
                    _postfix.push(new Relational(">="));
                }
                else{
                    _postfix.push(new Relational(">"));
                }
                break;
            }
            case 4:{
                if(_infix.front().token_str() == "="){
                    _infix.pop();
                    _postfix.push(new Relational("<="));
                }
                _postfix.push(new Relational("<"));
                break;
            }
            case 5:{
                _postfix.push(new Logical("and"));
                break;
            }
            case 6:{
                _postfix.push(new Logical("or"));
                break;
            }
            default:{
                _postfix.push(new TokenStr(t.token_str()));
                break;
            }
        }
    }
//===========================================================================================
    if(debug){
        int i = 0;
        Queue<Token*> temp = _postfix;
        cout << _postfix.size() << endl;
        while(!_postfix.empty()){
            cout << i << ": ";
            i++;
            Token* temp = _postfix.pop();
            if(temp->TypeOf() == LPAREN || temp->TypeOf() == RPAREN){
                cout << "parenthesis" << endl;
                // temp = _postfix.pop();
            }
            else{
                cout << temp->token_string() << endl;
            }
        }
        _postfix = temp;
    }
//===========================================================================================
}

//obsolete!
// Queue<Token*> ShuntingYard::token_ptr_conversion(){
    
    // int i = 0;
    // while(!_infix.empty()){
    //     Token t = _infix.pop();
    //     cout << i<< ": " << t.token_str() << endl;//token_str() << endl;
    //     i++;
    //     if(t.type() == TOKEN_OPERATOR){
    //         if(t.token_str() == "("){
    //             _postfix.push(new LeftParen("("));
    //         }
    //         if(t.token_str() == ")"){
    //             _postfix.push(new RightParen(")"));
    //         }
    //         if(t.token_str() == ">"){
    //             if(_infix.front().token_str() == "="){
    //                 cout << __LINE__ << endl;
    //                 _infix.pop();
    //                 _postfix.push(new Relational(">="));
    //             }
    //             else{
    //                 _postfix.push(new Relational(">"));
    //             }
    //         }
    //         if(t.token_str() == "<"){
    //             if(_infix.front().token_str() == "="){
    //                 cout << __LINE__ << endl;
    //                 _infix.pop();
    //                 _postfix.push(new Relational("<="));
    //             }
    //             else{
    //                 _postfix.push(new Relational("<"));
    //             }
    //         }
    //         if(t.token_str() == "="){
    //             _postfix.push(new Relational("="));
    //         }
    //         if(t.token_str() == "*"){
    //             _postfix.push(new TokenStr("*"));
    //         }
    //     }
    //     else{
    //         if(t.token_str() == string("and")){
    //             _postfix.push(new Logical("and"));
    //         }
    //         else if(t.token_str() == string("or")){
    //             _postfix.push(new Logical("or"));
    //         }
    //         else{
    //             _postfix.push(new TokenStr(t.token_str()));
    //         }
    //     }
    // }   
    // cout << "PF SIZE!" << _postfix.size() << endl << endl;
    // i = 0;
    // while(!_postfix.empty()){
    //     cout << i << ": ";
    //     i++;
    //     Token* temp = _postfix.pop();
    //     if(temp->TypeOf() == LPAREN || temp->TypeOf() == RPAREN){
    //         cout << "parenthesis" << endl;
    //         // temp = _postfix.pop();
    //     }
    //     else{
    //         cout << temp->token_string() << endl;
    //     }
    // }

    // exit(0);
// }