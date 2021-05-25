#include "operations.h"
#include <math.h>


status_codes sub_coords_center(point &point, struct point center)
{
    status_codes code = OK;

    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;

    return code;
}

status_codes add_coords_center(point &point, struct point center)
{
    status_codes code = OK;

    point.x += center.x;
    point.y += center.y;
    point.z += center.z;

    return code;
}

void move_point(point &point, move_k coeffs)
{
    point.x += coeffs.dx;
    point.y += coeffs.dy;
    point.z += coeffs.dz;
}

status_codes move_points(coordinates_arr &pts, point center, move_k coeffs)
{
    status_codes code = OK;

    if (code == OK)
        move_point(center, coeffs);

    for (int i = 0; code == OK && i < pts.n; i++)
        move_point(pts.arr[i], coeffs);

    return code;
}

void scale_point(point &point, scale_k coeffs)
{
    point.x = point.x * coeffs.kx;
    point.y = point.y * coeffs.ky;
    point.z = point.z * coeffs.kz;
}

status_codes scale_points(coordinates_arr& pts, point center, scale_k coeffs)
{
    status_codes code = OK;

    for(int i = 0; code == OK && i < pts.n; i++)
    {
        sub_coords_center(pts.arr[i], center);
        scale_point(pts.arr[i], coeffs);
        add_coords_center(pts.arr[i], center);
    }

    return code;
}

double d_cos(double angle)
{
    return cos(angle * M_PI / 180);
}

double d_sin(double angle)
{
    return sin(angle * M_PI / 180);
}

void x_turn_point(point &point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double y_src = point.y;
    point.y = y_src * cos_ang + point.z * sin_ang;
    point.z = -y_src * sin_ang + point.z * cos_ang;
}

void y_turn_point(point &point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double x_src = point.x;
    point.x = x_src * cos_ang + point.z * sin_ang;
    point.z = -x_src * sin_ang + point.z * cos_ang;
}

void z_turn_point(point &point, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    double x_src = point.x;
    point.x = x_src * cos_ang + point.y * sin_ang;
    point.y = -x_src * sin_ang + point.y * cos_ang;
}

status_codes turn_point(point &point, turn_k coeffs)
{
    status_codes code = OK;

    x_turn_point(point, coeffs.rx);
    y_turn_point(point, coeffs.ry);
    z_turn_point(point, coeffs.rz);

    return code;
}

status_codes turn_points(coordinates_arr& pts, point center, turn_k coeffs)
{
    status_codes code = OK;

    for (int i = 0; code == OK && i < pts.n; i++)
    {
        sub_coords_center(pts.arr[i], center);
        turn_point(pts.arr[i], coeffs);
        add_coords_center(pts.arr[i], center);
    }

    return code;
}

status_codes free_array(void *arr)
{
    status_codes code = OK;

    if (arr)
        free(arr);

    return code;
}
