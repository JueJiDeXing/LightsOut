#include "widgetmanager.h"
#include <QMessageBox>
QMap<QString, QWidget *> WidgetManager::widgetMap;

WidgetManager::WidgetManager() {

}
void WidgetManager::addWidget(QString pageName,QWidget* widget){
    widgetMap[pageName] = widget;
}
bool WidgetManager::show(QString pageName){
    QWidget*w = get(pageName);
    if(w==nullptr) return false;

    qDebug()<<"展示"<<pageName;
    w ->show();
    return true;
}

bool WidgetManager::hide(QString pageName){
    QWidget*w = get(pageName);
    if(w==nullptr) return false;

    qDebug()<<"关闭"<<pageName;
    w ->hide();
    return true;
}
QWidget* WidgetManager::get(QString pageName){
    if(widgetMap.find(pageName)==widgetMap.end()) {
        qDebug()<<"页面 - "<<pageName<<" 不存在";
        return nullptr;
    }
    return widgetMap[pageName];
}
