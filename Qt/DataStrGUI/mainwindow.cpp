#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    BTree<4, int> testBTree;
    int insertKeys[3] = {2, 8, 6};
    for(int i = 0; i < 3; ++i)
    {
        testBTree.insert(insertKeys[i]);
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
