/*
 * CommunicationPackage.h
 *
 *  Created on: Apr 10, 2015
 *      Author: Jendrik
 */

#include "PackageType.h"
#define UINTSIZE 4
#define DOUBLESIZE 8
#define FLOATSIZE 4
#define USHORTSIZE 2

namespace tcp{


class CommunicationPackage{

public:
	void getFrame(char *output) const;
	unsigned int getTimeStamp() const;
	bool isValid() const;
	bool isStarting(char *input);
	bool test();

	static const char starting[2];
	static const char ending[2];
	static const unsigned short timeStampPos;
	static const unsigned short packageTypePos;



private:
	unsigned short packageLength;
	char *frame;
	bool valid;
	unsigned int timeStamp;
	PackageType packageType;
	void writeStart();
	void readStart(char *output);

	void writeEnd();
	void readEnd(char *output);

	unsigned int readTimeStamp();

	unsigned int getUIntFromFrame(unsigned short position);
	void putUIntToFrame(unsigned int input, unsigned short position);

	unsigned int char2UInt(char *data);
	void uInt2Char(unsigned int input, char *output);

	float getFlaotFromFrame(unsigned short position);
	void putFloatToFrame(float input, unsigned short position);

	float char2Float(char *data);
	void float2Char(float input, char *output);

	unsigned short getUShortFromFrame(unsigned short position);
	void putUShortToFrame(unsigned short input, unsigned short position);

	unsigned short char2UShort(char *data);
	void uShort2Char(unsigned short input, char *output);

	double getDoubleFromFrame(unsigned short position);
	void putDoubleToFrame(double input, unsigned short position);

	double char2Double(char *data);
	void double2Char(double input, char *output);


protected:
	static const unsigned short floatBytes;
	static const unsigned short doubleBytes;
	static const unsigned short uIntBytes;
	static const unsigned short uShortBytes;


	CommunicationPackage();
	CommunicationPackage(const CommunicationPackage &input);
	CommunicationPackage(char *frame, PackageType type, unsigned short packageLength);
	~CommunicationPackage();

};

}