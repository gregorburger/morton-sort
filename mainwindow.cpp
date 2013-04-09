#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "morton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    this->addAction(ui->actionDraw);
    draw();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *) {
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::draw() {
    scene->clear();

    std::vector<vector> points(10000);

    gen_random(points);
    morton_sort(points);

    for (size_t i = 0; i < points.size() - 1; ++i) {
        scene->addLine(points[i].x, points[i].y, points[i+1].x, points[i+1].y);
    }
}


void MainWindow::on_actionDraw_triggered() {
    draw();
}
