#include "Util_Search.h"

QVector<QPair<int,int>>Util_Search::dirs;
QMap<QString,QQueue<QString>>Util_Search::stateMap;
QString Util_Search::dirText;
QString Util_Search::stateText;
QSettings* Util_Search::settings;
QString Util_Search::settingsFilePath = "setting.ini" ;
bool Util_Search::diyTextMod = false;
