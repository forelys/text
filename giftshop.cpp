#include "giftshop.h"
#include "ui_giftshop.h"
#include"picbutton.h"
#include<QScrollArea>
#include<QVBoxLayout>
#include<QPainter>
#include<QPalette>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

giftshop::giftshop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::giftshop)
{
    ui->setupUi(this);

    updateShop();
}

giftshop::~giftshop()
{
    delete ui;
}

void giftshop::updateShop()
{
    // 创建一个窗口对象
    QWidget* wg = new QWidget;
    // 创建一个网格布局对象
    QGridLayout* gridLayout = new QGridLayout(wg);
    gridLayout->setSpacing(10); // 设置网格布局的间距
    int rowCount = 0; // 当前行数
    int columnCount = 0; // 当前列数

    for(int i=0; i<3; ++i)//加载金色图片
    {
        QString name = QString(":/res/00%1.png").arg(i+1);
        QSqlQuery query;    // 执行查询语句
        QString selectGift = QString("select * from gift where name='%1';").arg(name);
        if(query.exec(selectGift))
        {
            if(query.next())
            {
                picbutton* button=new picbutton(name,400,240);
                connect(button, &picbutton::buttonClicked, this, &giftshop::changeBackgroundRequested);

                // 将picbutton添加到网格布局中
                gridLayout->addWidget(button, rowCount, columnCount);
                // 更新当前列数和行数
                columnCount++;
                if (columnCount == 4) {
                    columnCount = 0;
                    rowCount++;
                }
            }
        }
    }
    for(int i=0; i<16; ++i)//加载紫色图片
    {
        QString name = QString(":/res/0%1.png").arg(i+1);
        QSqlQuery query;    // 执行查询语句
        QString selectGift = QString("select * from gift where name='%1';").arg(name);
        if(query.exec(selectGift))
        {
            if(query.next())
            {
                picbutton* button=new picbutton(name,400,240);
                connect(button, &picbutton::buttonClicked, this, &giftshop::changeBackgroundRequested);

                // 将picbutton添加到网格布局中
                gridLayout->addWidget(button, rowCount, columnCount);
                // 更新当前列数和行数
                columnCount++;
                if (columnCount == 4) {
                    columnCount = 0;
                    rowCount++;
                }
            }
        }
    }
    for(int i=0; i<69; ++i)//加载蓝色图片
    {
        QString name = QString(":/res/%1.png").arg(i+1);
        QSqlQuery query;    // 执行查询语句
        QString selectGift = QString("select * from gift where name='%1';").arg(name);
        if(query.exec(selectGift))
        {
            if(query.next())
            {
                picbutton* button=new picbutton(name,400,240);
                connect(button, &picbutton::buttonClicked, this, &giftshop::changeBackgroundRequested);

                // 将picbutton添加到网格布局中
                gridLayout->addWidget(button, rowCount, columnCount);
                // 更新当前列数和行数
                columnCount++;
                if (columnCount == 4) {
                    columnCount = 0;
                    rowCount++;
                }
            }
        }
    }


    // 设置窗口对象的布局
    wg->setLayout(gridLayout);
    // 创建一个滚动区域对象
    QScrollArea* scrollArea = new QScrollArea;
    // 设置滚动区域的窗口部件
    scrollArea->setWidget(wg);
    // 设置滚动区域的垂直滚动条策略
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    // 设置滚动区域的水平滚动条策略
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置滚动区域为主窗口的中央部件
    setCentralWidget(scrollArea);

}
