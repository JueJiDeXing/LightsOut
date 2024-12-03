#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <QIcon>
#include <QPixmap>
#include <QSettings>
#include <QFile>
class GlobalData{
public:
    static int mapM,mapN;// m行,n列
    static QIcon LightOn,LightOff,Light;

    static void setMapSize(int m,int n){
        mapM=m;
        mapN=n;
    }
    static QColor color1,color2;

    static void loadQIcon(){
        LightOn = QIcon(":/qrc/LightOn.png");
        LightOff = QIcon(":/qrc/LightOff.png");
        Light = QIcon(":/qrc/Light.png");
    }

    static void loadBackGroundColor(){
        QString settingsFilePath="globaldata.ini";
        QSettings settings(settingsFilePath, QSettings::IniFormat);
        QString c1="#BA9BF9",c2= "#55DAE9" ;
        if (!QFile::exists(settingsFilePath)) {
            qDebug() << "配置文件不存在，创建新的配置文件...";
            settings.setValue("color1", c1);
            settings.setValue("color2",c2 );
            qDebug() << "已写入默认配置到 setting.ini";
        }else{
            c1 = settings.value("color1").toString();
            c2 = settings.value("color2").toString();
        }
        color1=QColor(c1);
        color2=QColor(c2);
    }

    static void loadSettings(){
        loadQIcon();
        loadBackGroundColor();
    }
};

#endif // GLOBALDATA_H
