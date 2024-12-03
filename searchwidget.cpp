#include "searchwidget.h"
#include "ui_searchwidget.h"
#include "widgetmanager.h"
#include "GlobalData.h"
#include <QLabel>
#include <QPushButton>
#include "Util_Search.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
SearchWidget::SearchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(GlobalData::Light);

    connect(ui->save, &QPushButton::clicked, this, &SearchWidget::onSave);
    connect(ui->load, &QPushButton::clicked, this, &SearchWidget::onLoad);
    connect(ui->backButton, &QPushButton::clicked, this, &SearchWidget::onBack);
    connect(ui->resetSize, &QPushButton::clicked, this, &SearchWidget::toResetMat);
    connect(ui->setState, &QPushButton::clicked, this, &SearchWidget::toSetState);
    connect(ui->diytext,&QCheckBox::checkStateChanged,this,&SearchWidget::toDiyText);

    ui->posEdit->setPlainText(Util_Search::getDirsText());
    ui->stateEdit->setPlainText(Util_Search::getStateText());
    ui->curStateMap->setText( Util_Search::getCurStateMapString());

    connect(ui->pos_yes, &QPushButton::clicked, this, &SearchWidget::onPosYes);
    connect(ui->pos_no, &QPushButton::clicked, this, &SearchWidget::onPosNo);
    connect(ui->state_yes, &QPushButton::clicked, this, &SearchWidget::onStateYes);
    connect(ui->state_no, &QPushButton::clicked, this, &SearchWidget::onStateNo);

}
void SearchWidget::onSave(){
    // 弹出文件选择对话框，让用户选择保存设置的文件路径
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Settings"), "", tr("Settings Files (*.ini)"));
    if (fileName.isEmpty()) return;

    QSettings settings(fileName, QSettings::IniFormat);
    QString posInfo = ui->posEdit->toPlainText();
    QString stateInfo = ui->stateEdit->toPlainText();
    int m = mat.length(),n=mat[0].length();
    settings.setValue("posInfo", posInfo);
    settings.setValue("stateInfo", stateInfo);
    settings.setValue("m", m);
    settings.setValue("n", n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            QString key = QString("button_%1_%2").arg(i).arg(j);
            settings.setValue(key, mat[i][j]->text());
        }
    }

    settings.setValue("key", "value");
    QMessageBox::information(this, tr("Success"), tr("保存成功"));
}
void SearchWidget::onLoad(){
    // 从文件加载参数
    QString fileName = QFileDialog::getOpenFileName(this, tr("Save Settings"), "", tr("Settings Files (*.ini)"));
    if (fileName.isEmpty()) return;

    QSettings settings(fileName, QSettings::IniFormat);
    QString posInfo = settings.value("posInfo").toString();
    QString stateInfo = settings.value("stateInfo").toString();

    Util_Search::setDirsText(posInfo);
    Util_Search::setStateText(stateInfo);
    ui->posEdit->setPlainText(posInfo);
    ui->stateEdit->setPlainText(stateInfo);
    int  m = settings.value("m").toInt(), n=settings.value("n").toInt();
    GlobalData::setMapSize(m,n);
    resetMat();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          QString key = QString("button_%1_%2").arg(i).arg(j);
          mat[i][j]->setText(settings.value(key).toString());
        }
    }
    QMessageBox::information(this, tr("Success"), tr("加载成功"));
}

void SearchWidget::onPosYes(){
    QString text=ui->posEdit->toPlainText();
    bool res = Util_Search::setDirsText(text);
    if(res)qDebug()<<"pos成功保存";
}
void SearchWidget::onPosNo(){
    ui->posEdit->setPlainText(Util_Search::getDirsText());
}

void SearchWidget::onStateYes(){
    QString text=ui->stateEdit->toPlainText();
    bool res =  Util_Search::setStateText(text);
    if(res){
        qDebug()<<"state成功保存";
        Util_Search::setAllState(mat);
    }
}
void SearchWidget::onStateNo(){
    ui->posEdit->setPlainText(Util_Search::getStateText());
}

void SearchWidget::onBack(){
    if(WidgetManager::show("开始")){
        this->hide();
    }
}
void SearchWidget::toSetState(){
    bool ok;
    QString state = QInputDialog::getText(this, tr("输入状态"), tr("状态:"),QLineEdit::Normal, "", &ok);
    if(!ok)return;
    Util_Search::setAllState(mat,state);
}
void SearchWidget::toDiyText(){
    Util_Search::diyTextMod=!Util_Search::diyTextMod;
}
void SearchWidget::toResetMat(){
    bool ok;
    int m = QInputDialog::getInt(this, tr("输入行数"), tr("行数:"), 0, 0, 1000, 1, &ok);
    if(!ok)return;
    int n = QInputDialog::getInt(this, tr("输入列数"),tr("列数:"), 0, 0, 1000, 1, &ok);
    if(!ok)return;
    GlobalData::setMapSize(m,n);
    resetMat();
}
void SearchWidget::resetMat(){
    Util_Search::clearMat(mat);
    int m = GlobalData::mapM, n=GlobalData::mapN;
    int widgetW=this->width(),widgetH=this->height();

    int buttonSize=50;
    int ox=150, oy=80;
    int offsetX=fmax(0,(widgetW-ox-n*buttonSize)/2),offsetY=fmax(0,(widgetH-oy-m*buttonSize)/2);


    mat = Util_Search::createMat(m,n,this);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j]->setGeometry(ox+offsetX+buttonSize*i,oy+offsetY+buttonSize*j,buttonSize,buttonSize);
            connect(mat[i][j], &QPushButton::clicked, [this,i, j]() {
                if(Util_Search::diyTextMod){
                    bool ok;
                    QString text = QInputDialog::getText(this, tr("设置该单元状态"), tr("状态:"), QLineEdit::Normal,  "", &ok);
                    if(!ok)return;
                    mat[i][j]->setText(text);
                }else{
                    Util_Search::onLightStep(mat, i, j);
                    QString curMapString =  Util_Search::getCurStateMapString();
                    ui->curStateMap->setText(curMapString);
                }
            });
        }
    }
}
void SearchWidget::showEvent(QShowEvent *event)  {
    resetMat();
}
SearchWidget::~SearchWidget(){
    delete ui;
}
