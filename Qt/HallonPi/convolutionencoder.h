#ifndef CONVOLUTIONENCODER_H
#define CONVOLUTIONENCODER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class ConvolutionEncoder : public QObject
{
    Q_OBJECT
public:
    explicit ConvolutionEncoder(unsigned char mask1, unsigned char mask2);
    ~ConvolutionEncoder();

signals:
    void do_setup(unsigned char, unsigned char);
    void dataEncoded(QList<unsigned short>);
    void minimalDistanceCalculated(unsigned char, double,
                                   unsigned char, unsigned char,
                                   ConvolutionEncoder *);

public slots:
    void newData(QList<unsigned char> input);
    void minimalDistance();

private slots:
    void setup(unsigned char mask1, unsigned char mask2);

private:
    unsigned short encodeData(unsigned char data);
    unsigned char resultingBit(unsigned char input);
    unsigned short calculateDistance(unsigned short code1, unsigned short code2);

    QThread *threadId;
    unsigned char mask1;
    unsigned char mask2;
    double distanceSum;
};

#endif // CONVOLUTIONENCODE_H
