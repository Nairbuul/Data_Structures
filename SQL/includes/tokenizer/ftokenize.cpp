#include "ftokenize.h"
FTokenizer::FTokenizer(char* fname){
    _f.open(fname);
    if(_f.is_open()){
        if(!get_new_block()){
            cout << "Could not get new block";
            exit(0);
        }
    }
    else if(_f.fail()){
        cout << "Opening File Failed. \n Exiting...";
        exit(0);
    }
}
Token FTokenizer::next_token(){
    Token t;
    _stk >> t;
    return t;
}
bool FTokenizer::more(){
    if(!_stk.more()){
        if(!get_new_block()){
            _f.close();
            return false;
        }
    }
    return true;
}
int FTokenizer::pos(){
    return _pos;
}        
int FTokenizer::block_pos(){
    return _blockPos;
}
FTokenizer& operator >> (FTokenizer& f, Token& t){
    t = f.next_token();
    return f;
}
bool FTokenizer::get_new_block(){
    if(_f.peek() == EOF){
        return false;
    }
    char new_block[MAX_BLOCK];
    _f.read(new_block, MAX_BLOCK-1);
    new_block[_f.gcount()] = '\0';
    _stk.set_string(new_block);

    cout << "----- New Block ---------------------["<< _f.gcount() <<"] bytes" << endl;
    return true;
}
