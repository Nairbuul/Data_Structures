#include "table.h"

long Table::serial_num = 0;

Table::Table(){
    last_record = 0;
    bool empty = true;
}

Table::Table(const string& name){
    //makes sure file exists...
    assert(file_exists((name+".tbl").c_str()));

    //initialize private variable tblname
    table_name = name;

    //read from txt file to fill up the vector of field names
    read_info((name+"_fields.txt").c_str(), fields);

    //initializing ptree 
    set_fields(fields);
    
    //Size will get changed when reindexing.
    last_record = 0;
    serial_num++;

    //Reindexing 
    reindex();

    //init conditions
    initialize_conditions();
}

Table::Table(const string& name, const vectorstr field_names){
    //this ctor creates a table...
    fstream _file;
    serial_num++;
    table_name = name;
    last_record = 0;
    initialize_conditions();
    set_fields(field_names);
    open_fileW(_file, (table_name + ".tbl").c_str());
    write_info((table_name + "_fields.txt").c_str(), field_names);
    _file.close();
}

void Table::insert_into(vectorstr field_names){
    //ensuring the file exists.
    assert(file_exists((table_name+".tbl").c_str()));
    
    //Opening the file with fstream
    //using FileRecord to write into the binary file.
    fstream f;
    FileRecord w(field_names);
    open_fileRW(f, (table_name+".tbl").c_str());
    last_record = w.write(f);

    //Using the number given to us by the write function we will give the field and id.
    //the reason we use multimap for this is because we can have a smaller data file because
    //we don't need to add duplicates.
    for(int i = 0; i < field_names.size(); i++){
        // string field_name = fields[i];
        indices[i][field_names[i]] += last_record;
    }
    f.close();
}

void Table::insert_into(FileRecord r){
    fstream f;
    open_fileRW(f, (table_name+".tbl").c_str());
    last_record = r.write(f);
    for(int i = 0; i < fields.size(); i++){
        string field_name = fields[i];
        indices[i][field_name] += last_record;
    }
    f.close(); //CLOSE YOUR FILE MAN.
}

Table Table::select_all(const vectorstr field_names){
    for(int i = 0; i < field_names.size(); i++){
        if(!field_map.contains(field_names[i])){
            return Table();
        }
    }

    selected_records.clear();

    //creating a table that with the same fields.
    string temp_name = table_name + "_" + to_string(serial_num);
    Table temp(temp_name, field_names);
    
    //reading all the fields;
    fstream f;
    FileRecord r;
    open_fileRW(f, (table_name+".tbl").c_str());
    
    int i = 0;
    long bytes = r.read(f,i);
    vectorstr desired_fields;
    while(bytes > 0){
        selected_records.push_back(i);
        for(int j = 0; j < field_names.size(); j++){
            desired_fields.push_back(r._record[field_map[field_names[j]]]);
        }
        bytes = r.read(f,i);
        i++;
        temp.insert_into(desired_fields);
        desired_fields.clear();
    }

    f.close();
    cout << temp << endl;
    return temp;
}

Table Table::select_all(){
    selected_records.clear();

    //creating a table that with the same fields.
    string temp_name = table_name + "_" + to_string(serial_num);
    Table temp(temp_name, fields);

    //reading all the fields;
    fstream f;
    FileRecord r;
    open_fileRW(f, (table_name+".tbl").c_str());
    int i = 0;
    long bytes = r.read(f,i);
    

    while (bytes>0){
        temp.insert_into(r);
        selected_records.push_back(i);
        i++;
        bytes = r.read(f, i);
    }

    f.close();
    cout << temp << endl;
    return temp;
}

Table Table::select(const vectorstr fields, const vectorlong infix){
    // Making sure all the fields exists.
    for(int i = 0; i < fields.size(); i++){
        // assert(field_map.contains(fields[i]));
        if(!field_map.contains(fields[i])){
            return Table();
        }
    }

    //Initializign table and reading it.
    string temp_name = table_name + "_" + to_string(serial_num);
    Table temp(temp_name, fields);
    fstream f;
    FileRecord r;
    vectorstr desired_fields;
    open_fileRW(f, (table_name+".tbl").c_str());
    for(int i = 0; i < infix.size(); i++){
        int ltoi = infix[i];
        r.read(f, ltoi);
        for(int j = 0; j < fields.size(); j++){
            desired_fields.push_back(string(r._record[field_map[fields[j]]]));
        }
        temp.insert_into(desired_fields);
        desired_fields.clear();
    }

    //closing file
    f. close();

    //returing the initialized table.
    cout << temp << endl;
    return temp;
}

Table Table::select(const vectorstr fields, const vectorstr conditions){
    //pass conditions off to shunting yards and what not...

    //  {"(", "age", "<", "17", "or", "age", ">", "20", ")", "and", "lname", "=", "Jackson"};
    // infix: age < 17 or age > 20 and lname = Jackson
    // postfix: age 17 < age 20 < or lname Jackson = and 
    
    //precedence chart:
    // < > < = >= <=        <-- highest precedence (meaning that it will only sit ontop of and/or)
    //and or                <-- lowest precedence...
    //()                    <-- will always sit on w/e
    ShuntingYard sy(conditions);
    Queue<Token* > postfix = sy.postfix();
    return select(fields, postfix);
}

Table Table::select(const vectorstr fields, Queue<Token *>postfix){

    //Field Value Condition
    const bool debug = false;
    selected_records.clear();

    // checks
    for(int i = 0; i < fields.size();i++){
        // assert(field_map.contains(fields[i]));
        if(!field_map.contains(fields[i])){
            return Table();
        }
    }

    //Token size changes as we pop it.
    Queue<Token *> transfer = postfix; 

    vectorstr Tokenstrings;
    vectorstr Relational;
    vectorstr Logical;

    vector<vectorlong> record_storage;
    vectorlong record_numbers;

    //could've just done a while loop(will fix later)
    for(int i = 0; i < postfix.size(); i++){
        Token* temp = transfer.pop();
        switch(temp->TypeOf()){
            case TOKENSTRING:{
                string a = temp->token_string();
                Tokenstrings.push_back(a);
                if(debug){cout << "TOKENSTRING" << endl;cout << Tokenstrings[0] << endl;}
                break;
            }
            case RELATIONAL:{
                string b = temp->token_string();
                Relational.push_back(b);
                if(debug){cout << "RELATIONAL" << endl;cout << Relational[0] << endl;}
                break;
            }
            case LOGICAL:{
                string c = temp->token_string();
                Logical.push_back(c);
                if(debug){cout << "LOGICAL" << endl;cout << Logical[0] << endl;}
                break;
            }
            default:{
                cout << "EXITING UNDEFINED TOKEN*" << endl;
                exit(0);
                break;
            }
        }
        if(Tokenstrings.size() == 2 && Relational.size() == 1){
            vectorlong temp = grab_records(fields, Tokenstrings[0], Relational[0], Tokenstrings[1]);
            record_storage.push_back(temp);
            Tokenstrings.clear();
            Relational.clear();
        }
        if(Logical.size() == 1){
            //BE WARRY OF SIZE CHANGING AFTER APPEND! COME BACK IF ERRORS
            if(Logical[0] == string("or")){
                if(debug){cout << "or " << endl;}
                int index = record_storage.size()-1;
                if(record_storage.size() > 1){
                    append(record_storage[index-1], record_storage[index]);
                    record_storage.pop_back();
                    filter_duplicates(record_storage[index-1]);
                }
                Logical.clear();
                //cases
                // filter_duplicates(record_storage[])
                //(Or):Append the vector of vector longs and filter duplicates.
                // record_numbers = (record_storage[i-1], record_storage[i]);
                // filter_duplicates(record_numbers);

                //fname = flo or lname = Orozoco
                //file records of 2, 4 ,5 or 1 
                //final = 1,2,4,5;
                
                //lname = gomez or lname = jackson
                //file records of 0, 5 or 4, 6

                //lname = gomez or fname = flo
                //file records of 0, 5 or 2,4,5
                //filter duplicates 
                //final = 0,2,4,5

            }
            else if(Logical[0] == string("and")){
                if(debug){cout << "and" << endl;} 
                int index = record_storage.size()-1;
                if(record_storage.size() > 1){
                    append(record_storage[index-1], record_storage[index]);
                    record_storage.pop_back();
                    grab_duplicates(record_storage[index-1]);
                }
                Logical.clear();
                //cases
                //fname = flo & lname = Orozco
                //file records of 1, 2, 4, 5
                //if no repeats we'll return all the records...

                //fname = flo & lname = Gomez
                //file records of 2, 4, 5 & 5
                //delete repeats = 2, 4, 5
                // find repeats.... the repeat is the value that we want...

                //age >=17 & fname = flo
                //file record of 0, 1, 2, 3, 4, 5 && 2, 4, 5
                //repeats = 2, 4, 5 <-- answer! if we have repeats we return the repeats.
            }
            else{
                cout << "ERORR! Incorrect Logical input!" << endl;
            }
        }
    }
    record_numbers = record_storage[0];
    selected_records = record_numbers;
    return select(fields, record_numbers);
}

Table Table::select(const vectorstr field_names, const string field, const string condition, const string value){
    // Check
    // assert(field_map.contains(field));
    if(!field_map.contains(field)){
        return Table();  
    }
    const bool debug = false;
    selected_records.clear();

    //Variables
    vector<long> record_numbers;
    int comparison = conditions_map[condition];
    long column = field_map[field];                         //<--- Grabs us the field index/column number
    selected_records.clear();

    //Grabing correct record numbers according to the condition
    switch(comparison){
        case 0:{
            if(debug){cout << "case 0(=):" << endl;}
            if(field != "age"){
                record_numbers = indices[column][value];
            }
            else{
                mmap_sl::Iterator walker = indices[column].begin();
                while(walker != indices[column].end()){
                    if(atoi(((*walker).key).c_str()) == atoi((value).c_str())){
                        append(record_numbers, (*walker).value_list);
                    }
                    walker++;
                }
            }
            break;
        }
        case 1:{
            if(debug){cout << "case 1(>): " << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(atoi(((*walker).key).c_str()) > atoi((value).c_str())){
                    append(record_numbers, (*walker).value_list);
                }
                walker++;
            }
            break;
        }
        case 2:{
            if(debug){cout << "case 2(<): " << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(atoi(((*walker).key).c_str()) < atoi((value).c_str())){
                    append(record_numbers, (*walker).value_list);
                }
                walker++;
            }
            break;
        }
        case 3:{
            if(debug){cout << "case 3(<=): " << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(atoi(((*walker).key).c_str()) <= atoi((value).c_str())){
                    append(record_numbers, (*walker).value_list);
                }
                walker++;
            }
            break;
        }
        case 4:{
            if(debug){cout << "case 4(>=)" << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(atoi(((*walker).key).c_str()) >= atoi((value).c_str())){
                    append(record_numbers, (*walker).value_list);
                }
                walker++;
            }
            break;
        }
    }

    // cout <<  "record" << record_numbers << endl;
    selected_records = record_numbers;
    return select(field_names, selected_records);
}

void Table::initialize_conditions(){
    conditions_map["="] += 0;
    conditions_map[">"] += 1;
    conditions_map["<"] += 2;
    conditions_map["<="] += 3;
    conditions_map[">="] += 4;
}

void Table::set_fields(const vector<string>& field_name){
    fields = field_name;
    for(int i = 0; i < fields.size();i++){
        field_map.insert(fields[i], i);
    }
    for(int i = 0; i < fields.size(); i++){
        indices.push_back(mmap_sl());
    }

    const bool debug = false; 
    if(debug){
        cout << "set_fields: map & column #" << endl;
        field_map.print_lookup();
    }
}

vectorstr Table::get_fields(){
    return fields;
}

void Table::reindex(){
    fstream f;
    FileRecord r;
    open_fileRW(f,(table_name+".tbl").c_str());
    long i = 0;
    long bytes = r.read(f,i);
    while( bytes > 0){
        for(long j = 0; j < fields.size(); j++){
            string value = r._record[j];
            indices[j][value] += i;
        }
        i++;
        bytes = r.read(f, i);
    }
    last_record = i-1;
    f.close();
}

vectorlong Table::select_recnos(){
    vectorlong place_holder = selected_records;
    selected_records.clear();
    return place_holder;
}

//Grab file function
vectorlong Table::grab_records(const vectorstr field_name, const string field, const string condition, const string value){
    //Same as the select but returning a vector of long instead of a table
    // Check
    // assert(field_map.contains(field));
    if(!field_map.contains(field)){
        return vectorlong(); 
    }
    const bool debug = false;
    MPair<string, long> check(value, vectorlong());
    
    //Variables
    vector<long> record_numbers;
    int comparison = conditions_map[condition];
    long column = field_map[field];                         //<--- Grabs us the field index/column number

    // cout << "Fields: " << field << endl  << "Relational: " << condition << endl << "value: " << value << endl;// << indices[column] << endl;

    //Grabing correct record numbers according to the condition
    switch(comparison){
        case 0:{
            if(debug){cout << "=" << endl;}
            if(!indices[column].contains(value)){
                return vectorlong();
            }
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(*walker == check){
                    append(record_numbers,((*walker).value_list));
                }
                walker++;
            }
            break;
        }
        case 1:{
            if(debug){cout << ">" << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(*walker > check){
                    append(record_numbers,((*walker).value_list));
                }
                walker++;
            }
            break;
        }
        case 2:{
            if(debug){cout << "<" << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(*walker <  check){
                    append(record_numbers,((*walker).value_list));
                }
                walker++;
            }
            break;
        }
        case 3:{
            if(debug){cout << "<=" << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(*walker <= check){
                    append(record_numbers,((*walker).value_list));
                }
                walker++;
            }
            break;
        }
        case 4:{
            if(debug){cout << ">=" << endl;}
            mmap_sl::Iterator walker = indices[column].begin();
            while(walker != indices[column].end()){
                if(*walker >= check){
                    append(record_numbers,((*walker).value_list));
                }
                walker++;
            }
            break;
        }
    }
    selected_records = record_numbers;
    return record_numbers;
}