#ifndef ACTIVEOBEJCT_H
#define ACTIVEOBEJCT_H

#include <QObject>

class ActiveObejct : public QObject
{
    Q_OBJECT
public:
    explicit ActiveObejct(QObject *parent = nullptr);

signals:

};

#endif // ACTIVEOBEJCT_H
