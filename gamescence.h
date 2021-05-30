#ifndef GAMESCENCE_H
#define GAMESCENCE_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include "playentity.h"
#include "GameSettings.h"

namespace Ui {class GameScence;}

class GameScence : public QWidget
{
    Q_OBJECT
public:
    explicit GameScence(QWidget *parent = nullptr);
    QGraphicsScene* gameScene;
    QGraphicsView *gameView;
    PlayerEntity * player;
    void timerEvent(QTimerEvent *timeEvent);

    void initPlayer();

    void addTickPix();


    int moveTick = startTimer(1000);         // 每隔1000ms的定时器，用于累加运动的时间
    int pixTick = startTimer(500);                //  每隔500ms的定时器，用于重绘图形
    int tickIndex[100]={0};
    QTimer *pixTicks = new QTimer(this);

protected:
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);
signals:

private:
    Ui::GameScence *ui;
};

#endif // GAMESCENCE_H
