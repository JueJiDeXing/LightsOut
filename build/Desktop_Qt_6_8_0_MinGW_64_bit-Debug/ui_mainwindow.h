/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_x;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(573, 690);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 150, 141, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans")});
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 260, 141, 51));
        pushButton_2->setFont(font);
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(180, 480, 141, 51));
        pushButton_x->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 370, 141, 51));
        pushButton_3->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 10, 181, 131));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\206\204\347\201\257\346\270\270\346\210\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\205\2703*3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\214\221\346\210\2305*5", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "\346\216\242\347\264\242\346\250\241\345\274\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\345\244\247\345\260\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\247\204\345\210\231:</p><p>\347\202\271\345\207\273\347\201\257\346\263\241\345\217\257\344\273\245\346\224\271\345\217\230\347\201\257\346\263\241\347\212\266\346\200\201</p><p>\344\275\206\346\230\257\347\233\270\351\202\273\347\232\204\347\201\257\346\263\241\344\271\237\344\274\232\345\220\214\346\227\266\346\224\271\345\217\230\347\212\266\346\200\201</p><p>\347\206\204\347\201\255\346\211\200\346\234\211\347\201\257\346\263\241\345\215\263\344\270\272\350\216\267\350\203\234</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
