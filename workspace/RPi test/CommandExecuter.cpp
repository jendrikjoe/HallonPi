/*
 * CommandExecuter.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: Jendrik
 */

#include "CommandExecuter.h"

CommandExecuter::CommandExecuter(RingBuffer<tcp::CommandCommunicationPackage> *commandBuffer,
		sem_t *commandSemaphore) : HallonThread(),
		commandBuffer(commandBuffer), commandSemaphore(commandSemaphore) {
	// TODO Auto-generated constructor stub

}

void* CommandExecuter::run() {
	tcp::CommandCommunicationPackage commandPackage;
	tcp::CommandNumber command;
	while(runBool) {
		sem_wait(commandSemaphore);
		commandPackage = commandBuffer->getElement();
		command = commandPackage.getCommandNumber();
		//TODO Command implementation
		std::cout << command << std::endl;
	}
}

CommandExecuter::~CommandExecuter() {
	// TODO Auto-generated destructor stub
}

