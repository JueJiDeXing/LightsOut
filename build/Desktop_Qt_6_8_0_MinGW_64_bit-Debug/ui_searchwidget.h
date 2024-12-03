/********************************************************************************
** Form generated from reading UI file 'searchwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWIDGET_H
#define UI_SEARCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchWidget
{
public:
    QPushButton *backButton;
    QPushButton *resetSize;
    QPushButton *setState;
    QPlainTextEdit *stateEdit;
    QPlainTextEdit *posEdit;
    QLabel *label;
    QPushButton *pos_yes;
    QPushButton *pos_no;
    QLabel *label_2;
    QPushButton *state_yes;
    QPushButton *state_no;
    QCheckBox *diytext;
    QLabel *label_3;
    QLabel *curStateMap;
    QPushButton *save;
    QPushButton *load;

    void setupUi(QWidget *SearchWidget)
    {
        if (SearchWidget->objectName().isEmpty())
            SearchWidget->setObjectName("SearchWidget");
        SearchWidget->resize(832, 829);
        backButton = new QPushButton(SearchWidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(20, 20, 41, 41));
        resetSize = new QPushButton(SearchWidget);
        resetSize->setObjectName("resetSize");
        resetSize->setGeometry(QRect(380, 30, 71, 28));
        setState = new QPushButton(SearchWidget);
        setState->setObjectName("setState");
        setState->setGeometry(QRect(490, 30, 111, 28));
        stateEdit = new QPlainTextEdit(SearchWidget);
        stateEdit->setObjectName("stateEdit");
        stateEdit->setGeometry(QRect(10, 350, 104, 181));
        posEdit = new QPlainTextEdit(SearchWidget);
        posEdit->setObjectName("posEdit");
        posEdit->setGeometry(QRect(10, 110, 104, 151));
        label = new QLabel(SearchWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 70, 111, 31));
        pos_yes = new QPushButton(SearchWidget);
        pos_yes->setObjectName("pos_yes");
        pos_yes->setGeometry(QRect(10, 270, 41, 41));
        pos_no = new QPushButton(SearchWidget);
        pos_no->setObjectName("pos_no");
        pos_no->setGeometry(QRect(70, 270, 41, 41));
        label_2 = new QLabel(SearchWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 320, 111, 31));
        state_yes = new QPushButton(SearchWidget);
        state_yes->setObjectName("state_yes");
        state_yes->setGeometry(QRect(10, 540, 41, 41));
        state_no = new QPushButton(SearchWidget);
        state_no->setObjectName("state_no");
        state_no->setGeometry(QRect(70, 540, 41, 41));
        diytext = new QCheckBox(SearchWidget);
        diytext->setObjectName("diytext");
        diytext->setGeometry(QRect(640, 30, 151, 25));
        label_3 = new QLabel(SearchWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 590, 111, 31));
        curStateMap = new QLabel(SearchWidget);
        curStateMap->setObjectName("curStateMap");
        curStateMap->setGeometry(QRect(10, 620, 101, 141));
        save = new QPushButton(SearchWidget);
        save->setObjectName("save");
        save->setGeometry(QRect(140, 30, 81, 28));
        load = new QPushButton(SearchWidget);
        load->setObjectName("load");
        load->setGeometry(QRect(260, 30, 81, 28));

        retranslateUi(SearchWidget);

        QMetaObject::connectSlotsByName(SearchWidget);
    } // setupUi

    void retranslateUi(QWidget *SearchWidget)
    {
        SearchWidget->setWindowTitle(QCoreApplication::translate("SearchWidget", "\347\206\204\347\201\257\346\270\270\346\210\217 - \346\216\242\347\264\242\346\250\241\345\274\217", nullptr));
        backButton->setText(QCoreApplication::translate("SearchWidget", "\350\277\224\345\233\236", nullptr));
        resetSize->setText(QCoreApplication::translate("SearchWidget", "\350\256\276\347\275\256\345\244\247\345\260\217", nullptr));
        setState->setText(QCoreApplication::translate("SearchWidget", "\350\256\276\347\275\256\345\205\250\344\275\223\347\212\266\346\200\201", nullptr));
        stateEdit->setPlainText(QString());
        posEdit->setPlainText(QString());
        label->setText(QCoreApplication::translate("SearchWidget", "\345\275\261\345\223\215\345\221\250\345\233\264\345\235\220\346\240\207:", nullptr));
        pos_yes->setText(QCoreApplication::translate("SearchWidget", "\347\241\256\345\256\232", nullptr));
        pos_no->setText(QCoreApplication::translate("SearchWidget", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("SearchWidget", "\347\212\266\346\200\201\350\275\254\347\247\273\346\200\273\350\241\250:", nullptr));
        state_yes->setText(QCoreApplication::translate("SearchWidget", "\347\241\256\345\256\232", nullptr));
        state_no->setText(QCoreApplication::translate("SearchWidget", "\345\217\226\346\266\210", nullptr));
        diytext->setText(QCoreApplication::translate("SearchWidget", "\350\207\252\345\256\232\344\271\211\345\215\225\345\205\203\346\240\274\347\212\266\346\200\201", nullptr));
        label_3->setText(QCoreApplication::translate("SearchWidget", "\345\275\223\345\211\215\347\212\266\346\200\201\350\275\254\347\247\273:", nullptr));
        curStateMap->setText(QString());
        save->setText(QCoreApplication::translate("SearchWidget", "\344\277\235\345\255\230\344\270\272\346\226\207\344\273\266", nullptr));
        load->setText(QCoreApplication::translate("SearchWidget", "\344\273\216\346\226\207\344\273\266\345\212\240\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchWidget: public Ui_SearchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWIDGET_H
