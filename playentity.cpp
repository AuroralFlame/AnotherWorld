#include "playentity.h"


PlayerEntity::PlayerEntity()
{
    qDebug() << getCurrentTime() << "initObject:player"  << endl;

    this->moveEntityPixmap = new PlayerItem();          //  获得图元实例
    this->setBaseHealth(BASE_HEALTH_PLAYER);           //  设置基础血量

    this->setMotionTickIndex(0);
    this->setAccelerationX(BASE_ACCEX_PLAYER);     // 设置初始水平加速度
    this->setGravity(BASE_ACCEY_PLAYER);                  // 设置初始竖直加速度
    this->setAccelerationF( BASE_ACCEX_F_PLAYER );  //设置水平阻力加速度
    this->setSpeedX(BASE_SPEEDX_PLAYER);                 // 设置初始水平速度为
    this->setMovingX(false);                                              // 设置是否有水平动量

    this->setXOffsets(0);                    // 设置水平偏移为0


}

PlayerEntity::~PlayerEntity()
{
    // 玩家死亡后应该设置对速度或者计时器全部停止计算
    this->setBaseHealth(0);
    delete this;
}


/* 物理性质函数 */
void PlayerEntity::setSpeed( qreal speedX, qreal speedY ){
    this->speed = sqrt(pow(speedX , 2) + pow(speedY , 2));
}
void PlayerEntity::setSpeed(qreal speed)
{
    this->speed = speed;
}
qreal PlayerEntity::getSpeed()
{
    return this->speed;
}

void PlayerEntity::setSpeedX(qreal speedX)
{
    this->speedX = speedX;
}
qreal PlayerEntity::getSpeedX()
{
    return this->speedX;
}

void PlayerEntity::setAccelerationX(qreal a)
{
    this->accelerationX = a;
}
qreal PlayerEntity::getAccelerationX()
{
    return this->accelerationX;
}

void PlayerEntity::setAccelerationF(qreal a)
{
    this->accelerationF = a;
}
qreal PlayerEntity::getAccelerationF()
{
    return this->accelerationF;
}

void PlayerEntity::setMovingX(bool temp)
{
    this->moving = temp;
}
bool PlayerEntity::isMovingX()
{
    return this->moving;
}

void PlayerEntity::setXOffsets(int offsets)
{
    this->offsetX = offsets;
}
int PlayerEntity::getXOffsets()
{
    return this->offsetX;
}

void PlayerEntity::setInertiaMove(int temp)
{
    //playerView->translate(0,temp);
}

void PlayerEntity::setMotionTickIndex(long int a)
{
    this->motionTickIndex = a;
}
long int PlayerEntity::getTimeGo()
{
    return this->motionTickIndex;
}

void PlayerEntity::setGravity(double fixedValue)
{
    this->gravity = fixedValue;
}
void PlayerEntity::setGravity(int poX, int posY,double speedX)
{
    this->gravity = ((-1) * posY * pow(speedX, 2)) / poX;
}
double PlayerEntity::getGravity()
{
    return this->gravity;
}



// 强制上升：
void PlayerEntity::uppingEvent()
{

}

// 按键跳跃
void PlayerEntity::uppingEvent(QKeyEvent *jumpEvent)
{
}
