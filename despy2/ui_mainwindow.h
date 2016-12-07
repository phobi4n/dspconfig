/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile_Open;
    QAction *actionFile_Save;
    QAction *actionFile_Save_As;
    QAction *actionQuit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QSlider *horizontalSlider;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QTreeView *treeView;
    QProgressBar *progressBar;
    QComboBox *comboBox;
    QWidget *tab_2;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox_3;
    QComboBox *comboBox_2;
    QFontComboBox *fontComboBox;
    QDateTimeEdit *dateTimeEdit;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser_2;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QFrame *frame;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QToolButton *toolButton;
    QDialogButtonBox *buttonBox_2;
    QToolButton *toolButton_2;
    QWidget *tab_4;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *horizontalSlider_2;
    QSlider *verticalSlider;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QWidget *tab_5;
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QTreeView *treeView_2;
    QWidget *tab_6;
    QGroupBox *groupBox_3;
    QToolBox *toolBox;
    QWidget *page;
    QPlainTextEdit *plainTextEdit;
    QWidget *page_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QWidget *tab_8;
    QTabWidget *tabWidget_3;
    QWidget *tab_9;
    QWidget *tab_10;
    QFrame *frame_2;
    QLabel *label_4;
    QFrame *frame_3;
    QLabel *label_3;
    QFrame *frame_4;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuDespy;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(655, 675);
        QIcon icon;
        icon.addFile(QStringLiteral(":/content/despy2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionFile_Open = new QAction(MainWindow);
        actionFile_Open->setObjectName(QStringLiteral("actionFile_Open"));
        QIcon icon1;
        QString iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionFile_Open->setIcon(icon1);
        actionFile_Save = new QAction(MainWindow);
        actionFile_Save->setObjectName(QStringLiteral("actionFile_Save"));
        QIcon icon2;
        iconThemeName = QStringLiteral("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionFile_Save->setIcon(icon2);
        actionFile_Save_As = new QAction(MainWindow);
        actionFile_Save_As->setObjectName(QStringLiteral("actionFile_Save_As"));
        QIcon icon3;
        iconThemeName = QStringLiteral("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionFile_Save_As->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        iconThemeName = QStringLiteral("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQuit->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(16, 8, 625, 601));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(8, 56, 377, 478));
        textBrowser->setSource(QUrl(QStringLiteral("qrc:/content/q")));
        textBrowser->setOpenExternalLinks(false);
        textBrowser->setOpenLinks(false);
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(39, 544, 314, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        buttonBox = new QDialogButtonBox(tab);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(392, 200, 185, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(421, 8, 156, 87));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(24, 32, 105, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(24, 53, 113, 16));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(448, 120, 77, 16));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(8, 8, 377, 24));
        treeView = new QTreeView(tab);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(392, 260, 217, 273));
        treeView->setIndentation(6);
        treeView->setAllColumnsShowFocus(true);
        treeView->setWordWrap(true);
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(408, 539, 185, 23));
        progressBar->setValue(24);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(424, 160, 149, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(384, 40, 177, 145));
        label->setWordWrap(true);
        label->setOpenExternalLinks(true);
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(48, 40, 179, 138));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 0, 0, 1, 2);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEditable(true);

        gridLayout->addWidget(comboBox_2, 1, 0, 1, 2);

        fontComboBox = new QFontComboBox(layoutWidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        gridLayout->addWidget(fontComboBox, 2, 0, 1, 2);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 3, 0, 1, 2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 4, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 4, 1, 1, 1);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(45, 240, 521, 321));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 0, 1, 2);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);

        textBrowser_2 = new QTextBrowser(layoutWidget1);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setSource(QUrl(QStringLiteral("qrc:/content/qml3")));

        gridLayout_2->addWidget(textBrowser_2, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(216, 288, 168, 113));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(16, 32, 93, 16));
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(16, 56, 93, 16));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(16, 80, 93, 16));
        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(216, 208, 168, 73));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(16, 16, 128, 16));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(16, 40, 128, 16));
        checkBox_3->setChecked(false);
        checkBox_3->setTristate(true);
        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(217, 112, 193, 54));
        gridLayout_3 = new QGridLayout(layoutWidget2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        toolButton = new QToolButton(layoutWidget2);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout_3->addWidget(toolButton, 0, 1, 1, 1);

        buttonBox_2 = new QDialogButtonBox(layoutWidget2);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox_2->setCenterButtons(true);

        gridLayout_3->addWidget(buttonBox_2, 1, 0, 1, 1);

        toolButton_2 = new QToolButton(layoutWidget2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setAutoRaise(true);
        toolButton_2->setArrowType(Qt::DownArrow);

        gridLayout_3->addWidget(toolButton_2, 1, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        layoutWidget->raise();
        frame->raise();
        groupBox_2->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalScrollBar = new QScrollBar(tab_4);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(72, 504, 465, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(tab_4);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(528, 31, 16, 465));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalSlider_2 = new QSlider(tab_4);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(128, 32, 353, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(tab_4);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(72, 63, 16, 409));
        verticalSlider->setOrientation(Qt::Vertical);
        progressBar_2 = new QProgressBar(tab_4);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(192, 224, 233, 23));
        progressBar_2->setValue(24);
        progressBar_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_2->setInvertedAppearance(false);
        progressBar_3 = new QProgressBar(tab_4);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(192, 264, 233, 23));
        progressBar_3->setValue(24);
        progressBar_3->setInvertedAppearance(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tableWidget = new QTableWidget(tab_5);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem13);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(32, 64, 313, 137));
        listWidget = new QListWidget(tab_5);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(424, 64, 153, 137));
        treeView_2 = new QTreeView(tab_5);
        treeView_2->setObjectName(QStringLiteral("treeView_2"));
        treeView_2->setGeometry(QRect(32, 296, 545, 225));
        treeView_2->setIndentation(6);
        treeView_2->setAllColumnsShowFocus(true);
        treeView_2->setWordWrap(true);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        groupBox_3 = new QGroupBox(tab_6);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(344, 432, 241, 113));
        toolBox = new QToolBox(tab_6);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(24, 32, 241, 169));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 241, 123));
        plainTextEdit = new QPlainTextEdit(page);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(23, 8, 193, 78));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        tabWidget_2 = new QTabWidget(tab_6);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(344, 32, 241, 161));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget_2->addTab(tab_8, QString());
        tabWidget_3 = new QTabWidget(tab_6);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(336, 216, 249, 185));
        tabWidget_3->setTabPosition(QTabWidget::West);
        tabWidget_3->setTabShape(QTabWidget::Triangular);
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        tabWidget_3->addTab(tab_10, QString());
        frame_2 = new QFrame(tab_6);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(40, 256, 217, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(8, 32, 201, 17));
        label_4->setAlignment(Qt::AlignCenter);
        frame_3 = new QFrame(tab_6);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(39, 360, 217, 80));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(14, 32, 185, 17));
        label_3->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(tab_6);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(39, 464, 217, 80));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(14, 32, 185, 16));
        label_2->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 15));
        menuDespy = new QMenu(menuBar);
        menuDespy->setObjectName(QStringLiteral("menuDespy"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuDespy->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuDespy->addAction(actionFile_Open);
        menuDespy->addAction(actionFile_Save);
        menuDespy->addAction(actionFile_Save_As);
        menuDespy->addSeparator();
        menuDespy->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionFile_Open);
        mainToolBar->addAction(actionFile_Save);
        mainToolBar->addAction(actionFile_Save_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), progressBar_3, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), progressBar_2, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), verticalSlider, SLOT(setValue(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Despy", 0));
        actionFile_Open->setText(QApplication::translate("MainWindow", "&File Open", 0));
        actionFile_Save->setText(QApplication::translate("MainWindow", "File &Save", 0));
        actionFile_Save_As->setText(QApplication::translate("MainWindow", "F&ile Save As", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton &1", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "RadioButton &2", 0));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "I am, in fact, a line edit.", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Combo Box", 0)
         << QApplication::translate("MainWindow", "Combo 2", 0)
         << QApplication::translate("MainWindow", "Combo 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Demo", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">This is a label showing <span style=\" color:#ff008e;\">Rich </span><span style=\" color:#00d08e;\">Text</span> which can be <span style=\" font-weight:600; color:#386dc4;\">formatted </span>in <span style=\" font-style:italic;\">various</span> ways. It can include links <a href=\"https://ixquick.com\"><span style=\" text-decoration: underline; color:#2980b9;\">ixquick</span></a> and images <img src=\":/content/abc.png\"/></p></body></html>", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Combo Box", 0)
         << QApplication::translate("MainWindow", "Are you really", 0)
         << QApplication::translate("MainWindow", "reading this?", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Editable Combo", 0)
         << QApplication::translate("MainWindow", "The first line", 0)
         << QApplication::translate("MainWindow", "And another", 0)
        );
        lineEdit_2->setText(QApplication::translate("MainWindow", "Well, it's a moose, sir, he swerves and hits a tree.", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">To begin at the beginning:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">It is spring, moonless night in the small town, starless</span></p>\n"
"<p style=\" margin-top:0px; ma"
                        "rgin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">and bible-black, the cobblestreets silent and the hunched,</span></p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Droid Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Inputs", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", " TriState CheckBox", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Buttons", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Sliders/Scrollers", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "First", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Second", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Third", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Alpha", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Beta", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Gamma", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Classical", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Jazz", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Pop", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Post Punk", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Electronic", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Minimalism", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Zydeco", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Blues", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "alpha", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "beta", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "gamma", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "delta", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "epsilon", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "zeta", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "eta", 0));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "theta", 0));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MainWindow", "iota", 0));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MainWindow", "kappa", 0));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MainWindow", "lambda", 0));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MainWindow", "mu", 0));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MainWindow", "nu", 0));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MainWindow", "xi", 0));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("MainWindow", "omicron", 0));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("MainWindow", "pi", 0));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("MainWindow", "rho", 0));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("MainWindow", "sigma", 0));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("MainWindow", "tau", 0));
        QListWidgetItem *___qlistwidgetitem19 = listWidget->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("MainWindow", "upsilon", 0));
        QListWidgetItem *___qlistwidgetitem20 = listWidget->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("MainWindow", "phi", 0));
        QListWidgetItem *___qlistwidgetitem21 = listWidget->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("MainWindow", "chi", 0));
        QListWidgetItem *___qlistwidgetitem22 = listWidget->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("MainWindow", "psi", 0));
        QListWidgetItem *___qlistwidgetitem23 = listWidget->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("MainWindow", "omega", 0));
        listWidget->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Views", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Page 1", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "Tab 2", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QApplication::translate("MainWindow", "Tab 2", 0));
        label_4->setText(QApplication::translate("MainWindow", "Styled Panel", 0));
        label_3->setText(QApplication::translate("MainWindow", "Sunken", 0));
        label_2->setText(QApplication::translate("MainWindow", "Box", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Containers", 0));
        menuDespy->setTitle(QApplication::translate("MainWindow", "Despy", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "He&lp", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
