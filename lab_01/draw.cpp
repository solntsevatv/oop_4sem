#include "draw.h"
#include "task.h"

point_2d get_dot(point* pts, int ind)
{
    point_2d dot = {(int) pts[ind].x, (int) pts[ind].y};
    return dot;
}

status_codes get_dots(point_2d &p1, point_2d &p2, point* pts, edge pts_indexes)
{
    status_codes code = OK;

    p1 = get_dot(pts, pts_indexes.point_ind1);
    p2 = get_dot(pts, pts_indexes.point_ind2);

    return code;
}

point_2d point_transform(point_2d src_point, draw_tools arg)
{
    point_2d new_point;

    new_point.x = src_point.x + arg.w / 2;
    new_point.y = src_point.y + arg.h / 2;

    return new_point;
}

status_codes draw_line(point_2d p1, point_2d p2, graphics a, draw_tools arg)
{
    status_codes code = OK;

    p1 = point_transform(p1, arg);
    p2 = point_transform(p2, arg);

    a.scene->addLine(p1.x, p1.y, p2.x, p2.y, a.pen);

    return code;
}

status_codes draw_edges(coordinates_arr coords, edges_arr edges, draw_tools arg, graphics a)
{
    status_codes code = OK;

    for (int i = 0; i < edges.n; i++)
    {
        point_2d p1, p2;
        get_dots(p1, p2, coords.arr, edges.arr[i]);
        draw_line(p1, p2, a, arg);
    }

    return code;
}
