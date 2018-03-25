/********************************************************************************
** Form generated from reading UI file 'calibdemo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBDEMO_H
#define UI_CALIBDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibDemo
{
public:
    QAction *action;
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalibDemo)
    {
        if (CalibDemo->objectName().isEmpty())
            CalibDemo->setObjectName(QStringLiteral("CalibDemo"));
        CalibDemo->resize(869, 674);
        action = new QAction(CalibDemo);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(CalibDemo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 421, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(430, 0, 51, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 0, 61, 21));
        label_2->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 0, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        pushButton->setFont(font1);
        CalibDemo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalibDemo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        CalibDemo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalibDemo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CalibDemo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalibDemo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CalibDemo->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(CalibDemo);

        QMetaObject::connectSlotsByName(CalibDemo);
    } // setupUi

    void retranslateUi(QMainWindow *CalibDemo)
    {
        CalibDemo->setWindowTitle(QApplication::translate("CalibDemo", "CalibDemo", Q_NULLPTR));
        action->setText(QApplication::translate("CalibDemo", "\346\211\223\345\274\200\346\240\207\345\256\232\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("CalibDemo", "\350\257\267\347\224\250\351\274\240\346\240\207\345\257\271\347\205\247\346\240\207\345\256\232\345\260\272\347\224\273\344\270\200\345\216\230\347\261\263\347\233\264\347\272\277\357\274\214\346\240\207\345\256\232\345\214\272\345\237\237\344\270\200\344\270\252\345\203\217\347\264\240\344\273\243\350\241\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("CalibDemo", "\346\257\253\347\261\263(mm)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CalibDemo", "\347\241\256\350\256\244\347\273\223\346\236\234", Q_NULLPTR));
        menu->setTitle(QApplication::translate("CalibDemo", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalibDemo: public Ui_CalibDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBDEMO_H
