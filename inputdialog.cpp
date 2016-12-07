#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

QString InputDialog::getUserInput()
{
    return ui->lineUserInput->text();
}

void InputDialog::setData(const QString &labelText)
{
    ui->label->setText(labelText);
}

void InputDialog::setTitle(const QString &titleText)
{
    this->setWindowTitle(titleText);
}
