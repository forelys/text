#ifndef TASKSETTING_H
#define TASKSETTING_H

#include <QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QString>
#include<QListWidgetItem>

namespace Ui {
class tasksetting;
}

class tasksetting : public QWidget
{
    Q_OBJECT

public:
    explicit tasksetting(QWidget *parent = nullptr);
    ~tasksetting();
    //QSqlDatabase db;   //

signals:
    void taskAdded();

private slots:
    void on_saveBtn_clicked();

private:
    Ui::tasksetting *ui;
};

#endif // TASKSETTING_H
