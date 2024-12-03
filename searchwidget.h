#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include<QVector>
#include<QPushButton>
#include <QPainter>
#include "GlobalData.h"
namespace Ui {
class SearchWidget;
}

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWidget(QWidget *parent = nullptr);
    ~SearchWidget();

    void onBack();
    void resetMat();
    void onSave();
    void onLoad();
private slots:
    void toSetState();
    void toResetMat();
    void toDiyText();
    void onPosYes();
    void onPosNo();

    void onStateYes();
    void onStateNo();
protected:
    void showEvent(QShowEvent *event) override;
private:
    QVector<QVector<QPushButton*>>mat;
    Ui::SearchWidget *ui;
protected:
    void paintEvent(QPaintEvent *) override {// 渐变色背景
        QPainter painter(this);
        QLinearGradient gradient(0, 0, width(), height());
        gradient.setColorAt(0.0, GlobalData::color1);
        gradient.setColorAt(1.0, GlobalData::color2);
        painter.fillRect(rect(), gradient);
    }
};

#endif // SEARCHWIDGET_H
