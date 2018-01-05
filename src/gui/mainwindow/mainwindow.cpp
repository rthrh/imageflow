#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWidget>

//#include "graphwidget.h"

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

    //GraphWidget *widget = new GraphWidget;

   // this->setCentralWidget(widget); //uncomment to see graphs and nodes

    // MAKE CONNECTIONS HERE
    connect(        ui->treeCompView, &QTreeWidget::itemDoubleClicked,  [=]( QTreeWidgetItem *item, int column) { MainWindow::addNewComponent(item, column); }    );


}

MainWindow::~MainWindow()
{

}

void MainWindow::addNewComponent(QTreeWidgetItem *item, int column)
{
    // Function is supposed to find proper component name based on clicked column, create its gui diagram and return instance of object

    //auto Node =

    qDebug () << "dupa " << column;
}
