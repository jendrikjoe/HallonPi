/*
 * test.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Jendrik
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "GPIOAccess.h"
#include <unistd.h>
#include <wiringPi.h>
#include "BitStruct.h"
#include "TCPSender.h"
using namespace std;

int main (void)
{
  wiringPiSetup();
  pinMode(7, OUTPUT);
  /*bitcalc::intstruct test;
  bitcalc::bytestruct test2;
  test2.byte = 2;
  cout << sizeof(unsigned int) << sizeof(long) << endl;
  cout << test2.bit1 << test2.bit2 << test2.bit3 << test2.bit4
		  << test2.bit5 << test2.bit6 << test2.bit7 << test2.bit8 << endl;
  test.integer = 0xffffffff;
  unsigned char output = test.byte4;
  test2.byte = output;
  cout << test2.bit1 << test2.bit2 << test2.bit3 << test2.bit4
  		  << test2.bit5 << test2.bit6 << test2.bit7 << test2.bit8;
  output = test.byte3;
  test2.byte = output;
  cout << test2.bit1 << test2.bit2 << test2.bit3 << test2.bit4
    		  << test2.bit5 << test2.bit6 << test2.bit7 << test2.bit8;
  output = test.byte2;
  test2.byte = output;
  cout << test2.bit1 << test2.bit2 << test2.bit3 << test2.bit4
      		  << test2.bit5 << test2.bit6 << test2.bit7 << test2.bit8;
  output = test.byte1;
  test2.byte = output;
    cout << test2.bit1 << test2.bit2 << test2.bit3 << test2.bit4
        		  << test2.bit5 << test2.bit6 << test2.bit7 << test2.bit8 << endl;

	*/
  TCPSender *tcpSender = new TCPSender();
  return 0 ;
}

