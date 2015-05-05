#ifndef CONVOLUTIONTESTER_H
#define CONVOLUTIONTESTER_H

#include <QObject>
#include <math.h>
#include <QDebug>
#include "convolutionencoder.h"

class ConvolutionTester : public QObject
{
    Q_OBJECT
public:
    explicit ConvolutionTester();
    ~ConvolutionTester();

signals:
    void do_setup();
    void optimumFound(unsigned char, double, unsigned char,
                      unsigned char);
    void newResult();

public slots:
    void startTest();
    void receiveResult(unsigned char distance, double distanceSum,
                       unsigned char mask1, unsigned char mask2, ConvolutionEncoder*);
    void setRegisterLength(unsigned char length);

private slots:
    void setup();

private:
    void startThread();
    QThread *threadId;
    QList<ConvolutionEncoder*> *encoderList;
    unsigned char maxNumberOfThreads;
    unsigned char registerLength;
    unsigned char currentNumberOfThreads;
    unsigned char maximumHamming;
    unsigned char bestMask1;
    unsigned char bestMask2;
    int counterMask1;
    int counterMask2;
    double distAvg;
    int length;
    bool done;

};

#endif // CONVOLUTIONTESTER_H
