#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QObject>
#include <QWidget>
#include <QMap>
class WidgetManager
{
public:
    WidgetManager();
    static void addWidget(QString pageName, QWidget*  widget);
    static bool show(QString pageName);
    static bool hide(QString pageName);
    static QWidget* get(QString pageName);
    static QMap<QString, QWidget *> widgetMap;
};

#endif // WIDGETMANAGER_H
