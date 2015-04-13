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
#include <time.h>
#include "BitStruct.h"
#include "TCPSender.h"
#include "global.h"

#define NUMBEROFTHREADS 4

using namespace std;



void *startTCP(void* threadid){
	printf("Hello World");
	//TCPSender *tcpSender = new TCPSender();
	pthread_exit(NULL);
}

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
  //tcp::CommunicationPackage *package = new tcp::CommunicationPackage();
  //startTCP((void*) tcpThread);
  /*cout << "Before thread" << endl;
  control = pthread_create(&tcpThread, NULL, startTCP, (void*) tcpThread);
  if (control){
           printf("ERROR; return code from pthread_create() is %d\n", control);
           exit(-1);
        }
  pthread_exit(NULL);*/
}


