#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include "GameSettings.h"

namespace Ui {class GameMenu;}

class GameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = nullptr);
    ~GameMenu();

signals:
private slots:
private:
    Ui::GameMenu *ui;
};

#endif // GAMEMENU_H
