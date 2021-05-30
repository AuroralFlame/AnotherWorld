#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "gamemenu.h"
#include "GameSettings.h"

class QStackedWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE


class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    void switchPage();
    virtual void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MenuWindow *ui;
    QGraphicsView menuView;
    QGraphicsScene menuScene;
    QGraphicsPixmapItem menuBackground;

    QStackedWidget *gameMenu;

    GameMenu *mainMenu;
    GameMenu *chooseMenu;

signals:
    void changeWidth();
    void changeHeight();

public slots:
    void hideMenu();

private slots:
    void renderBackground(int width, int height);
    void on_startButton_clicked();
    void on_quitButtonMenu_clicked();
    void reshow();
    void on_returnButton_clicked();

    void on_newGameButton_clicked();
};
#endif // MENUWINDOW_H
