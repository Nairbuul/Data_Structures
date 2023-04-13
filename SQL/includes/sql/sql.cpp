#include "sql.h"

SQL::SQL(){
    initialize_stringEnum();
}

SQL::SQL(char* fname){
    // FTokenizer ftk(fname);
    //ifstream read fstream write

    initialize_stringEnum();
    vectorstr batch_file;
    read_info(fname, batch_file);    
    for(int i = 0; i < batch_file.size(); i++){
        if(batch_file[i].size() != 0)
            cout << "Batch File-" << i << ": " << batch_file[i] << endl;
        command(batch_file[i]);
    }
}

Table SQL::command(const string input){
    char buffer[input.size()];
    strcpy(buffer, input.c_str());
    Parser p(buffer);
    ptree = p.parse_tree();
    if(ptree.empty()){
        return Table();
    }    
    Table t = evaluate();
    return t;
}   

vectorlong SQL::select_recnos(){
    return record_no;
}

Table SQL::evaluate(){
    const bool debug = false;

    vectorstr command;
    vectorstr field_names;
    vectorstr table_name;
    vectorstr conditions;
    vectorstr values;
    
    vectorstr check_list = {"command", "fields", "table", "condition","values"};
    vector<int> check;
    for(int i = 0; i < check_list.size(); i++){
        if(ptree.contains(check_list[i])){
            check.push_back(i);
        }
    }

    for(int i = 0; i < check.size(); i++){
        switch(check[i]){
            case 0:{
                if(debug){cout << "case 0:" << endl;}
                command = ptree.at("command");
                if(command.size() > 1){
                    cout << "EXITING TOO MANY COMMANDS:" << endl;
                    exit(0);
                }
                break;
            }
            case 1:{
                if(debug){cout << "case 1:" << endl;}
                field_names = ptree.at("fields");
                break;
            }
            case 2:{
                if(debug){cout << "case 2:" << endl;}
                table_name = ptree.at("table");
                if(table_name.size() > 1){
                    cout << "EXITING INVALID COMMAND(MORE THAN ONE TABLE NAME CALLED)" << endl;
                    exit(0);
                }
                break;
            }
            case 3:{
                if(debug){cout << "case 3:" << endl;}
                conditions = ptree.at("condition");
                break;
            }
            case 4:{
                if(debug){cout << "case 4:" << endl;}
                values = ptree.at("values");
                break;
            }
        }
    }


    switch(cases[command[0]]){
        case 0:{
            //select
            record_no.clear();
            if(field_names[0] == "*"){
                if(conditions.size() == 0){
                    Table t(table_name[0]);
                    Table temp = t.select_all();
                    record_no = t.records();
                    return temp;
                }
                else{
                    Queue<Token> infix;
                    for(int i = 0; i < conditions.size();i++){
                        Token tok(conditions[i],0);
                        infix.push(tok);
                    }
                    ShuntingYard sy(infix);
                    Queue<Token*> postfix = sy.postfix();
                    Table t(table_name[0]);
                    vectorstr fieldNames;
                    read_info((table_name[0]+"_fields.txt").c_str(), fieldNames);
                    Table temp = t.select(fieldNames, postfix);
                    record_no = t.records();
                    return temp;
                }
            }
            else if(conditions.size() == 0){
                Table t(table_name[0]);
                Table temp = t.select_all(field_names);
                    record_no = t.records();
                return temp;
            }
            else{
                Table t(table_name[0]);
                Table temp = t.select(field_names, conditions);
                cout <<temp << endl;
            }
            break;
        }
        case 1:{
            //insert
            Table t(table_name[0]);
            t.insert_into(values); 
            return t;
            break;
        }
        case 2:{
            //make
            Table t(table_name[0], field_names);
            return t;
            break;
        }
    }
}

void SQL::initialize_stringEnum(){
    cases.insert(string("select"), 0);
    cases.insert(string("insert"), 1);
    cases.insert(string("make"), 2);
}

