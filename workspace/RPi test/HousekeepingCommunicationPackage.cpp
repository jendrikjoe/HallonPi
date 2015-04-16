/*
 * HousekeepingCommunicationPackage.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: Jendrik
 */

#include "HousekeepingCommunicationPackage.h"

namespace tcp {

const unsigned short HousekeepingCommunicationPackage::cpuAveragePosition = 10;
const unsigned short HousekeepingCommunicationPackage::packageLength = 14;
const PackageType HousekeepingCommunicationPackage::packageType = HOUSE_COM;


HousekeepingCommunicationPackage::HousekeepingCommunicationPackage() :
CommunicationPackage() {
	this->cpuAverage = 0;
}

HousekeepingCommunicationPackage::HousekeepingCommunicationPackage(char* frame) :
	CommunicationPackage(frame, packageType, packageLength){
	if(!valid) {
		this->cpuAverage = 0;
	}
	else  {
		this->cpuAverage = readCpuAverage();
	}
}

HousekeepingCommunicationPackage::HousekeepingCommunicationPackage(unsigned int timestamp, unsigned short cpuAverage) :
		CommunicationPackage(packageType, timestamp, packageLength){
	this->cpuAverage = cpuAverage;
	if(!writeCpuAverage(this->cpuAverage)) valid = false;
}

HousekeepingCommunicationPackage::~HousekeepingCommunicationPackage() {
	// TODO Auto-generated destructor stub
}

unsigned short HousekeepingCommunicationPackage::readCpuAverage() {
	getUShortFromFrame(cpuAveragePosition);
}

bool HousekeepingCommunicationPackage::writeCpuAverage(unsigned short value) {
	return putUShortToFrame(value, cpuAveragePosition);
}

}
