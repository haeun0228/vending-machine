#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbReset->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::checkChange(int drink){
    if(money<drink){
        return false;
    }
    else return true;
}



void Widget::incMoney(int button){
    money += button;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(checkChange(100));
    ui->pbMilk->setEnabled(checkChange(150));
    ui->pbTea->setEnabled(checkChange(200));
    ui->pbReset->setEnabled(money);
}

void Widget::on_pb10_clicked()
{
    incMoney(10);

}


void Widget::on_pb50_clicked()
{
    incMoney(50);
}


void Widget::on_pb100_clicked()
{
    incMoney(100);
}


void Widget::on_pb500_clicked()
{
    incMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    incMoney(-100);
}


void Widget::on_pbMilk_clicked()
{
    incMoney(-150);
}


void Widget::on_pbTea_clicked()
{
    incMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;

    int money500 = money / 500;
    int money100 = (money%500) / 100;
    int money50 = (money%500)%100 / 50;
    int money10 = ((money%500)%100)%50 / 10;

    QString s = QString("500won: %1 \n100won: %2 \n50won: %3 \n10won: %4").arg(money500).arg(money100).arg(money50).arg(money10);

    mb.information(this,"Change",s);
    incMoney(-money);
}

