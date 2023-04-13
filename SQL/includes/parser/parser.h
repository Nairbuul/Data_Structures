#ifndef PARSER_H
#define PARSER_H

#include "../bplustree/map.h"
#include "../bplustree/multimap.h"
#include "../tokenizer/state_machine_functions.h"
#include "../tokenizer/stokenize.h"
#include "../stl_utils/typedefs.h"


class Parser{
public:
    Parser();
    Parser(char* input);

    void initialize_keywords();
    void initialize_table();

    void set_string(char* input);
    int get_column(string token);
    void print_lookup();
    
    bool fail(int state);
    bool get_parse_tree();
    MMap<string, string> parse_tree();

    void output_loop();

private:
    Map<string, int> keyword_map;
    MMap<string, string> PTree;
    static int STM[MAX_ROWS][MAX_COLUMNS];
    
   
    vector<string> _tokens;
   
    char* _input;
    bool _fail;

    enum keywords {
        SYMBOL = 1,  
        SELECT = 2, 
        MAKE = 3,   
        INSERT = 4,
        FROM = 5,
        STAR = 6,
        FIELDS = 7,
        WHERE = 8,
        VALUES = 9
    };
};

#endif