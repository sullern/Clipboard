#include "mainwindow.h"

#include <QApplication>
#include<QSystemTrayIcon>
#include<QMenu>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    MainWindow w;
    QSystemTrayIcon* sysIon=new QSystemTrayIcon(QIcon::fromTheme("edit-paste"),&w);
    QMenu* menw=new QMenu;
    menw->addAction("显示面板",&w,[&](){w.hideui();});
    menw->addAction("清除记录",&w,&MainWindow::clearClip);
    menw->addAction("退出", &a, &QApplication::quit);
    sysIon->setContextMenu(menw);
    sysIon->show();
    return a.exec();
}
