#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GlobalData.h"
#include "widgetmanager.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(GlobalData::Light);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::onStart_3_3);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::onStart_5_5);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::onStart_diy);
    connect(ui->pushButton_x,&QPushButton::clicked,this,&MainWindow::onStart_x);
}
void MainWindow::onStart_3_3(){
    GlobalData::setMapSize(3,3);
    if(WidgetManager::show("游戏")){
        this->hide();
    }
}
void MainWindow::onStart_5_5(){
    GlobalData::setMapSize(5,5);
    if(WidgetManager::show("游戏")){
        this->hide();
    }
}
void MainWindow::onStart_diy(){
    // 输入框
    bool ok;
    int m = QInputDialog::getInt(this, tr("输入行数"), tr("行数:"), 0, 0, 1000, 1, &ok);
    if(!ok)return;
    int n = QInputDialog::getInt(this, tr("输入列数"),tr("列数:"), 0, 0, 1000, 1, &ok);
    if(!ok)return;
    GlobalData::setMapSize(m,n);
    if(WidgetManager::show("游戏")){
        this->hide();
    }
}
void MainWindow::onStart_x(){
    GlobalData::setMapSize(3,3);
    if(WidgetManager::show("探索")){
        this->hide();
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
