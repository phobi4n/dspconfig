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
    void on_actionQuit_triggered();
    void on_actionDemo_triggered();
    void on_actionSave_triggered();
    void on_actionHide_menubar_triggered();

    void on_pushMincolour_clicked();
    void on_pushMaxcolour_clicked();
    void on_pushClosecolour_clicked();
    void on_horizontalUnohue_valueChanged(int value);
    void on_checkUno4_clicked(bool checked);
    void on_checkUno3_clicked(bool checked);
    void on_checkUno5_clicked(bool checked);
    void on_checkToolgrad3_clicked(bool checked);
    void on_checkToolgrad4_clicked(bool checked);
    void on_checkToolgrad5_clicked(bool checked);
    void on_checkToolact3_clicked(bool checked);
    void on_checkToolact4_clicked(bool checked);
    void on_checkToolact5_clicked(bool checked);
    void on_comboUnonoisestyle_currentIndexChanged(int index);
    void on_pushNoisefile_clicked();
    void on_checkToolfollow_clicked(bool checked);
    void on_checkPushgrad3_clicked(bool checked);
    void on_checkPushgrad4_clicked(bool checked);
    void on_checkPushgrad5_clicked(bool checked);
    void on_horizontalToolhue_valueChanged(int value);
    void on_horizontalPushhue_valueChanged(int value);
    void on_checkInputgrad3_clicked(bool checked);
    void on_checkInputgrad4_clicked(bool checked);
    void on_checkInputgrad5_clicked(bool checked);
    void on_horizontalInputhue_valueChanged(int value);
    void on_checkTabgrad3_clicked(bool checked);
    void on_checkTabgrad4_clicked(bool checked);
    void on_checkTabgrad5_clicked(bool checked);
    void on_checkTabbargrad3_clicked(bool checked);
    void on_checkTabbargrad4_clicked(bool checked);
    void on_checkTabbargrad5_clicked(bool checked);
    void on_checkWingrad3_clicked(bool checked);
    void on_checkWingrad4_clicked(bool checked);
    void on_checkWingrad5_clicked(bool checked);
    void on_pushWinfile_clicked();
    void on_comboWinnoisestyle_currentIndexChanged(int index);
    void on_checkScrollgrad3_clicked(bool checked);
    void on_checkScrollgrad4_clicked(bool checked);
    void on_checkScrollgrad5_clicked(bool checked);
    void on_checkScrollgroovegrad3_clicked(bool checked);
    void on_checkScrollgroovegrad4_clicked(bool checked);
    void on_checkScrollgroovegrad5_clicked(bool checked);
    void on_radioYosemite_clicked(bool checked);
    void on_radioNotyosemite_clicked(bool checked);
    void on_checkSlidegrad3_clicked(bool checked);
    void on_checkSlidegrad4_clicked(bool checked);
    void on_checkSlidegrad5_clicked(bool checked);
    void on_checkSlidegroovegrad3_clicked(bool checked);
    void on_checkSlidegroovegrad4_clicked(bool checked);
    void on_checkSlidegroovegrad5_clicked(bool checked);
    void on_checkProggrad3_clicked(bool checked);
    void on_checkProggrad4_clicked(bool checked);
    void on_checkProggrad5_clicked(bool checked);
    void on_checkMenugrad3_clicked(bool checked);
    void on_checkMenugrad4_clicked(bool checked);
    void on_checkMenugrad5_clicked(bool checked);
    void on_checkMenuitemgrad3_clicked(bool checked);
    void on_checkMenuitemgrad4_clicked(bool checked);
    void on_checkMenuitemgrad5_clicked(bool checked);
    void on_actionImport_Theme_triggered();
    void on_listInstalled_doubleClicked(const QModelIndex &index);


    void on_actionDefault_triggered();

    void on_actionExport_Theme_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    void populate();
    void write_config(QString);
    QString stringMincolor, stringMaxcolor, stringClosecolor;
    QString build_gradient_string_uno();
    QString build_gradient_string_tool();
    QString build_gradient_string_toolact();
    QString build_gradient_string_push();
    QString build_gradient_string_input();
    QString build_gradient_string_tab();
    QString build_gradient_string_tabbar();
    QString build_gradient_string_win();
    QString build_gradient_string_scroll();
    QString build_gradient_string_scrollgroove();
    QString build_gradient_string_slide();
    QString build_gradient_string_slidegroove();
    QString build_gradient_string_progress();
    QString build_gradient_string_menu();
    QString build_gradient_string_menuitem();
    QList<QPair<QString, QString> > get_installed_themes();
    QString get_current_theme();
    void update_theme_listview();
    void do_import();
};

#endif // MAINWINDOW_H
