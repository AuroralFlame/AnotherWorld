#ifndef ENTITYBASE_H
#define ENTITYBASE_H

#include <QObject>
#include <QtMath>
#include <cmath>
#include "GameSettings.h"

class EntityBase : public QObject
{
    Q_OBJECT
public:
    explicit EntityBase(QObject *parent = nullptr);

signals:

};

#endif // ENTITYBASE_H
