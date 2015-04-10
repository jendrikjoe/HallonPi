/*
 * Sender.h
 *
 *  Created on: Mar 18, 2015
 *      Author: Jendrik
 */
#include <wiringPi.h>

#ifndef SENDER_H_
#define SENDER_H_

class Sender{
public:
	Sender();
	~Sender();
	int sendChars(char* data, int len);


private:
	char *sendBuffer;
	char encryptData(char);


};



#endif /* SENDER_H_ */
