#ifndef EDGES_H
#define EDGES_H

#include "const_errors.h"

struct edge
{
    int point_ind1;
    int point_ind2;
};

struct edges_arr
{
    int n;
    edge *arr;
};

status_codes allocate_edges(edges_arr& edges, int len);
status_codes free_edges(edges_arr &edges);

#endif
