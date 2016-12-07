#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H
#include <QList>
#include <QPair>
#include <QString>


class ThemeManager
{
public:
    ThemeManager();
    QList<QPair<QString, QString> > list_themes();
    QString current_theme();
    void set_current(QString);
    bool import_theme(QString importFile);
    QString export_theme_filename();
    bool create_default();
    void do_Saveas(QString new_theme);
};

#endif // THEMEMANAGER_H
