#include <iostream>
#include <iomanip>
#include "includes/binary_files/file_record.h"

using namespace std;

void confuse_me();

void simple_test();

int main(int argc, char *argv[])
{
    cout <<endl<<endl<<endl<< "================================" << endl;
    simple_test();
    cout <<endl<<endl<< ". . . . . . . . . . .. .. . . . ." <<endl<< endl;

    //confuse_me();

    //cout <<endl<<endl<<endl<< "================================" << endl;
    return 0;
}

void simple_test(){

    fstream f;
    //reset the file: use this for new files
    open_fileW(f, "record_list.bin");

    FileRecord r;
    int recno=-1;
    r = FileRecord("Joe Zero");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    r = FileRecord("One Arm Jane");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    r = FileRecord("Two face Harvey");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    r = FileRecord("Three Eyed Raven");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    r = FileRecord("Four Eyes, Four Eyes! ");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    r = FileRecord("Cinco De Mayo, Bryan! ");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    r = FileRecord("The Six Shooter Kid! ");      //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;


    f.close();



    FileRecord r2;
    //open the file for reading and writing.
    open_fileRW(f, "record_list.bin" );
    r2.read(f, 3);       //empty envelop to be filled by the Record object
    cout<<"record 3: "<<r2<<endl;    //insertion operator of the Record object
    r2.read(f, 6);
    cout<<"record 6: "<<r2<<endl;

    //reading passed the end of file:
    long bytes = r2.read(f, 19);
    cout<<"number of bytes read: "<<bytes<<endl;

}

void confuse_me(){
    string list[10] = {"zero",
                       "one",
                       "two",
                       "three",
                       "four",
                       "five",
                       "six",
                       "seven",
                       "eight",
                       "nine"};

    for (int i = 0; i< 10; i++){
        cout<<list[i]<<endl;
    }

    fstream f;
    //reset the file:
    open_fileW(f, "record_list.bin");
    for (int i= 0; i<10; i++){
        FileRecord r(list[i]);      //filling the envelop
        long recno = r.write(f);
        cout<<"["<<list[i] <<"]"<< " was written into file as record: "<<recno<<endl;
    }
    f.close();



    FileRecord r;
    //open the file for reading and writing.
    open_fileRW(f, "record_list.bin" );
    r.read(f, 3);       //empty envelop to be filled by the Record object
    cout<<"record 3: "<<r<<endl;    //insertion operator of the Record object
    r.read(f, 6);
    cout<<"record 6: "<<r<<endl;

    //reading passed the end of file:
    long bytes = r.read(f, 19);
    cout<<"number of bytes read: "<<bytes<<endl;

}

/*
 *
 *     int recno = 0;
    //get_record returns a vector containing all
    //      the rows of the Record object.
    r.read(f, recno); //first record
    while (!f.eof()){
        cout<<"["<<recno<<"]"<<r.get_record()<<endl;
        recno++;

        r.read(f, recno); //read the next record

 *
 *
 */