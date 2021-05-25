#ifndef CONST_ERRORS_H
#define CONST_ERRORS_H

enum status_codes
{
    OK,
    UNKNOWN_COMMAND,
    EMPTY_POINTS_ARR,
    FILE_NOT_FOUND,
    FILE_READ_ERR,
    FILE_INCORRECT_AMOUNT,
    FILE_READ_AMOUNT_ERR,
    FILE_READ_POINT_ERR,
    FILE_READ_EDGE_ERR,
    FILE_WRITE_ERROR,
    MEMORY_ERR,
    CREATE_SCENEE_ERR,
};

enum status_request
{
    INIT,
    LOAD_FILE,
    SAVE_FILE,
    DRAW,
    SCALE,
    TURN,
    MOVE,
    QUIT
};

#endif
