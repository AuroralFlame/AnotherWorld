#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

// 人物帧动画载入
#define MAX_SPEED_X_PLAYER 10
#define BASE_ACCEX_PLAYER 2.0
#define BASE_ACCEY_PLAYER 9.0
#define BASE_ACCEX_F_PLAYER 0.0
#define BASE_ACCEY_F_PLAYER 0.0
#define BASE_HEALTH_PLAYER 100
#define BASE_SPEEDX_PLAYER 0.0
#define BASE_SPEEDY_PLAYER 0
#define TICK_PLAYER_PIXNUMBER_NOR 4
#define TICK_PLAYER_PIXNUMBER_RUN 4
#define TICK_PLAYER_PIXNUMBER_CRO 4
#define TICK_PLAYER_PIXNUMBER_TOP 1
#define TICK_PLAYER_PIXNUMBER_UP 1
#define TICK_PLAYER_PIXNUMBER_DOWN 1

#include <QString>
#include <QDebug>
#include <QDateTime>

// 一些控制台输出函数：
static QString getCurrentTime()
{
    QDateTime local(QDateTime::currentDateTime());
    QString currentTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    return currentTime + ":";
}

// 玩家运动状态：
 enum motionState{
     NORMAL=1,
     RUNNING,
     CROUCHING,
     UPING,
     DOWNING,
     TOP
 } ;

#endif // GAMESETTINGS_H
