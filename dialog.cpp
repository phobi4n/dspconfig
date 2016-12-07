#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setData(const QString &labelText)
{
    ui->label->setText(labelText);
}

void Dialog::setTitle(const QString &titleText)
{
    this->setWindowTitle(titleText);
}
