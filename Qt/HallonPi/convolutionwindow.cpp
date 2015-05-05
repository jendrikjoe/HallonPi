#include "convolutionwindow.h"

ConvolutionWindow::ConvolutionWindow(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("");
    mainLayout = new QVBoxLayout(this);
    hLayoutList = new QList<QHBoxLayout*>();
    labelList = new QList<QLabel*>();
    spinBoxList = new QList<QSpinBox*>();
    hLayoutList->append(new QHBoxLayout());
    labelList->append(new QLabel("Register Length",this));
    spinBoxList->append(new QSpinBox(this));
    spinBoxList->last()->setMaximum(8);
    spinBoxList->last()->setMinimum(0);
    hLayoutList->last()->addWidget(labelList->last());
    hLayoutList->last()->addWidget(spinBoxList->last());
    mainLayout->addLayout(hLayoutList->last());

    hLayoutList->append(new QHBoxLayout());
    output = new QTextBrowser(this);
    runButton = new QPushButton("Run", this);
    runButton->setFixedSize(40,40);
    hLayoutList->last()->addWidget(output);
    hLayoutList->last()->addWidget(runButton);
    mainLayout->addLayout(hLayoutList->last());
    progress = new QProgressBar(this);
    mainLayout->addWidget(progress);
    progress->setMaximum(100);

    tester = new ConvolutionTester();
    connect(runButton, SIGNAL(clicked()),
            this, SLOT(startTester()));
    connect(tester, SIGNAL(newResult()), this, SLOT(increasedProgress()));
    connect(tester, SIGNAL(optimumFound(unsigned char, double, unsigned char,unsigned char)),
            this, SLOT(receiveResult(unsigned char, double, unsigned char,unsigned char)));
    connect(this,SIGNAL(startTest()), tester, SLOT(startTest()));
}

void ConvolutionWindow::startTester() {
    unsigned char spinBoxValue = spinBoxList->first()->value();
    qDebug() << QString::number(((pow(2,spinBoxValue)-2)*(pow(2,spinBoxValue)-1)/2));
    progress->setMaximum((pow(2,spinBoxValue)-2)*(pow(2,spinBoxValue)-1)/2);
    progress->setValue(0);
    tester->setRegisterLength(spinBoxList->first()->value());
    emit startTest();
}

void ConvolutionWindow::receiveResult(unsigned char distance, double distanceSum, unsigned char mask1, unsigned char mask2) {
    output->append("Maximal Distance: " + QString::number(distance) +
                   "Distance Sum: " + QString::number((double)distanceSum) +
                         "Mask1: " + QString::number(mask1) +
                         "Mask2: " + QString::number(mask2) + "\n");
}

void ConvolutionWindow::increasedProgress() {
    progress->setValue(progress->value()+1);
}


ConvolutionWindow::~ConvolutionWindow()
{
    for(int i=0; i<hLayoutList->length(); i++) {
        delete hLayoutList->at(i);
    }
    delete hLayoutList;
    delete labelList;
    delete spinBoxList;
    delete tester;
}

