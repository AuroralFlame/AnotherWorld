#ifndef PLAYENTITY_H
#define PLAYENTITY_H

/*玩家类*/
#include "livingentity.h"
#include "playeritem.h"
#include <QWidget>
#include <QGraphicsView>
#include <QKeyEvent>

class PlayerEntity : public LivingEntity
{
    // 纯虚父类MoveEntity的方法必须全部实现才能使子类玩家类变成实体类，否则仍然是抽象类不能实例化。
public:
    long int motionTickIndex;
    motionState motions;                            // 运动状态
    PlayerItem *moveEntityPixmap;
    QGraphicsView *playerView;
    PlayerEntity();
    ~PlayerEntity();

    /* 合速度操作：*/
    void setSpeed( qreal speed);
    void setSpeed( qreal speedX, qreal speedY );
    qreal getSpeed();

    /* X方向速度（对变量speedX）操作：*/
    void setSpeedX( qreal speedX );
    qreal getSpeedX();

    void setAccelerationX( qreal a );
    qreal getAccelerationX();

    void setAccelerationF( qreal a );
    qreal getAccelerationF();

    void setMovingX(bool temp);
    bool isMovingX();

    void setXOffsets( int offsets);
    int getXOffsets();

    //惯性移动（停止按键时触发一小段距离移动）
    void setInertiaMove(int temp);

    void setMotionTickIndex(long int a );
    long int getTimeGo();

    void setGravity(qreal fixedValue);
    void setGravity(int poX, int posY, qreal speedX);
    qreal getGravity();

    void uppingEvent();
    void uppingEvent(QKeyEvent *jumpEvent);

private:
    qreal accelerationX;        // X方向加速度
    qreal speedX;                    // X方向合速度
    qreal accelerationF;        // X方向阻力加速度
    bool moving = true;         // 是否在X方向发生位移
    int offsetX;                          // X方向δx偏移量
};

#endif // PLAYENTITY_H
