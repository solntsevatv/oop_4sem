#ifndef COORDINATES_H
#define COORDINATES_H

#include "const_errors.h"
#include <iostream>

struct point
{
    double x;
    double y;
    double z;
};

struct coordinates_arr
{
    int n;
    point *arr;
};

status_codes allocate_coordinates(coordinates_arr& points, int len);
status_codes free_coordinates(coordinates_arr &points);


#endif
