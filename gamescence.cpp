#include "gamescence.h"
#include "ui_gamescence.h"

GameScence::GameScence(QWidget *parent) :QWidget(parent),ui(new Ui::GameScence)
{
    /* 游戏场景的初始化：*/
    qDebug() << getCurrentTime() << "初始化：游戏场景"  << endl;
    this->grabKeyboard();       // 始终捕获键盘事件：https://blog.csdn.net/ZT_0910/article/details/79990538
    initPlayer();                           // 初始化玩家


}


void GameScence::initPlayer()
{

    player = new PlayerEntity;
    player->moveEntityPixmap->addTickPix();
    gameScene = new QGraphicsScene;
    player->playerView = new QGraphicsView;


    /* 图形化操作：*/

    // 重绘函数
    QPixmap pixmap(":/res/gamescence/player/run/run_0.png");
    player->moveEntityPixmap->setPixmap(pixmap);



    gameScene->addItem( player->moveEntityPixmap );          // 添加item置于Scene中（这里可能由于后继承的类而失效）

    //player->playerView->resize(1000, 1000);
    gameScene->setSceneRect(QRectF(0,0,1000,1000));
    player->moveEntityPixmap->setPos(0,0);
     player->playerView->setScene(gameScene);
     player->playerView->setParent(this);
     player->playerView->show();

    //player->playerView->setMinimumSize(1000,1000);

    QTimer timer;

        QObject::connect(&timer, SIGNAL(timeout()),gameScene, SLOT(PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)));

        timer.start(1000);
//    pixTicks->start(500);
//    connect(pixTicks, &QTimer::timeout, this, &GameScence::paints);
}
















void GameScence::timerEvent(QTimerEvent *timeEvent)
{
    qDebug() << getCurrentTime() << "Timer:called"  << endl;

    this->gameScene->update();              // 场景更新（用于更新图元重绘）

    // 水平加速度判定操作：
    if(!this->player->isMovingX()){
        this->player->setAccelerationX(0.0);                                                                        // 设置水平加速度
        this->player->setAccelerationF( 2 * (this->player->getAccelerationX()) );       // 设置水平阻力加速度
    }
    else{
        this->player->setAccelerationX(BASE_ACCEX_PLAYER);                                     // 设置水平加速度
        this->player->setAccelerationF(BASE_ACCEX_F_PLAYER);                                 // 设置水平阻力加速度
    }

    // 水平速度判定操作：
    if(this->player->getSpeedX()<=MAX_SPEED_X_PLAYER &&(this->player->getSpeedX()>0) ){
        this->player->setSpeedX( this->player->getTimeGo() * (this->player->getAccelerationX() - this->player->getAccelerationF()) + this->player->getSpeedX());
    }
    else if(this->player->getSpeedX()> MAX_SPEED_X_PLAYER){
        this->player->setSpeedX( MAX_SPEED_X_PLAYER);       // 如果速度超过最大速度则拉回
    }
    else if(this->player->getSpeedX()<=0){
        this->player->setSpeedX(0);                                               // 如果速度小于0则归0
    }
    qDebug() << getCurrentTime() << "playerSpeedUpdata:" << this->player->getSpeedX() <<" pix/s"<< endl;

        /*if(playerEntity->isMovingX()==false){
            playerEntity->setInertiaMove(
                                         int(0.5 * playerEntity->getAccelerationF() * playerEntity->getTimeGo() * playerEntity->getTimeGo() + playerEntity->getSpeedX() * playerEntity->getTimeGo()));
        }*/

        // 玩家水平移动状态计时器（计算运动学所需的时间变量变化）：
        if(timeEvent->timerId() == moveTick){
             qDebug() << getCurrentTime() << "motionChangeTick:knock" << endl;
             qDebug() << getCurrentTime() << this->player->getTimeGo() << endl;

             if( !this->player->getSpeed() ){
                 this->player->motionTickIndex++;
             }
             else{
                 this->player->setMotionTickIndex(0);
             }
        }

        // 玩家图元帧切换计时器（可以简化）：
        if(timeEvent->timerId() == pixTick){
         qDebug() << getCurrentTime() << "pixChangeTick:knock" << endl;

         if(player->motions==NORMAL){

             tickIndex[0]++;
             if(tickIndex[0]==TICK_PLAYER_PIXNUMBER_NOR-1)
                 tickIndex[0]=0;
         }
         else{
             if(tickIndex[0]!=0)
                tickIndex[0]=0;
         }

         if(player->motions==RUNNING){
             if(tickIndex[1]==TICK_PLAYER_PIXNUMBER_RUN-1)
                 tickIndex[1]=0;
             else{
                 tickIndex[1]++;
             }
         }
         else{
             if(tickIndex[1]!=0)
                tickIndex[1]=0;
         }

         if(player->motions==CROUCHING){
             if(tickIndex[2]==TICK_PLAYER_PIXNUMBER_CRO-1)
                 tickIndex[2]=0;
             else{
                 tickIndex[2]++;
             }
         }
         else{
             if(tickIndex[2]!=0)
                tickIndex[2]=0;
         }

         if(player->motions==UPING){
             if(tickIndex[3]==TICK_PLAYER_PIXNUMBER_UP-1)
                 tickIndex[3]=0;
             else{
                 tickIndex[3]++;
             }
         }
         else{
             if(tickIndex[3]!=0)
                tickIndex[3]=0;
         }

         if(player->motions==DOWNING){
             if(tickIndex[4]==TICK_PLAYER_PIXNUMBER_DOWN-1)
                 tickIndex[4]=0;
             else{
                 tickIndex[4]++;
             }
         }
         else{
             if(tickIndex[4]!=0)
                tickIndex[4]=0;
         }

         if(player->motions==TOP){
             if(tickIndex[5]==TICK_PLAYER_PIXNUMBER_TOP-1)
                 tickIndex[5]=0;
             else{
                 tickIndex[5]++;
             }
         }
         else{
             if(tickIndex[5]!=0)
                tickIndex[5]=0;
         }

       qDebug() << getCurrentTime() << "pixChangeTick:normalIndex" <<tickIndex[0]<< endl;
       qDebug() << getCurrentTime() << "pixChangeTick:runIndex" <<tickIndex[1]<< endl;
       qDebug() << getCurrentTime() << "pixChangeTick:crouchIndex" <<tickIndex[2]<< endl;
       qDebug() << getCurrentTime() << "pixChangeTick:upIndex" <<tickIndex[3]<< endl;
       qDebug() << getCurrentTime() << "pixChangeTick:downIndex" <<tickIndex[4]<< endl;
       qDebug() << getCurrentTime() << "pixChangeTick:topIndex" <<tickIndex[5]<< endl;

    }

}



void GameScence::keyPressEvent(QKeyEvent *keyEvent)
{
    qDebug() << getCurrentTime() << "移动事件"  << endl;
    if((this->player->isMovingX()==false)&& (keyEvent->key()==Qt::Key_A || keyEvent->key()==Qt::Key_Left) && (keyEvent->key()==Qt::Key_D || keyEvent->key()==Qt::Key_Right)){
        player->motions = RUNNING;
        qDebug() << getCurrentTime() << "Don't Move"<<endl;
        this->player->setMovingX(true);
    }
    // 向右移动
    if( (keyEvent->key()==Qt::Key_D || keyEvent->key()==Qt::Key_Right)){
        qDebug() << getCurrentTime() << "RightMove"<<this->player->moveEntityPixmap->pos()<<endl;
        player->motions = RUNNING;
        this->player->setMovingX(true);
        int a = static_cast<int>((0.5 * this->player->getAccelerationX() * this->player->getTimeGo() * this->player->getTimeGo() + this->player->getSpeedX() * this->player->getTimeGo()));
        //this->player->moveEntityPixmap->setOffset(a,100);
        this->player->moveEntityPixmap->moveBy(a,0);
    }
    // 向左移动
    if((this->player->isMovingX()==false)&& (keyEvent->key()==Qt::Key_A || keyEvent->key()==Qt::Key_Left)){
        qDebug() << getCurrentTime() << "LeftMove"<<this->player->moveEntityPixmap->pos()<<endl;

        player->motions = RUNNING;
        this->player->setMovingX(true);
        //this->player->setMove(-1 * int(0.5 * this->player->getAccelerationX() * this->player->getTimeGo() * this->player->getTimeGo() + this->player->getSpeedX() * this->player->getTimeGo()));
        int a= -1*static_cast<int>(int(0.5 * this->player->getAccelerationX() * this->player->getTimeGo() * this->player->getTimeGo() + this->player->getSpeedX() * this->player->getTimeGo()));
        this->player->moveEntityPixmap->moveBy(a,0);
    }
}

void GameScence::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if( (this->player->isMovingX()==true)&&(keyEvent->key()==Qt::Key_A || keyEvent->key()==Qt::Key_Left) && (keyEvent->key()==Qt::Key_D || keyEvent->key()==Qt::Key_Right)){
        this->player->setMovingX(false);
         this->player->motions=NORMAL;
    }
    // 向右移动
    if( (this->player->isMovingX()==true)&&(keyEvent->key()==Qt::Key_D || keyEvent->key()==Qt::Key_Right)){
        this->player->setMovingX(false);
         this->player->motions=NORMAL;
    }
    // 向左移动
    if((this->player->isMovingX()==true)&& (keyEvent->key()==Qt::Key_A || keyEvent->key()==Qt::Key_Left)){
            this->player->setMovingX(false);
         this->player->motions=NORMAL;
    }
}


