#include"PlanetDetailsDialouge.h"
#include <QDialog>

PlanetDetailsDialouge::PlanetDetailsDialouge(const PlanetInfo &info, QWidget *parent)
    : QDialog(parent), info(info)
{

}
