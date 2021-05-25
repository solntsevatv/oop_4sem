#ifndef FIGURE_H
#define FIGURE_H

#include "const_errors.h"
#include "coordinates.h"
#include "edges.h"
#include "draw.h"
#include "operations.h"

struct figure
{
    coordinates_arr points;
    edges_arr edges;
    point center;
};

figure& init();
status_codes load_figure(figure& fig, const char* file_name);
status_codes save_figure(figure fig, const char* file_name);
status_codes free_figure(figure& fig);
status_codes draw_figure(figure& fig, draw_tools arg);
status_codes scale_figure(figure& fig, scale_k coeffs);
status_codes turn_figure(figure& fig, turn_k coeffs);
status_codes move_figure(figure& fig, move_k coeffs);

#endif
