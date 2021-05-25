#include "file_processing.h"

status_codes read_amount(FILE* f, int* n)
{
    status_codes code = OK;

    if (fscanf(f, "%d", n) != 1)
        code = FILE_READ_AMOUNT_ERR;
    else if (*n <= 0)
        code = FILE_INCORRECT_AMOUNT;

    return code;
}

status_codes read_point(point& pt, FILE *f)
{
    status_codes code = OK;

    if (fscanf(f, "%lf%lf%lf", &pt.x, &pt.y, &pt.z) != 3)
        code = FILE_READ_POINT_ERR;

    return code;
}

status_codes read_points(point* pts_arr, int len, FILE *f)
{
    status_codes code = OK;

    for (int i = 0; i < len && code == OK; i++)
        code = read_point(pts_arr[i], f);

    return code;
}

status_codes check_edge_indexes(edge edge, int points_amount)
{
    status_codes code = OK;

    if (edge.point_ind1 < 0 || edge.point_ind1 >= points_amount)
        code = FILE_READ_EDGE_ERR;
    else if (edge.point_ind2 < 0 || edge.point_ind2 >= points_amount)
        code = FILE_READ_EDGE_ERR;

    return code;
}

status_codes check_edges(edges_arr edges, int points_amount)
{
    status_codes code = OK;

    for (int i = 0; i < edges.n && code == OK; i++)
    {
        code = check_edge_indexes(edges.arr[i], points_amount);
    }

    return code;
}

status_codes read_edge(edge *edge, FILE *f)
{
    status_codes code = OK;

    if (fscanf(f, "%d%d", &edge->point_ind1, &edge->point_ind2) != 2)
        code = FILE_READ_EDGE_ERR;

    return code;
}

status_codes read_edges(edges_arr &edges, FILE *f)
{
    status_codes code = OK;

    for (int i = 0; i < edges.n && code == OK; i++)
    {
        code = read_edge(&edges.arr[i], f);
    }

    return code;
}

status_codes process_points(coordinates_arr &coords, FILE *f)
{
    status_codes code = read_amount(f, &coords.n);

    if (code == OK)
    {
        code = allocate_coordinates(coords, coords.n);
        if (code == OK)
        {
            code = read_points(coords.arr, coords.n, f);
            if (code != OK)
                free_coordinates(coords);
        }
    }

    return code;
}

status_codes process_edges(edges_arr &edges, FILE *f)
{
    status_codes code = read_amount(f, &edges.n);

    if (code == OK)
    {
        code = allocate_edges(edges, edges.n);
        if (code == OK)
        {
            code = read_edges(edges, f);
            if (code != OK)
                free_edges(edges);
        }
    }

    return code;
}

status_codes read_center(point &center, FILE *f)
{
    status_codes code = read_point(center, f);

    return code;
}

status_codes check_file(const char *file_name)
{
    status_codes code = OK;

    if (file_name == NULL)
        code = FILE_NOT_FOUND;
    else
    {
        FILE *f = fopen(file_name, "r");
        if (f != nullptr)
            fclose(f);
        else
            code = FILE_READ_ERR;
    }

    return code;
}

status_codes read_figure_from_file(figure& fig, const char* file_name)
{
    status_codes code = check_file(file_name);
    if (code != OK)
        return code;

    FILE *f = fopen(file_name, "r");

    read_center(fig.center, f);
    if (code == OK)
    {
        code = process_points(fig.points, f);

        if (code == OK)
        {
            code = process_edges(fig.edges, f);

            if (code != OK)
                free_coordinates(fig.points);
        }
    }

    return code;
}

status_codes write_point(point point, FILE *f)
{
    status_codes code = OK;

    fprintf(f, "%lf %lf %lf\n", point.x, point.y, point.z);

    return code;
}

status_codes write_points(point center, coordinates_arr points, FILE *f)
{
    status_codes code = OK;

    write_point(center, f);

    fprintf(f, "%d\n", points.n);

    for (int i = 0; code == OK && i < points.n; i++)
        write_point(points.arr[i], f);

    return code;
}

status_codes write_edge(edge edge, FILE *f)
{
    status_codes code = OK;

    fprintf(f, "%d %d\n", edge.point_ind1, edge.point_ind2);

    return code;
}

status_codes write_edges(edges_arr edges, FILE *f)
{
    status_codes code = OK;

    fprintf(f, "%d\n", edges.n);

    for (int i = 0; i < edges.n; i++)
        write_edge(edges.arr[i], f);


    return code;
}

status_codes save_figure_in_file(figure fig, const char* file_name)
{
    status_codes code = OK;

    FILE *f = fopen(file_name, "w");

    write_points(fig.center, fig.points, f);
    write_edges(fig.edges, f);

    fclose(f);

    return code;
}
