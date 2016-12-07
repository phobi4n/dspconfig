#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setData(const QString &labelText);
    void setTitle(const QString &titleText);

private slots:

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
