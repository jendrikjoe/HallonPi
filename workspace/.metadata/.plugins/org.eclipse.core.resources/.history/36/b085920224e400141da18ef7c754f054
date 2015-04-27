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
	HousekeepingCommunicationPackage(unsigned int timestamp, unsigned short cpuAverage);


	virtual ~HousekeepingCommunicationPackage();

private:
	unsigned short cpuAverage;
	static const unsigned short packageLength;
	static const PackageType packageType;
	static const unsigned short cpuAveragePosition;

	unsigned short readCpuAverage();
	bool writeCpuAverage(unsigned short value);
};
}
#endif /* HOUSEKEEPINGCOMMUNICATIONPACKAGE_H_ */
