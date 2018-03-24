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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibDemo
{
public:
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalibDemo)
    {
        if (CalibDemo->objectName().isEmpty())
            CalibDemo->setObjectName(QStringLiteral("CalibDemo"));
        CalibDemo->resize(826, 670);
        action = new QAction(CalibDemo);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(CalibDemo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CalibDemo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalibDemo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 23));
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
        menu->setTitle(QApplication::translate("CalibDemo", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalibDemo: public Ui_CalibDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBDEMO_H
