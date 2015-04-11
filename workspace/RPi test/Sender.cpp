/*
 * Sender.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: Jendrik
 */

#define CRC32MASKREV 0xEDB88320
#include "Sender.h"

Sender::Sender(){
	sendBuffer = new char[102400];
}

Sender::~Sender(){
	delete sendBuffer;
}

