#ifndef GIFTSHOP_H
#define GIFTSHOP_H

#include <QMainWindow>

namespace Ui {
class giftshop;
}

class giftshop : public QMainWindow
{
    Q_OBJECT

public:
    explicit giftshop(QWidget *parent = nullptr);
    ~giftshop();
    void updateShop();

signals:
    void changeBackgroundRequested(const QString &name); // 发出更改背景图片请求的信号

private:
    Ui::giftshop *ui;
};

#endif // GIFTSHOP_H
