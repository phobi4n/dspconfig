#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dsp/settings.h"
#include "thememanager.h"
#include "dialog.h"
#include "inputdialog.h"
#include <QProcess>
#include <QShortcut>
#include <QDebug>
#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QList>
#include <QPair>
#include <QStringListModel>
#include <QListView>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QShortcut *menuhide_shortcut = new QShortcut(QKeySequence("Ctrl+m"),this);
    QObject::connect(menuhide_shortcut, SIGNAL(activated()), this, SLOT(on_actionHide_menubar_triggered()));
    populate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
    qApp->quit();
}

void MainWindow::on_actionSave_triggered()
{
    write_config("");
}

void MainWindow::write_config(QString name)
{
    if (!name.isEmpty()) {
        DSP::Settings::setFileName(name);
    }


    // Page 1 General
    DSP::Settings::writeVal(DSP::Settings::Opacity, ui->sliderOpacity->value());
    DSP::Settings::writeVal(DSP::Settings::Blacklist, ui->plainBlacklist->toPlainText());
    DSP::Settings::writeVal(DSP::Settings::Titlepos, ui->comboTitleposition->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Hackdialogs, ui->checkHackdialog->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Compactmenu, ui->checkCompactmenu->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Splitterext, ui->checkSplitterextender->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Arrowsize, ui->spinMaximumarrow->value());
    DSP::Settings::writeVal(DSP::Settings::Simplearrows, ui->checkSimplearrows->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Balloontips, ui->checkBalloontips->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Animatestack, ui->checkAnimatestack->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Animatescroll, ui->checkAnimateScrolling->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Lockdocks, ui->checkLockdocks->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Differentinactive, ui->checkDifferentInactive->isChecked());

    // Page 2 Shadows
    DSP::Settings::writeVal(DSP::Settings::Shadowopacity, ui->horizontalShadows->value());
    DSP::Settings::writeVal(DSP::Settings::Shadowillumination, ui->horizontalIllumination->value());
    DSP::Settings::writeVal(DSP::Settings::Shadowontextopacity, ui->horizontalTextshadow->value());
    DSP::Settings::writeVal(DSP::Settings::Shadowdarkraised, ui->checkDarkraise->isChecked());

    // Page 3 Titlebar
    DSP::Settings::writeVal(DSP::Settings::Removetitle, ui->groupBox_Removetitlebar->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Titlepos, ui->comboTitleposition->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Decomincolor, stringMincolor);
    DSP::Settings::writeVal(DSP::Settings::Decomaxcolor, stringMaxcolor);
    DSP::Settings::writeVal(DSP::Settings::Decoclosecolor, stringClosecolor);
    DSP::Settings::writeVal(DSP::Settings::Decoshadowsize, ui->spinShadowsize->value());
    DSP::Settings::writeVal(DSP::Settings::Decoframe, ui->spinFramesize->value());
    DSP::Settings::writeVal(DSP::Settings::Decobuttons, ui->comboDecobuttons->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Decoicon, ui->checkDecoicon->isChecked());

    // Page 4 UNO
    DSP::Settings::writeVal(DSP::Settings::Unoenabled, ui->groupUnoenable->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Unonoise, ui->spinUnonoisestrength->value());
    DSP::Settings::writeVal(DSP::Settings::Unonoisestyle, ui->comboUnonoisestyle->currentIndex() - 1);
    DSP::Settings::writeVal(DSP::Settings::Unohor, ui->checkUnogradhoriz->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Unocont, ui->groupUnocontent->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Unoopacity, ui->spinUnocontopacity->value());
    DSP::Settings::writeVal(DSP::Settings::Unocontblur, ui->spinUnocontblur->value());
    DSP::Settings::writeVal(DSP::Settings::Unograd, build_gradient_string_uno());
    DSP::Settings::writeVal(DSP::Settings::Unonoisefile, ui->lineNoisefile->text());

    // Tint
    if (ui->groupUnotint->isChecked()) {
        QString holder = QString("%1:%2").arg(ui->horizontalUnohue->value())
                .arg(ui->horizontalUnostrength->value());
        DSP::Settings::writeVal(DSP::Settings::Unotint, holder);
    } else
        DSP::Settings::writeVal(DSP::Settings::Unotint, "-1:0");

    // Page 5 Toolbutton
    DSP::Settings::writeVal(DSP::Settings::Toolbtngrad, build_gradient_string_tool());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnactivegrad, build_gradient_string_toolact());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnrnd, ui->spinToolround->value());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnshadow, ui->comboToolshadow->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnfolcol, ui->checkToolfollow->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Toolbtninvact, ui->checkToolinvert->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnflat, ui->checkToolflat->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnmorph, ui->checkToolmorph->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnnormal, ui->checkToolnormal->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Toolbtnmask, ui->checkToolmask->isChecked());

    // Tint
    if (ui->groupTooltint->isChecked()) {
        QString holder = QString("%1:%2").arg(ui->horizontalToolhue->value())
                .arg(ui->horizontalToolstrength->value());
        DSP::Settings::writeVal(DSP::Settings::Toolbtntint, holder);
    } else
        DSP::Settings::writeVal(DSP::Settings::Toolbtntint, "-1:0");

    // Page 6 Pushbutton
    DSP::Settings::writeVal(DSP::Settings::Pushbtngrad, build_gradient_string_push());
    DSP::Settings::writeVal(DSP::Settings::Pushbtnrnd, ui->spinPushround->value());
    DSP::Settings::writeVal(DSP::Settings::Pushbtnshadow, ui->comboPushshadow->currentIndex());

    // Tint
    if (ui->groupPushtint->isChecked()) {
        QString holder = QString("%1:%2").arg(ui->horizontalPushhue->value())
                .arg(ui->horizontalPushstrength->value());
        DSP::Settings::writeVal(DSP::Settings::Pushbtntint, holder);
    } else
        DSP::Settings::writeVal(DSP::Settings::Pushbtntint, "-1:0");

    // Page 7 Inputs
    DSP::Settings::writeVal(DSP::Settings::Inputgrad, build_gradient_string_input());
    DSP::Settings::writeVal(DSP::Settings::Inputrnd, ui->spinInputround->value());
    DSP::Settings::writeVal(DSP::Settings::Inputshadow, ui->comboInputround->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Inputunornd, ui->spinInputrounduno->value());

    // Tint
    if (ui->groupInputtint->isChecked()) {
        QString holder = QString("%1:%2").arg(ui->horizontalInputhue->value())
                .arg(ui->horizontalInputstrength->value());
        DSP::Settings::writeVal(DSP::Settings::Inputtint, holder);
    } else
        DSP::Settings::writeVal(DSP::Settings::Inputtint, "-1:0");

    // Page 8 Tabs
    DSP::Settings::writeVal(DSP::Settings::Tabgrad, build_gradient_string_tab());
    DSP::Settings::writeVal(DSP::Settings::Tabbargrad, build_gradient_string_tabbar());
    DSP::Settings::writeVal(DSP::Settings::Tabrnd, ui->spinTabround->value());
    DSP::Settings::writeVal(DSP::Settings::Tabshadow, ui->comboTabshadow->currentIndex());
    //Why couldn't this be boolean?
    int side = 0;
    if(ui->radioRight->isChecked())
        side = 1;
    DSP::Settings::writeVal(DSP::Settings::Tabcloser, side);
    DSP::Settings::writeVal(DSP::Settings::Tabsaf, ui->groupSafari->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Tabsafrnd, ui->spinSafarirnd->value());
    DSP::Settings::writeVal(DSP::Settings::Tabcloserrnd, ui->spinTabcloserrnd->value());

    int barstyle = 0;
    if (ui->radioSimple->isChecked())
        barstyle = 1;
    DSP::Settings::writeVal(DSP::Settings::Tabdocstyle, barstyle);
    DSP::Settings::writeVal(DSP::Settings::Tabdocwidth, ui->spinTabdocwidth->value());
    DSP::Settings::writeVal(DSP::Settings::Tabselectors, ui->checkTabselector->isChecked());
    DSP::Settings::restoreFileName();

    // Page 9 Windows
    DSP::Settings::writeVal(DSP::Settings::Wingrad, build_gradient_string_win());
    DSP::Settings::writeVal(DSP::Settings::Winhor, ui->checkWinhorizgrad->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Winnoise, ui->spinWinnoisestrength->value());
    DSP::Settings::writeVal(DSP::Settings::Winnoisestyle, ui->comboWinnoisestyle->currentIndex() - 1);
    DSP::Settings::writeVal(DSP::Settings::Winnoisefile, ui->lineWinnoisefile->text());

    // Page 10 Scrollers
    DSP::Settings::writeVal(DSP::Settings::Scrollergrad, build_gradient_string_scroll());
    DSP::Settings::writeVal(DSP::Settings::Scrollergroove, build_gradient_string_scrollgroove());
    //Why couldn't this be boolean?
    int scrollStyle = 0;
    if(ui->radioNotyosemite->isChecked())
        scrollStyle = 1;
    DSP::Settings::writeVal(DSP::Settings::Scrollerstyle, scrollStyle);
    DSP::Settings::writeVal(DSP::Settings::Scrollerinvert, ui->comboGroovestyle->currentIndex());

    // Page 11 Sliders
    DSP::Settings::writeVal(DSP::Settings::Slidergrad, build_gradient_string_slide());
    DSP::Settings::writeVal(DSP::Settings::Slidergroove, build_gradient_string_slidegroove());
    DSP::Settings::writeVal(DSP::Settings::Slidersize, ui->spinSlidersize->value());
    DSP::Settings::writeVal(DSP::Settings::Sliderdot, ui->checkDot->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Slidermetal, ui->checkMetal->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Slidergrooveshadow, ui->comboSlidegrooveshadow->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Sliderfillgroove, ui->checkFill->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Sliderinvert, ui->comboSlidegroovestyle->currentIndex());

    // Page 12 Progress Bars
    DSP::Settings::writeVal(DSP::Settings::Proggrad, build_gradient_string_progress());
    DSP::Settings::writeVal(DSP::Settings::Progrnd, ui->spinProgrnd->value());
    DSP::Settings::writeVal(DSP::Settings::Progshadow, ui->comboProgshadow->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Progtxthover, ui->checkProghover->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Progtxtpos, ui->comboProgtextpos->currentIndex());
    DSP::Settings::writeVal(DSP::Settings::Progstripe, ui->spinProgstripe->value());

    // Page 13 Menus
    DSP::Settings::writeVal(DSP::Settings::Menugrad, build_gradient_string_menu());
    DSP::Settings::writeVal(DSP::Settings::Menuitemgrad, build_gradient_string_menuitem());
    DSP::Settings::writeVal(DSP::Settings::Menuicons, ui->checkMenuicon->isChecked());
    DSP::Settings::writeVal(DSP::Settings::Menuitemshadow, ui->comboMenuitemshadow->currentIndex());
}

void MainWindow::on_actionDemo_triggered()
{
    QProcess demo;
    QString command = "despy";
    QStringList args;
    args << "--dsppreset" << "despy";

    write_config(command);

    demo.start(command, args, QIODevice::ReadOnly);
    demo.waitForFinished(-1);
}



void MainWindow::on_actionHide_menubar_triggered()
{
    qDebug() << "HIDE ME";
    if (ui->menuBar->isHidden())
        ui->menuBar->show();
    else
        ui->menuBar->hide();
}

void MainWindow::populate()
{
    // Page 1 General
    ui->sliderOpacity->setValue(DSP::Settings::readInt(DSP::Settings::Opacity));
    ui->sliderOpacity->setToolTip(DSP::Settings::description(DSP::Settings::Opacity));
    ui->labelOpacity->setNum(DSP::Settings::readInt(DSP::Settings::Opacity));
    ui->checkAnimateScrolling->setChecked(DSP::Settings::readBool(DSP::Settings::Animatescroll));
    ui->checkAnimateScrolling->setToolTip(DSP::Settings::description(DSP::Settings::Animatescroll));
    QStringList bl;
    bl << DSP::Settings::readStringList(DSP::Settings::Blacklist);
    QString blackList = bl.join(" ");
    ui->plainBlacklist->setPlainText(blackList);
    ui->plainBlacklist->setToolTip(DSP::Settings::description(DSP::Settings::Blacklist));
    ui->checkCompactmenu->setChecked(DSP::Settings::readBool(DSP::Settings::Compactmenu));
    ui->checkCompactmenu->setToolTip(DSP::Settings::description(DSP::Settings::Compactmenu));
    ui->checkSplitterextender->setChecked(DSP::Settings::readBool(DSP::Settings::Splitterext));
    ui->checkSplitterextender->setToolTip(DSP::Settings::description(DSP::Settings::Splitterext));
    ui->spinMaximumarrow->setValue(DSP::Settings::readInt(DSP::Settings::Arrowsize));
    ui->spinMaximumarrow->setToolTip(DSP::Settings::description(DSP::Settings::Arrowsize));
    ui->checkSimplearrows->setChecked(DSP::Settings::readBool(DSP::Settings::Simplearrows));
    ui->checkSimplearrows->setToolTip(DSP::Settings::description(DSP::Settings::Simplearrows));
    ui->checkBalloontips->setChecked(DSP::Settings::readBool(DSP::Settings::Balloontips));
    ui->checkBalloontips->setToolTip(DSP::Settings::description(DSP::Settings::Balloontips));
    ui->checkAnimatestack->setChecked(DSP::Settings::readBool(DSP::Settings::Animatestack));
    ui->checkAnimatestack->setToolTip(DSP::Settings::description(DSP::Settings::Animatestack));
    ui->checkLockdocks->setChecked(DSP::Settings::readBool(DSP::Settings::Lockdocks));
    ui->checkLockdocks->setToolTip(DSP::Settings::description(DSP::Settings::Lockdocks));
    ui->checkDifferentInactive->setChecked(DSP::Settings::readBool(DSP::Settings::Differentinactive));
    ui->checkDifferentInactive->setToolTip(DSP::Settings::description(DSP::Settings::Differentinactive));
    ui->checkHackdialog->setChecked(DSP::Settings::readBool(DSP::Settings::Hackdialogs));
    ui->checkHackdialog->setToolTip(DSP::Settings::description(DSP::Settings::Hackdialogs));

    // Page 2 Shadows
    ui->horizontalShadows->setValue(DSP::Settings::readInt(DSP::Settings::Shadowopacity));
    ui->horizontalShadows->setToolTip(DSP::Settings::description(DSP::Settings::Shadowopacity));
    ui->horizontalIllumination->setValue(DSP::Settings::readInt(DSP::Settings::Shadowillumination));
    ui->horizontalIllumination->setToolTip(DSP::Settings::description(DSP::Settings::Shadowillumination));
    ui->horizontalTextshadow->setValue(DSP::Settings::readInt(DSP::Settings::Shadowontextopacity));
    ui->horizontalTextshadow->setToolTip(DSP::Settings::description(DSP::Settings::Shadowontextopacity));
    ui->checkDarkraise->setChecked(DSP::Settings::readBool(DSP::Settings::Shadowdarkraised));
    ui->checkDarkraise->setToolTip(DSP::Settings::description(DSP::Settings::Shadowdarkraised));

    // Page 3 Titlebar
    ui->groupBox_Removetitlebar->setChecked(DSP::Settings::readBool(DSP::Settings::Removetitle));
    ui->groupBox_Removetitlebar->setToolTip(DSP::Settings::description(DSP::Settings::Removetitle));
    ui->comboTitleposition->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Titlepos));
    ui->comboTitleposition->setToolTip(DSP::Settings::description(DSP::Settings::Titlepos));
    ui->comboDecobuttons->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Decobuttons));
    ui->comboDecobuttons->setToolTip(DSP::Settings::description(DSP::Settings::Decobuttons));
    ui->checkDecoicon->setChecked(DSP::Settings::readBool(DSP::Settings::Decoicon));
    ui->checkDecoicon->setToolTip(DSP::Settings::description(DSP::Settings::Decoicon));
    stringMincolor = DSP::Settings::readString(DSP::Settings::Decomincolor);
    ui->pushMincolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                     .arg(stringMincolor));
    stringMaxcolor = DSP::Settings::readString(DSP::Settings::Decomaxcolor);
    ui->pushMaxcolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                     .arg(stringMaxcolor));
    stringClosecolor = DSP::Settings::readString(DSP::Settings::Decoclosecolor);
    ui->pushClosecolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                       .arg(stringClosecolor));
    ui->spinShadowsize->setValue(DSP::Settings::readInt(DSP::Settings::Decoshadowsize));
    ui->spinShadowsize->setToolTip(DSP::Settings::description(DSP::Settings::Decoshadowsize));
    ui->spinFramesize->setValue(DSP::Settings::readInt(DSP::Settings::Decoframe));
    ui->spinFramesize->setToolTip(DSP::Settings::description(DSP::Settings::Decoframe));

    // Page 4 UNO
    ui->lineNoisefile->setText(DSP::Settings::readString(DSP::Settings::Unonoisefile));
    ui->groupUnoenable->setChecked(DSP::Settings::readBool(DSP::Settings::Unoenabled));
    ui->groupUnoenable->setToolTip(DSP::Settings::description(DSP::Settings::Unoenabled));
    ui->spinUnonoisestrength->setValue(DSP::Settings::readInt(DSP::Settings::Unonoise));
    ui->spinUnonoisestrength->setToolTip(DSP::Settings::description(DSP::Settings::Unonoise));
    ui->comboUnonoisestyle->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Unonoisestyle) + 1);
    ui->comboUnonoisestyle->setToolTip(DSP::Settings::description(DSP::Settings::Unonoisestyle));
    ui->checkUnogradhoriz->setChecked(DSP::Settings::readBool(DSP::Settings::Unohor));
    ui->checkUnogradhoriz->setToolTip(DSP::Settings::description(DSP::Settings::Unohor));
    ui->groupUnocontent->setChecked(DSP::Settings::readBool(DSP::Settings::Unocont));
    ui->groupUnocontent->setToolTip(DSP::Settings::description(DSP::Settings::Unocont));
    ui->spinUnocontopacity->setValue(DSP::Settings::readInt(DSP::Settings::Unoopacity));
    ui->spinUnocontopacity->setToolTip(DSP::Settings::description(DSP::Settings::Unoopacity));
    ui->spinUnocontblur->setValue(DSP::Settings::readInt(DSP::Settings::Unocontblur));
    ui->spinUnocontblur->setToolTip(DSP::Settings::description(DSP::Settings::Unocontblur));

    // Page 4 Tint
    ui->groupUnotint->setToolTip(DSP::Settings::description(DSP::Settings::Unotint));
     QStringList unoList = DSP::Settings::readString(DSP::Settings::Unotint).split(":");
    if (unoList[0] == "-1")
        ui->groupUnotint->setChecked(false);
    else {
        ui->groupUnotint->setChecked(true);
        ui->horizontalUnohue->setValue(unoList[0].toInt());
        ui->horizontalUnostrength->setValue(unoList[1].toInt());
    }

    // Page 4 Gradient
    QString unoGradientString = DSP::Settings::readString(DSP::Settings::Unograd);
    if (unoGradientString.isEmpty())
        unoGradientString = "0.0:0, 1.0:0";
    QStringList unoGradientList = unoGradientString.split(",");
    int unoGradientCounter = unoGradientList.count();
    QStringList uno_holder;

    if (unoGradientCounter > 0) {
        uno_holder = unoGradientList.at(0).split(":");
        ui->doubleUno1->setValue(uno_holder.at(0).toFloat());
        ui->spinUno1->setValue(uno_holder.at(1).toInt());
    }

    if (unoGradientCounter > 1) {
        uno_holder = unoGradientList.at(1).split(":");
        ui->doubleUno2->setValue(uno_holder.at(0).toFloat());
        ui->spinUno2->setValue(uno_holder.at(1).toInt());
    }

    if (unoGradientCounter > 2) {
        ui->checkUno3->setChecked(true);
        uno_holder = unoGradientList.at(2).split(":");
        ui->doubleUno3->setValue(uno_holder.at(0).toFloat());
        ui->spinUno3->setValue(uno_holder.at(1).toInt());
    } else {
        ui->checkUno3->setChecked(false);
        ui->doubleUno3->setEnabled(false);
        ui->spinUno3->setEnabled(false);
    }

    if (unoGradientCounter > 3) {
        ui->checkUno4->setChecked(true);
        uno_holder = unoGradientList.at(3).split(":");
        ui->doubleUno4->setValue(uno_holder.at(0).toFloat());
        ui->spinUno4->setValue(uno_holder.at(1).toInt());
    } else {
        ui->checkUno4->setChecked(false);
        ui->doubleUno4->setEnabled(false);
        ui->spinUno4->setEnabled(false);
    }

    if (unoGradientCounter > 4) {
        ui->checkUno5->setChecked(true);
        uno_holder = unoGradientList.at(4).split(":");
        ui->doubleUno5->setValue(uno_holder.at(0).toFloat());
        ui->spinUno5->setValue(uno_holder.at(1).toInt());
    } else {
        ui->checkUno5->setChecked(false);
        ui->doubleUno5->setEnabled(false);
        ui->spinUno5->setEnabled(false);
    }

    // Page 5 Toolbutton
    ui->spinToolround->setValue(DSP::Settings::readInt(DSP::Settings::Toolbtnrnd));
    ui->spinToolround->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnrnd));
    ui->comboToolshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Toolbtnshadow));
    ui->comboToolshadow->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnshadow));
    ui->checkToolfollow->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtnfolcol));
    ui->checkToolfollow->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnfolcol));
    ui->checkToolinvert->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtninvact));
    ui->checkToolinvert->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtninvact));
    ui->checkToolflat->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtnflat));
    ui->checkToolflat->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnflat));
    ui->checkToolmorph->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtnmorph));
    ui->checkToolmorph->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnmorph));
    ui->checkToolnormal->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtnnormal));
    ui->checkToolnormal->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnnormal));
    ui->checkToolmask->setChecked(DSP::Settings::readBool(DSP::Settings::Toolbtnmask));
    ui->checkToolmask->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtnmask));

    if (ui->checkToolfollow->isChecked())
        ui->checkToolmorph->setEnabled(true);
    else
        ui->checkToolmorph->setEnabled(false);

    // Page 5 Tint
    ui->groupTooltint->setToolTip(DSP::Settings::description(DSP::Settings::Toolbtntint));
    QStringList toolList = DSP::Settings::readString(DSP::Settings::Toolbtntint).split(":");
    if (toolList[0] == "-1")
        ui->groupTooltint->setChecked(false);
    else {
        ui->groupTooltint->setChecked(true);
        ui->horizontalToolhue->setValue(toolList[0].toInt());
        ui->horizontalToolstrength->setValue(toolList[1].toInt());
    }

    // Page 5 Gradient
    QString toolGradientString = DSP::Settings::readString(DSP::Settings::Toolbtngrad);
    if (toolGradientString.isEmpty())
        toolGradientString = "0.0:0, 1.0:0";
    QStringList toolGradientList = toolGradientString.split(",");
    int toolGradientCounter = toolGradientList.count();
    QStringList tool_holder;

    if (toolGradientCounter > 0) {
        tool_holder = toolGradientList.at(0).split(":");
        ui->doubleToolgrad1->setValue(tool_holder.at(0).toFloat());
        ui->spinToolgrad1->setValue(tool_holder.at(1).toInt());
    }

    if (toolGradientCounter > 1) {
        tool_holder = toolGradientList.at(1).split(":");
        ui->doubleToolgrad2->setValue(tool_holder.at(0).toFloat());
        ui->spinToolgrad2->setValue(tool_holder.at(1).toInt());
    }

    if (toolGradientCounter > 2) {
        ui->checkToolgrad3->setChecked(true);
        tool_holder = toolGradientList.at(2).split(":");
        ui->doubleToolgrad3->setValue(tool_holder.at(0).toFloat());
        ui->spinToolgrad3->setValue(tool_holder.at(1).toInt());
    } else {
        ui->checkToolgrad3->setChecked(false);
        ui->doubleToolgrad3->setEnabled(false);
        ui->spinToolgrad3->setEnabled(false);
    }

    if (toolGradientCounter > 3) {
        ui->checkToolgrad4->setChecked(true);
        tool_holder = toolGradientList.at(3).split(":");
        ui->doubleToolgrad4->setValue(tool_holder.at(0).toFloat());
        ui->spinToolgrad4->setValue(tool_holder.at(1).toInt());
    } else {
        ui->checkToolgrad4->setChecked(false);
        ui->doubleToolgrad4->setEnabled(false);
        ui->spinToolgrad4->setEnabled(false);
    }

    if (toolGradientCounter > 4) {
        ui->checkToolgrad5->setChecked(true);
        tool_holder = toolGradientList.at(4).split(":");
        ui->doubleToolgrad5->setValue(tool_holder.at(0).toFloat());
        ui->spinToolgrad5->setValue(tool_holder.at(1).toInt());
    } else {
        ui->checkToolgrad5->setChecked(false);
        ui->doubleToolgrad5->setEnabled(false);
        ui->spinToolgrad5->setEnabled(false);
    }

    QString toolActGradientString = DSP::Settings::readString(DSP::Settings::Toolbtnactivegrad);
    if (toolActGradientString.isEmpty())
        toolActGradientString = "0.0:0, 1.0:0";
    QStringList toolActGradientList = toolActGradientString.split(",");
    int toolActGradientCounter = toolActGradientList.count();
    QStringList toolAct_holder;

    if (toolActGradientCounter > 0) {
        toolAct_holder = toolActGradientList.at(0).split(":");
        ui->doubleToolact1->setValue(toolAct_holder.at(0).toFloat());
        ui->spinToolact1->setValue(toolAct_holder.at(1).toInt());
    }

    if (toolActGradientCounter > 1) {
        toolAct_holder = toolActGradientList.at(1).split(":");
        ui->doubleToolact2->setValue(toolAct_holder.at(0).toFloat());
        ui->spinToolact2->setValue(toolAct_holder.at(1).toInt());
    }

    if (toolActGradientCounter > 2) {
        ui->checkToolact3->setChecked(true);
        toolAct_holder = toolActGradientList.at(2).split(":");
        ui->doubleToolact3->setValue(toolAct_holder.at(0).toFloat());
        ui->spinToolact3->setValue(toolAct_holder.at(1).toInt());
    } else {
        ui->checkToolact3->setChecked(false);
        ui->doubleToolact3->setEnabled(false);
        ui->spinToolact3->setEnabled(false);
    }

    if (toolActGradientCounter > 3) {
        ui->checkToolact4->setChecked(true);
        toolAct_holder = toolActGradientList.at(3).split(":");
        ui->doubleToolact4->setValue(toolAct_holder.at(0).toFloat());
        ui->spinToolact4->setValue(toolAct_holder.at(1).toInt());
    } else {
        ui->checkToolact4->setChecked(false);
        ui->doubleToolact4->setEnabled(false);
        ui->spinToolact4->setEnabled(false);
    }

    if (toolActGradientCounter > 4) {
        ui->checkToolact5->setChecked(true);
        toolAct_holder = toolActGradientList.at(4).split(":");
        ui->doubleToolact5->setValue(toolAct_holder.at(0).toFloat());
        ui->spinToolact5->setValue(toolAct_holder.at(1).toInt());
    } else {
        ui->checkToolact5->setChecked(false);
        ui->doubleToolact5->setEnabled(false);
        ui->spinToolact5->setEnabled(false);
    }

    // Page 6 Push Button
    ui->spinPushround->setValue(DSP::Settings::readInt(DSP::Settings::Pushbtnrnd));
    ui->spinPushround->setToolTip(DSP::Settings::description(DSP::Settings::Pushbtnrnd));
    ui->comboPushshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Pushbtnshadow));
    ui->comboPushshadow->setToolTip(DSP::Settings::description(DSP::Settings::Pushbtnshadow));

    // Page 6 Tint
    ui->groupPushtint->setToolTip(DSP::Settings::description(DSP::Settings::Pushbtntint));
    QStringList pushList = DSP::Settings::readString(DSP::Settings::Pushbtntint).split(":");
    if (pushList[0] == "-1")
        ui->groupPushtint->setChecked(false);
    else {
        ui->groupPushtint->setChecked(true);
        ui->horizontalPushhue->setValue(pushList[0].toInt());
        ui->horizontalPushstrength->setValue(pushList[1].toInt());
    }

    // Page 6 Gradient
    QString pushGradientString = DSP::Settings::readString(DSP::Settings::Pushbtngrad);
    if (pushGradientString.isEmpty())
        pushGradientString = "0.0:0, 1.0:0";
    QStringList pushGradientList = pushGradientString.split(",");
    int pushGradientCounter = pushGradientList.count();
    QStringList push_holder;

    if (pushGradientCounter > 0) {
        push_holder = pushGradientList.at(0).split(":");
        ui->doublePushgrad1->setValue(push_holder.at(0).toFloat());
        ui->spinPushgrad1->setValue(push_holder.at(1).toInt());
    }

    if (pushGradientCounter > 1) {
        push_holder = pushGradientList.at(1).split(":");
        ui->doublePushgrad2->setValue(push_holder.at(0).toFloat());
        ui->spinPushgrad2->setValue(push_holder.at(1).toInt());
    }

    if (pushGradientCounter > 2) {
        ui->checkPushgrad3->setChecked(true);
        push_holder = pushGradientList.at(2).split(":");
        ui->doublePushgrad3->setValue(push_holder.at(0).toFloat());
        ui->spinPushgrad3->setValue(push_holder.at(1).toInt());
    } else {
        ui->checkPushgrad3->setChecked(false);
        ui->doublePushgrad3->setEnabled(false);
        ui->spinPushgrad3->setEnabled(false);
    }

    if (pushGradientCounter > 3) {
        ui->checkPushgrad4->setChecked(true);
        push_holder = pushGradientList.at(3).split(":");
        ui->doublePushgrad4->setValue(push_holder.at(0).toFloat());
        ui->spinPushgrad4->setValue(push_holder.at(1).toInt());
    } else {
        ui->checkPushgrad4->setChecked(false);
        ui->doublePushgrad4->setEnabled(false);
        ui->spinPushgrad4->setEnabled(false);
    }

    if (pushGradientCounter > 4) {
        ui->checkPushgrad5->setChecked(true);
        push_holder = pushGradientList.at(4).split(":");
        ui->doublePushgrad5->setValue(push_holder.at(0).toFloat());
        ui->spinPushgrad5->setValue(push_holder.at(1).toInt());
    } else {
        ui->checkPushgrad5->setChecked(false);
        ui->doublePushgrad5->setEnabled(false);
        ui->spinPushgrad5->setEnabled(false);
    }

    // Page 7 Input
    ui->spinInputround->setValue(DSP::Settings::readInt(DSP::Settings::Inputrnd));
    ui->spinInputround->setToolTip(DSP::Settings::description(DSP::Settings::Inputrnd));
    ui->comboInputround->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Inputshadow));
    ui->comboInputround->setToolTip(DSP::Settings::description(DSP::Settings::Inputshadow));
    ui->spinInputrounduno->setValue(DSP::Settings::readInt(DSP::Settings::Inputunornd));
    ui->spinInputrounduno->setToolTip(DSP::Settings::description(DSP::Settings::Inputunornd));

    // Page 7 Tint
    ui->groupInputtint->setToolTip(DSP::Settings::description(DSP::Settings::Inputtint));
    QStringList inputList = DSP::Settings::readString(DSP::Settings::Inputtint).split(":");
    if (inputList[0] == "-1")
        ui->groupInputtint->setChecked(false);
    else {
        ui->groupInputtint->setChecked(true);
        ui->horizontalInputhue->setValue(inputList[0].toInt());
        ui->horizontalInputstrength->setValue(inputList[1].toInt());
    }

    // Page 7 Gradient
    QString inputGradientString = DSP::Settings::readString(DSP::Settings::Inputgrad);
    if (inputGradientString.isEmpty())
        inputGradientString = "0.0:0, 1.0:0";
    QStringList InputGradientList = inputGradientString.split(",");
    int InputGradientCounter = InputGradientList.count();
    QStringList input_holder;

    if (InputGradientCounter > 0) {
        input_holder = InputGradientList.at(0).split(":");
        ui->doubleInputgrad1->setValue(input_holder.at(0).toFloat());
        ui->spinInputgrad1->setValue(input_holder.at(1).toInt());
    }

    if (InputGradientCounter > 1) {
        input_holder = InputGradientList.at(1).split(":");
        ui->doubleInputgrad2->setValue(input_holder.at(0).toFloat());
        ui->spinInputgrad2->setValue(input_holder.at(1).toInt());
    }

    if (InputGradientCounter > 2) {
        ui->checkInputgrad3->setChecked(true);
        input_holder = InputGradientList.at(2).split(":");
        ui->doubleInputgrad3->setValue(input_holder.at(0).toFloat());
        ui->spinInputgrad3->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkInputgrad3->setChecked(false);
        ui->doubleInputgrad3->setEnabled(false);
        ui->spinInputgrad3->setEnabled(false);
    }

    if (InputGradientCounter > 3) {
        ui->checkInputgrad4->setChecked(true);
        input_holder = InputGradientList.at(3).split(":");
        ui->doubleInputgrad4->setValue(input_holder.at(0).toFloat());
        ui->spinInputgrad4->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkInputgrad4->setChecked(false);
        ui->doubleInputgrad4->setEnabled(false);
        ui->spinInputgrad4->setEnabled(false);
    }

    if (InputGradientCounter > 4) {
        ui->checkInputgrad5->setChecked(true);
        input_holder = InputGradientList.at(4).split(":");
        ui->doubleInputgrad5->setValue(input_holder.at(0).toFloat());
        ui->spinInputgrad5->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkInputgrad5->setChecked(false);
        ui->doubleInputgrad5->setEnabled(false);
        ui->spinInputgrad5->setEnabled(false);
    }

    // Page 8 Tabs
    ui->spinTabround->setValue(DSP::Settings::readInt(DSP::Settings::Tabrnd));
    ui->spinTabround->setToolTip(DSP::Settings::description(DSP::Settings::Tabrnd));
    ui->comboTabshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Tabshadow));
    ui->comboTabshadow->setToolTip(DSP::Settings::description(DSP::Settings::Tabshadow));

    if (DSP::Settings::readInt(DSP::Settings::Tabcloser) == 0)
        ui->radioLeft->toggle();
    else
        ui->radioRight->toggle();

    ui->groupTabcloser->setToolTip(DSP::Settings::description(DSP::Settings::Tabcloser));
    ui->groupSafari->setChecked(DSP::Settings::readBool(DSP::Settings::Tabsaf));
    ui->groupSafari->setToolTip(DSP::Settings::description(DSP::Settings::Tabsaf));
    ui->spinSafarirnd->setValue(DSP::Settings::readInt(DSP::Settings::Tabsafrnd));
    ui->spinSafarirnd->setToolTip(DSP::Settings::description(DSP::Settings::Tabsafrnd));
    ui->spinTabcloserrnd->setValue(DSP::Settings::readInt(DSP::Settings::Tabcloserrnd));
    ui->spinTabcloserrnd->setToolTip(DSP::Settings::description(DSP::Settings::Tabcloserrnd));

    if (DSP::Settings::readInt(DSP::Settings::Tabdocstyle) == 0)
        ui->radioChrome->toggle();
    else
        ui->radioSimple->toggle();

    ui->groupTabbar->setToolTip(DSP::Settings::description(DSP::Settings::Tabdocstyle));
    ui->spinTabdocwidth->setValue(DSP::Settings::readInt(DSP::Settings::Tabdocwidth));
    ui->spinTabdocwidth->setToolTip(DSP::Settings::description(DSP::Settings::Tabdocwidth));
    ui->checkTabselector->setChecked(DSP::Settings::readBool(DSP::Settings::Tabselectors));
    ui->checkTabselector->setToolTip(DSP::Settings::description(DSP::Settings::Tabselectors));

    // Gradient Tabs
    QString tabGradientString = DSP::Settings::readString(DSP::Settings::Tabgrad);
    if (tabGradientString.isEmpty())
        tabGradientString = "0.0:0, 1.0:0";
    QStringList tabGradientList = tabGradientString.split(",");
    int tabGradientCounter = tabGradientList.count();
    QStringList tab_holder;

    if (tabGradientCounter > 0) {
        input_holder = tabGradientList.at(0).split(":");
        ui->doubleTabgrad1->setValue(input_holder.at(0).toFloat());
        ui->spinTabgrad1->setValue(input_holder.at(1).toInt());
    }

    if (tabGradientCounter > 1) {
        input_holder = tabGradientList.at(1).split(":");
        ui->doubleTabgrad2->setValue(input_holder.at(0).toFloat());
        ui->spinTabgrad2->setValue(input_holder.at(1).toInt());
    }

    if (tabGradientCounter > 2) {
        ui->checkTabgrad3->setChecked(true);
        input_holder = tabGradientList.at(2).split(":");
        ui->doubleTabgrad3->setValue(input_holder.at(0).toFloat());
        ui->spinTabgrad3->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkTabgrad3->setChecked(false);
        ui->doubleTabgrad3->setEnabled(false);
        ui->spinTabgrad3->setEnabled(false);
    }

    if (tabGradientCounter > 3) {
        ui->checkTabgrad4->setChecked(true);
        input_holder = tabGradientList.at(3).split(":");
        ui->doubleTabgrad4->setValue(input_holder.at(0).toFloat());
        ui->spinTabgrad4->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkTabgrad4->setChecked(false);
        ui->doubleTabgrad4->setEnabled(false);
        ui->spinTabgrad4->setEnabled(false);
    }

    if (tabGradientCounter > 4) {
        ui->checkTabgrad5->setChecked(true);
        input_holder = tabGradientList.at(4).split(":");
        ui->doubleTabgrad5->setValue(input_holder.at(0).toFloat());
        ui->spinTabgrad5->setValue(input_holder.at(1).toInt());
    } else {
        ui->checkTabgrad5->setChecked(false);
        ui->doubleTabgrad5->setEnabled(false);
        ui->spinTabgrad5->setEnabled(false);
    }

    // Gradient Tabbars
    QString tabbarGradientString = DSP::Settings::readString(DSP::Settings::Tabbargrad);
    if (tabbarGradientString.isEmpty())
        tabbarGradientString = "0.0:0, 1.0:0";
    QStringList tabbarGradientList = tabbarGradientString.split(",");
    int tabbarGradientCounter = tabbarGradientList.count();
    QStringList tabbar_holder;

    if (tabbarGradientCounter > 0) {
        tabbar_holder = tabbarGradientList.at(0).split(":");
        ui->doubleTabbargrad1->setValue(tabbar_holder.at(0).toFloat());
        ui->spinTabbargrad1->setValue(tabbar_holder.at(1).toInt());
    }

    if (tabbarGradientCounter > 1) {
        tabbar_holder = tabbarGradientList.at(1).split(":");
        ui->doubleTabbargrad2->setValue(tabbar_holder.at(0).toFloat());
        ui->spinTabbargrad2->setValue(tabbar_holder.at(1).toInt());
    }

    if (tabbarGradientCounter > 2) {
        ui->checkTabbargrad3->setChecked(true);
        tabbar_holder = tabbarGradientList.at(2).split(":");
        ui->doubleTabbargrad3->setValue(tabbar_holder.at(0).toFloat());
        ui->spinTabbargrad3->setValue(tabbar_holder.at(1).toInt());
    } else {
        ui->checkTabbargrad3->setChecked(false);
        ui->doubleTabbargrad3->setEnabled(false);
        ui->spinTabbargrad3->setEnabled(false);
    }

    if (tabbarGradientCounter > 3) {
        ui->checkTabbargrad4->setChecked(true);
        tabbar_holder = tabbarGradientList.at(3).split(":");
        ui->doubleTabbargrad4->setValue(tabbar_holder.at(0).toFloat());
        ui->spinTabbargrad4->setValue(tabbar_holder.at(1).toInt());
    } else {
        ui->checkTabbargrad4->setChecked(false);
        ui->doubleTabbargrad4->setEnabled(false);
        ui->spinTabbargrad4->setEnabled(false);
    }

    if (tabbarGradientCounter > 4) {
        ui->checkTabbargrad5->setChecked(true);
        tabbar_holder = tabbarGradientList.at(4).split(":");
        ui->doubleTabbargrad5->setValue(tabbar_holder.at(0).toFloat());
        ui->spinTabbargrad5->setValue(tabbar_holder.at(1).toInt());
    } else {
        ui->checkTabbargrad5->setChecked(false);
        ui->doubleTabbargrad5->setEnabled(false);
        ui->spinTabbargrad5->setEnabled(false);
    }

    // Page 9 Window

    // Gradient Window
    QString winGradientString = DSP::Settings::readString(DSP::Settings::Wingrad);
    if (winGradientString.isEmpty())
        winGradientString = "0.0:0, 1.0:0";
    QStringList winGradientList = winGradientString.split(",");
    int winGradientCounter = winGradientList.count();
    QStringList win_holder;

    if (winGradientCounter > 0) {
        win_holder = winGradientList.at(0).split(":");
        ui->doubleWingrad1->setValue(win_holder.at(0).toFloat());
        ui->spinWingrad1->setValue(win_holder.at(1).toInt());
    }

    if (winGradientCounter > 1) {
        win_holder = winGradientList.at(1).split(":");
        ui->doubleWingrad2->setValue(win_holder.at(0).toFloat());
        ui->spinWingrad2->setValue(win_holder.at(1).toInt());
    }

    if (winGradientCounter > 2) {
        ui->checkWingrad3->setChecked(true);
        win_holder = winGradientList.at(2).split(":");
        ui->doubleWingrad3->setValue(win_holder.at(0).toFloat());
        ui->spinWingrad3->setValue(win_holder.at(1).toInt());
    } else {
        ui->checkWingrad3->setChecked(false);
        ui->doubleWingrad3->setEnabled(false);
        ui->spinWingrad3->setEnabled(false);
    }

    if (winGradientCounter > 3) {
        ui->checkWingrad4->setChecked(true);
        win_holder = winGradientList.at(3).split(":");
        ui->doubleWingrad4->setValue(win_holder.at(0).toFloat());
        ui->spinWingrad4->setValue(win_holder.at(1).toInt());
    } else {
        ui->checkWingrad4->setChecked(false);
        ui->doubleWingrad4->setEnabled(false);
        ui->spinWingrad4->setEnabled(false);
    }

    if (winGradientCounter > 4) {
        ui->checkWingrad5->setChecked(true);
        win_holder = winGradientList.at(4).split(":");
        ui->doubleWingrad5->setValue(win_holder.at(0).toFloat());
        ui->spinWingrad5->setValue(win_holder.at(1).toInt());
    } else {
        ui->checkWingrad5->setChecked(false);
        ui->doubleWingrad5->setEnabled(false);
        ui->spinWingrad5->setEnabled(false);
    }

    ui->checkWinhorizgrad->setChecked(DSP::Settings::readBool(DSP::Settings::Winhor));
    ui->checkWinhorizgrad->setToolTip(DSP::Settings::description(DSP::Settings::Winhor));
    ui->spinWinnoisestrength->setValue(DSP::Settings::readInt(DSP::Settings::Winnoise));
    ui->spinWinnoisestrength->setToolTip(DSP::Settings::description(DSP::Settings::Winnoise));
    ui->comboWinnoisestyle->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Winnoisestyle) + 1);
    ui->comboWinnoisestyle->setToolTip(DSP::Settings::description(DSP::Settings::Winnoisestyle));
    ui->lineWinnoisefile->setText(DSP::Settings::readString(DSP::Settings::Winnoisefile));
    ui->lineWinnoisefile->setToolTip(DSP::Settings::description(DSP::Settings::Winnoisefile));

    //Page 10 Scrollers
    ui->spinScrollsize->setValue(DSP::Settings::readInt(DSP::Settings::Scrollersize));
    ui->spinScrollsize->setToolTip(DSP::Settings::description(DSP::Settings::Scrollersize));

    if (DSP::Settings::readInt(DSP::Settings::Scrollerstyle) == 0) {
        ui->radioYosemite->toggle();
        ui->comboGroovestyle->setEnabled(false);
        ui->comboGrooveshadow->setEnabled(false);
        ui->labelGroovefill->setEnabled(false);
        ui->labelGrooveshadow->setEnabled(false);
    } else {
        ui->radioNotyosemite->toggle();
        ui->comboGroovestyle->setEnabled(true);
        ui->comboGrooveshadow->setEnabled(true);
        ui->labelGroovefill->setEnabled(true);
        ui->labelGrooveshadow->setEnabled(true);
    }

    ui->comboGroovestyle->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Scrollerinvert));
    ui->comboGroovestyle->setToolTip(DSP::Settings::description(DSP::Settings::Scrollerinvert));
    ui->comboGrooveshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Scrollergshadow));
    ui->comboGrooveshadow->setToolTip(DSP::Settings::description(DSP::Settings::Scrollergshadow));

    // Gradient Scroller
    QString scrollGradientString = DSP::Settings::readString(DSP::Settings::Scrollergrad);
    if (scrollGradientString.isEmpty())
        scrollGradientString = "0.0:0, 1.0:0";
    QStringList scrollGradientList = scrollGradientString.split(",");
    int scrollGradientCounter = scrollGradientList.count();
    QStringList scroll_holder;

    if (scrollGradientCounter > 0) {
        scroll_holder = scrollGradientList.at(0).split(":");
        ui->doubleScrollgrad1->setValue(scroll_holder.at(0).toFloat());
        ui->spinScrollgrad1->setValue(scroll_holder.at(1).toInt());
    }

    if (scrollGradientCounter > 1) {
        scroll_holder = scrollGradientList.at(1).split(":");
        ui->doubleScrollgrad2->setValue(scroll_holder.at(0).toFloat());
        ui->spinScrollgrad2->setValue(scroll_holder.at(1).toInt());
    }

    if (scrollGradientCounter > 2) {
        ui->checkScrollgrad3->setChecked(true);
        scroll_holder = scrollGradientList.at(2).split(":");
        ui->doubleScrollgrad3->setValue(scroll_holder.at(0).toFloat());
        ui->spinScrollgrad3->setValue(scroll_holder.at(1).toInt());
    } else {
        ui->checkScrollgrad3->setChecked(false);
        ui->doubleScrollgrad3->setEnabled(false);
        ui->spinScrollgrad3->setEnabled(false);
    }

    if (scrollGradientCounter > 3) {
        ui->checkScrollgrad4->setChecked(true);
        scroll_holder = scrollGradientList.at(3).split(":");
        ui->doubleScrollgrad4->setValue(scroll_holder.at(0).toFloat());
        ui->spinScrollgrad4->setValue(scroll_holder.at(1).toInt());
    } else {
        ui->checkScrollgrad4->setChecked(false);
        ui->doubleScrollgrad4->setEnabled(false);
        ui->spinScrollgrad4->setEnabled(false);
    }

    if (scrollGradientCounter > 4) {
        ui->checkScrollgrad5->setChecked(true);
        scroll_holder = scrollGradientList.at(4).split(":");
        ui->doubleScrollgrad5->setValue(scroll_holder.at(0).toFloat());
        ui->spinScrollgrad5->setValue(scroll_holder.at(1).toInt());
    } else {
        ui->checkScrollgrad5->setChecked(false);
        ui->doubleScrollgrad5->setEnabled(false);
        ui->spinScrollgrad5->setEnabled(false);
    }

    // Gradient ScrollerGroove
        QString scrollgrooveGradientString = DSP::Settings::readString(DSP::Settings::Scrollergroove);
        if (scrollgrooveGradientString.isEmpty())
            scrollgrooveGradientString = "0.0:0, 1.0:0";
        QStringList scrollgrooveGradientList = scrollgrooveGradientString.split(",");
        int scrollgrooveGradientCounter = scrollgrooveGradientList.count();
        QStringList scrollgroove_holder;

        if (scrollgrooveGradientCounter > 0) {
            scrollgroove_holder = scrollgrooveGradientList.at(0).split(":");
            ui->doubleScrollgroovegrad1->setValue(scrollgroove_holder.at(0).toFloat());
            ui->spinScrollgroovegrad1->setValue(scrollgroove_holder.at(1).toInt());
        }

        if (scrollgrooveGradientCounter > 1) {
            scrollgroove_holder = scrollgrooveGradientList.at(1).split(":");
            ui->doubleScrollgroovegrad2->setValue(scrollgroove_holder.at(0).toFloat());
            ui->spinScrollgroovegrad2->setValue(scrollgroove_holder.at(1).toInt());
        }

        if (scrollgrooveGradientCounter > 2) {
            ui->checkScrollgroovegrad3->setChecked(true);
            scrollgroove_holder = scrollgrooveGradientList.at(2).split(":");
            ui->doubleScrollgroovegrad3->setValue(scrollgroove_holder.at(0).toFloat());
            ui->spinScrollgroovegrad3->setValue(scrollgroove_holder.at(1).toInt());
        } else {
            ui->checkScrollgroovegrad3->setChecked(false);
            ui->doubleScrollgroovegrad3->setEnabled(false);
            ui->spinScrollgroovegrad3->setEnabled(false);
        }

        if (scrollgrooveGradientCounter > 3) {
            ui->checkScrollgroovegrad4->setChecked(true);
            scrollgroove_holder = scrollgrooveGradientList.at(3).split(":");
            ui->doubleScrollgroovegrad4->setValue(scrollgroove_holder.at(0).toFloat());
            ui->spinScrollgroovegrad4->setValue(scrollgroove_holder.at(1).toInt());
        } else {
            ui->checkScrollgroovegrad4->setChecked(false);
            ui->doubleScrollgroovegrad4->setEnabled(false);
            ui->spinScrollgroovegrad4->setEnabled(false);
        }

        if (scrollgrooveGradientCounter > 4) {
            ui->checkScrollgroovegrad5->setChecked(true);
            scrollgroove_holder = scrollgrooveGradientList.at(4).split(":");
            ui->doubleScrollgroovegrad5->setValue(scrollgroove_holder.at(0).toFloat());
            ui->spinScrollgroovegrad5->setValue(scrollgroove_holder.at(1).toInt());
        } else {
            ui->checkScrollgroovegrad5->setChecked(false);
            ui->doubleScrollgroovegrad5->setEnabled(false);
            ui->spinScrollgroovegrad5->setEnabled(false);
        }

        // Page 11 Sliders
        ui->spinSlidersize->setValue(DSP::Settings::readInt(DSP::Settings::Slidersize));
        ui->spinSlidersize->setToolTip(DSP::Settings::description(DSP::Settings::Slidersize));
        ui->checkDot->setChecked(DSP::Settings::readBool(DSP::Settings::Sliderdot));
        ui->checkDot->setToolTip(DSP::Settings::description(DSP::Settings::Sliderdot));
        ui->checkMetal->setChecked(DSP::Settings::readBool(DSP::Settings::Slidermetal));
        ui->checkMetal->setToolTip(DSP::Settings::description(DSP::Settings::Slidermetal));
        ui->comboSlidegrooveshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Slidergrooveshadow));
        ui->comboSlidegrooveshadow->setToolTip(DSP::Settings::description(DSP::Settings::Slidergrooveshadow));
        ui->checkFill->setChecked(DSP::Settings::readBool(DSP::Settings::Sliderfillgroove));
        ui->checkFill->setToolTip(DSP::Settings::description(DSP::Settings::Sliderfillgroove));
        ui->comboSlidegroovestyle->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Sliderinvert));
        ui->comboSlidegroovestyle->setToolTip(DSP::Settings::description(DSP::Settings::Sliderinvert));

        // Gradient Slider
        QString slideGradientString = DSP::Settings::readString(DSP::Settings::Slidergrad);
        if (slideGradientString.isEmpty())
            slideGradientString = "0.0:0, 1.0:0";
        QStringList slideGradientList = slideGradientString.split(",");
        int slideGradientCounter = slideGradientList.count();
        QStringList slide_holder;

        if (slideGradientCounter > 0) {
            slide_holder = slideGradientList.at(0).split(":");
            ui->doubleSlidegrad1->setValue(slide_holder.at(0).toFloat());
            ui->spinSlidegrad1->setValue(slide_holder.at(1).toInt());
        }

        if (slideGradientCounter > 1) {
            slide_holder = slideGradientList.at(1).split(":");
            ui->doubleSlidegrad2->setValue(slide_holder.at(0).toFloat());
            ui->spinSlidegrad2->setValue(slide_holder.at(1).toInt());
        }

        if (slideGradientCounter > 2) {
            ui->checkSlidegrad3->setChecked(true);
            slide_holder = slideGradientList.at(2).split(":");
            ui->doubleSlidegrad3->setValue(slide_holder.at(0).toFloat());
            ui->spinSlidegrad3->setValue(slide_holder.at(1).toInt());
        } else {
            ui->checkSlidegrad3->setChecked(false);
            ui->doubleSlidegrad3->setEnabled(false);
            ui->spinSlidegrad3->setEnabled(false);
        }

        if (slideGradientCounter > 3) {
            ui->checkSlidegrad4->setChecked(true);
            slide_holder = slideGradientList.at(3).split(":");
            ui->doubleSlidegrad4->setValue(slide_holder.at(0).toFloat());
            ui->spinSlidegrad4->setValue(slide_holder.at(1).toInt());
        } else {
            ui->checkSlidegrad4->setChecked(false);
            ui->doubleSlidegrad4->setEnabled(false);
            ui->spinSlidegrad4->setEnabled(false);
        }

        if (slideGradientCounter > 4) {
            ui->checkSlidegrad5->setChecked(true);
            slide_holder = slideGradientList.at(4).split(":");
            ui->doubleSlidegrad5->setValue(slide_holder.at(0).toFloat());
            ui->spinSlidegrad5->setValue(slide_holder.at(1).toInt());
        } else {
            ui->checkSlidegrad5->setChecked(false);
            ui->doubleSlidegrad5->setEnabled(false);
            ui->spinSlidegrad5->setEnabled(false);
        }

        // Gradient SliderGroove
        QString slidegrooveGradientString = DSP::Settings::readString(DSP::Settings::Slidergroove);
        if (slidegrooveGradientString.isEmpty())
            slidegrooveGradientString = "0.0:0, 1.0:0";
        QStringList slidegrooveGradientList = slidegrooveGradientString.split(",");
        int slidegrooveGradientCounter = slidegrooveGradientList.count();
        QStringList slidegroove_holder;

        if (slidegrooveGradientCounter > 0) {
            slidegroove_holder = slidegrooveGradientList.at(0).split(":");
            ui->doubleSlidegroovegrad1->setValue(slidegroove_holder.at(0).toFloat());
            ui->spinSlidegroovegrad1->setValue(slidegroove_holder.at(1).toInt());
        }

        if (slidegrooveGradientCounter > 1) {
            slidegroove_holder = slidegrooveGradientList.at(1).split(":");
            ui->doubleSlidegroovegrad2->setValue(slidegroove_holder.at(0).toFloat());
            ui->spinSlidegroovegrad2->setValue(slidegroove_holder.at(1).toInt());
        }

        if (slidegrooveGradientCounter > 2) {
            ui->checkSlidegroovegrad3->setChecked(true);
            slidegroove_holder = slidegrooveGradientList.at(2).split(":");
            ui->doubleSlidegroovegrad3->setValue(slidegroove_holder.at(0).toFloat());
            ui->spinSlidegroovegrad3->setValue(slidegroove_holder.at(1).toInt());
        } else {
            ui->checkSlidegroovegrad3->setChecked(false);
            ui->doubleSlidegroovegrad3->setEnabled(false);
            ui->spinSlidegroovegrad3->setEnabled(false);
        }

        if (slidegrooveGradientCounter > 3) {
            ui->checkSlidegroovegrad4->setChecked(true);
            slidegroove_holder = slidegrooveGradientList.at(3).split(":");
            ui->doubleSlidegroovegrad4->setValue(slidegroove_holder.at(0).toFloat());
            ui->spinSlidegroovegrad4->setValue(slidegroove_holder.at(1).toInt());
        } else {
            ui->checkSlidegroovegrad4->setChecked(false);
            ui->doubleSlidegroovegrad4->setEnabled(false);
            ui->spinSlidegroovegrad4->setEnabled(false);
        }

        if (slidegrooveGradientCounter > 4) {
            ui->checkSlidegroovegrad5->setChecked(true);
            slidegroove_holder = slidegrooveGradientList.at(4).split(":");
            ui->doubleSlidegroovegrad5->setValue(slidegroove_holder.at(0).toFloat());
            ui->spinSlidegroovegrad5->setValue(slidegroove_holder.at(1).toInt());
        } else {
            ui->checkSlidegroovegrad5->setChecked(false);
            ui->doubleSlidegroovegrad5->setEnabled(false);
            ui->spinSlidegroovegrad5->setEnabled(false);
        }

        // Page 12 Progress Bars
        ui->spinProgrnd->setValue(DSP::Settings::readInt(DSP::Settings::Progrnd));
        ui->spinProgrnd->setToolTip(DSP::Settings::description(DSP::Settings::Progrnd));
        ui->comboProgshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Progshadow));
        ui->comboProgshadow->setToolTip(DSP::Settings::description(DSP::Settings::Progshadow));
        ui->checkProghover->setChecked(DSP::Settings::readBool(DSP::Settings::Progtxthover));
        ui->checkProghover->setToolTip(DSP::Settings::description(DSP::Settings::Progtxthover));
        ui->comboProgtextpos->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Progtxtpos));
        ui->comboProgtextpos->setToolTip(DSP::Settings::description(DSP::Settings::Progtxtpos));
        ui->spinProgstripe->setValue(DSP::Settings::readInt(DSP::Settings::Progstripe));
        ui->spinProgstripe->setToolTip(DSP::Settings::description(DSP::Settings::Progstripe));

        // Gradient Progress
        QString progGradientString = DSP::Settings::readString(DSP::Settings::Proggrad);
        if (progGradientString.isEmpty())
            progGradientString = "0.0:0, 1.0:0";
        QStringList progGradientList = progGradientString.split(",");
        int progGradientCounter = progGradientList.count();
        QStringList prog_holder;

        if (progGradientCounter > 0) {
            prog_holder = progGradientList.at(0).split(":");
            ui->doubleProggrad1->setValue(prog_holder.at(0).toFloat());
            ui->spinProggrad1->setValue(prog_holder.at(1).toInt());
        }

        if (progGradientCounter > 1) {
            prog_holder = progGradientList.at(1).split(":");
            ui->doubleProggrad2->setValue(prog_holder.at(0).toFloat());
            ui->spinProggrad2->setValue(prog_holder.at(1).toInt());
        }

        if (progGradientCounter > 2) {
            ui->checkProggrad3->setChecked(true);
            prog_holder = progGradientList.at(2).split(":");
            ui->doubleProggrad3->setValue(prog_holder.at(0).toFloat());
            ui->spinProggrad3->setValue(prog_holder.at(1).toInt());
        } else {
            ui->checkProggrad3->setChecked(false);
            ui->doubleProggrad3->setEnabled(false);
            ui->spinProggrad3->setEnabled(false);
        }

        if (progGradientCounter > 3) {
            ui->checkProggrad4->setChecked(true);
            prog_holder = progGradientList.at(3).split(":");
            ui->doubleProggrad4->setValue(prog_holder.at(0).toFloat());
            ui->spinProggrad4->setValue(prog_holder.at(1).toInt());
        } else {
            ui->checkProggrad4->setChecked(false);
            ui->doubleProggrad4->setEnabled(false);
            ui->spinProggrad4->setEnabled(false);
        }

        if (progGradientCounter > 4) {
            ui->checkProggrad5->setChecked(true);
            prog_holder = progGradientList.at(4).split(":");
            ui->doubleProggrad5->setValue(prog_holder.at(0).toFloat());
            ui->spinProggrad5->setValue(prog_holder.at(1).toInt());
        } else {
            ui->checkProggrad5->setChecked(false);
            ui->doubleProggrad5->setEnabled(false);
            ui->spinProggrad5->setEnabled(false);
        }

        //Page 13 Menus
        ui->checkMenuicon->setChecked(DSP::Settings::readBool(DSP::Settings::Menuicons));
        ui->checkMenuicon->setToolTip(DSP::Settings::description(DSP::Settings::Menuicons));
        ui->comboMenuitemshadow->setCurrentIndex(DSP::Settings::readInt(DSP::Settings::Menuitemshadow));
        ui->comboMenuitemshadow->setToolTip(DSP::Settings::description(DSP::Settings::Menuitemshadow));

        // Gradient Menu
        QString menuGradientString = DSP::Settings::readString(DSP::Settings::Menugrad);
        if (menuGradientString.isEmpty())
            menuGradientString = "0.0:0, 1.0:0";
        QStringList menuGradientList = menuGradientString.split(",");
        int menuGradientCounter = menuGradientList.count();
        QStringList menu_holder;

        if (menuGradientCounter > 0) {
            menu_holder = menuGradientList.at(0).split(":");
            ui->doubleMenugrad1->setValue(menu_holder.at(0).toFloat());
            ui->spinMenugrad1->setValue(menu_holder.at(1).toInt());
        }

        if (menuGradientCounter > 1) {
            menu_holder = menuGradientList.at(1).split(":");
            ui->doubleMenugrad2->setValue(menu_holder.at(0).toFloat());
            ui->spinMenugrad2->setValue(menu_holder.at(1).toInt());
        }

        if (menuGradientCounter > 2) {
            ui->checkMenugrad3->setChecked(true);
            menu_holder = menuGradientList.at(2).split(":");
            ui->doubleMenugrad3->setValue(menu_holder.at(0).toFloat());
            ui->spinMenugrad3->setValue(menu_holder.at(1).toInt());
        } else {
            ui->checkMenugrad3->setChecked(false);
            ui->doubleMenugrad3->setEnabled(false);
            ui->spinMenugrad3->setEnabled(false);
        }

        if (menuGradientCounter > 3) {
            ui->checkMenugrad4->setChecked(true);
            menu_holder = menuGradientList.at(3).split(":");
            ui->doubleMenugrad4->setValue(menu_holder.at(0).toFloat());
            ui->spinMenugrad4->setValue(menu_holder.at(1).toInt());
        } else {
            ui->checkMenugrad4->setChecked(false);
            ui->doubleMenugrad4->setEnabled(false);
            ui->spinMenugrad4->setEnabled(false);
        }

        if (menuGradientCounter > 4) {
            ui->checkMenugrad5->setChecked(true);
            menu_holder = menuGradientList.at(4).split(":");
            ui->doubleMenugrad5->setValue(menu_holder.at(0).toFloat());
            ui->spinMenugrad5->setValue(menu_holder.at(1).toInt());
        } else {
            ui->checkMenugrad5->setChecked(false);
            ui->doubleMenugrad5->setEnabled(false);
            ui->spinMenugrad5->setEnabled(false);
        }

        // Gradient Menu Item
        QString menuitemGradientString = DSP::Settings::readString(DSP::Settings::Menuitemgrad);
        if (menuitemGradientString.isEmpty())
            menuitemGradientString = "0.0:0, 1.0:0";
        QStringList menuitemGradientList = menuitemGradientString.split(",");
        int menuitemGradientCounter = menuitemGradientList.count();
        QStringList menuitem_holder;

        if (menuitemGradientCounter > 0) {
            menuitem_holder = menuitemGradientList.at(0).split(":");
            ui->doubleMenuitemgrad1->setValue(menuitem_holder.at(0).toFloat());
            ui->spinMenuitemgrad1->setValue(menuitem_holder.at(1).toInt());
        }

        if (menuitemGradientCounter > 1) {
            menuitem_holder = menuitemGradientList.at(1).split(":");
            ui->doubleMenuitemgrad2->setValue(menuitem_holder.at(0).toFloat());
            ui->spinMenuitemgrad2->setValue(menuitem_holder.at(1).toInt());
        }

        if (menuitemGradientCounter > 2) {
            ui->checkMenuitemgrad3->setChecked(true);
            menuitem_holder = menuitemGradientList.at(2).split(":");
            ui->doubleMenuitemgrad3->setValue(menuitem_holder.at(0).toFloat());
            ui->spinMenuitemgrad3->setValue(menuitem_holder.at(1).toInt());
        } else {
            ui->checkMenuitemgrad3->setChecked(false);
            ui->doubleMenuitemgrad3->setEnabled(false);
            ui->spinMenuitemgrad3->setEnabled(false);
        }

        if (menuitemGradientCounter > 3) {
            ui->checkMenuitemgrad4->setChecked(true);
            menuitem_holder = menuitemGradientList.at(3).split(":");
            ui->doubleMenuitemgrad4->setValue(menuitem_holder.at(0).toFloat());
            ui->spinMenuitemgrad4->setValue(menuitem_holder.at(1).toInt());
        } else {
            ui->checkMenuitemgrad4->setChecked(false);
            ui->doubleMenuitemgrad4->setEnabled(false);
            ui->spinMenuitemgrad4->setEnabled(false);
        }

        if (menuitemGradientCounter > 4) {
            ui->checkMenuitemgrad5->setChecked(true);
            menuitem_holder = menuitemGradientList.at(4).split(":");
            ui->doubleMenuitemgrad5->setValue(menuitem_holder.at(0).toFloat());
            ui->spinMenuitemgrad5->setValue(menuitem_holder.at(1).toInt());
        } else {
            ui->checkMenuitemgrad5->setChecked(false);
            ui->doubleMenuitemgrad5->setEnabled(false);
            ui->spinMenuitemgrad5->setEnabled(false);
        }

        // Page 14 Themes
        update_theme_listview();
}

void MainWindow::update_theme_listview()
{
    QList<QPair<QString, QString> > themeList = get_installed_themes();
    QString current_theme = get_current_theme();
    QStringList stringModel;
    QPair <QString, QString> tmp;
    foreach(tmp, themeList) {
        stringModel << tmp.second;
    }
    int q = stringModel.indexOf(QRegExp(current_theme));

    QStringListModel *model = new QStringListModel();
    model->setStringList(stringModel);
    ui->listInstalled->setModel(model);
    ui->listInstalled->setCurrentIndex(model->index(q));
}

void MainWindow::on_pushMincolour_clicked()
{
    QColor color;
    QColor initial;
    initial.setNamedColor(stringMincolor);
    color = QColorDialog::getColor(initial, 0, QString(), QColorDialog::ShowAlphaChannel);
    if(color.isValid()){
        stringMincolor = QString("#%1%2%3")
                .arg(color.red(), 2, 16, QChar('0'))
                .arg(color.green(), 2, 16, QChar('0'))
                .arg(color.blue(), 2, 16, QChar('0'));
        ui->pushMincolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                         .arg(stringMincolor));
    }
}

void MainWindow::on_pushMaxcolour_clicked()
{
    QColor color;
    QColor initial;
    initial.setNamedColor(stringMaxcolor);
    color = QColorDialog::getColor(initial, 0, QString(), QColorDialog::ShowAlphaChannel);
    if(color.isValid()){
        stringMaxcolor = QString("#%1%2%3")
                .arg(color.red(), 2, 16, QChar('0'))
                .arg(color.green(), 2, 16, QChar('0'))
                .arg(color.blue(), 2, 16, QChar('0'));
        ui->pushMaxcolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                         .arg(stringMaxcolor));
    }
}

void MainWindow::on_pushClosecolour_clicked()
{
    QColor color;
    QColor initial;
    initial.setNamedColor(stringClosecolor);
    color = QColorDialog::getColor(initial, 0, QString(), QColorDialog::ShowAlphaChannel);
    if(color.isValid()){
        stringClosecolor = QString("#%1%2%3")
                .arg(color.red(), 2, 16, QChar('0'))
                .arg(color.green(), 2, 16, QChar('0'))
                .arg(color.blue(), 2, 16, QChar('0'));
        ui->pushClosecolour->setStyleSheet(QString("QPushButton { background-color: %1; color: white; } ")
                                           .arg(stringClosecolor));
    }
}

void MainWindow::on_horizontalUnohue_valueChanged(int value)
{
    // Chicken & Egg situation
    //int strength = ui->horizontalUnostrength->value();
    //qDebug() << strength;
    QString holder = QString("QWidget { background-color: hsl(%1, 255, 128); }").arg(value);
    ui->widgetUnotint->setStyleSheet(holder);
}

void MainWindow::on_checkUno3_clicked(bool checked)
{
    if (checked) {
        ui->doubleUno3->setEnabled(true);
        ui->spinUno3->setEnabled(true);
    } else if (!ui->checkUno4->isChecked()) {
        ui->doubleUno3->setEnabled(false);
        ui->spinUno3->setEnabled(false);
    }
}

void MainWindow::on_checkUno4_clicked(bool checked)
{
    if (checked && ui->checkUno3->isChecked()) {
        ui->doubleUno4->setEnabled(true);
        ui->spinUno4->setEnabled(true);
    } else if (!ui->checkUno5->isChecked()) {
        ui->checkUno4->setChecked(false);
        ui->doubleUno4->setEnabled(false);
        ui->spinUno4->setEnabled(false);
    }
}


void MainWindow::on_checkUno5_clicked(bool checked)
{
    if (checked && ui->checkUno4->isChecked()) {
        ui->doubleUno5->setEnabled(true);
        ui->spinUno5->setEnabled(true);
    } else {
        ui->checkUno5->setChecked(false);
        ui->doubleUno5->setEnabled(false);
        ui->spinUno5->setEnabled(false);
    }
}

QString MainWindow::build_gradient_string_uno()
{
    QString stringFinal = QString::number(ui->doubleUno1->value()) + ":"
            + QString::number(ui->spinUno1->value()) + ","
            + QString::number(ui->doubleUno2->value()) + ":"
            + QString::number(ui->spinUno2->value());

    if (ui->checkUno3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleUno3->value()) + ":"
                + QString::number(ui->spinUno3->value());

    if (ui->checkUno4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleUno4->value()) + ":"
                + QString::number(ui->spinUno4->value());

    if (ui->checkUno5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleUno5->value()) + ":"
                + QString::number(ui->spinUno5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_tool()
{
    QString stringFinal = QString::number(ui->doubleToolgrad1->value()) + ":"
            + QString::number(ui->spinToolgrad1->value()) + ","
            + QString::number(ui->doubleToolgrad2->value()) + ":"
            + QString::number(ui->spinToolgrad2->value());

    if (ui->checkToolgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolgrad3->value()) + ":"
                + QString::number(ui->spinToolgrad3->value());

    if (ui->checkToolgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolgrad4->value()) + ":"
                + QString::number(ui->spinToolgrad4->value());

    if (ui->checkToolgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolgrad5->value()) + ":"
                + QString::number(ui->spinToolgrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_toolact()
{
    QString stringFinal = QString::number(ui->doubleToolact1->value()) + ":"
            + QString::number(ui->spinToolact1->value()) + ","
            + QString::number(ui->doubleToolact2->value()) + ":"
            + QString::number(ui->spinToolact2->value());

    if (ui->checkToolact3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolact3->value()) + ":"
                + QString::number(ui->spinToolact3->value());

    if (ui->checkToolact4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolact4->value()) + ":"
                + QString::number(ui->spinToolact4->value());

    if (ui->checkToolact5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleToolact5->value()) + ":"
                + QString::number(ui->spinToolact5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_push()
{
    QString stringFinal = QString::number(ui->doublePushgrad1->value()) + ":"
            + QString::number(ui->spinPushgrad1->value()) + ","
            + QString::number(ui->doublePushgrad2->value()) + ":"
            + QString::number(ui->spinPushgrad2->value());

    if (ui->checkPushgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doublePushgrad3->value()) + ":"
                + QString::number(ui->spinPushgrad3->value());

    if (ui->checkPushgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doublePushgrad4->value()) + ":"
                + QString::number(ui->spinPushgrad4->value());

    if (ui->checkPushgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doublePushgrad5->value()) + ":"
                + QString::number(ui->spinPushgrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_input()
{
    QString stringFinal = QString::number(ui->doubleInputgrad1->value()) + ":"
            + QString::number(ui->spinInputgrad1->value()) + ","
            + QString::number(ui->doubleInputgrad2->value()) + ":"
            + QString::number(ui->spinInputgrad2->value());

    if (ui->checkInputgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleInputgrad3->value()) + ":"
                + QString::number(ui->spinInputgrad3->value());

    if (ui->checkInputgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleInputgrad4->value()) + ":"
                + QString::number(ui->spinInputgrad4->value());

    if (ui->checkInputgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleInputgrad5->value()) + ":"
                + QString::number(ui->spinInputgrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_tab()
{
    QString stringFinal = QString::number(ui->doubleTabgrad1->value()) + ":"
            + QString::number(ui->spinTabgrad1->value()) + ","
            + QString::number(ui->doubleTabgrad2->value()) + ":"
            + QString::number(ui->spinTabgrad2->value());

    if (ui->checkTabgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabgrad3->value()) + ":"
                + QString::number(ui->spinTabgrad3->value());

    if (ui->checkTabgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabgrad4->value()) + ":"
                + QString::number(ui->spinTabgrad4->value());

    if (ui->checkTabgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabgrad5->value()) + ":"
                + QString::number(ui->spinTabgrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_tabbar()
{
    QString stringFinal = QString::number(ui->doubleTabbargrad1->value()) + ":"
            + QString::number(ui->spinTabbargrad1->value()) + ","
            + QString::number(ui->doubleTabbargrad2->value()) + ":"
            + QString::number(ui->spinTabbargrad2->value());

    if (ui->checkTabbargrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabbargrad3->value()) + ":"
                + QString::number(ui->spinTabbargrad3->value());

    if (ui->checkTabbargrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabbargrad4->value()) + ":"
                + QString::number(ui->spinTabbargrad4->value());

    if (ui->checkTabbargrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleTabbargrad5->value()) + ":"
                + QString::number(ui->spinTabbargrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_win()
{
    QString stringFinal = QString::number(ui->doubleWingrad1->value()) + ":"
            + QString::number(ui->spinWingrad1->value()) + ","
            + QString::number(ui->doubleWingrad2->value()) + ":"
            + QString::number(ui->spinWingrad2->value());

    if (ui->checkWingrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleWingrad3->value()) + ":"
                + QString::number(ui->spinWingrad3->value());

    if (ui->checkWingrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleWingrad4->value()) + ":"
                + QString::number(ui->spinWingrad4->value());

    if (ui->checkWingrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleWingrad5->value()) + ":"
                + QString::number(ui->spinWingrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_scroll()
{
    QString stringFinal = QString::number(ui->doubleScrollgrad1->value()) + ":"
            + QString::number(ui->spinScrollgrad1->value()) + ","
            + QString::number(ui->doubleScrollgrad2->value()) + ":"
            + QString::number(ui->spinScrollgrad2->value());

    if (ui->checkScrollgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgrad3->value()) + ":"
                + QString::number(ui->spinScrollgrad3->value());

    if (ui->checkScrollgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgrad4->value()) + ":"
                + QString::number(ui->spinScrollgrad4->value());

    if (ui->checkScrollgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgrad5->value()) + ":"
                + QString::number(ui->spinScrollgrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_scrollgroove()
{
    QString stringFinal = QString::number(ui->doubleScrollgroovegrad1->value()) + ":"
            + QString::number(ui->spinScrollgroovegrad1->value()) + ","
            + QString::number(ui->doubleScrollgroovegrad2->value()) + ":"
            + QString::number(ui->spinScrollgroovegrad2->value());

    if (ui->checkScrollgroovegrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgroovegrad3->value()) + ":"
                + QString::number(ui->spinScrollgroovegrad3->value());

    if (ui->checkScrollgroovegrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgroovegrad4->value()) + ":"
                + QString::number(ui->spinScrollgroovegrad4->value());

    if (ui->checkScrollgroovegrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleScrollgroovegrad5->value()) + ":"
                + QString::number(ui->spinScrollgroovegrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_slide()
{
    QString stringFinal = QString::number(ui->doubleSlidegrad1->value()) + ":"
            + QString::number(ui->spinSlidegrad1->value()) + ","
            + QString::number(ui->doubleSlidegrad2->value()) + ":"
            + QString::number(ui->spinSlidegrad2->value());

    if (ui->checkSlidegrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegrad3->value()) + ":"
                + QString::number(ui->spinSlidegrad3->value());

    if (ui->checkSlidegrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegrad4->value()) + ":"
                + QString::number(ui->spinSlidegrad4->value());

    if (ui->checkSlidegrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegrad5->value()) + ":"
                + QString::number(ui->spinSlidegrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_slidegroove()
{
    QString stringFinal = QString::number(ui->doubleSlidegroovegrad1->value()) + ":"
            + QString::number(ui->spinSlidegroovegrad1->value()) + ","
            + QString::number(ui->doubleSlidegroovegrad2->value()) + ":"
            + QString::number(ui->spinSlidegroovegrad2->value());

    if (ui->checkSlidegroovegrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegroovegrad3->value()) + ":"
                + QString::number(ui->spinSlidegroovegrad3->value());

    if (ui->checkSlidegroovegrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegroovegrad4->value()) + ":"
                + QString::number(ui->spinSlidegroovegrad4->value());

    if (ui->checkSlidegroovegrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleSlidegroovegrad5->value()) + ":"
                + QString::number(ui->spinSlidegroovegrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_progress()
{
    QString stringFinal = QString::number(ui->doubleProggrad1->value()) + ":"
            + QString::number(ui->spinProggrad1->value()) + ","
            + QString::number(ui->doubleProggrad2->value()) + ":"
            + QString::number(ui->spinProggrad2->value());

    if (ui->checkProggrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleProggrad3->value()) + ":"
                + QString::number(ui->spinProggrad3->value());

    if (ui->checkProggrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleProggrad4->value()) + ":"
                + QString::number(ui->spinProggrad4->value());

    if (ui->checkProggrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleProggrad5->value()) + ":"
                + QString::number(ui->spinProggrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_menu()
{
    QString stringFinal = QString::number(ui->doubleMenugrad1->value()) + ":"
            + QString::number(ui->spinMenugrad1->value()) + ","
            + QString::number(ui->doubleMenugrad2->value()) + ":"
            + QString::number(ui->spinMenugrad2->value());

    if (ui->checkMenugrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenugrad3->value()) + ":"
                + QString::number(ui->spinMenugrad3->value());

    if (ui->checkMenugrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenugrad4->value()) + ":"
                + QString::number(ui->spinMenugrad4->value());

    if (ui->checkMenugrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenugrad5->value()) + ":"
                + QString::number(ui->spinMenugrad5->value());

    return stringFinal;
}

QString MainWindow::build_gradient_string_menuitem()
{
    QString stringFinal = QString::number(ui->doubleMenuitemgrad1->value()) + ":"
            + QString::number(ui->spinMenuitemgrad1->value()) + ","
            + QString::number(ui->doubleMenuitemgrad2->value()) + ":"
            + QString::number(ui->spinMenuitemgrad2->value());

    if (ui->checkMenuitemgrad3->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenuitemgrad3->value()) + ":"
                + QString::number(ui->spinMenuitemgrad3->value());

    if (ui->checkMenuitemgrad4->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenuitemgrad4->value()) + ":"
                + QString::number(ui->spinMenuitemgrad4->value());

    if (ui->checkMenuitemgrad5->isChecked())
        stringFinal += ","
                + QString::number(ui->doubleMenuitemgrad5->value()) + ":"
                + QString::number(ui->spinMenuitemgrad5->value());

    return stringFinal;
}

void MainWindow::on_checkToolgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleToolgrad3->setEnabled(true);
        ui->spinToolgrad3->setEnabled(true);
    } else if (!ui->checkToolgrad4->isChecked()){
        ui->doubleToolgrad3->setEnabled(false);
        ui->spinToolgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkToolgrad4_clicked(bool checked)
{
    if (checked && ui->checkToolgrad3->isChecked()) {
        ui->doubleToolgrad4->setEnabled(true);
        ui->spinToolgrad4->setEnabled(true);
    } else if (!ui->checkToolgrad5->isChecked()){
        ui->doubleToolgrad4->setEnabled(false);
        ui->spinToolgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkToolgrad5_clicked(bool checked)
{
    if (checked && ui->checkToolgrad4->isChecked()) {
        ui->doubleToolgrad5->setEnabled(true);
        ui->spinToolgrad5->setEnabled(true);
    } else {
        ui->doubleToolgrad5->setEnabled(false);
        ui->spinToolgrad5->setEnabled(false);
    }
}

void MainWindow::on_checkToolact3_clicked(bool checked)
{
    if (checked) {
        ui->doubleToolact3->setEnabled(true);
        ui->spinToolact3->setEnabled(true);
    } else if (!ui->checkToolact4->isChecked()){
        ui->doubleToolact3->setEnabled(false);
        ui->spinToolact3->setEnabled(false);
    }
}

void MainWindow::on_checkToolact4_clicked(bool checked)
{
    if (checked && ui->checkToolact3->isChecked()) {
        ui->doubleToolact4->setEnabled(true);
        ui->spinToolact4->setEnabled(true);
    } else if (!ui->checkToolact5->isChecked()){
        ui->doubleToolact4->setEnabled(false);
        ui->spinToolact4->setEnabled(false);
    }
}

void MainWindow::on_checkToolact5_clicked(bool checked)
{
    if (checked && ui->checkToolact4->isChecked()) {
        ui->doubleToolact5->setEnabled(true);
        ui->spinToolact5->setEnabled(true);
    } else {
        ui->doubleToolact5->setEnabled(false);
        ui->spinToolact5->setEnabled(false);
    }
}

void MainWindow::on_comboUnonoisestyle_currentIndexChanged(int index)
{
    if (index != 0) {
        ui->lineNoisefile->setEnabled(false);
        ui->pushNoisefile->setEnabled(false);
    } else {
        ui->lineNoisefile->setEnabled(true);
        ui->pushNoisefile->setEnabled(true);
    }
}

void MainWindow::on_pushNoisefile_clicked()
{
    QString dirname = QString("%1/.local/share/data/dsp").arg(QDir::homePath());
    QDir dspdata(dirname);
    qDebug() << dspdata.exists() << "DEBUG";

    if (!dspdata.exists())
        dspdata.mkdir(dirname);

    QFileInfo fname(QFileDialog::getOpenFileName(this,
        tr("Open Image"), dirname, tr("Image Files (*.png)")));
    qDebug() << fname.fileName();
    ui->lineNoisefile->setText(fname.fileName());
}

void MainWindow::on_checkToolfollow_clicked(bool checked)
{
    if (checked)
        ui->checkToolmorph->setEnabled(true);
    else
        ui->checkToolmorph->setEnabled(false);
}

void MainWindow::on_checkPushgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doublePushgrad3->setEnabled(true);
        ui->spinPushgrad3->setEnabled(true);
    } else if (!ui->checkPushgrad4->isChecked()){
        ui->doublePushgrad3->setEnabled(false);
        ui->spinPushgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkPushgrad4_clicked(bool checked)
{
    if (checked && ui->checkPushgrad3->isChecked()) {
        ui->doublePushgrad4->setEnabled(true);
        ui->spinPushgrad4->setEnabled(true);
    } else if (!ui->checkPushgrad5->isChecked()){
        ui->doublePushgrad4->setEnabled(false);
        ui->spinPushgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkPushgrad5_clicked(bool checked)
{
    if (checked && ui->checkPushgrad4->isChecked()) {
        ui->doublePushgrad5->setEnabled(true);
        ui->spinPushgrad5->setEnabled(true);
    } else {
        ui->doublePushgrad5->setEnabled(false);
        ui->spinPushgrad5->setEnabled(false);
    }
}

void MainWindow::on_horizontalToolhue_valueChanged(int value)
{
    QString holder = QString("QWidget { background-color: hsl(%1, 255, 128); }").arg(value);
    ui->widgetToolhue->setStyleSheet(holder);
}



void MainWindow::on_horizontalPushhue_valueChanged(int value)
{
    QString holder = QString("QWidget { background-color: hsl(%1, 255, 128); }").arg(value);
    ui->widgetPush->setStyleSheet(holder);
}

void MainWindow::on_checkInputgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleInputgrad3->setEnabled(true);
        ui->spinInputgrad3->setEnabled(true);
    } else if (!ui->checkInputgrad4->isChecked()){
        ui->doubleInputgrad3->setEnabled(false);
        ui->spinInputgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkInputgrad4_clicked(bool checked)
{
    if (checked && ui->checkInputgrad3->isChecked()) {
        ui->doubleInputgrad4->setEnabled(true);
        ui->spinInputgrad4->setEnabled(true);
    } else if (!ui->checkInputgrad5->isChecked()){
        ui->doubleInputgrad4->setEnabled(false);
        ui->spinInputgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkInputgrad5_clicked(bool checked)
{
    if (checked && ui->checkInputgrad4->isChecked()) {
        ui->doubleInputgrad5->setEnabled(true);
        ui->spinInputgrad5->setEnabled(true);
    } else {
        ui->doubleInputgrad5->setEnabled(false);
        ui->spinInputgrad5->setEnabled(false);
    }
}


void MainWindow::on_horizontalInputhue_valueChanged(int value)
{
    QString holder = QString("QWidget { background-color: hsl(%1, 255, 128); }").arg(value);
    ui->widgetInput->setStyleSheet(holder);
}

void MainWindow::on_checkTabgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleTabgrad3->setEnabled(true);
        ui->spinTabgrad3->setEnabled(true);
    } else if (!ui->checkTabgrad4->isChecked()){
        ui->doubleTabgrad3->setEnabled(false);
        ui->spinTabgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkTabgrad4_clicked(bool checked)
{
    if (checked && ui->checkTabgrad3->isChecked()) {
        ui->doubleTabgrad4->setEnabled(true);
        ui->spinTabgrad4->setEnabled(true);
    } else if (!ui->checkTabgrad5->isChecked()){
        ui->doubleTabgrad4->setEnabled(false);
        ui->spinTabgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkTabgrad5_clicked(bool checked)
{
    if (checked && ui->checkTabgrad4->isChecked()) {
        ui->doubleTabgrad5->setEnabled(true);
        ui->spinTabgrad5->setEnabled(true);
    } else {
        ui->doubleTabgrad5->setEnabled(false);
        ui->spinTabgrad5->setEnabled(false);
    }
}

void MainWindow::on_checkTabbargrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleTabbargrad3->setEnabled(true);
        ui->spinTabbargrad3->setEnabled(true);
    } else if (!ui->checkTabbargrad4->isChecked()){
        ui->doubleTabbargrad3->setEnabled(false);
        ui->spinTabbargrad3->setEnabled(false);
    }
}

void MainWindow::on_checkTabbargrad4_clicked(bool checked)
{
    if (checked && ui->checkTabbargrad3->isChecked()) {
        ui->doubleTabbargrad4->setEnabled(true);
        ui->spinTabbargrad4->setEnabled(true);
    } else if (!ui->checkTabbargrad5->isChecked()){
        ui->doubleTabbargrad4->setEnabled(false);
        ui->spinTabbargrad4->setEnabled(false);
    }
}

void MainWindow::on_checkTabbargrad5_clicked(bool checked)
{
    if (checked && ui->checkTabbargrad4->isChecked()) {
        ui->doubleTabbargrad5->setEnabled(true);
        ui->spinTabbargrad5->setEnabled(true);
    } else {
        ui->doubleTabbargrad5->setEnabled(false);
        ui->spinTabbargrad5->setEnabled(false);
    }
}

void MainWindow::on_checkWingrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleWingrad3->setEnabled(true);
        ui->spinWingrad3->setEnabled(true);
    } else if (!ui->checkWingrad4->isChecked()){
        ui->doubleWingrad3->setEnabled(false);
        ui->spinWingrad3->setEnabled(false);
    }
}

void MainWindow::on_checkWingrad4_clicked(bool checked)
{
    if (checked && ui->checkWingrad3->isChecked()) {
        ui->doubleWingrad4->setEnabled(true);
        ui->spinWingrad4->setEnabled(true);
    } else if (!ui->checkWingrad5->isChecked()){
        ui->doubleWingrad4->setEnabled(false);
        ui->spinWingrad4->setEnabled(false);
    }
}

void MainWindow::on_checkWingrad5_clicked(bool checked)
{
    if (checked && ui->checkWingrad4->isChecked()) {
        ui->doubleWingrad5->setEnabled(true);
        ui->spinWingrad5->setEnabled(true);
    } else {
        ui->doubleWingrad5->setEnabled(false);
        ui->spinWingrad5->setEnabled(false);
    }
}

void MainWindow::on_pushWinfile_clicked()
{
    QString dirname = QString("%1/.local/share/data/dsp").arg(QDir::homePath());
    QDir dspdata(dirname);
    qDebug() << dspdata.exists() << "DEBUG";

    if (!dspdata.exists())
        dspdata.mkdir(dirname);

    QFileInfo fname(QFileDialog::getOpenFileName(this,
        tr("Open Image"), dirname, tr("Image Files (*.png)")));
    qDebug() << fname.fileName();
    ui->lineWinnoisefile->setText(fname.fileName());
}

void MainWindow::on_comboWinnoisestyle_currentIndexChanged(int index)
{
    if (index != 0) {
        ui->lineWinnoisefile->setEnabled(false);
        ui->pushWinfile->setEnabled(false);
    } else {
        ui->lineWinnoisefile->setEnabled(true);
        ui->pushWinfile->setEnabled(true);
    }
}

void MainWindow::on_checkScrollgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleScrollgrad3->setEnabled(true);
        ui->spinScrollgrad3->setEnabled(true);
    } else if (!ui->checkScrollgrad4->isChecked()){
        ui->doubleScrollgrad3->setEnabled(false);
        ui->spinScrollgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkScrollgrad4_clicked(bool checked)
{
    if (checked && ui->checkScrollgrad3->isChecked()) {
        ui->doubleScrollgrad4->setEnabled(true);
        ui->spinScrollgrad4->setEnabled(true);
    } else if (!ui->checkScrollgrad5->isChecked()){
        ui->doubleScrollgrad4->setEnabled(false);
        ui->spinScrollgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkScrollgrad5_clicked(bool checked)
{
    if (checked && ui->checkScrollgrad4->isChecked()) {
        ui->doubleScrollgrad5->setEnabled(true);
        ui->spinScrollgrad5->setEnabled(true);
    } else {
        ui->doubleScrollgrad5->setEnabled(false);
        ui->spinScrollgrad5->setEnabled(false);
    }
}

void MainWindow::on_checkScrollgroovegrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleScrollgroovegrad3->setEnabled(true);
        ui->spinScrollgroovegrad3->setEnabled(true);
    } else if (!ui->checkScrollgroovegrad4->isChecked()){
        ui->doubleScrollgroovegrad3->setEnabled(false);
        ui->spinScrollgroovegrad3->setEnabled(false);
    }
}

void MainWindow::on_checkScrollgroovegrad4_clicked(bool checked)
{
    if (checked && ui->checkScrollgroovegrad3->isChecked()) {
        ui->doubleScrollgroovegrad4->setEnabled(true);
        ui->spinScrollgroovegrad4->setEnabled(true);
    } else if (!ui->checkScrollgroovegrad5->isChecked()){
        ui->doubleScrollgroovegrad4->setEnabled(false);
        ui->spinScrollgroovegrad4->setEnabled(false);
    }
}

void MainWindow::on_checkScrollgroovegrad5_clicked(bool checked)
{
    if (checked && ui->checkScrollgroovegrad4->isChecked()) {
        ui->doubleScrollgroovegrad5->setEnabled(true);
        ui->spinScrollgroovegrad5->setEnabled(true);
    } else {
        ui->doubleScrollgroovegrad5->setEnabled(false);
        ui->spinScrollgroovegrad5->setEnabled(false);
    }
}

void MainWindow::on_radioYosemite_clicked(bool checked)
{
    if (checked) {
        ui->comboGroovestyle->setEnabled(false);
        ui->comboGrooveshadow->setEnabled(false);
        ui->labelGroovefill->setEnabled(false);
        ui->labelGrooveshadow->setEnabled(false);
    } else {
        ui->comboGroovestyle->setEnabled(true);
        ui->comboGrooveshadow->setEnabled(true);
        ui->labelGroovefill->setEnabled(true);
        ui->labelGrooveshadow->setEnabled(true);
    }
}

void MainWindow::on_radioNotyosemite_clicked(bool checked)
{
    if (checked) {
        ui->comboGroovestyle->setEnabled(true);
        ui->comboGrooveshadow->setEnabled(true);
        ui->labelGroovefill->setEnabled(true);
        ui->labelGrooveshadow->setEnabled(true);
    } else {
        ui->comboGroovestyle->setEnabled(false);
        ui->comboGrooveshadow->setEnabled(false);
        ui->labelGroovefill->setEnabled(false);
        ui->labelGrooveshadow->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleSlidegrad3->setEnabled(true);
        ui->spinSlidegrad3->setEnabled(true);
    } else if (!ui->checkSlidegrad4->isChecked()){
        ui->doubleSlidegrad3->setEnabled(false);
        ui->spinSlidegrad3->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegrad4_clicked(bool checked)
{
    if (checked && ui->checkSlidegrad3->isChecked()) {
        ui->doubleSlidegrad4->setEnabled(true);
        ui->spinSlidegrad4->setEnabled(true);
    } else if (!ui->checkSlidegrad5->isChecked()){
        ui->doubleSlidegrad4->setEnabled(false);
        ui->spinSlidegrad4->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegrad5_clicked(bool checked)
{
    if (checked && ui->checkSlidegrad4->isChecked()) {
        ui->doubleSlidegrad5->setEnabled(true);
        ui->spinSlidegrad5->setEnabled(true);
    } else {
        ui->doubleSlidegrad5->setEnabled(false);
        ui->spinSlidegrad5->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegroovegrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleSlidegroovegrad3->setEnabled(true);
        ui->spinSlidegroovegrad3->setEnabled(true);
    } else if (!ui->checkSlidegroovegrad4->isChecked()){
        ui->doubleSlidegroovegrad3->setEnabled(false);
        ui->spinSlidegroovegrad3->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegroovegrad4_clicked(bool checked)
{
    if (checked && ui->checkSlidegroovegrad3->isChecked()) {
        ui->doubleSlidegroovegrad4->setEnabled(true);
        ui->spinSlidegroovegrad4->setEnabled(true);
    } else if (!ui->checkSlidegroovegrad5->isChecked()){
        ui->doubleSlidegroovegrad4->setEnabled(false);
        ui->spinSlidegroovegrad4->setEnabled(false);
    }
}

void MainWindow::on_checkSlidegroovegrad5_clicked(bool checked)
{
    if (checked && ui->checkSlidegroovegrad4->isChecked()) {
        ui->doubleSlidegroovegrad5->setEnabled(true);
        ui->spinSlidegroovegrad5->setEnabled(true);
    } else {
        ui->doubleSlidegroovegrad5->setEnabled(false);
        ui->spinSlidegroovegrad5->setEnabled(false);
    }
}

void MainWindow::on_checkProggrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleProggrad3->setEnabled(true);
        ui->spinProggrad3->setEnabled(true);
    } else if (!ui->checkProggrad4->isChecked()){
        ui->doubleProggrad3->setEnabled(false);
        ui->spinProggrad3->setEnabled(false);
    }
}

void MainWindow::on_checkProggrad4_clicked(bool checked)
{
    if (checked && ui->checkProggrad3->isChecked()) {
        ui->doubleProggrad4->setEnabled(true);
        ui->spinProggrad4->setEnabled(true);
    } else if (!ui->checkProggrad5->isChecked()){
        ui->doubleProggrad4->setEnabled(false);
        ui->spinProggrad4->setEnabled(false);
    }
}

void MainWindow::on_checkProggrad5_clicked(bool checked)
{
    if (checked && ui->checkProggrad4->isChecked()) {
        ui->doubleProggrad5->setEnabled(true);
        ui->spinProggrad5->setEnabled(true);
    } else {
        ui->doubleProggrad5->setEnabled(false);
        ui->spinProggrad5->setEnabled(false);
    }
}

void MainWindow::on_checkMenugrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleMenugrad3->setEnabled(true);
        ui->spinMenugrad3->setEnabled(true);
    } else if (!ui->checkMenugrad4->isChecked()){
        ui->doubleMenugrad3->setEnabled(false);
        ui->spinMenugrad3->setEnabled(false);
    }
}

void MainWindow::on_checkMenugrad4_clicked(bool checked)
{
    if (checked && ui->checkMenugrad3->isChecked()) {
        ui->doubleMenugrad4->setEnabled(true);
        ui->spinMenugrad4->setEnabled(true);
    } else if (!ui->checkMenugrad5->isChecked()){
        ui->doubleMenugrad4->setEnabled(false);
        ui->spinMenugrad4->setEnabled(false);
    }
}

void MainWindow::on_checkMenugrad5_clicked(bool checked)
{
    if (checked && ui->checkMenugrad4->isChecked()) {
        ui->doubleMenugrad5->setEnabled(true);
        ui->spinMenugrad5->setEnabled(true);
    } else {
        ui->doubleMenugrad5->setEnabled(false);
        ui->spinMenugrad5->setEnabled(false);
    }
}

void MainWindow::on_checkMenuitemgrad3_clicked(bool checked)
{
    if (checked) {
        ui->doubleMenuitemgrad3->setEnabled(true);
        ui->spinMenuitemgrad3->setEnabled(true);
    } else if (!ui->checkMenuitemgrad4->isChecked()){
        ui->doubleMenuitemgrad3->setEnabled(false);
        ui->spinMenuitemgrad3->setEnabled(false);
    }
}

void MainWindow::on_checkMenuitemgrad4_clicked(bool checked)
{
    if (checked && ui->checkMenuitemgrad3->isChecked()) {
        ui->doubleMenuitemgrad4->setEnabled(true);
        ui->spinMenuitemgrad4->setEnabled(true);
    } else if (!ui->checkMenuitemgrad5->isChecked()){
        ui->doubleMenuitemgrad4->setEnabled(false);
        ui->spinMenuitemgrad4->setEnabled(false);
    }
}

void MainWindow::on_checkMenuitemgrad5_clicked(bool checked)
{
    if (checked && ui->checkMenuitemgrad4->isChecked()) {
        ui->doubleMenuitemgrad5->setEnabled(true);
        ui->spinMenuitemgrad5->setEnabled(true);
    } else {
        ui->doubleMenuitemgrad5->setEnabled(false);
        ui->spinMenuitemgrad5->setEnabled(false);
    }
}

void MainWindow::on_actionImport_Theme_triggered()
{
    ui->listWidget->setCurrentRow(13);
    do_import();
}

QList<QPair<QString, QString> > MainWindow::get_installed_themes()
{
    QList<QPair<QString, QString> > theme_holder;
    ThemeManager manager;
    theme_holder = manager.list_themes();
    return theme_holder;
}

QString MainWindow::get_current_theme()
{
    ThemeManager x;
    QString tmp = x.current_theme();
    return tmp;
}

void MainWindow::on_listInstalled_doubleClicked(const QModelIndex &index)
{
    QList<QPair<QString, QString> > themeList = get_installed_themes();
    QString selected_theme = themeList[index.row()].first;
    ThemeManager t;
    t.set_current(selected_theme);
}



void MainWindow::do_import()
{
    QString imp_name;
    imp_name = (QFileDialog::getOpenFileName(this,
        tr("Import DSP Config"), QDir::homePath(), tr("DSP Config (*.dspconf)")));

    if(imp_name.isEmpty())
            return;

    QSettings themeInfo(imp_name, QSettings::IniFormat);
    QString keyName = themeInfo.value("Theme/Name").toString();

    if(keyName.isEmpty()) {
       Dialog r;
       r.setTitle("Import Error");
       r.setData("This config has no theme information. I cannot import it.");
       r.exec();
       return;
    }

    ThemeManager t;
    if(t.import_theme(imp_name)) {
        qDebug() << "successful";
        update_theme_listview();
    } else {
        Dialog s;
        s.setTitle("Import Error");
        s.setData("Config already exists.");
        s.exec();
    }
}


void MainWindow::on_actionDefault_triggered()
{
    ThemeManager t;
    t.create_default();
    update_theme_listview();
}

void MainWindow::on_actionExport_Theme_triggered()
{
    ui->listWidget->setCurrentRow(13);
    ThemeManager t;
    QString x_name = t.export_theme_filename();
    QString save_me = QFileDialog::getExistingDirectory(this,
            tr("Export to"), QDir::homePath(),  QFileDialog::ShowDirsOnly);

    if(!save_me.isEmpty()){
        save_me += '/' + x_name;
        QString x = QString("%1/.local/share/dspconfig/themes/%2").arg(QDir::homePath())
                .arg(x_name);
        QFile y(x);
        if(!y.copy(save_me)){
            Dialog z;
            z.setTitle("Export Error");
            z.setData("Unable to export " + x_name);
            z.exec();
        }
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    ui->listWidget->setCurrentRow(13);
    QList<QPair<QString, QString> > themeList = get_installed_themes();
    QPair <QString, QString> tmp;
    QStringList file_name, theme_name;

    foreach(tmp, themeList) {
        file_name << tmp.first;
        theme_name << tmp.second;
    }

    InputDialog id;
    id.setTitle("Save as ...");
    id.setData("New theme name:");
    if(id.exec() == QDialog::Accepted){
        QString nn =id.getUserInput();

        if(theme_name.contains(nn)){
            Dialog g;
            g.setTitle("Duplicate Error");
            g.setData("A theme with this name already exists.");
            g.exec();
            return;
        }

        if(nn.isEmpty())
            return;

        ThemeManager t;
        t.do_Saveas(nn);

        update_theme_listview();
    }
}
