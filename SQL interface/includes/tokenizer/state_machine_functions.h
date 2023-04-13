#ifndef STATE_MACHINE_FUNCTIONS_H
#define STATE_MACHINE_FUNCTIONS_H


#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <cstring>
#include <string.h>

#include "constants.h"

void init_table(int _table[][MAX_COLUMNS]);
void mark_success(int _table[][MAX_COLUMNS], int row);
void mark_fail(int _table[][MAX_COLUMNS], int row);
bool is_success(int _table[][MAX_COLUMNS], int row);
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state);
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state);
void mark_cell(int row, int table[][MAX_COLUMNS], int column, int state);

#endif