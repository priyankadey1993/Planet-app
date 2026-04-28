#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),tabs(new QTabWidget)

{
    setWindowTitle("Planet Information App");
    resize(800, 650);
    setCentralWidget(tabs);
    qApp->setStyleSheet("QWidget { background-color: #000000; color: white; }"
                        "QPushButton { background-color: #222222; color: white; border-radius: 6px; padding: 6px 12px; }"
                        "QPushButton:hover { background-color: #444444; }"
                        "QTabWidget::pane { background-color: #000000; }"
                        "QTabBar::tab { background-color: #111111; color: white; padding: 8px 16px; }"
                        "QTabBar::tab:selected { background-color: #333333; }");
    createTabs();
//    ui->setupUi(this);
}

void MainWindow ::createTabs()
{
    planets = {
        {"Mercury", ":/mercury.jpg", "Mercury is the smallest planet and closest to the Sun. It has a rocky surface and very thin atmosphere."},
        {"Venus", ":/venus.jpg", "Venus has a thick atmosphere made mostly of carbon dioxide. It is the hottest planet in the solar system."},
        {"Earth", ":/earth.jpeg", "Earth is the third planet from the Sun and the only known planet that supports life."},
        {"Mars", ":/mars.png", "Mars is called the Red Planet because of iron oxide on its surface. It has the tallest volcano in the solar system."},
        {"Jupiter", ":/jupiter.jpeg", "Jupiter is the largest planet in the solar system. It is a gas giant with a famous Great Red Spot."},
        {"Saturn", ":/saturn.jpg", "Saturn is known for its beautiful ring system. It is also a gas giant."},
        {"Uranus", ":/uranus.jpg", "Uranus is an ice giant with a bluish color. It rotates on its side."},
        {"Neptune", ":/naptune.jpg", "Neptune is a cold, windy ice giant and the farthest known planet from the Sun."}
    };

    for (int i = 0; i < planets.size(); ++i) {
        const auto &planet = planets[i];
        auto *tab = new planetTab(planet);
        connect(tab, &planetTab::detailRequested, this, [this](const PlanetInfo &info) {
            DetailsDialouge dialog(info, this);
            dialog.exec();
        });
        tabs->addTab(tab, planet.name);
    }

}

MainWindow::~MainWindow()
{
 //   delete ui;
}
