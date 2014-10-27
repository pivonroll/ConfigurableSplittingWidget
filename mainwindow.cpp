#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "configurablewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(new ConfigurableWidget(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
