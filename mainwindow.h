#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QVector>
#include"planetTab.h"
#include"DetailsDialouge.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void createTabs();


public:
    QTabWidget *tabs;
    QVector<PlanetInfo> planets;
    planetTab *tab;




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
