#ifndef PLAYERITEM_H
#define PLAYERITEM_H

/* 玩家图元类*/
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "GameSettings.h"

class PlayerItem : public QGraphicsPixmapItem
{

public:
    PlayerItem(QPixmap * pixmap);
    PlayerItem();
    QVector<QString> tickPathNormal, tickPathCrouching, tickPathRunning,tickPathTop,tickPathDowning,tickPathUping;
    QVector<QPixmap> tickNorPix, tickCroPix, tickRunPix, tickUpPix,tickDownPix,tickTopPix;


    // 碰撞矩形
    QRectF boundingRect() const;

    // 重绘函数
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    PlayerItem(const QPixmap &pixmap);
    void addTickPix();
    QPainterPath shape() const;
    void advance(int);
    void beCollide();
private:
    QPixmap pix;
};



#endif // PLAYERITEM_H
