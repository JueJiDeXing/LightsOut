#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include<QVector>
#include<QPushButton>
#include <QPainter>
#include "GlobalData.h"
namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    void dialog();
    void resetMat();
    void onBack();
protected:
    void showEvent(QShowEvent *event) override;
private:
    QVector<QVector<QPushButton*>>mat;
    Ui::GameWidget *ui;
protected:
    void paintEvent(QPaintEvent *) override {// 渐变色背景
        QPainter painter(this);
        QLinearGradient gradient(0, 0, width(), height());
        gradient.setColorAt(0.0, GlobalData::color1);
        gradient.setColorAt(1.0, GlobalData::color2);
        painter.fillRect(rect(), gradient);
    }
};

#endif // GAMEWIDGET_H
