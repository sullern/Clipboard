#include "autorun.h"

#include <QCoreApplication>

AutoRun::AutoRun(QWidget *parent)
    : QObject{parent}
{}

bool AutoRun::setAutoRun(const QString &appName, const QString &exePath)
{
//判断路径有没有问题
    QString realPath=exePath.isEmpty()?getFilesPaths():QString("\"%1\"").arg(exePath);
QSettings re("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    re.setValue(appName,realPath);
return re.contains(appName);
}

bool AutoRun::CancelAutoRun(const QString &appName)
{
    QSettings re("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    re.remove(appName);
    return !re.contains(appName);
}

QString AutoRun::getFilesPaths()
{
    QString exePath=QCoreApplication::applicationFilePath();
    return QString("\"%1\"").arg(exePath);
}
