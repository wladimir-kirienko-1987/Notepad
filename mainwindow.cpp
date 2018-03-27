#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_action_create_triggered();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_info_triggered()
{
    QMessageBox::information(this,"О программе","Блокнот v 1.00");
}

void MainWindow::on_action_create_triggered()
{
    this->setWindowTitle("Безымянный.txt");

    QFile mFile(".//Безымянный.txt");

    FileName = ".//Безымянный.txt";

    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        //QMessageBox::critical(this, "Ошибка", "Ошибка создания файла!");
        return;
    }

    mFile.close();
}

void MainWindow::on_action_open_triggered()
{
    FileName = QFileDialog::getOpenFileName(this,
        tr("Открыть файл..."), FileName , tr("Text files (*.txt)"));

    if (!FileName.isEmpty())
           this->setWindowTitle(FileName);

    QFile mFile(FileName);

    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        //QMessageBox::critical(this, "Ошибка", "Не правильный путь!");
        return;
    }

    QTextStream stream(&mFile);

    QString buffer = stream.readAll();

    ui->textEdit->setText(buffer);


    mFile.close();
}

void MainWindow::on_action_save_triggered()
{
    QFile mFile(FileName);

    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        //QMessageBox::critical(this, "Ошибка", "Не правильный путь!");
        return;
    }

    QTextStream stream(&mFile);

    stream << ui->textEdit->toPlainText();

    mFile.close();
}

void MainWindow::on_action_save_as_triggered()
{
    FileName = QFileDialog::getSaveFileName(this,
        tr("Сохранить файл..."), FileName , tr("Text files (*.txt)"));

    if (!FileName.isEmpty())
        this->setWindowTitle(FileName);

    QFile mFile(FileName);

    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        //QMessageBox::critical(this, "Ошибка", "Не правильный путь!");
        return;
    }

    QTextStream stream(&mFile);

    stream << ui->textEdit->toPlainText();

    mFile.close();
}
