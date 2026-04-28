#ifndef DETAILSDIALOUGE_H
#define DETAILSDIALOUGE_H
#include"PlanetInfo.h"

#include <QApplication>

#include <QTabWidget>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QVector>
#include <QPixmap>

class DetailsDialouge: public QDialog
{
    Q_OBJECT
public:
    explicit DetailsDialouge(const PlanetInfo &info, QWidget *parent = nullptr);
    void setup_ui();
private:
    PlanetInfo info;
    QLabel *nameLabel;
    QLabel *imageLabel;
    QLabel *detailsLabel;

};

#endif // DETAILSDIALOUGE_H
