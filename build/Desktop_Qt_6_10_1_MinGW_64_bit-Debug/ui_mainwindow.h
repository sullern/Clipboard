/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsetting;
    QAction *actionlist;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit;
    QListView *listView;
    QMenuBar *menubar;
    QMenu *menuseting;
    QMenu *menulist;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(488, 555);
        MainWindow->setStyleSheet(QString::fromUtf8("/* \345\205\250\345\261\200\345\237\272\347\241\200\346\240\267\345\274\217 - \344\273\205\347\224\250Qt\345\256\214\345\205\250\346\224\257\346\214\201\347\232\204\345\261\236\346\200\247 */\n"
"QWidget {\n"
"    font-family: \"Segoe UI\", Roboto, Arial, sans-serif;\n"
"    font-size: 13px;\n"
"    color: #24292f;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"/* \345\234\206\350\247\222\345\256\271\345\231\250 */\n"
"QWidget#widget {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #e1e4e8;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"/* \345\240\206\345\217\240\347\252\227\345\217\243 */\n"
"QStackedWidget {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* \346\240\207\347\255\276 */\n"
"QLabel {\n"
"    color: #24292f;\n"
"    background-color: transparent;\n"
"}\n"
"QLabel#label {\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"/* \346\225\260\345\255\227\350\276\223\345\205\245\346\241\206 - \347\247\273\351\231\244\346\211\200\346\234\211CSS3\345\261\236\346\200\247 *"
                        "/\n"
"QSpinBox {\n"
"    min-height: 32px;\n"
"    padding: 0 8px;\n"
"    border: 1px solid #d0d7de;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    selection-background-color: #0969da;\n"
"    selection-color: #ffffff;\n"
"}\n"
"QSpinBox:hover {\n"
"    border-color: #8c959f;\n"
"}\n"
"QSpinBox:focus {\n"
"    border-color: #0969da;\n"
"    /* \345\275\273\345\272\225\347\247\273\351\231\244box-shadow\357\274\214\347\224\250\345\217\214\345\261\202\350\276\271\346\241\206\346\250\241\346\213\237\351\253\230\345\205\211\357\274\210Qt\345\205\250\347\211\210\346\234\254\346\224\257\346\214\201\357\274\211 */\n"
"    border: 2px solid #0969da;\n"
"    padding: 0 7px; /* \346\212\265\346\266\210\350\276\271\346\241\206\345\212\240\345\256\275\347\232\204\351\227\264\350\267\235 */\n"
"}\n"
"/* SpinBox\344\270\212\344\270\213\347\256\255\345\244\264 */\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    width: 16px;\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
""
                        "QSpinBox::up-arrow {\n"
"    width: 8px;\n"
"    height: 8px;\n"
"}\n"
"QSpinBox::down-arrow {\n"
"    width: 8px;\n"
"    height: 8px;\n"
"}\n"
"\n"
"/* \345\244\215\351\200\211\346\241\206 */\n"
"QCheckBox {\n"
"    min-height: 32px;\n"
"    spacing: 8px;\n"
"    background-color: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border: 1px solid #d0d7de;\n"
"    border-radius: 3px;\n"
"    background-color: #ffffff;\n"
"}\n"
"QCheckBox::indicator:hover {\n"
"    border-color: #8c959f;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #0969da;\n"
"    border-color: #0969da;\n"
"}\n"
"QCheckBox:checked {\n"
"    color: #24292f;\n"
"}\n"
"\n"
"/* \345\215\225\350\241\214\350\276\223\345\205\245\346\241\206 - \347\247\273\351\231\244\346\211\200\346\234\211CSS3\345\261\236\346\200\247 */\n"
"QLineEdit {\n"
"    min-height: 32px;\n"
"    padding: 0 12px;\n"
"    border: 1px solid #d0d7de;\n"
"    border-radius: 6px;\n"
"    background-color: #fffff"
                        "f;\n"
"    selection-background-color: #0969da;\n"
"    selection-color: #ffffff;\n"
"}\n"
"QLineEdit:hover {\n"
"    border-color: #8c959f;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #0969da;\n"
"    /* \345\217\214\345\261\202\350\276\271\346\241\206\346\250\241\346\213\237\351\253\230\345\205\211\357\274\214\346\233\277\344\273\243box-shadow/outline */\n"
"    border: 2px solid #0969da;\n"
"    padding: 0 11px; /* \346\212\265\346\266\210\350\276\271\346\241\206\345\212\240\345\256\275 */\n"
"}\n"
"\n"
"/* \345\210\227\350\241\250\350\247\206\345\233\276 */\n"
"QListView {\n"
"    border: 1px solid #e1e4e8;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    outline: none;\n"
"    show-decoration-selected: 1;\n"
"}\n"
"QListView::item {\n"
"    padding: 8px 12px;\n"
"    border-bottom: 1px solid #f6f8fa;\n"
"}\n"
"QListView::item:hover {\n"
"    background-color: #f6f8fa;\n"
"}\n"
"QListView::item:selected {\n"
"    background-color: #0969da;\n"
"    color: #ffffff;\n"
"}\n"
"QList"
                        "View::item:selected:active {\n"
"    background-color: #0858c0;\n"
"}\n"
"\n"
"/* \345\210\227\350\241\250\346\273\232\345\212\250\346\235\241 */\n"
"QListView QScrollBar:vertical {\n"
"    width: 8px;\n"
"    background-color: transparent;\n"
"}\n"
"QListView QScrollBar::handle:vertical {\n"
"    background-color: #d0d7de;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QListView QScrollBar::handle:vertical:hover {\n"
"    background-color: #8c959f;\n"
"}\n"
"QListView QScrollBar::add-line:vertical, QListView QScrollBar::sub-line:vertical {\n"
"    height: 0;\n"
"}\n"
"\n"
"/* \345\270\203\345\261\200\345\256\271\345\231\250 */\n"
"QGridLayout, QVBoxLayout, QHBoxLayout {\n"
"    spacing: 8px;\n"
"    margin: 0;\n"
"}\n"
"QWidget#layoutWidget {\n"
"    background-color: transparent;\n"
"}"));
        actionsetting = new QAction(MainWindow);
        actionsetting->setObjectName("actionsetting");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        actionsetting->setIcon(icon);
        actionsetting->setMenuRole(QAction::MenuRole::NoRole);
        actionlist = new QAction(MainWindow);
        actionlist->setObjectName("actionlist");
        actionlist->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 169, 116));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName("spinBox");

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setChecked(false);

        gridLayout_4->addWidget(checkBox_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");

        gridLayout_3->addWidget(lineEdit, 0, 0, 1, 1);

        listView = new QListView(page_2);
        listView->setObjectName("listView");

        gridLayout_3->addWidget(listView, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 488, 22));
        menuseting = new QMenu(menubar);
        menuseting->setObjectName("menuseting");
        menulist = new QMenu(menubar);
        menulist->setObjectName("menulist");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuseting->menuAction());
        menubar->addAction(menulist->menuAction());
        menuseting->addAction(actionsetting);
        menulist->addAction(actionlist);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsetting->setText(QCoreApplication::translate("MainWindow", "setting", nullptr));
        actionlist->setText(QCoreApplication::translate("MainWindow", "list", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\255\230\345\202\250\346\235\241\346\225\260\357\274\232", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "AutoRun", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\351\232\220\350\227\217", nullptr));
        menuseting->setTitle(QCoreApplication::translate("MainWindow", "seting", nullptr));
        menulist->setTitle(QCoreApplication::translate("MainWindow", "list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
