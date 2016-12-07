/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(338, 132);
        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(32, 16, 97, 89));
        label->setPixmap(QPixmap(QString::fromUtf8(":/content/dspconfig.png")));
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(112, 24, 185, 65));
        label_2->setWordWrap(true);
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(224, 96, 77, 24));

        retranslateUi(AboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AboutDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Despy 2</span> - A theme previewer for DSP Manager.</p></body></html>", 0));
        pushButton->setText(QApplication::translate("AboutDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
