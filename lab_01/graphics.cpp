#include "graphics.h"

status_codes init_graphics(graphics &a, draw_tools arg)
{
    status_codes code = OK;

    a.scene = new QGraphicsScene(arg.gV);
    if (!a.scene)
        code = CREATE_SCENEE_ERR;
    else
    {
        a.pen = QPen(Qt::black);
        a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.w, arg.h)));
        set(arg.gV, a);
    }

    return code;
}

void set(QGraphicsView *gV, graphics &a)
{
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(a.scene);
}

status_codes init_graphics_tools(Ui::MainWindow* ui, draw_tools *arg)
{
    status_codes code = OK;

    arg->gV = ui->graphicsView;
    arg->h = ui->graphicsView->height();
    arg->w = ui->graphicsView->width();

    return code;
}
