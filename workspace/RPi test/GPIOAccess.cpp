/*
 * GPIOAccess.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Jendrik
 */


#include "GPIOAccess.h"

using namespace std;

GPIOAccess::GPIOAccess(string number){
	this->gpioNumber = number;
}

int GPIOAccess::exportGpio(){
	string exportStr = "/sys/class/gpio/export";
	ofstream exportStream(exportStr.c_str());
	if(exportStream <0)
	{
		cout <<"Unable to export GPIO!" <<this;
		return -1;
	}
	exportStream << this->gpioNumber;
	exportStream.close();
	return 0;
}

int GPIOAccess::unexportGpio(){
	string unexportStr = "/sys/class/gpio/unexport";
	ofstream unexportStream(unexportStr.c_str());
	if(unexportStream <0)
	{
		cout <<"Unable to unexport GPIO!" <<this;
		return -1;
	}
	unexportStream << this->gpioNumber;
	unexportStream.close();
	return 0;
}

int GPIOAccess::setDirection(string val){
	string setDirStr = "/sys/class/gpio/gpio" + this->gpioNumber + "/direction";
	ofstream setDirStream(setDirStr.c_str());
		if(setDirStream <0)
		{
			cout <<"Unable to set Direction!" <<this;
			return -1;
		}
		setDirStream << val;
		setDirStream.close();
		return 0;
}

int GPIOAccess::setValGpio(string val){
	string setValStr = "/sys/class/gpio/gpio" + this->gpioNumber + "/value";
	ofstream setValueStream(setValStr.c_str());
		if(setValueStream <0)
		{
			cout <<"Unable to set value GPIO!" <<this;
			return -1;
		}
		setValueStream << val;
		setValueStream.close();
		return 0;
}

int GPIOAccess::getValGpio(string &val){
	string getValStr = "/sys/class/gpio/gpio" + this->gpioNumber + "/value";
	ifstream getValueStream(getValStr.c_str());
		if(getValueStream <0)
		{
			cout <<"Unable to get value GPIO!" <<this;
			return -1;
		}
		getValueStream >> val;
		getValueStream.close();
		if(val != "0"){
			val ="1";
		}
		else val ="0";

		return 0;
}

string GPIOAccess::getGpioNumber(){
	return this->gpioNumber;
}




