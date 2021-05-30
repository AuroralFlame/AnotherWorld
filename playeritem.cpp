#include "playeritem.h"
#include "gamescence.h"

PlayerItem::PlayerItem(const QPixmap &pixmap)
{
    pix = pixmap;
}

PlayerItem::PlayerItem()
{
    setFlags(QGraphicsItem::ItemIsMovable);
}

QRectF PlayerItem::boundingRect() const
{
    return QRectF(26, 0, 32, 59);
}
QPainterPath PlayerItem::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}



/* 基于整体重绘的帧图片载入（之后可能会优化为分区块的载入方法） */
void PlayerItem::addTickPix(){
    // Normal：
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_NOR; ++i) {
        QString temp = "://res/gamescence/player/normal/nor_" + QString::number(i) + ".png";
        tickPathNormal.push_back(temp);
        QPixmap tempPix(tickPathNormal[i]);
        tickNorPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully" << endl;
    }
    // Running：
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_RUN; ++i) {
        QString temp = ":://res/gamescence/player/run/run_" + QString::number(i) + ".png";
        tickPathRunning.push_back(temp);
        QPixmap tempPix(tickPathRunning[i]);
        tickRunPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully"  << endl;
    }
    // Crouching：
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_CRO; ++i) {
        QString temp = ":://res/gamescence/player/crouch/cro_" + QString::number(i) + ".png";
        tickPathCrouching.push_back(temp);
        QPixmap tempPix(tickPathCrouching[i]);
        tickCroPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully"  << endl;
    }
    // Uping
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_UP; ++i) {
        QString temp = ":://res/gamescence/player/up/up_" + QString::number(i) + ".png";
        tickPathUping.push_back(temp);
        QPixmap tempPix(tickPathUping[i]);
        tickUpPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully"  << endl;
    }
    // Downing
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_DOWN; ++i) {
        QString temp = ":://res/gamescence/player/down/down_" + QString::number(i) + ".png";
        tickPathDowning.push_back(temp);
        QPixmap tempPix(tickPathDowning[i]);
        tickDownPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully"  << endl;
    }
    // Top
    for (int i = 0; i < TICK_PLAYER_PIXNUMBER_DOWN; ++i) {
        QString temp = ":://res/gamescence/player/top/top_" + QString::number(i) + ".png";
        tickPathTop.push_back(temp);
        QPixmap tempPix(tickPathTop[i]);
        tickTopPix.push_back(tempPix);
        qDebug() << getCurrentTime() << "add pix" << temp << "successfully"  << endl;
    }
}
// 对于玩家图像的重画函数（这里有一个严重的问题，就是载入gamescence的传参问题

void PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << getCurrentTime() << "here" << endl;
    GameScence *game = (GameScence*)widget;

    int iNor = game->tickIndex[0];
    int iRun = game->tickIndex[1];
    int iCro = game->tickIndex[2];
    int iUp = game->tickIndex[3];
    int iDown = game->tickIndex[4];
    int iTop= game->tickIndex[5];
    // 不按键时按照norDrawTick进行重绘，tickIndex>TICK_PALYER_PIX=0

    switch (game->player->motions) {
        case NORMAL:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickNorPix[iNor].width()/2, -game->player->moveEntityPixmap->tickNorPix[iNor].height()/2, game->player->moveEntityPixmap->tickNorPix[iNor]);
            break;
        case RUNNING:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickRunPix[iRun].width()/2, -game->player->moveEntityPixmap->tickRunPix[iRun].height()/2, game->player->moveEntityPixmap->tickRunPix[iRun]);
            break;
        case CROUCHING:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickCroPix[iCro].width()/2, -game->player->moveEntityPixmap->tickCroPix[iCro].height()/2, game->player->moveEntityPixmap->tickCroPix[iCro]);
            break;
        case UPING:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickUpPix[iUp].width()/2, -game->player->moveEntityPixmap->tickUpPix[iUp].height()/2, game->player->moveEntityPixmap->tickUpPix[iUp]);
            break;
        case DOWNING:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickDownPix[iDown].width()/2, -game->player->moveEntityPixmap->tickDownPix[iDown].height()/2, game->player->moveEntityPixmap->tickDownPix[iDown]);
            break;
        case TOP:
            painter->drawPixmap(-game->player->moveEntityPixmap->tickTopPix[iDown].width()/2, -game->player->moveEntityPixmap->tickTopPix[iDown].height()/2, game->player->moveEntityPixmap->tickTopPix[iDown]);
            break;
    }
}

// 移动函数
void PlayerItem::advance(int) {

}

void PlayerItem::beCollide()
{
    /*
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
                case ENEMYPLANENAME:
                    strike();
                    if (m_blood == 0) {
                        m_bomb = 0;
                        m_bullet = 0;
                        fall();
                    }
                    break;
                case ENEMYBULLETNAME:
                    flyer->fall();
                    strike();
                    if (m_blood == 0) {
                        m_bomb = 0;
                        m_bullet = 0;
                        fall();
                    }
                    break;
                case BLOODSUPPLYNAME:
                    flyer->fall();
                    if (m_blood < PLAYERPLANEBLOOD) {
                        m_blood++;
                        //emit sig_blood(m_blood);
                    }
                    break;
                case BOMBSUPPLYNAME:
                    flyer->fall();
                    if (m_bomb < PLAYERPLANEBOMB) {
                        m_bomb++;
                        //emit sig_bomb(m_bomb);
                    }
                    break;
                case BULLETSUPPLYNAME:
                    flyer->fall();
                    if (m_bullet < PLAYERPLANEBULLET) {
                        m_bullet++;
                    }
                    break;
            }
        }
    }*/
}
