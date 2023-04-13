#ifndef TABLE_H
#define TABLE_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string.h>
#include <fstream>
#include <assert.h>
#include <algorithm>
// #include <bits/stdc++.h>

#include "../stl_utils/typedefs.h"
#include "../bplustree/multimap.h"
#include "../bplustree/map.h"
#include "../binary_files/file_record.h"
#include "../binary_files/utilities.h"
#include "../stl_utils/vector_utilities.h"
#include "../token/token.h"
#include "../shunting_yards/shunting_yards.h"

using namespace std;
class Table{
public:
    Table();
    Table(const string& name);
    Table(const string& name, const vectorstr field_names);

    void insert_into(vectorstr fields);
    void insert_into(FileRecord r);

    Table select_all();
    Table select_all(const vectorstr fields);
    Table select(const vectorstr fields, const vectorlong infx);
    Table select(const vectorstr fields, const vectorstr conditions);
    Table select(const vectorstr fields, Queue<Token *> postfix);
    Table select(const vectorstr fields, const string field, const string condition, const string value);

    vectorlong grab_records(const vectorstr field_name, const string field, const string conditions, const string values);
    
    vectorlong records(){return selected_records;}
    vectorlong select_recnos();
    vectorstr get_fields();
    void set_fields(const vector<string> &field_names);
    void initialize_conditions();
    void reindex();

    friend ostream& operator<<(ostream& outs, const Table& print_me){
        //Table name and field names
        if(print_me.last_record != 0)
            outs << endl << "Table name: " << print_me.table_name <<  ", " << "records: " << print_me.last_record+1 << endl;
        else
            outs << endl << "Table name: " << print_me.table_name <<  ", " << "records: " << 0 << endl;
        vectorstr output;
        read_info((print_me.table_name+"_fields.txt").c_str(), output);
        outs << setw(10) << "record";
        for(int i =0; i <output.size(); i++){
            outs << setw(25) << output[i];
        }
        outs << endl << endl;

        //Print binary file tbl records
        fstream f;
        FileRecord r;
        open_fileRW(f, (print_me.table_name+".tbl").c_str());
        int i = 0;
        long bytes = r.read(f,i);
        while (bytes>0){
            outs << setw(10) << i << setw(10) << r << endl;
            i++;
            bytes = r.read(f, i);
        }
        outs << endl;

        return outs;
    }

private:
    static long serial_num; //Table ID.
    long last_record;
    bool empty; 
    
    vectorlong selected_records;

    vectorstr fields;
    vector<mmap_sl> indices;
    string table_name;
    map_sl field_map;
    map_sl conditions_map;
};

#endif