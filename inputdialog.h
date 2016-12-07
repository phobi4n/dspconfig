#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    QString getUserInput();
    ~InputDialog();
    void setData(const QString &labelText);
    void setTitle(const QString &titleText);

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
