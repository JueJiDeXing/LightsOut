/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QPushButton *backButton;
    QLabel *label;
    QLabel *stepCnt;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(554, 582);
        backButton = new QPushButton(GameWidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(20, 20, 41, 41));
        label = new QLabel(GameWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 30, 71, 19));
        stepCnt = new QLabel(GameWidget);
        stepCnt->setObjectName("stepCnt");
        stepCnt->setGeometry(QRect(470, 30, 71, 19));

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "\347\206\204\347\201\257\346\270\270\346\210\217", nullptr));
        backButton->setText(QCoreApplication::translate("GameWidget", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("GameWidget", "\344\275\277\347\224\250\346\255\245\346\225\260:", nullptr));
        stepCnt->setText(QCoreApplication::translate("GameWidget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
