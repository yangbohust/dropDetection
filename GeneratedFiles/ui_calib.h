/********************************************************************************
** Form generated from reading UI file 'calib.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIB_H
#define UI_CALIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calib
{
public:

    void setupUi(QWidget *Calib)
    {
        if (Calib->objectName().isEmpty())
            Calib->setObjectName(QStringLiteral("Calib"));
        Calib->resize(754, 573);

        retranslateUi(Calib);

        QMetaObject::connectSlotsByName(Calib);
    } // setupUi

    void retranslateUi(QWidget *Calib)
    {
        Calib->setWindowTitle(QApplication::translate("Calib", "Calib", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calib: public Ui_Calib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIB_H
