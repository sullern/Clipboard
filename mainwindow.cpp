#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QClipboard>
#include<QBuffer>
#include<QAction>
#ifdef Q_OS_WIN32
#include <windows.h> // Windows模拟键盘事件
#include"autorun.h"
#include<QMessageBox>
#endif
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    //指向系统剪切板
    M_clipbord=QApplication::clipboard();
    m_setting = new QSettings("config.ini", QSettings::IniFormat, this);
    connect(M_clipbord, &QClipboard::dataChanged, this, &MainWindow::Clipchange);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//清除记录
void MainWindow::clearClip()
{
    if(QMessageBox::question(this,"清除记录","是否清除所有剪切板记录？")!=QMessageBox::Yes)
    {
        return;
    }
    M_ListItem.clear();
    QSItem_Model->clear();
    save();

}

//初始化视图
void MainWindow::initUI()
{
    QSItem_Model=new QStandardItemModel(this);
    ui->listView->setModel(QSItem_Model);
    ui->spinBox->setValue(20);//设置一个默认值
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//seting and list
    connect(ui->actionsetting,&QAction::triggered,this,[this](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->actionlist,&QAction::triggered,this,[this](){
        ui->stackedWidget->setCurrentIndex(1);
    });
     connect(ui->listView, &QListView::doubleClicked, this, &MainWindow::dbclick);
}

void MainWindow::loadhistroy()
{
    QJsonArray jsonarr=QJsonDocument::fromJson(m_setting->value("history").toByteArray()).array();
    for(const QJsonValue& qjsonv:jsonarr)
    {
        M_ListItem.append(QClipboardItem::fromjson(qjsonv.toObject()));
    }
    on_lineEdit_textChanged(ui->lineEdit->text());
}

void MainWindow::save()
{
    QJsonArray jsonarr;
    for(const QClipboardItem &item:M_ListItem)
    {
        jsonarr.append(item.tojson());
    }
    m_setting->setValue("history",QJsonDocument(jsonarr).toJson());
}

//添加记录到列表  set max
void MainWindow::addItem(const QClipboardItem &item)
{
    //去重
    bool rds=false;
    for(const QClipboardItem &tempItem:M_ListItem)
    {
        if(tempItem.type==item.type && tempItem.content==item.content)
        {
            rds=true;
            return;
        }
    }
    if(rds) return;

    M_ListItem.insert(0,item);

    //不大于最大的个数
    m_setting->setValue("maxlist",ui->spinBox->value());
    while(M_ListItem.size()>m_setting->value("maxlist",20).toInt())
    {
        M_ListItem.removeLast();//删除列表最后一个元素
    }
    //更新视图
    on_lineEdit_textChanged(ui->lineEdit->text());
}

void MainWindow::hideui()
{
    on_checkBox_2_stateChanged(m_isPanelVisible);
}

//搜索文本记录
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // 清空模型
    QSItem_Model->clear();
    QString reacthtext=arg1.trimmed();
    for(QClipboardItem& Item:M_ListItem)
    {
        if(reacthtext.isEmpty() || Item.content.contains(reacthtext,Qt::CaseInsensitive))
        {
    //创建一个列表项
            QStandardItem *listItem=new QStandardItem(Item.content);
    if(Item.type=="text")
            {
                listItem->setIcon(QIcon::fromTheme("text-plain"));
        QString showtext=Item.content.length()>50?Item.content.left(50)+"...":Item.content;
                listItem->setText(QString("[文本]%1|%2").arg(showtext).arg(Item.time));
    }
    else if(Item.type=="image")
    {
        listItem->setIcon(QIcon::fromTheme("image-x-generic"));
        listItem->setText(QString("[图片] 截图|%1").arg(Item.time));
        listItem->setData(QVariant::fromValue(Item.image),Qt::UserRole);
        }
    else if(Item.type=="file")
    {
        listItem->setIcon(QIcon::fromTheme("folder"));
        listItem->setText(QString("[文件] %1|%2").arg(Item.content).arg(Item.time));
    }
listItem->setData(QVariant::fromValue(Item),Qt::UserRole+1);
    QSItem_Model->appendRow(listItem);
    }
    }
}

void MainWindow::Clipchange()
{
    const QMimeData* mime=M_clipbord->mimeData();
    QClipboardItem item;
    item.time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    if(mime->hasUrls())
    {
        item.type = "file";
        QStringList path;//装文件的路径
        for (const QUrl& url : mime->urls())
        {
            path.append(url.toLocalFile());
        }
        item.content = path.join("; "); // 多个文件用分号分隔 转换为字符串只会就能显示了
    }
    else if(mime->hasImage())//想办法将二进制的图片数据转换为字符串存入
    {
        item.type = "image";
        //获取剪切板上的图片
        item.image=M_clipbord->image();
        //创建二进制数组去装图片数据
        QByteArray qba;
        //创建内存缓冲区
        QBuffer buffer(&qba);
        buffer.open(QIODeviceBase::WriteOnly);
        item.image.save(&buffer,"png");
        item.content = QString(qba.toBase64());
    }
    else if(mime->hasText())
    {
        item.type="text";
        item.content=M_clipbord->text().trimmed();
        if(item.content.isEmpty()) return;
    }
    else
    {
        return;
    }
    //将解析好的数据添加到列表
    addItem(item);
}

//操作剪切板


//双颊粘贴
void MainWindow::dbclick(const QModelIndex& index)
{
    if (!index.isValid()) {
        return;
    }
   QClipboardItem clipItem = QSItem_Model->data(index,Qt::UserRole+1).value<QClipboardItem>();
    simulatePaste(clipItem.content, clipItem.type);
  //  hide();
  // m_isPanelVisible = false;
}

//将数据放回剪切板
void MainWindow::simulatePaste(const QString &content, const QString &type)
{
    if(type=="text")
    {
        M_clipbord->setText(content);
    }
    else if(type=="image")
    {
        QByteArray data=QByteArray::fromBase64(content.toUtf8());
        QImage image;
        image.loadFromData(data);
        M_clipbord->setImage(image);
    }
    else if(type=="file")
    {
        QStringList paths = content.split("; ");
        QList<QUrl> urls;
        for (const QString& path : paths) {
            urls.append(QUrl::fromLocalFile(path));
        }
        QMimeData* mimeData = new QMimeData;
        mimeData->setUrls(urls);
        M_clipbord->setMimeData(mimeData);
    }

    // 2. 模拟Ctrl+V按键（Windows为例）
#ifdef Q_OS_WIN32
    // 确保当前窗口激活
    Sleep(100);
    // 按下Ctrl+V
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);
    // 释放Ctrl+V
    keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
#endif
}


QJsonObject QClipboardItem::tojson() const
{
    QJsonObject obj;
    obj["type"]=type;
    obj["content"]=content;
    obj["time"] = time;
    return obj;
}

QClipboardItem QClipboardItem::fromjson(const QJsonObject &obj)
{
    QClipboardItem Item;
    Item.type=obj["type"].toString();
    Item.content=obj["content"].toString();
    Item.time=obj["time"].toString();
    if(Item.type=="image" && !Item.content.isEmpty())
    {
        QByteArray data=QByteArray::fromBase64(Item.content.toUtf8());
        Item.image.loadFromData(data);
    }
}
//自启动
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        autorun->setAutoRun(jianqieb,autorun->getFilesPaths());
    }
    else if(arg1==Qt::Unchecked){
        autorun->CancelAutoRun(jianqieb);
    }
}

//隐藏
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        hide();
        m_isPanelVisible = false;
    }
    else if(arg1==Qt::Unchecked)
    {
        show();
        raise();
        activateWindow(); // 激活窗口，聚焦搜索框
        ui->lineEdit->setFocus();
        m_isPanelVisible = true;
    }
}

