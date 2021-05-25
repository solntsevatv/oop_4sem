#include "edges.h"
#include "operations.h"

status_codes allocate_edges(edges_arr& edges, int len)
{
    status_codes code = OK;

    edges.n = len;
    edges.arr = (edge*) calloc(len, sizeof(edge));

    if (!edges.arr)
    {
        code = MEMORY_ERR;
        free_edges(edges);
    }

    return code;
}

status_codes free_edges(edges_arr &edges)
{
    status_codes code = OK;

    edges.n = 0;
    free_array(edges.arr);

    return code;
}
