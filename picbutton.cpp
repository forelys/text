#include "picbutton.h"

picbutton::picbutton(QString name,int width,int height)
{
    QPixmap pixmap(name);
    // 设置按钮的大小限制，保持宽高比
    this->setFixedSize(width,height);
    // 缩放图片为按钮的大小
    QPixmap scaledPixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // 设置按钮的图标为缩放后的图片
    this->setIcon(QIcon(scaledPixmap));
    // 设置按钮的图标大小策略，使图标填充按钮
    this->setIconSize(this->size());
    // 设置按钮的文本为空，以隐藏默认文本
    this->setText("");

    connect(this, &picbutton::clicked, [this, name]() {
        emit buttonClicked(name);
    });
}
