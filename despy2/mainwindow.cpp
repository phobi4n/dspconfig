#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populate()
{
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::homePath());
    QModelIndex index = model->index(QDir::homePath());
    ui->treeView->setModel(model);
    ui->treeView->expand(index);
    ui->treeView->scrollTo(index);
    ui->treeView->setCurrentIndex(index);
    ui->treeView->setColumnWidth(0, 128);
    ui->treeView->hideColumn(1);
    ui->horizontalSlider->setValue(36);
    ui->horizontalSlider_2->setValue(36);
    ui->treeView_2->setModel(model);
    ui->treeView_2->expand(index);
    ui->treeView_2->scrollTo(index);
    ui->treeView_2->setCurrentIndex(index);
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionFile_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::homePath(), tr("All Files (*)"));
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog about;
    about.exec();
}
