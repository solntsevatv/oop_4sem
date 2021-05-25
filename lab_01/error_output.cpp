#include "error_output.h"
#include "QMessageBox"

status_codes output_error(status_codes code)
{
    if (code == FILE_NOT_FOUND)
    {
        QMessageBox::critical(NULL, "ERROR", "File is broken, or doesn't exist");
    }
    else if (code == FILE_READ_AMOUNT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Can't read amount from file");
    }
    else if (code == FILE_READ_POINT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Can't read point from file");
    }
    else if (code == FILE_READ_EDGE_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Can't read edge from file");
    }
    else if (code == FILE_INCORRECT_AMOUNT)
    {
        QMessageBox::critical(NULL, "ERROR", "Amount is incorrect. (Should be >0)");
    }
    else if (code == FILE_WRITE_ERROR)
    {
        QMessageBox::critical(NULL, "ERROR", "Can't write to file.");
    }
    else if (code == EMPTY_POINTS_ARR)
    {
        QMessageBox::critical(NULL, "ERROR", "Points array is empty.");
    }
    else if (code == MEMORY_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Something wrong with working with memory.");
    }
    else if (code == CREATE_SCENEE_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Can't create scene.");
    }
    else if (code == UNKNOWN_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
    }
    else
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown error");
    }

    return code;
}
