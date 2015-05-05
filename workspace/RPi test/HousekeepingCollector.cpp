/*
 * HousekeepingCollector.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: Jendrik
 */

#include "HousekeepingCollector.h"

const std::string HousekeepingCollector::readpathCPU = std::string("/proc/stat");
const std::string HousekeepingCollector::readpathMemory = std::string("/proc/meminfo");
const std::string HousekeepingCollector::readpathTemperature = std::string("/sys/class/thermal/thermal_zone0/temp");


HousekeepingCollector::HousekeepingCollector(
		RingBuffer<tcp::HousekeepingCommunicationPackage> *houseBuffer) :
		HallonThread(), houseBuffer(houseBuffer) {
	usage = 0;
	usageBuffer = 0;
	cpuLoad = 0;
	temperature = 0;
}

void* HousekeepingCollector::run() {
	std::ifstream housestream;
	std::string line;
	int buffer;
	usageBuffer = 0;
	housestream.open(readpathCPU.c_str());
	std::getline(housestream, line);
	buffer = line.find(' ',0);
	usageBuffer += atof((line.substr(buffer)).c_str());
	buffer = line.find_first_not_of(' ', buffer);
	buffer = line.find(' ',buffer);
	usageBuffer += atof((line.substr(buffer)).c_str());
	buffer = line.find_first_not_of(' ', buffer);
	buffer = line.find(' ',buffer);
	usageBuffer += atof((line.substr(buffer)).c_str());
	sleep(1);
	while(runBool) {
		//Get CPU usage:
		usage = 0;
		housestream.open(readpathCPU.c_str());
		std::getline(housestream, line);
		buffer = line.find(' ',0);
		usage += atof((line.substr(buffer)).c_str());
		buffer = line.find_first_not_of(' ', buffer);
		buffer = line.find(' ',buffer);
		usage += atof((line.substr(buffer)).c_str());
		buffer = line.find_first_not_of(' ', buffer);
		buffer = line.find(' ',buffer);
		usage += atof((line.substr(buffer)).c_str());
		cpuLoad = 1.*(usage - usageBuffer) / 400.;
		usageBuffer = usage;
		housestream.close();

		//Get memory used:
		housestream.open(readpathMemory.c_str());
		std::getline(housestream, line);
		buffer = line.find(' ',0);
		memoryUsed = atof((line.substr(buffer)).c_str());
		std::getline(housestream, line);
		buffer = line.find(' ',0);
		memoryUsed -= atof((line.substr(buffer)).c_str());
		housestream.close();

		//Get temperature:
		housestream.open(readpathTemperature.c_str());
		std::getline(housestream, line);
		temperature = atof(line.c_str())/1000;
		housestream.close();

		tcp::HousekeepingCommunicationPackage house = tcp::HousekeepingCommunicationPackage(time(NULL), cpuLoad, memoryUsed, temperature);
		houseBuffer->writeElementToBuffer(house);
		/*std::cout << "CPU: " <<  house.getCpuAverage()
				  << "\tMemory used[MB]: " << ((double)house.getMemoryUsage())/1000
				  << "\tTemperature [C]: " << house.getTemperature() << std::endl;*/
		sleep(1);
	}
	return 0;
}


HousekeepingCollector::~HousekeepingCollector() {
	// TODO Auto-generated destructor stub
}

