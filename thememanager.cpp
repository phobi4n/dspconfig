#include "thememanager.h"
#include "mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QDir>
#include <QSettings>
#include <QPair>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

ThemeManager::ThemeManager()
{
    return;
}

QList<QPair<QString, QString> > ThemeManager::list_themes()
{
    QList<QPair<QString, QString> > list;
    QString dirName = QString("%1/.local/share/dspconfig/themes").arg(QDir::homePath());
    QDir themeDirectory(dirName);

    if (!themeDirectory.exists()) {
        themeDirectory.mkpath(dirName);
        return list;
    }

    themeDirectory.setNameFilters(QStringList("*.dspconf"));
    QStringList fileList = themeDirectory.entryList();

    for(int i = 0; i < fileList.size(); i++) {
        QString fullFilename = dirName + "/" + fileList[i];
        QSettings themeInfo(fullFilename, QSettings::IniFormat);
        QString keyName = themeInfo.value("Theme/Name").toString();

        if(!keyName.isEmpty())
        list.append(qMakePair(fullFilename, keyName));
    }

    return list;
}

QString ThemeManager::current_theme()
{
    QString current;
    QString dsp_config = QString("%1/.config/dsp/dsp.conf").arg(QDir::homePath());
    QFile file(dsp_config);
    bool results = true;

    if(!file.exists()){
        results = create_default();
    } else {
        QFileInfo qinf(dsp_config);
        if(!qinf.isSymLink()) {
            QString dsp_backup = QString("%1/.config/dsp/dsp_original.conf").arg(QDir::homePath());
            file.rename(dsp_backup);

            Dialog q;
            q.setData("A current config was found. It has been saved as dsp_original.conf");
            q.setTitle("Backup Warning");
            q.exec();

            results = create_default();
        }
    }
    QSettings themeInfo(dsp_config, QSettings::IniFormat);
    QString keyName = themeInfo.value("Theme/Name").toString();

    if(keyName.isEmpty()){
        qDebug() << "Empty Key";
        return keyName;
    }
    qDebug() << results;
    return keyName;
}

void ThemeManager::set_current(QString chosen)
{
    //qDebug() << chosen;
    QString dsp_config = QString("%1/.config/dsp/dsp.conf").arg(QDir::homePath());
    QFileInfo qinf(dsp_config);

    if(!qinf.isSymLink()) {
        Dialog q;
        q.setData("The current dsp.conf is not managed by me. I will not overwrite it.");
        q.exec();
        return;
    }

    QFile f(dsp_config);
    if(!f.remove()){
        qDebug() << "Couldn't remove dsp.conf";
        return;
    }

    QFile g(chosen);
    g.link(dsp_config);
}

bool ThemeManager::import_theme(QString importFile)
{
    QStringList basename = importFile.split("/");
    QString destination = QString("%1/.local/share/dspconfig/themes/%2")
            .arg(QDir::homePath()).arg(basename.value(basename.length() - 1));
    QFile qf(importFile);
    qDebug() << destination;
    return qf.copy(destination);
}

QString ThemeManager::export_theme_filename()
{
    QString dsp_config = QString("%1/.config/dsp/dsp.conf").arg(QDir::homePath());
    QFile dsp(dsp_config);
    QFileInfo info(dsp.symLinkTarget());
    return info.fileName();
}


bool ThemeManager::create_default()
{
    Dialog def;
    def.setTitle("Default Config");
    def.setData("Writing default configuration.");
    def.exec();

    QString default_config = QString("%1/.local/share/dspconfig/themes/default.dspconf").arg(QDir::homePath());
    QFile qf(default_config);
    bool outcome = true;

    if(qf.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&qf);
        out << R"([Theme]
Name=Default

[General]
animatescroll=false
animatestack=false
balloontips=false
blacklist=smplayer
compactmenu=false
deco.buttons=0
deco.closecolor=#F98862
deco.embedded=false
deco.framesize=0
deco.icon=true
deco.maxcolor=#88EB51
deco.mincolor=#FFC05E
deco.shadowsize=32
differentinactive=false
hackdialogs=false
input.gradient="0.0:-5, 1.0:5"
input.inunornd=8
input.rnd=8
input.shadow=3
input.tinthue=-1:0
lockdocks=false
maxarrowsize=9
menues.gradient="0:5, 1:-5"
menues.icons=false
menues.itemgradient="0.0:5, 1.0:-5"
menues.itemshadow=0
opacity=100
palette=
progressbars.gradient="0:5, 1:-5"
progressbars.rnd=4
progressbars.shadow=3
progressbars.stripesize=32
progressbars.textonlyonhover=false
progressbars.textpos=0
pushbtn.gradient="0.0:5, 1.0:-5"
pushbtn.rnd=8
pushbtn.shadow=3
pushbtn.tinthue=-1:0
removetitlebars=false
scrollers.groovegradient="0.0:5, 0.5:-5, 1.0:5"
scrollers.grooveshadow=0
scrollers.groovestyle=0
scrollers.size=12
scrollers.slidergradient="0.0:5, 1.0:-5"
scrollers.style=0
shadows.darkraisededges=false
shadows.illuminationopacity=33
shadows.ontextopacity=50
shadows.opacity=33
simplearrows=true
sliders.dot=true
sliders.fillgroove=false
sliders.groovegradient="0.0:-5, 1.0:5"
sliders.grooveshadow=0
sliders.groovestyle=0
sliders.metallic=false
sliders.size=16
sliders.slidergradient="0.0:5, 1.0:-5"
splitterext=false
tabs.bargrad="0.0:-5, 1.0:5"
tabs.closebuttonside=0
tabs.closerrnd=16
tabs.docstyle=0
tabs.docwidth=0
tabs.gradient="0.0:5, 1.0:-5"
tabs.invertDocumode=false
tabs.rnd=4
tabs.safari=true
tabs.safrnd=4
tabs.selectors=true
tabs.shadow=3
titlepos=1
toolbtn.activegradient="0.0:-5, 1.0:5"
toolbtn.flat=false
toolbtn.followcolors=false
toolbtn.gradient="0.0:5, 1.0:-5"
toolbtn.invertactive=false
toolbtn.mask=true
toolbtn.morph=true
toolbtn.normal=false
toolbtn.rnd=8
toolbtn.shadow=3
toolbtn.tinthue=-1:0
uno=true
uno.contentaware=@Invalid()
uno.contentblurradius=2
uno.contentopacity=10
uno.gradient="0.0:5, 1.0:-5"
uno.horizontal=false
uno.noisefactor=5
uno.noisefile=
uno.noisestyle=0
uno.tinthue=-1:0
views.headergradient="0:5, 1:-5"
views.itemgradient="0:5, 1:-5"
views.itemrnd=6
views.itemshadow=0
views.opacity=255
views.treelines=true
windows.gradient="0.0:-10, 0.5:10, 1.0:-10"
windows.horizontal=true
windows.noisefactor=0
windows.noisefile=
windows.noisestyle=0)";
        qf.close();
        QString dsp_config = QString("%1/.config/dsp/dsp.conf").arg(QDir::homePath());
        QFile g(default_config);
        QFile h(dsp_config);

        if(h.exists())
            h.remove();

        h.close();
        g.link(dsp_config);
    } else {
        outcome = false;
        Dialog qpq;
        qpq.setTitle("Error");
        qpq.setData("Unable to write a default configuration.");
        qpq.exec();
    }

    return outcome;
}

void ThemeManager::do_Saveas(QString new_name)
{
    QString dsp_config = QString("%1/.config/dsp/dsp.conf").arg(QDir::homePath());
    QFile dsp(dsp_config);
    QFileInfo info(dsp.symLinkTarget());

    QString original_theme = QString("%1/.local/share/dspconfig/themes/%2").arg(QDir::homePath())
            .arg(info.fileName());
    QString new_theme = QString("%1/.local/share/dspconfig/themes/%2.dspconf").arg(QDir::homePath()).arg(new_name);

    QFile qq(original_theme);
    if(!qq.copy(new_theme)){
        Dialog p;
        p.setTitle("Copy Error");
        p.setData("Unable to save new theme.");
        p.exec();
        return;
    }

    QSettings qs(new_theme, QSettings::IniFormat);
    qs.setValue("Theme/Name", new_name);
}
