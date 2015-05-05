#include "convolutionencoder.h"

ConvolutionEncoder::ConvolutionEncoder(unsigned char mask1, unsigned char mask2) : QObject()
{
    threadId = new QThread();
    threadId->start();
    this->moveToThread(threadId);

    connect(this, SIGNAL(do_setup(unsigned char, unsigned char)),
            this, SLOT(setup(unsigned char, unsigned char)));
    emit do_setup(mask1, mask2);

}

void ConvolutionEncoder::newData(QList<unsigned char> input) {
    QList<unsigned short> result;
    result.clear();
    for (int i=0; i<input.length(); i++) {
        result.append(this->encodeData(input.at(i)));
    }
    emit dataEncoded(result);
}

void ConvolutionEncoder::minimalDistance() {
    QList<unsigned short> resultList;
    resultList.clear();
    unsigned short minimum = 1000, buffer;
    for (int i=0; i<256; i++) {
        resultList.append(encodeData(i));
    }
    for (int i=resultList.length()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            buffer = calculateDistance(resultList.at(i), resultList.at(j));
            distanceSum += (double)(buffer)/(128.*257.);
            if (buffer < minimum) minimum = buffer;
        }
    }
    emit minimalDistanceCalculated(minimum, distanceSum, mask1, mask2, this);
}


void ConvolutionEncoder::setup(unsigned char mask1, unsigned char mask2) {
    this->mask1 = mask1;
    this->mask2 = mask2;
    this->distanceSum = 0;
    minimalDistance();
}


unsigned short ConvolutionEncoder::encodeData(unsigned char data) {
    unsigned short result = 0;
    unsigned char shiftRegister = 0;
    for (int i=0; i<8; i++) {
        shiftRegister += data/128;
        result += resultingBit(shiftRegister & mask1);
        result <<= 1;
        result += resultingBit(shiftRegister & mask2);
        result <<= 1;
        shiftRegister <<= 1;
        data <<= 1;
    }
    //qDebug() << result;
    return result;
}

unsigned char ConvolutionEncoder::resultingBit(unsigned char input) {
    input = (unsigned char) (input & 0x55) + (unsigned char) ((input>>1) & 0x55);
    input = (unsigned char) (input & 0x33) + (unsigned char) ((input>>2) & 0x33);
    input = (unsigned char) (input & 0x0F) + (unsigned char) ((input>>4) & 0x0F);
    return input%2;
}

unsigned short ConvolutionEncoder::calculateDistance(unsigned short code1, unsigned short code2) {
    code1 ^= code2;
    code1 = (unsigned short) (code1 & 0x5555) + (unsigned short) ((code1 >> 1) & 0x5555);
    code1 = (unsigned short) (code1 & 0x3333) + (unsigned short) ((code1 >> 2) & 0x3333);
    code1 = (unsigned short) (code1 & 0x0F0F) + (unsigned short) ((code1 >> 4) & 0x0F0F);
    code1 = (unsigned short) (code1 & 0x00FF) + (unsigned short) ((code1 >> 8) & 0x00FF);
    return code1;
}


ConvolutionEncoder::~ConvolutionEncoder()
{
    threadId->terminate();
}

