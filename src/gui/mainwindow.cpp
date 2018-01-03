#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // SETUP INITIAL STATE OF WIDGETS HERE
    // TODO: load list of components from config file and return them as const QList<QTreeWidgetItem *> &items, later append them QTreeWidget, preserving parent-child relations

    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeCompView);
    itm->setText(0, "test string");
    ui->treeCompView->insertTopLevelItem(0, itm);



    // MAKE CONNECTIONS HERE
    connect(        ui->treeCompView, &QTreeWidget::itemDoubleClicked,  [=]( QTreeWidgetItem *item, int column) { ctxMenu(item, column); }    );


}

MainWindow::~MainWindow()
{
    // DUNNO IF THIS IMPLEMENTATION IS NEEDED

}

void MainWindow::ctxMenu(QTreeWidgetItem *item, int column)
{
    qDebug () << "dupa " << column;
}
