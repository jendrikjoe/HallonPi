#ifndef CONVOLUTIONWINDOW_H
#define CONVOLUTIONWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QDebug>
#include <QTextBrowser>
#include "convolutiontester.h"

class ConvolutionWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ConvolutionWindow(QWidget *parent = 0);
    ~ConvolutionWindow();

signals:
    void startTest();

public slots:
    void receiveResult(unsigned char distance, double distanceSum,
                       unsigned char mask1,unsigned char mask2);
    void increasedProgress();


private slots:
    void startTester();

private:
    QVBoxLayout *mainLayout;
    QList<QHBoxLayout*> *hLayoutList;
    QList<QSpinBox*> *spinBoxList;
    QList<QLabel*> *labelList;
    QTextBrowser *output;
    QPushButton *runButton;
    ConvolutionTester *tester;
    QProgressBar *progress;

};

#endif // CONVOLUTIONWINDOW_H
