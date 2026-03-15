#ifndef AUTORUN_H
#define AUTORUN_H

#include <QMainWindow>
#include<QSettings>
class AutoRun : public QObject
{
    Q_OBJECT
public:
    explicit AutoRun(QWidget *parent = nullptr);
//开机自启
    bool setAutoRun(const QString &appName, const QString &exePath = "");
    //取消开机自启
    bool CancelAutoRun(const QString &appName);
    //获取文件路径
    QString getFilesPaths();
   // private:
    //AutoRun* autorun;
signals:
};

#endif // AUTORUN_H
