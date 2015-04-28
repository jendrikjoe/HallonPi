/*
 * TCPSender.h
 *
 *  Created on: Apr 10, 2015
 *      Author: Jendrik
 */

#ifndef TCPSENDER_H_
#define TCPSENDER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#define MYPORT 31725
#define CLIENTNUMBER 2



class TCPSender{

public:
	TCPSender();
	~TCPSender();

private:
	int socketNumber;
	struct sockaddr_in myAddr;
	int inputSocket;
	struct sockaddr_in remoteAddr;


};

#endif
