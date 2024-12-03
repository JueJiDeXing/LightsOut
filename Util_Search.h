#ifndef UTIL_SEARCH_H
#define UTIL_SEARCH_H
#include <QVector>
#include <QPushButton>
#include "GlobalData.h"
#include <QString>
#include <QSettings>
#include <QFile>
#include <QPair>
#include <QQueue>
#include <QMessageBox>
class Util_Search{

public:
    static QSettings* settings;
    static QString settingsFilePath ;
    static QString dirText, stateText;

    static QVector<QPair<int,int>>dirs;
    static QMap<QString,QQueue<QString>>stateMap;
    static bool diyTextMod;
    static void checkSetting(){
        dirText="0,0\n0,1\n1,0\n0,-1\n-1,0";
        stateText="亮->灭\n灭->亮";
        settings=new QSettings(settingsFilePath, QSettings::IniFormat);
        if (!QFile::exists(settingsFilePath)) {
            qDebug() << "配置文件不存在，创建新的配置文件...";
            settings->setValue("dirs", dirText);
            settings->setValue("state", stateText);
            qDebug() << "已写入默认配置到 setting.ini";
        }else{
           dirText = settings->value("dirs").toString();
           stateText = settings->value("state").toString();
        }
        setDirsText(dirText);
        setStateText(stateText);
    }


    static bool setDirsText(QString text){
        QVector<QPair<int, int>> tempDirs;
        QStringList lines = text.split('\n', Qt::SkipEmptyParts);

        for (const QString& line : lines) {
            QStringList parts = line.split(',');
            if (parts.size() != 2) return false;

            bool ok1, ok2;
            int first = parts[0].trimmed().toInt(&ok1);
            int second = parts[1].trimmed().toInt(&ok2);
            if (!ok1 || !ok2) return false;
            tempDirs.append(qMakePair(first, second));
        }
        dirs = tempDirs;
        settings->setValue("dirs", text);
        return true;
    }

    static QString getDirsText(){
        return dirText;
    }

    static bool setStateText(QString text){
        QMap<QString, QQueue<QString>> tempStateMap;
        QStringList lines = text.split('\n', Qt::SkipEmptyParts);

        for (const QString& line : lines) {
            QStringList parts = line.split("->");
            if (parts.size() != 2) {
                QMessageBox::information(nullptr, "Information", "状态数不为2:"+line);
                return false;
            }
            QString key = parts[0].trimmed();
            QString value = parts[1].trimmed();
            if(key.isEmpty()||value.isEmpty()){
                QMessageBox::information(nullptr, "Information", "有空状态:"+line);
                return false;
            }
            QStringList values = value.split('|', Qt::SkipEmptyParts);
            for (const QString& val : values) {
                tempStateMap[key].push_back(val.trimmed());
            }
        }
        stateMap = tempStateMap;
        stateText=text;
        settings->setValue("state", text);
        return true;
    }

    static QString getStateText(){
        return stateText;
    }
    static void printMap(){
        for(auto key:stateMap.keys()){
            auto debug =qDebug();
            debug  <<key<<":{";
            for(auto v:stateMap[key]){
                debug<<v;
            }
            debug<<"}";
        }
        qDebug()<<"-----";
    }
    static void toNextState(QPushButton*b){
        QString curState=b->text();
        if(!stateMap.contains(curState)){
            qDebug()<<curState<<"不存在";
            return ;
        }
        auto q=stateMap[curState];
        if(q.empty()){
            qDebug()<<"队列空";
            return  ;
        }
        QString state = q.head();
        b->setText(state);
    }

    static bool isValid(int i,int j,int m,int n){
        return 0<=i&&i<m&&0<=j&&j<n;
    }

    static void setAllState(QVector<QVector<QPushButton*>>&mat ){
        setAllState(mat,stateMap.firstKey());
    }

    static void setAllState(QVector<QVector<QPushButton*>>&mat,QString state){
        for(auto row:mat){
            for(auto col:row){
                col->setText(state);
            }
        }
    }

    static void onLightStep(QVector<QVector<QPushButton*>>&mat,int i,int j){
        for(auto d:dirs){
            int nextI=i+d.first,nextJ=j+d.second;
            if(isValid(nextI,nextJ,GlobalData::mapM,GlobalData::mapN)){
                toNextState(mat[nextI][nextJ]);
            }
        }
        printMap();
        for(auto& queue:stateMap){
            if(!queue.empty()){
                queue.enqueue(queue.dequeue());
            }
        }
        printMap();
    }

    static QVector<QVector<QPushButton*>> createMat(int m,int n,QWidget*widget){
        QVector<QVector<QPushButton*>> mat(m,QVector<QPushButton*>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = new QPushButton(widget);
                mat[i][j]->setText(stateMap.firstKey());
                mat[i][j]->show();
            }
        }
        return mat;
    }
    static void clearMat(QVector<QVector<QPushButton*>> mat ){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]->deleteLater();
            }
        }
    }
    static QMap<QString,QString> getCurStateMap(){
        QMap<QString,QString> curMap;
        for(auto key:stateMap.keys()){
            auto queue = stateMap[key];
            if(queue.empty())continue;
            curMap[key]=queue.head();
        }
        return curMap;
    }
    static QString getCurStateMapString(){
        auto curMap =  getCurStateMap();
        QString curMapString="";
        for(auto key:curMap.keys()){
            curMapString += key+"->"+curMap[key]+"\n";
        }
        return curMapString;
    }
};
#endif // UTIL_SEARCH_H
