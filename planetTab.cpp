#include "planetTab.h"

planetTab::planetTab(const PlanetInfo &info, QWidget *parent)
    : QWidget(parent), info(info)
{
    auto *layout = new QVBoxLayout();
    titleLabel= new QLabel(info.name);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 22px; font-weight: bold;");

    imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignCenter);

    QPixmap pix(info.imagePath);
    if (!pix.isNull())
    {
        imageLabel->setPixmap(pix.scaled(360, 360, Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation));
    }
    else
    {
        imageLabel->setText("Image not found");
    }
    layout->addWidget(titleLabel);
    layout->addWidget(imageLabel);

    detailButton = new QPushButton("Details");
    detailButton->setFixedWidth(120);

    layout->addWidget(detailButton, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(detailButton, &QPushButton::clicked, this, [this]() {
        emit detailRequested(this->info);
    });
    setLayout(layout);




}
