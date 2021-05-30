#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <windows.h>
#include <QDialog>
#include "gamescence.h"


MenuWindow::MenuWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MenuWindow)
{

         setWindowTitle("BewilderAction");
         Sleep(2000);

        //TODO：这里想着还是不加了，如果换成分层背景就不需要固定了，故采用设计方案2和3二选一。
        //this->setFixedSize(1300, 700);            // 设置窗口大小固定

        // 设置只显示图元在场景中的一部分
        //menuView.setSceneRect(QRectF(0,0,0,0));

        // 场景大小的长和宽，会随着窗口大小变换而改变。
        long int maxMenuWidth = 2000;
        long int maxMenuHeight = 1000;
       // if(窗口变换)

        // 设置场景的总大小
        menuScene.setSceneRect(QRectF(0, 0, maxMenuWidth, maxMenuHeight));

        // 资源文件绑定：使用QT官方的QPixmap，scaled函数为对此类对象的缩放函数
        QPixmap pixmap(":/gamestarted/loading/res/gamestart/test.png");
        QPixmap scaledPixmap = pixmap.scaled(1024, 512,Qt::KeepAspectRatio);    // 原图大小不适宜可以接收对原图放缩后的对象：KeepAspectRatio (F1）是保持比例进行缩放

        // 我们可以联想到分层背景的每一层都是一个图元组，在放大或者缩小过程中都保持比例缩放

        // 用PixmapItem的图元对象引用 Pixmap对象
        menuBackground.setPixmap(scaledPixmap);
        // 为图元对象设置Z轴（简易分层，更复杂的分层就像弹射物可以打击到任意层级除了永久不动层的层级。）
        menuBackground.setZValue(0);

        // 在Scence
        /*Graphics View提供了一个界面，它既可以管理大数量的定制2D graphical items，
         * 又可与它们交互，有一个view widget可以把这些项绘制出来，并支持旋转与缩放。
         * 这个柜架也包含一个事件传播结构，对于在scene中的这些items,它具有双精度的交互能力。
         *
         * Items能处理键盘事件，鼠标的按，移动、释放、双击事件，也可以跟踪鼠标移动。
         *
         * Graphics View使用BSP树来提供对item的快速查找，使用这种技术，它可以实时地绘制大规模场景，甚至以百万items计。
         * Graphics View在Qt 4.2中被引用，它替代了它的前辈QCanvas。
         URL：https://www.cnblogs.com/cy568searchx/p/3502242.html
         */

        // 我该如何把这个加入到主界面渲染线程里？
        // 把图元对象加入到Scene中便于快速管理和绘制，负责渲染操作
        menuScene.addItem(&menuBackground);

        // 把图元Scence加入到View中便于快速管理，负责代码逻辑操作，如碰撞
        menuView.setScene(&menuScene);

        // 把View加入到窗口里设置归属
        menuView.setParent(this);
        menuView.show();

        // 设置控件布局：
        ui->setupUi(this);

        gameMenu = new QStackedWidget(this);

        mainMenu = new GameMenu(this);
        chooseMenu = new GameMenu(this);

        // 为栈界面添加页面（用于切换）：
        gameMenu->addWidget(mainMenu);
        gameMenu->addWidget(chooseMenu);

        this->ui->returnButton->hide();
        this->ui->newGameButton->hide();
        this->ui->cntinuButton->hide();
        this->ui->saveButton->hide();
       // connect(ui->startButton,&QPushButton::clicked,this,&MenuWindow::renderBackground(this->frameGeometry().height(),this->frameGeometry().width()));

        connect(ui->newGameButton,SIGNAL(clicked()),this,SLOT(hideMenu()));

}




MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::hideMenu(){
    this->hide();
}

// 不管怎样，场景永远是以中央为中心的，
// 这里检测更改窗口大小的事件，也是实时绘制背景的事件。
void MenuWindow::renderBackground(int width, int height)
{
    // screenWidth
    int oriWidth=1024, oriHeight=512;
    double cmp = oriWidth/oriHeight;
    double cmpCurrent = width/height;
    if(width!=oriWidth || height!=oriHeight){
        // 检测当前窗口宽度变化：
        if(width>oriWidth){
            double multiple = ( width-oriWidth )/oriWidth;
            if(multiple>1){
                //（multiple+1） * (BottomItemGroup\BackItemGroup\TopItemGroup)渲染数量
            }
           // double resultHeight = double(width)/cmp;
        }
        else if(width<oriWidth){
            double resultWidth = double(height)*cmp;
        }
        else{
            // 按比例放大：整体放大事件触发
        }
    }

    // 按照比例缩放
    if(double(width)/double(oriWidth)==double(height)/double(oriHeight)){
            double multiple = ( width-oriWidth )/oriWidth;
    }

 }




void MenuWindow::on_quitButtonMenu_clicked()
{
    qDebug() << getCurrentTime() << "Quit The Game." << endl;
    QApplication* a;
    a->exit(0);
}




void MenuWindow::on_startButton_clicked()
{
    int oldIndex = gameMenu->currentIndex();

    this->ui->pushButton->hide();
    this->ui->quitButtonMenu->hide();
    this->ui->startButton->hide();

    this->ui->returnButton->show();
    this->ui->newGameButton->show();
    this->ui->cntinuButton->show();
    this->ui->saveButton->show();

    gameMenu->setCurrentIndex(1);

    qDebug() << getCurrentTime() << "Page" << oldIndex <<" Turned To Page " << gameMenu->currentIndex() << endl;
}


void MenuWindow::on_returnButton_clicked()
{
    int oldIndex = gameMenu->currentIndex();
    gameMenu->setCurrentIndex(0);

    this->ui->returnButton->hide();
    this->ui->cntinuButton->hide();
    this->ui->saveButton->hide();
    this->ui->newGameButton->hide();

    this->ui->pushButton->show();
    this->ui->quitButtonMenu->show();
    this->ui->startButton->show();

    qDebug() << getCurrentTime() << "Page" << oldIndex <<" Turned To Page " << gameMenu->currentIndex() << endl;
}

void MenuWindow::resizeEvent(QResizeEvent *event)
{
}

void MenuWindow::switchPage(){
}
void MenuWindow::reshow(){
}

void MenuWindow::on_newGameButton_clicked()
{
    GameScence *g = new GameScence;
    g->show();
}
