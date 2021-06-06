#include "cabin.h"

#include <QString>

#include "qdebug.h"

Cabin::Cabin(QObject *parent) : QObject(parent),
                                current_floor(1),
                                target(-1),
                                current_state(WAIT),
                                current_direction(STAY) {
    crossing_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabin_called()), this, SLOT(cabin_move()));
    QObject::connect(this, SIGNAL(cabin_reached_target(int)), this, SLOT(cabin_stop()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
    QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_wait()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));
}

void Cabin::cabin_move() {
    if (current_state == START) 
    {
        current_state = MOVE;
        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    } 
    else if (current_state == MOVE) 
    {
        current_state = MOVE;

        current_floor += current_direction;

        if (current_floor == target) {
            emit cabin_reached_target(current_floor);
        } else {
            emit cabin_crossing_floor(current_floor, current_direction);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}

void Cabin::cabin_stop() {
    if (current_state == MOVE) {
        current_state = STOP;
        qDebug() << "Stopped at floor " << QString::number(current_floor) << ".";
        emit cabin_stopped(current_floor);
    }
}

void Cabin::cabin_wait() {
    if (current_state == STOP) {
        current_state = WAIT;
        qDebug() << "Cabin waiting";
        emit cabin_waited(current_floor);
    }
}

void Cabin::cabin_call(int floor, direction dir) {
    if (current_state == WAIT || current_state == MOVE) 
    {
        current_state = START;
        target = floor;
        current_direction = dir;

        emit cabin_called();
    }
}
