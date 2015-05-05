#include "convolutiontester.h"

ConvolutionTester::ConvolutionTester() : QObject()
{
    threadId = new QThread();
    threadId->start();
    this->moveToThread(threadId);

    connect(this, SIGNAL(do_setup()),this, SLOT(setup()));
    emit do_setup();
}


void ConvolutionTester::setup() {
    maxNumberOfThreads = 10;
    currentNumberOfThreads = 0;
    maximumHamming = 0;
    bestMask1 = 0;
    bestMask2 = 0;
    counterMask1 = 0;
    counterMask2 = 0;
    registerLength = 0;
    length = 0;
    done = false;
    encoderList = new QList<ConvolutionEncoder*>();
}


void ConvolutionTester::startTest() {
    qDebug() << "Test started";
    encoderList->clear();
    counterMask1 = pow(2,registerLength);
    counterMask2 = 0;
    maximumHamming = 0;
    length = 0;
    done = false;
    for(int i=0; i< maxNumberOfThreads; i++) {
        startThread();
    }
}

void ConvolutionTester::startThread() {
    if(counterMask2<counterMask1) {
        ConvolutionEncoder *encoder = new ConvolutionEncoder(counterMask1,counterMask2);
        connect(encoder, SIGNAL(minimalDistanceCalculated(unsigned char, double, unsigned char,unsigned char,ConvolutionEncoder*)),
                this, SLOT(receiveResult(unsigned char, double, unsigned char,unsigned char, ConvolutionEncoder*)));
        encoderList->append(encoder);
        counterMask2++;
    }
    else {
        counterMask1--;
        if (counterMask1==0) {
            done = true;
        }
        else {
           counterMask2 = 0;
           ConvolutionEncoder *encoder = new ConvolutionEncoder(counterMask1,counterMask2);
           connect(encoder, SIGNAL(minimalDistanceCalculated(unsigned char, double, unsigned char,unsigned char,ConvolutionEncoder*)),
                   this, SLOT(receiveResult(unsigned char, double, unsigned char ,unsigned char, ConvolutionEncoder*)));
           encoderList->append(encoder);
           counterMask2++;
        }
    }
}

void ConvolutionTester::receiveResult(unsigned char distance, double distanceSum,
                                      unsigned char mask1, unsigned char mask2,
                                      ConvolutionEncoder* encoder) {
    qDebug() << "Result Received: " << "distance: " << QString::number(distance)
             << "distance avg: " << QString::number(distanceSum)
             << " mask1: " << QString::number(mask1)
             << " mask2: " << QString::number(mask2) << "\n";
    if (maximumHamming <= distance) {
        if (maximumHamming < distance) {
            maximumHamming = distance;
            bestMask1 = mask1;
            bestMask2 = mask2;
            distAvg = distanceSum;
        }
        else if (distAvg < distanceSum) {
            maximumHamming = distance;
            bestMask1 = mask1;
            bestMask2 = mask2;
            distAvg = distanceSum;
        }
    }
    emit newResult();
    disconnect(encoder, SIGNAL(minimalDistanceCalculated(unsigned char, double, unsigned char,unsigned char,ConvolutionEncoder*)),
               this, SLOT(receiveResult(unsigned char, double, unsigned char,unsigned char,ConvolutionEncoder*)));
    if (!encoderList->removeOne(encoder)) {
        length +=1;
    }
    delete encoder;
    if(!done) {
        startThread();
    }
    if(encoderList->length()==0) {
        emit optimumFound(maximumHamming, distAvg, bestMask1, bestMask2);
    }
}


void ConvolutionTester::setRegisterLength(unsigned char length) {
    registerLength = length;
}




ConvolutionTester::~ConvolutionTester()
{
    threadId->terminate();
}

