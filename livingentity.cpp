#include "livingentity.h"

LivingEntity::LivingEntity()
{

}

LivingEntity::~LivingEntity()
{

}


int LivingEntity::getHelPromote() const
{
    return this->getBaseHeath()*0.1;
}


int LivingEntity::getHeath () const
{
    return this->getHelPromote()+getBaseHeath();
}

int LivingEntity::getBaseHeath() const
{
    return this->baseHealth;
}

void LivingEntity::setBaseHealth(int base)
{
    this->baseHealth = base;
}
