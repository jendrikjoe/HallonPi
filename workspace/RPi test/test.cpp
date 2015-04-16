/*
 * test.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Jendrik
 */

#include <wiringPi.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GPIOAccess.h"
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "BitStruct.h"
#include "TCPSender.h"
#include "global.h"


#define NUMBEROFTHREADS 4

using namespace std;




int main (void)
{
  wiringPiSetup();
  pinMode(7, OUTPUT);
  pthread_t tcpThread;
  int control;
  tcp::ADCCommunicationPackage *adcPack = new tcp::ADCCommunicationPackage(1000,15);
  cout << adcPack->getADCValue() << " " << adcPack->getTimeStamp() <<endl;
  char test[500];
  adcPack->getFrame(test);
  tcp::ADCCommunicationPackage *adcPack2 = new tcp::ADCCommunicationPackage(test);
  cout << adcPack2->getADCValue() << " " << adcPack2->getTimeStamp() <<endl;
}


