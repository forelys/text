#ifndef PICBUTTON_H
#define PICBUTTON_H
#include<QPushButton>
#include<QString>

class picbutton:public QPushButton
{
    Q_OBJECT
public:
    picbutton(QString name,int width,int herght);
signals:
    void buttonClicked(QString name);
};

#endif // PICBUTTON_H
