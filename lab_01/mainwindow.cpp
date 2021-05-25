#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include "error_output.h"
#include "graphics.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    request request;
    request.state = INIT;
    perform_task(request);
}

MainWindow::~MainWindow()
{
    request request;
    request.state = QUIT;
    perform_task(request);

    delete ui;
}

status_codes show_new_figure(request req, Ui::MainWindow* ui)
{
    status_codes code = perform_task(req);

    if (code == OK)
    {
        req.state = DRAW;

        draw_tools draw;
        init_graphics_tools(ui, &draw);
        req.draw = draw;

        code = perform_task(req);
    }

    if (code != OK)
        output_error(code);

    return code;
}

void MainWindow::on_action_save_file_triggered()
{
    request request;
    request.state = SAVE_FILE;

    show_new_figure(request, ui);
}

void MainWindow::on_action_open_file_triggered()
{
    request request;
    char* new_file;

    QString file_name = QFileDialog::getOpenFileName(0, "Выбрать файл для загрузки фигуры", "", "*.txt");

    if (!file_name.isEmpty() && !file_name.isNull())
    {
        QByteArray file_name_arr = file_name.toLocal8Bit();
        new_file = file_name_arr.data();
        request.filename = new_file;

        request.state = LOAD_FILE;

        show_new_figure(request, ui);
    }
}


void MainWindow::on_but_scale_clicked()
{
    request req;
    req.state = SCALE;

    req.scale.kx = ui->lineEdit_kx->text().toFloat();
    req.scale.ky = ui->lineEdit_ky->text().toFloat();
    req.scale.kz = ui->lineEdit_kz->text().toFloat();

    show_new_figure(req, ui);
}

void MainWindow::on_but_turn_clicked()
{
    request req;
    req.state = TURN;

    req.turn.rx = ui->lineEdit_rx->text().toFloat();
    req.turn.ry = ui->lineEdit_ry->text().toFloat();
    req.turn.rz = ui->lineEdit_rz->text().toFloat();

    show_new_figure(req, ui);
}


void MainWindow::on_but_move_clicked()
{
    request req;
    req.state = MOVE;

    req.move.dx = ui->lineEdit_dx->text().toInt();
    req.move.dy = ui->lineEdit_dy->text().toInt();
    req.move.dz = ui->lineEdit_dz->text().toInt();

    show_new_figure(req, ui);
}
