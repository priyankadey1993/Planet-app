#ifndef PLANETTAB_H
#define PLANETTAB_H

#include <QWidget>
#include <QObject>
#include "PlanetInfo.h"
#include"detailsdialouge.h"

class planetTab :public QWidget
{
    Q_OBJECT

public:
    explicit planetTab(const PlanetInfo &info, QWidget *parent = nullptr);
signals:
    void detailRequested(const PlanetInfo &info);

private :
    DetailsDialouge *dia;
    PlanetInfo info;
    QLabel *titleLabel;
    QLabel *imageLabel;
    QPushButton *detailButton   ;
};

#endif // PLANETTAB_H
