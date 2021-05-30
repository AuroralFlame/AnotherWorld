#include "gamemenu.h"
#include "ui_gamemenu.h"

GameMenu::GameMenu(QWidget *parent) :QWidget(parent),ui(new Ui::GameMenu)
{

}

GameMenu::~GameMenu()
{
    delete ui;
}

