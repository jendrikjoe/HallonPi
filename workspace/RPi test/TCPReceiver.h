/*
 * TCPReceiver.h
 *
 *  Created on: Apr 27, 2015
 *      Author: Jendrik
 */

#ifndef TCPRECEIVER_H_
#define TCPRECEIVER_H_

#include "HallonThread.h"
#include "Global.h"
#include "RingBuffer.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <semaphore.h>

extern bool runBool;

class TCPReceiver: public HallonThread {
public:
	TCPReceiver(int inputSocket, struct sockaddr_in remoteAddress,
			RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer,
			sem_t* commandSemaphore);

	virtual ~TCPReceiver();

private:
	int inputSocket;
	struct sockaddr_in remoteAddress;
	std::string buffer;
	RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer;
	sem_t* commandSemaphore;
	void* run();

};

#endif /* TCPRECEIVER_H_ */
