/*
 * TCPSender.h
 *
 *  Created on: Apr 10, 2015
 *      Author: Jendrik
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include <semaphore.h>

#include "Global.h"
#include "HallonThread.h"
#include "RingBuffer.h"
#include "TCPSender.h"
#include "TCPReceiver.h"

#define MYPORT 31725
#define CLIENTNUMBER 2

extern bool runBool;

class TCPServer : public HallonThread{

public:
	TCPServer(const std::map<tcp::PackageType,void*> &bufferMap,
			RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer,
			sem_t *tcpReadSemaphore, sem_t* commandSemaphore);
	~TCPServer();

private:
	int socketNumber;
	struct sockaddr_in myAddr;
	struct sockaddr_in remoteAddr;
	const std::map<tcp::PackageType, void*> bufferMap;
	sem_t *tcpReadSemaphore;
	RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer;
	sem_t *commandSemaphore;
	void* run();


};

#endif
