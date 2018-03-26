#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_exit_triggered();

    void on_action_info_triggered();

    void on_action_create_triggered();

    void on_action_open_triggered();

    void on_action_save_triggered();

    void on_action_save_as_triggered();

private:
    Ui::MainWindow *ui;

    QString FileName;
};

#endif // MAINWINDOW_H
