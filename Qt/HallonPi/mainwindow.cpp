#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->resize(1200, 675);
    this->setStyleSheet("QWidget{background:black}; \
            QTabBar::tab:selected,QTabBar::tab:hover{color:red};");
    tabWidget = new QTabWidget(this);
    this->setCentralWidget(tabWidget);

    tcpComWidget = new QWidget(tabWidget);
    tabWidget->addTab(tcpComWidget, "TCP");

    adcWidget = new QWidget(tabWidget);
    tabWidget->addTab(adcWidget, "ADC");




}

MainWindow::~MainWindow()
{
    delete adcWidget;
    delete tcpComWidget;
    delete tabWidget;
}
