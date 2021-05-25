#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "const_errors.h"
#include "coordinates.h"

struct scale_k
{
    double kx;
    double ky;
    double kz;
};

struct turn_k
{
    int rx;
    int ry;
    int rz;
};

struct move_k
{
    int dx;
    int dy;
    int dz;
};

status_codes scale_points(coordinates_arr &pts, point center, scale_k coeffs);
status_codes turn_points(coordinates_arr &pts, point center, turn_k coeffs);
status_codes move_points(coordinates_arr &pts, point center, move_k coeffs);
status_codes free_array(void *arr);

#endif
