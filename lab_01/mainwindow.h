#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsView"

#include "const_errors.h"
#include "operations.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_action_save_file_triggered();
    void on_action_open_file_triggered();
    void on_but_scale_clicked();
    void on_but_turn_clicked();
    void on_but_move_clicked();

private:
    Ui::MainWindow *ui;
};

typedef struct
{
    QGraphicsView *gV;
    int w;
    int h;
} draw_tools;

struct request
{
    status_request state;
    union
    {
        const char* filename;
        draw_tools draw;
        struct scale_k scale;
        struct turn_k turn;
        struct move_k move;
    };
};

status_codes show_new_figure(request req, Ui::MainWindow* ui);

#endif
