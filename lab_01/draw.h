#ifndef DRAW_H
#define DRAW_H
#include "const_errors.h"
#include "coordinates.h"
#include "edges.h"
#include "graphics.h"
#include "ui_mainwindow.h"

struct point_2d
{
    int x;
    int y;
};

status_codes draw_edges(coordinates_arr pts, edges_arr edges, draw_tools arg, graphics a);

#endif
