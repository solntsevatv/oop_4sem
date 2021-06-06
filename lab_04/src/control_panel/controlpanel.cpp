#include "controlpanel.h"

#include <iostream>

#include "qdebug.h"

ControlPanel::ControlPanel(QObject *parent) : QObject(parent),
                                              cur_floor(1),
                                              cur_target(-1),
                                              is_target(NUM_FLOORS, false),
                                              current_state(FREE),
                                              cur_direction(STAY) {}

void ControlPanel::set_new_target(int floor) {
    current_state = BUSY;
    is_target[floor - 1] = true;

    if (cur_target == -1) {
        cur_target = floor;
    }

    if ((cur_direction == UP && floor > cur_target) || (cur_direction == DOWN && floor < cur_target)) {
        cur_target = floor;
    }

    next_target(floor);
    cur_direction = (cur_floor > cur_target) ? DOWN : UP;
    emit set_target(floor, cur_direction);

}

void ControlPanel::achieved_floor(int floor) {
    if (current_state == BUSY) {
        cur_floor = floor;
        is_target[floor - 1] = false;
        if (cur_floor == cur_target) {
            cur_target = -1;
            find_new_target();
        }

        if (next_target(floor)) {
            cur_direction = (cur_floor > cur_target) ? DOWN : UP;

            emit set_target(floor, cur_direction);
        } else {
            current_state = FREE;
        }
    }
}

void ControlPanel::passed_floor(int floor) {
    cur_floor = floor;
    qDebug() << "Moving... floor:" << floor;
}

void ControlPanel::find_new_target() {
    int state = false;
    if (cur_direction == UP && !state) 
    {
        for (int i = NUM_FLOORS; i >= 1; i--) 
        {
            if (is_target[i - 1] == true) {
                state = true;
                cur_target = i;
            }
        }
    } 
    else 
    {
        for (int i = 1; i <= NUM_FLOORS && !state; i++) 
        {
            if (is_target[i - 1]) {
                state = true;
                cur_target = i;
            }
        }
    }
}

bool ControlPanel::next_target(int &floor) {
    bool state = false;
    if (cur_target > cur_floor) {
        for (int i = cur_floor; i <= NUM_FLOORS && !state; i += 1) {
            if (is_target[i - 1]) {
                floor = i;
                state = true;
            }
        }
    } else {
        for (int i = cur_floor; i >= 1 && !state; i -= 1) {
            if (is_target[i - 1]) {
                floor = i;
                state = true;
            }
        }
    }
    return state;
}