#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "GlobalData.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onStart_3_3();
    void onStart_5_5();
    void onStart_diy();
    void onStart_x();
private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent *) override {// 渐变色背景
        QPainter painter(this);
        QLinearGradient gradient(0, 0, width(), height());
        gradient.setColorAt(0.0, GlobalData::color1);
        gradient.setColorAt(1.0, GlobalData::color2);
        painter.fillRect(rect(), gradient);
    }
};
#endif // MAINWINDOW_H
