#include "state_machine_functions.h"

void init_table(int _table[][MAX_COLUMNS]){
    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLUMNS; j++){
            if(j == 0){
                _table[i][j] = 0;
            }
            else{
                _table[i][j] = -1;
            }
        }
    }
}

void mark_success(int _table[][MAX_COLUMNS], int row){
    _table[row][0] = 1;
}
void mark_fail(int _table[][MAX_COLUMNS], int row){
    _table[row][0] = -1;
}
bool is_success(int _table[][MAX_COLUMNS], int row){
    return _table[row][0] == 1;
}
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state){
    for(int i = from; i <= to; i++){
        _table[row][i] = state;
    }
}
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state){
    for(int i = 0; i < strlen(columns); i++){
        _table[row][columns[i]] = state;
    }
}
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state){
    _table[row][column] = state;
}
