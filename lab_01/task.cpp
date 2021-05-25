#include "task.h"
#include "figure.h"
#include "file_processing.h"
#include <QObject>

status_codes perform_task(request request)
{
    status_codes code = OK;
    static figure fig = init();

    switch (request.state)
    {
        case INIT:
            break;
        case LOAD_FILE:
            code = load_figure(fig, request.filename);
            break;
        case SAVE_FILE:
            code = save_figure(fig, request.filename);
            break;
        case DRAW:
            code = draw_figure(fig, request.draw);
            break;
        case SCALE:
            code = scale_figure(fig, request.scale);
            break;
        case TURN:
            code = turn_figure(fig, request.turn);
            break;
        case MOVE:
            code = move_figure(fig, request.move);
            break;
        case QUIT:
            free_figure(fig);
            break;
        default:
            code = UNKNOWN_COMMAND;
    }

    return code;
}
