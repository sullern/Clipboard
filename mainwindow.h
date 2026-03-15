#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QImage>
#include<QJsonObject>//序列化对象
#include<QStandardItemModel>
#include<QMimeData>//操作剪切板数据
#include<QClipboard>//剪切板类
#include<QUrl>
#include<QString>
#include<QJsonArray>
#include<QSettings>
#include"autorun.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct QClipboardItem
{
    QString type;
    QString time;
    QString content;
    QImage image;

    //序列化 反序列化
    QJsonObject tojson()const;
    static QClipboardItem fromjson(const QJsonObject& obj);
    //QClipboardItem() {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //清空记录
    void clearClip();
//初始化面板
    void initUI();
    //初始化快捷键
    void initShortcuts();
//加载本地存储
    void loadhistroy();
    //保存记录
    void save();
    //添加记录到列表
    void addItem(const QClipboardItem& item);
    //粘贴到当前窗口
    void paste(const QString& content,const QString& type);
    //显示/隐藏面板
    void hideui();
private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void Clipchange();
    void dbclick(const QModelIndex& index);//双击粘贴
    void on_checkBox_stateChanged(int arg1);//autorun
    //显示/隐藏面板
    void on_checkBox_2_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    bool m_isPanelVisible = false;    // 面板是否显示
    QStandardItemModel* QSItem_Model;//列表模型
    QList<QClipboardItem> M_ListItem;//存储数据信息
    QClipboard* M_clipbord;//系统剪切板
    void simulatePaste(const QString& content, const QString& type);//粘贴
    QSettings* m_setting;//本地设置
     const QString jianqieb="jianqieb";//应用名
    AutoRun* autorun;//自启动对象
};
#endif // MAINWINDOW_H
