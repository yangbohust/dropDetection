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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_video_test1Class
{
public:
    QAction *action;
    QAction *action_2;
    QAction *openCalib;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *chooseROI;
    QPushButton *cleanPainter;
    QPushButton *startCount;
    QPushButton *stopCount;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *cur_volume;
    QLabel *sum_volume;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *count;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *ROI_show;
    QLabel *label_ROI;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_ROI;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *video_test1Class)
    {
        if (video_test1Class->objectName().isEmpty())
            video_test1Class->setObjectName(QStringLiteral("video_test1Class"));
        video_test1Class->resize(1018, 618);
        action = new QAction(video_test1Class);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(video_test1Class);
        action_2->setObjectName(QStringLiteral("action_2"));
        openCalib = new QAction(video_test1Class);
        openCalib->setObjectName(QStringLiteral("openCalib"));
        centralWidget = new QWidget(video_test1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(920, 390, 71, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_3->addWidget(label_6);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(770, 490, 162, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        chooseROI = new QPushButton(formLayoutWidget);
        chooseROI->setObjectName(QStringLiteral("chooseROI"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        chooseROI->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, chooseROI);

        cleanPainter = new QPushButton(formLayoutWidget);
        cleanPainter->setObjectName(QStringLiteral("cleanPainter"));
        cleanPainter->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, cleanPainter);

        startCount = new QPushButton(formLayoutWidget);
        startCount->setObjectName(QStringLiteral("startCount"));
        startCount->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, startCount);

        stopCount = new QPushButton(formLayoutWidget);
        stopCount->setObjectName(QStringLiteral("stopCount"));
        stopCount->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, stopCount);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(720, 210, 261, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout->addWidget(label_8);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        horizontalLayout->addWidget(label_9);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(800, 390, 101, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        cur_volume = new QLabel(verticalLayoutWidget_2);
        cur_volume->setObjectName(QStringLiteral("cur_volume"));
        cur_volume->setFont(font);

        verticalLayout_2->addWidget(cur_volume);

        sum_volume = new QLabel(verticalLayoutWidget_2);
        sum_volume->setObjectName(QStringLiteral("sum_volume"));
        sum_volume->setFont(font);

        verticalLayout_2->addWidget(sum_volume);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(700, 390, 91, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(700, 320, 291, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        count = new QLabel(horizontalLayoutWidget_2);
        count->setObjectName(QStringLiteral("count"));
        count->setFont(font);

        horizontalLayout_2->addWidget(count);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(830, 10, 51, 41));
        label_7->setFont(font);
        ROI_show = new QLabel(centralWidget);
        ROI_show->setObjectName(QStringLiteral("ROI_show"));
        ROI_show->setGeometry(QRect(780, 50, 131, 161));
        label_ROI = new QLabel(centralWidget);
        label_ROI->setObjectName(QStringLiteral("label_ROI"));
        label_ROI->setGeometry(QRect(720, 260, 291, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(10);
        label_ROI->setFont(font2);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 20, 631, 551));
        video_test1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(video_test1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1018, 23));
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
        label_5->setText(QApplication::translate("video_test1Class", "ml", Q_NULLPTR));
        label_6->setText(QApplication::translate("video_test1Class", "ml", Q_NULLPTR));
        chooseROI->setText(QApplication::translate("video_test1Class", "\351\200\211\345\217\226", Q_NULLPTR));
        cleanPainter->setText(QApplication::translate("video_test1Class", "\346\270\205\351\231\244", Q_NULLPTR));
        startCount->setText(QApplication::translate("video_test1Class", "\345\274\200\345\247\213", Q_NULLPTR));
        stopCount->setText(QApplication::translate("video_test1Class", "\346\232\202\345\201\234", Q_NULLPTR));
        label_8->setText(QApplication::translate("video_test1Class", "ROI\344\270\200\344\270\252\345\203\217\347\264\240\345\256\275\345\272\246\347\272\246\344\270\272", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("video_test1Class", "1.17", Q_NULLPTR));
        label_9->setText(QApplication::translate("video_test1Class", "\346\257\253\347\261\263", Q_NULLPTR));
        cur_volume->setText(QString());
        sum_volume->setText(QString());
        label_2->setText(QApplication::translate("video_test1Class", "\345\275\223\345\211\215\344\275\223\347\247\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("video_test1Class", "\347\264\257\350\256\241\344\275\223\347\247\257", Q_NULLPTR));
        label->setText(QApplication::translate("video_test1Class", "\350\256\241\346\225\260", Q_NULLPTR));
        count->setText(QString());
        label_4->setText(QApplication::translate("video_test1Class", "\346\273\264", Q_NULLPTR));
        label_7->setText(QApplication::translate("video_test1Class", "ROI", Q_NULLPTR));
        ROI_show->setText(QString());
        label_ROI->setText(QString());
        label_10->setText(QString());
        menu->setTitle(QApplication::translate("video_test1Class", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_ROI->setTitle(QApplication::translate("video_test1Class", "\346\240\207\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class video_test1Class: public Ui_video_test1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_TEST1_H
