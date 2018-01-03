#ifndef mainwindow_h
#define mainwindow_h

#include <QMainWindow>
#include <QScopedPointer>
#include <QTreeWidget>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private:
    QScopedPointer<Ui::MainWindow> ui;

private slots:
    void addNewComponent(QTreeWidgetItem *item, int column);
};

#endif
