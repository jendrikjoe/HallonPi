/*
 * CommandExecuter.h
 *
 *  Created on: Apr 27, 2015
 *      Author: Jendrik
 */

#ifndef COMMANDEXECUTER_H_
#define COMMANDEXECUTER_H_

#include "HallonThread.h"
#include "Global.h"
#include "RingBuffer.h"
#include "semaphore.h"

extern bool runBool;

class CommandExecuter: public HallonThread {
public:
	CommandExecuter(RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer,
			sem_t *commandSemaphore);
	virtual ~CommandExecuter();
private:
	RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer;
	sem_t *commandSemaphore;
	void* run();
};

#endif /* COMMANDEXECUTER_H_ */
