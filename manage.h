#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include<QPainter>
#include"tasksetting.h"
#include"taskform.h"

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = nullptr);
    ~manage();
    void updateWindow();//更新ui
    tasksetting*taskWindow=new tasksetting;
    void paintEvent(QPaintEvent *event);

signals:
    void saved();

private slots:
    void on_accountBtn_clicked();

    void on_addTaskBtn_clicked();

    void on_saveBtn_clicked();

private:
    Ui::manage *ui;
};

#endif // MANAGE_H
