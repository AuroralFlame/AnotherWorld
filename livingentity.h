#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include "moveentity.h"
#include <QKeyEvent>
#include <QGraphicsView>


class LivingEntity : public MoveEntity
{
public:
    LivingEntity();
    ~LivingEntity();
    int getHeath() const;
    int getBaseHeath() const;
    void setBaseHealth(int baseH);
    int getHelPromote() const;

private:
    int baseHealth = 100;
};

#endif // LIVINGENTITY_H
