/********************************************************************************
** Form generated from reading UI file 'video_test1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_TEST1_H
#define UI_VIDEO_TEST1_H

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

class Ui_video_test1Class
{
public:
    QAction *action;
    QAction *action_2;
    QAction *openCalib;
    QWidget *centralWidget;
    QPushButton *startCount;
    QLabel *cur_volume;
    QLabel *label_4;
    QLabel *count;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLabel *sum_volume;
    QLabel *label_5;
    QLabel *ROI_show;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_9;
    QPushButton *stopCount;
    QPushButton *clearPainter;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_ROI;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *video_test1Class)
    {
        if (video_test1Class->objectName().isEmpty())
            video_test1Class->setObjectName(QStringLiteral("video_test1Class"));
        video_test1Class->resize(997, 592);
        action = new QAction(video_test1Class);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(video_test1Class);
        action_2->setObjectName(QStringLiteral("action_2"));
        openCalib = new QAction(video_test1Class);
        openCalib->setObjectName(QStringLiteral("openCalib"));
        centralWidget = new QWidget(video_test1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startCount = new QPushButton(centralWidget);
        startCount->setObjectName(QStringLiteral("startCount"));
        startCount->setGeometry(QRect(720, 440, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        startCount->setFont(font);
        cur_volume = new QLabel(centralWidget);
        cur_volume->setObjectName(QStringLiteral("cur_volume"));
        cur_volume->setGeometry(QRect(820, 340, 61, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        cur_volume->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(890, 280, 51, 21));
        label_4->setFont(font);
        count = new QLabel(centralWidget);
        count->setObjectName(QStringLiteral("count"));
        count->setGeometry(QRect(820, 282, 61, 20));
        count->setFont(font1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(890, 380, 51, 21));
        label_6->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(730, 380, 81, 21));
        label_3->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(730, 340, 81, 21));
        label_2->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(760, 280, 51, 21));
        label->setFont(font);
        sum_volume = new QLabel(centralWidget);
        sum_volume->setObjectName(QStringLiteral("sum_volume"));
        sum_volume->setGeometry(QRect(820, 380, 51, 21));
        sum_volume->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(890, 340, 51, 21));
        label_5->setFont(font1);
        ROI_show = new QLabel(centralWidget);
        ROI_show->setObjectName(QStringLiteral("ROI_show"));
        ROI_show->setGeometry(QRect(780, 50, 91, 121));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(810, 20, 51, 21));
        label_7->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(700, 180, 151, 21));
        label_8->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(850, 180, 51, 20));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(910, 180, 31, 21));
        label_9->setFont(font);
        stopCount = new QPushButton(centralWidget);
        stopCount->setObjectName(QStringLiteral("stopCount"));
        stopCount->setGeometry(QRect(820, 440, 71, 31));
        stopCount->setFont(font);
        clearPainter = new QPushButton(centralWidget);
        clearPainter->setObjectName(QStringLiteral("clearPainter"));
        clearPainter->setGeometry(QRect(730, 230, 71, 31));
        clearPainter->setFont(font);
        video_test1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(video_test1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_ROI = new QMenu(menuBar);
        menu_ROI->setObjectName(QStringLiteral("menu_ROI"));
        video_test1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(video_test1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        video_test1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(video_test1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        video_test1Class->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_ROI->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_ROI->addAction(openCalib);

        retranslateUi(video_test1Class);

        QMetaObject::connectSlotsByName(video_test1Class);
    } // setupUi

    void retranslateUi(QMainWindow *video_test1Class)
    {
        video_test1Class->setWindowTitle(QApplication::translate("video_test1Class", "video_test1", Q_NULLPTR));
        action->setText(QApplication::translate("video_test1Class", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        action_2->setText(QApplication::translate("video_test1Class", "\344\277\235\345\255\230\350\256\260\345\275\225", Q_NULLPTR));
        openCalib->setText(QApplication::translate("video_test1Class", "\346\211\223\345\274\200\346\240\207\345\256\232\351\241\265", Q_NULLPTR));
        startCount->setText(QApplication::translate("video_test1Class", "\345\274\200\345\247\213\350\256\241\346\225\260", Q_NULLPTR));
        cur_volume->setText(QString());
        label_4->setText(QApplication::translate("video_test1Class", "\346\273\264", Q_NULLPTR));
        count->setText(QString());
        label_6->setText(QApplication::translate("video_test1Class", "ml", Q_NULLPTR));
        label_3->setText(QApplication::translate("video_test1Class", "\347\264\257\350\256\241\344\275\223\347\247\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("video_test1Class", "\345\275\223\345\211\215\344\275\223\347\247\257", Q_NULLPTR));
        label->setText(QApplication::translate("video_test1Class", "\350\256\241\346\225\260", Q_NULLPTR));
        sum_volume->setText(QString());
        label_5->setText(QApplication::translate("video_test1Class", "ml", Q_NULLPTR));
        ROI_show->setText(QString());
        label_7->setText(QApplication::translate("video_test1Class", "ROI", Q_NULLPTR));
        label_8->setText(QApplication::translate("video_test1Class", "ROI\344\270\200\344\270\252\345\203\217\347\264\240\345\256\275\345\272\246\347\272\246\344\270\272", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("video_test1Class", "1.17", Q_NULLPTR));
        label_9->setText(QApplication::translate("video_test1Class", "\346\257\253\347\261\263", Q_NULLPTR));
        stopCount->setText(QApplication::translate("video_test1Class", "\346\232\202\345\201\234\350\256\241\347\256\227", Q_NULLPTR));
        clearPainter->setText(QApplication::translate("video_test1Class", "\346\270\205\351\231\244", Q_NULLPTR));
        menu->setTitle(QApplication::translate("video_test1Class", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_ROI->setTitle(QApplication::translate("video_test1Class", "\346\240\207\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class video_test1Class: public Ui_video_test1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_TEST1_H
