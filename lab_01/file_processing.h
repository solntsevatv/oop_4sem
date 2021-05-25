#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H
#include "QGraphicsView"
#include "const_errors.h"
#include "figure.h"

status_codes read_figure_from_file(figure& fig, const char* file_name);
status_codes save_figure_in_file(figure fig, const char* file_name);
status_codes check_edges(edges_arr edges, int points_amount);

#endif
