
#ifndef UTIL_H
#define UTIL_H
#include<QVector>
#include<QPushButton>
#include "GlobalData.h"
class Util{
public:
    static bool isOn(QPushButton*b){
        return b->icon().cacheKey()==GlobalData::LightOn.cacheKey();
    }
    static void setOn(QPushButton*b){
        return b->setIcon(GlobalData::LightOn);
    }
    static void setOff(QPushButton*b){
        return b->setIcon(GlobalData::LightOff);
    }
    static void changeState(QPushButton*b){
        if(isOn(b)){
            setOff(b);
        }else{
            setOn(b);
        }
    }
    static bool isValid(int i,int j,int m,int n){
        return 0<=i&&i<m&&0<=j&&j<n;
    }
    static bool isWin(QVector<QVector<QPushButton*>>&mat){
        for(auto row:mat){
            for(auto col:row){
                if(isOn(col))return false;
            }
        }
        return true;
    }

    static void onButtonClicked(QVector<QVector<QPushButton*>>&mat,int i,int j){
        int dirs[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};
        for(auto d:dirs){
            int nextI=i+d[0],nextJ=j+d[1];
            if(isValid(nextI,nextJ,GlobalData::mapM,GlobalData::mapN)){
                changeState(mat[nextI][nextJ]);
            }
        }
    }
    static void clearMat(QVector<QVector<QPushButton*>> &mat){
        for(auto line:mat){
            for(QPushButton* btn:line){
                btn->deleteLater();
            }
        }
    }
    static QVector<QVector<QPushButton*>> createMat(int m,int n,QWidget*widget){
        QVector<QVector<QPushButton*>> mat(m,QVector<QPushButton*>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = new QPushButton(widget);
                mat[i][j]->setIcon(GlobalData::LightOn);
                mat[i][j]->setIconSize(mat[i][j]->size());
                mat[i][j]->show();
            }
        }
        return mat;
    }
};
#endif // UTIL_H
