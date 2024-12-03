#include "mainwindow.h"
#include <QSettings>
#include <QFile>
#include <QApplication>
#include "widgetmanager.h"
#include "gamewidget.h"
#include "searchwidget.h"
#include "GlobalData.h"
#include "Util_Search.h"
#include <QFont>
void addWidget(){
    MainWindow *mainWidget=new MainWindow();
    GameWidget*gameWidget=new GameWidget();
    SearchWidget*searchWidget=new SearchWidget();

    WidgetManager::addWidget("开始",mainWidget);
    WidgetManager::addWidget("游戏",gameWidget);
    WidgetManager::addWidget("探索",searchWidget);


}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 加载设置项
    GlobalData::loadSettings();
    Util_Search::checkSetting();
    // 页面切换
    addWidget();
    // 正式启动
    WidgetManager::show("开始");
    return a.exec();
}
