#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "QGraphicsView"
#include "const_errors.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

status_codes init_graphics(graphics &a, draw_tools arg);
void set(QGraphicsView *gV, graphics &a);
status_codes init_graphics_tools(Ui::MainWindow* ui, draw_tools *arg);

#endif
