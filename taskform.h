#ifndef TASKFORM_H
#define TASKFORM_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QString>
#include<QListWidgetItem>

namespace Ui {
class taskForm;
}

class taskForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit taskForm(QWidget *parent = nullptr);
    ~taskForm();

    void taskInfo(int id,QString name,int grade,int studyTime,int breakTime);

signals:
    void deleted();

private slots:
    void on_deleteBtn_clicked();

private:
    Ui::taskForm *ui;
    int id;
};

#endif // TASKFORM_H
