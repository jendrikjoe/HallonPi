/*
 * HousekeepingCommunicationPackage.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Jendrik
 */

#ifndef HOUSEKEEPINGCOMMUNICATIONPACKAGE_H_
#define HOUSEKEEPINGCOMMUNICATIONPACKAGE_H_

#include "CommunicationPackage.h"

namespace tcp{

class HousekeepingCommunicationPackage :
		public CommunicationPackage{

public:
	HousekeepingCommunicationPackage();
	HousekeepingCommunicationPackage(char* frame);
	HousekeepingCommunicationPackage(unsigned int timestamp, unsigned short cpuAverage,
			unsigned int memoryUsed, unsigned short temperature);

	unsigned short getCpuAverage() const;
	unsigned int getMemoryUsage() const;
	unsigned short getTemperature() const;



private:
	unsigned short cpuAverage;
	unsigned int memoryUsed;
	unsigned short temperature;
	static const unsigned short packageLength;
	static const PackageType packageType;
	static const unsigned short cpuAveragePosition;
	static const unsigned short memoryUsedPosition;
	static const unsigned short temperaturePosition;

	unsigned short readCpuAverage();
	bool writeCpuAverage(unsigned short value);

	unsigned int readMemoryUsed();
	bool writeMemoryUsed(unsigned int value);

	unsigned short readTemperature();
	bool writeTemperature(unsigned short value);
};
}
#endif /* HOUSEKEEPINGCOMMUNICATIONPACKAGE_H_ */
