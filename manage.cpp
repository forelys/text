#include "manage.h"
#include "ui_manage.h"

manage::manage( QWidget *parent) : QWidget(parent)
    , ui(new Ui::manage)
{
    ui->setupUi(this);
    //taskWindow->db=db;
    connect(taskWindow, &tasksetting::taskAdded, this, &manage::updateWindow);
}

manage::~manage()
{
    delete ui;
}

void manage::on_accountBtn_clicked()//账号系统，考虑做不做
{

}

void manage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setOpacity(0.4);
    QPixmap backPic(":/res/42.png");
    QPixmap scaledPixmap = backPic.scaled(this->size(),Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    painter.drawPixmap((this->size().width()-scaledPixmap.width())/2, 0 ,scaledPixmap);
        //通过计算使图片水平居中                       //图片置于顶端
}

void manage::on_addTaskBtn_clicked()//添加任务
{
    taskWindow->show();
}

void manage::updateWindow()
{
    ui->listWidget->clear();
    QSqlQuery query;
    QString sqlSelect = QString("select * from task;");//查询
    if(!query.exec(sqlSelect))
    {
        qDebug()<<"select error";
    }
    while(query.next())
    {
        int id=query.value("id").toInt();
        QString name=query.value("name").toString();
        int grade=query.value("grade").toInt();
        int studyTime=query.value("studyTime").toInt();
        int breakTime=query.value("breakTime").toInt();

        taskForm*task=new taskForm();
        task->taskInfo(id,name,grade,studyTime,breakTime);//                           //                  //
        QListWidgetItem* item=new QListWidgetItem;
        item->setSizeHint(QSize(735,56));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,task);
    }
}

void manage::on_saveBtn_clicked()
{
    emit saved();
    updateWindow();
}

