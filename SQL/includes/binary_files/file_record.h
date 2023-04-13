#ifndef FILE_RECORD_H
#define FILE_RECORD_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include "utilities.h"
#include "../stl_utils/vector_utilities.h"

using namespace std;

//HANDLES BINARY FILE
class FileRecord{
public:
    //when you construct a FileRecord, it's either empty or it
    //contains a word
    FileRecord(){
        _record[0][0] = '\0';
        recno = -1;
        //['\0'|  | G | a | r | b | a   |  g  |  e |    ]
    }

    FileRecord(char str[]){
        strncpy(_record[0], str, MAX);
        _record[1][0]='\0';
    }
    
    FileRecord(string s){
        strncpy(_record[0], s.c_str(), MAX);
        _record[0][s.size()+1] ='\0';
    }

    FileRecord(vector<string> twod){
        for(int i = 0; i < twod.size(); i++){
            strncpy(_record[i], twod[i].c_str(), MAX);
        }
        _record[twod.size()+1][0] = '\0';
    }

    long write(fstream& outs);              //returns the record number
    long read(fstream& ins, long recno);    //returns the number of bytes
                                            //      read = MAX, or zero if
                                            //      read passed the end of file


    friend ostream& operator<<(ostream& outs, const FileRecord& r);


// private:
    static const int MAX = 100;
    int recno;
    char _record[MAX+1][MAX+1]; //NULL char
};

#endif

