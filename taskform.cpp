#include "taskform.h"
#include "ui_taskform.h"

taskForm::taskForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::taskForm)
{
    ui->setupUi(this);
}

taskForm::~taskForm()
{
    delete ui;
}

void taskForm::taskInfo(int id,QString name,int grade,int studyTime,int breakTime)
{
    //ui->idlabel->setText(QString::number(id));
    this->id=id;
    ui->namelabel->setText(name);
    ui->gradelabel->setText(QString::number(grade));
    ui->studylabel->setText(QString::number(studyTime));
    ui->breaklabel->setText(QString::number(breakTime));
}

void taskForm::on_deleteBtn_clicked()
{
    QSqlQuery query;

    QString id=QString::number(this->id);
    QString sqlDe=QString("delete from task where id=%1;").arg(id.toInt());
    if(!query.exec(sqlDe))
    {
        qDebug()<<"delete error";
    }
    emit deleted();
}

