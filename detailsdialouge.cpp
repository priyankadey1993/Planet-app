#include "detailsdialouge.h"
#include<QDialog>
DetailsDialouge::DetailsDialouge(const PlanetInfo &info, QWidget *parent)
    : QDialog(parent), info(info)
{

    setup_ui();
}

void DetailsDialouge::setup_ui()
{
    setWindowTitle(info.name + " Details");
    resize(520, 560);

   auto mainLayout = new QVBoxLayout(this);

    nameLabel = new QLabel(info.name);
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);

    QPixmap pix(info.imagePath);
    if (!pix.isNull())
    {
        imageLabel->setPixmap(pix.scaled(250, 250, Qt::KeepAspectRatio,
                                         Qt::SmoothTransformation));
    }
    else
    {
        imageLabel->setText("Image not found");
    }
    detailsLabel = new QLabel(info.detail);
    detailsLabel->setWordWrap(true);

    detailsLabel->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    detailsLabel->setStyleSheet("font-size: 15px;");

    auto *scroll = new QScrollArea;
    scroll->setWidgetResizable(true);

    QWidget *content = new QWidget;
    auto *contentLayout = new QVBoxLayout(content);
    contentLayout->addWidget(detailsLabel);
    contentLayout->addStretch(true);
    content->setLayout(contentLayout);

    scroll->setWidget(content);
    auto *closeButton = new QPushButton("Close");
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);



    mainLayout->addWidget(nameLabel);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(scroll);
    mainLayout->addWidget(closeButton,0,Qt::AlignCenter);
  //  setLayout(layout);

}


