#include "utilities.h"
#include "file_record.h"

bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,
        std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;
    ff.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]) throw(char*){
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (!file_exists(filename)){
        //create the file
        f.open(filename, std::fstream::out|std::fstream::binary);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename,
            std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}

void open_fileW(fstream& f, const char filename[]){
    f.open (filename,
            std::fstream::out| std::fstream::binary);
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }
}

// TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE 
void write_info(const char filename[], vector<string> info){
    ofstream f(filename);
    if(f.is_open()){
        // cout << "open" << endl;
        for(int i = 0; i < info.size(); i++){
            f << info[i] << endl;
        }
    }
    else{
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }
    // cout << "closed" << endl;
    f.close();
}

void read_info(const char filename [], vector<string>& info){
    ifstream f(filename);
  
    string output;
    if(f.is_open()){
        while(getline(f, output)){
            info.push_back(output);
        }
    }
    f.close();
}

// TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE TEXT FILE 