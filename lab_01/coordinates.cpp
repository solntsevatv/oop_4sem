#include "coordinates.h"
#include "operations.h"

status_codes allocate_coordinates(coordinates_arr& points, int len)
{
    status_codes code = OK;

    points.n = len;
    points.arr = (point *) calloc(len, sizeof(point));

    if (!points.arr)
    {
        code = MEMORY_ERR;
        free_coordinates(points);
    }

    return code;
}

status_codes free_coordinates(coordinates_arr &points)
{
    status_codes code = OK;

    points.n = 0;
    free_array(points.arr);

    return code;
}
