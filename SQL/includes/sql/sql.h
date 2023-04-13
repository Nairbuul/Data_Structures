#ifndef SQL_H
#define SQL_H

#include "../table/table.h"
#include "../parser/parser.h"
#include "../tokenizer/ftokenize.h"

class SQL{
public:
    SQL();
    SQL(char* fname);
    Table command(const string input);
    vectorlong select_recnos();
private:
    Map<string, Table> file_cabinet;
    Table t;
    vectorlong record_no;
    mmap_ss ptree;
    map_sl cases;
    Table evaluate();
    void initialize_stringEnum();
};


#endif