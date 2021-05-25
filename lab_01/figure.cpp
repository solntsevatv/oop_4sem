#include "figure.h"
#include "file_processing.h"
#include "graphics.h"
#include <cstdlib>
#include <iostream>

figure& init()
{
    static figure fig;

    fig.points.n = 0;
    fig.points.arr = NULL;

    fig.edges.n = 0;
    fig.edges.arr = NULL;

    fig.center.x = 0;
    fig.center.y = 0;
    fig.center.z = 0;

    return fig;
}

status_codes check_figure(figure fig)
{
    status_codes code = OK;

    coordinates_arr points = fig.points;
    code = check_edges(fig.edges, points.n);

    return code;
}

status_codes load_figure(figure& fig, const char* file_name)
{
    status_codes code = OK;
    figure curr_figure;

    curr_figure = init();
    code = read_figure_from_file(curr_figure, file_name);
    if (code == OK)
        code = check_figure(curr_figure);

    if (code != OK)
    {
        free_edges(curr_figure.edges);
        free_coordinates(curr_figure.points);
    }

    if (code == OK)
    {
        free_figure(fig);
        fig = curr_figure;
    }

    return code;
}

status_codes save_figure(figure fig, const char* file_name)
{
    status_codes code = OK;

    code = save_figure_in_file(fig, file_name);

    return code;
}

status_codes free_figure(figure& fig)
{
    status_codes code = OK;

    fig.points.n = 0;
    free_coordinates(fig.points);

    fig.edges.n = 0;
    free_edges(fig.edges);

    return code;
}

status_codes draw_figure(figure& fig, draw_tools arg)
{
    status_codes code = OK;

    graphics a;
    code = init_graphics(a, arg);

    if (code == OK)
    {
        draw_edges(fig.points, fig.edges, arg, a);
    }

    return code;
}

status_codes scale_figure(figure& fig, scale_k coeffs)
{
    return scale_points(fig.points, fig.center, coeffs);
}

status_codes turn_figure(figure& fig, turn_k coeffs)
{
    return turn_points(fig.points, fig.center, coeffs);
}

status_codes move_figure(figure& fig, move_k coeffs)
{
    return move_points(fig.points, fig.center, coeffs);
}


