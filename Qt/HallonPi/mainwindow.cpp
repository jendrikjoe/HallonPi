#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Style
    this->setStyleSheet("QWidget{background:black}; \
            QTabBar::tab:selected,QTabBar::tab:hover{color:red};");
    // Adapt size to Desktop size
    desktopSize = new QDesktopWidget();
    this->resize(desktopSize->size());

    // Tab Widgets
    tabWidget = new QTabWidget(this);
    this->setCentralWidget(tabWidget);

    tcpComWidget = new QWidget(tabWidget);
    tabWidget->addTab(tcpComWidget, "TCP");
    tabWidget->tabBar()->setTabTextColor(0, Qt::red);

    adcWidget = new QWidget(tabWidget);
    tabWidget->addTab(adcWidget, "ADC");
    tabWidget->tabBar()->setTabTextColor(1, Qt::red);
    tabWidget->setFixedWidth(0.8*desktopSize->width());

    houseKeeping = new QDockWidget(this);
    houseKeeping->setFeatures(QDockWidget::NoDockWidgetFeatures);
    houseKeeping->setFixedWidth(0.2*desktopSize->width());
    this->addDockWidget(Qt::LeftDockWidgetArea, houseKeeping);

    adcLayout = new QGridLayout();

    adcChooseChannelLabel = new QLabel();
    adcChooseChannelLabel->setText("ADC Channel");
    adcChooseChannelLabel->setStyleSheet("QLabel {color : red}");
    adcChooseChannelBox = new QComboBox();
    QString adcChannels = "1;2;3;4;5;6;7;8";
    const QStringList adcChannelList = adcChannels.split(";");
    adcChooseChannelBox->addItems(adcChannelList);
    adcChooseChannelBox->setStyleSheet("QItem {color : red}");
    adcLayout->addWidget(adcChooseChannelLabel, 0, 0);
    adcLayout->addWidget(adcChooseChannelBox, 0, 1);


    adcAverage = new QCheckBox("Average Voltage");
    //adcAverage->setStyleSheet("QCheckBox::indicator {width: 13px;height: 13px;}");
    adcAverage->setStyleSheet(QString("QCheckBox {color : red; font : bold; font : 20px; border : 2px}") +
                              QString("QCheckBox::indicator { width:20px; height: 20px; border : 2px}") +
                              QString("QCheckBox::indicator:unchecked { background-color : white;}") +
                              QString("QCheckBox::indicator:checked {color : red; background-color : off; }"));
    adcLayout->addWidget(adcAverage, 1, 0, 1, 2);

    adcWidget->setLayout(adcLayout);

}

MainWindow::~MainWindow()
{
    delete adcWidget;
    delete tcpComWidget;
    delete tabWidget;
}
