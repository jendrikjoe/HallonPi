/*
 * HousekeepingCollector.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Jendrik
 */

#ifndef HOUSEKEEPINGCOLLECTOR_H_
#define HOUSEKEEPINGCOLLECTOR_H_

#include "HallonThread.h"
#include "RingBuffer.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Global.h"
#include <stdio.h>

extern bool runBool;


class HousekeepingCollector : public HallonThread {

public:
	HousekeepingCollector(RingBuffer<tcp::HousekeepingCommunicationPackage>* houseBuffer);

	virtual ~HousekeepingCollector();


private:
	RingBuffer<tcp::HousekeepingCommunicationPackage> *houseBuffer;
	const static std::string readpathCPU;
	const static std::string readpathMemory;
	const static std::string readpathTemperature;
	void* run();
	unsigned long usage;
	unsigned long usageBuffer;
	double cpuLoad;
	unsigned int memoryUsed;
	unsigned short temperature;
};



#endif /* HOUSEKEEPINGCOLLECTOR_H_ */
