#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>
#include<QTimer>
#include"gift.h"
#include"manage.h"
#include"tasksetting.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void paintEvent(QPaintEvent *event)；
    void changeBackground(QString name);

private slots:

    void updateTime();

    void InitTime();

    void on_rewardBtn_clicked();

    void on_startBtn_clicked();

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

    void on_manageBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString currentBackground=":/res/42.png";//背景图片,默认为番茄娘
    manage* manageWindow=new manage;
    gift*giftWindow=NULL;
    int state=0; //时钟状态
    int tomato_num=0; //番茄计数，轮流工作休息
    int studyTime=0;//学习时间
    int breakTime=0;//休息时间
    QTimer *timer;
    QTime time;
    QSqlDatabase basedb; // 声明数据库连接对象

};
#endif // MAINWINDOW_H
