#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

//Binary file
bool file_exists(const char filename[]);
void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);

//text file
void write_info(const char filename[], vector<string> info);
void read_info(const char filename [], vector<string>& info);

#endif