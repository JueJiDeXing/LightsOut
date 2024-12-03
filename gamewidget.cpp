#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "widgetmanager.h"
#include "GlobalData.h"
#include <QLabel>
#include <QPushButton>
#include "Util.h"
#include <QMessageBox>
GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(GlobalData::Light);
    connect(ui->backButton,&QPushButton::clicked,this,&GameWidget::onBack);
}
void GameWidget::resetMat(){
    int m = GlobalData::mapM, n=GlobalData::mapN;
    int ox = 50, oy = 50;
    int buttonSize = 50;
    int offsetX = fmax(0,(this->width()-ox-m*buttonSize)/2),offsetY=fmax(0,(this->height()-oy-n*buttonSize)/2);
    Util::clearMat(mat);
    mat = Util::createMat(m,n,this);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j]->setGeometry(ox+offsetX+buttonSize*i,oy+offsetY+buttonSize*j,buttonSize,buttonSize);
            connect(mat[i][j], &QPushButton::clicked, [this,i, j]() {
                Util::onButtonClicked(mat, i, j);
                ui->stepCnt->setText(QString::number(ui->stepCnt->text().toInt()+1));
                if(Util::isWin(mat))dialog();
            });
        }
    }
}
void GameWidget::onBack(){
    if(WidgetManager::show("开始")){
        this->hide();
    }
}
void GameWidget::dialog(){
    QMessageBox msgBox;
    msgBox.setText("成功熄灭所有灯泡");

    QPushButton *button1 = msgBox.addButton(tr("重新开始"), QMessageBox::ActionRole);
    QPushButton *button2 = msgBox.addButton(tr("返回主页"), QMessageBox::ActionRole);

    msgBox.exec();
    if (msgBox.clickedButton() == button1) {
        resetMat();
    } else if (msgBox.clickedButton() == button2) {
        onBack();
    }
    ui->stepCnt->setText("0");
}
void GameWidget::showEvent(QShowEvent *event) {
    ui->stepCnt->setText("0");
    resetMat();
}
GameWidget::~GameWidget()
{
    delete ui;
}
