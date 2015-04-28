/*
 * HallonThread.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Jendrik
 *      source : http://www.bogotobogo.com/cplusplus/multithreading_pthread.php
 *      date: 15.04.2015
 */


#ifndef HALLONTHREAD_H_
#define HALLONTHREAD_H_
#include <pthread.h>
#include <error.h>
#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>

class HallonThread {

public:
	HallonThread();
	virtual ~HallonThread();
	void start();
	void* join();

private:
	pthread_t threadId;
	pthread_attr_t threadAttribute;
	HallonThread(const HallonThread&);
	const HallonThread &operator = (const HallonThread&);
	void setCompleted();
	void *result;
	virtual void* run() {return 0;};
	static void* startThread(void* pVoid);
	void printError(char * msg, int status, char* fileName, int lineNumber);


};


#endif


