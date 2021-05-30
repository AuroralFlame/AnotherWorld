#ifndef MOVEENTITY_H
#define MOVEENTITY_H

/* 移动实体类：抽象类 */
#include <QObject>
#include <QGraphicsPixmapItem>
#include "entitybase.h"

class MoveEntity : public EntityBase
{
    Q_OBJECT
public:
    explicit MoveEntity();
    ~MoveEntity();
    virtual void setSpeed( qreal speed) = 0;
    virtual void setSpeed( qreal speedX, qreal speedY ) = 0;
    virtual qreal getSpeed() = 0;

    // 每种实体的重力都不尽相同
    virtual void setGravity(qreal fixedValue) = 0;
    virtual void setGravity(int poX, int posY,qreal speedX) = 0;
    virtual qreal getGravity() = 0;

protected:
    double speed;       // 合速度
    double gravity;
};

#endif // MOVEENTITY_H
