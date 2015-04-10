/*
 * GPIOAccess.h
 *
 *  Created on: Mar 17, 2015
 *      Author: Jendrik
 */

#ifndef GPIOACCESS_H_
#define GPIOACCESS_H_

#include<string>
using namespace std;

class GPIOAccess{

public:
	GPIOAccess(string number); //opens GPIO-pin with the number x
	int exportGpio();	//exports the GPIO-pin
	int unexportGpio(); //unexports the GPIO-pin
	int setDirection(string dir); //sets the direction of the GPIO to dir
	int setValGpio(string val); //sets the pin to val
	int getValGpio(string &val); //gets the pin value
	string getGpioNumber(); // returns the ports number
private:
	string gpioNumber;
};




#endif /* GPIOACCESS_H_ */
