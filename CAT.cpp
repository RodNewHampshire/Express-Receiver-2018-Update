/******************************************************************************
*
* EXPRESS RECEIVER by AD5GH
* (http://www.expressreceiver.com)
* ARDUINO MEGA DISPLAY & CONTROL BOARD SOFTWARE
* BFO ROUTINES
*
* Copyright 2018 Rod Gatehouse AD5GH
* Distributed under the terms of the MIT License:
* http://www.opensource.org/licenses/mit-license
*
*
* VERSION 1.1.0
* June 16, 2018
*
********************************************************************************/


#include <CAT.h>
#include <SoftwareSerial.h>


//Static Responses

const char respAI[4] = "AI0;";
const char respDA[4] = "DA0;";
const char respFV[7] = "FV1.00;";
const char respID[6] = "ID021;";

//Dynamic Response Arrays

char _AG[4];
char _BD[2];
char _BU[2];
char _CA[1];

char respFA[14] = "FA00014095600;";
char _FB[11];
char _FL[1];
char _FR[1];
char _FT[1];
char _GC[1];
char respIF[38] = "IF00014095600     +000000000020000000;";
char _LK[2];
char _MC[3];
char respMD[4] = "MD2;";
char _MG[3];
char _MR[47];
char _MW[47];
char _PA[2];
char _PC[3];
char _RA[4];
char _RG[3];
char _SM[5];
char _TX[1];
char _XI[15];

SoftwareSerial catSerial (12, 13, 1);					// using SoftSerial to accommodate Timewave Navigator inverted TTL logic, idle = LOW

char catCommand[20];
uint8_t cmdCounter = 0;
uint8_t cmdCharacter = 0;


CAT::CAT(void)
{

}


void CAT::begin(void)
{
	catSerial.begin(9600);
}


uint8_t CAT::available(void)
{
	if(catSerial.available())
	{
		cmdCharacter = catSerial.read();

		if(cmdCharacter == ';') 
		{
			catCommand[cmdCounter] = cmdCharacter;
			for(uint8_t n = 0; n < cmdCharacter; n++) Serial.print(catCommand[n]);
			Serial.println(" ");
			execute();
			cmdCounter = 0;
		}

		else
		{
			catCommand[cmdCounter] = cmdCharacter;
			cmdCounter++;
		}
	}
}


void CAT::send(uint8_t data[], uint8_t num )
{
	for (uint8_t i=0; i<num; i++) catSerial.write(data[i]);
}


void CAT::execute(void)
{
	switch(catCommand[0])
	{
		case 'A':
			switch(catCommand[1])
			{
				case 'G':								//AF Gain
					break;

				case 'I':								//Auto Information ON/OFF
					send(respAI, 4);
					break;
			}
			break;

		case 'B':
			switch(catCommand[1])
			{
				case 'D':								//Set Frequency Band
					break;

				case 'U':								//Set Frequency Band
					break;
			}
			break;

		case 'C':
			switch(catCommand[1])
			{
				case 'A':								//CW Tune Function
					break;
			}
			break;

		case 'D':
			switch(catCommand[1])
			{
				case 'A':								//Data Mode
					send(respDA, 4);
					break;
			}
			break;

		case 'F':
			switch(catCommand[1])
			{
				case 'A':								//VFO A Frequency
					if(catCommand[2] = ';') 
					{
						send(respFA, 14);
					}
					break;

				case 'B':								//VFO B Frequency
					break;

				case 'L':								//IF Filter
					break;

				case 'R':								//Select/Read VFO or Mem Chan Mode
					break;

				case 'T':								//Select/Read VFO or Mem Chan Mode
					break;

				case 'V':								//Firmware Version
					send(respFV, 7);
					break;
			}
			break;

		case 'G':
			switch(catCommand[1])
			{
				case 'C':								//AGC
					break;
			}
			break;

		case 'I':
			switch(catCommand[1])
			{
				case 'D':								//Transceiver ID Number
					send(respID, 6);
					break;

				case 'F':								//Transceiver Status
					send(respIF, 38);
					break;
			}
			break;

		case 'L':
			switch(catCommand[1])
			{
				case 'K':								//Lock Status
					break;
			}
			break;

		case 'M':
			switch(catCommand[1])
			{
				case 'C':								//Memory Channel Number
					break;

				case 'D':								//Operating Mode
					send(respMD, 4);
					break;

				case 'G':								//Microphone Gain
					break;

				case 'R':								//Memory Channel Data
					break;

				case 'W':								//Memory Channel Data
					break;
			}
			break;

		case 'P':
			switch(catCommand[1])
			{
				case 'A':								//Pre-amplifier Function
					break;

				case 'C':								//Output Power
					break;
			}
			break;

		case 'R':
			switch(catCommand[1])
			{
				case 'A':								//RF Attenuator
					break;

				case 'G':								//RF Gain Status
					break;
			}
			break;

		case 'S':
			switch(catCommand[1])
			{
				case 'M':								//S-Meter
					break;
			}
			break;

		case 'T':
			switch(catCommand[1])
			{
				case 'X':								//Transmission Mode
					break;
			}
			break;

		case 'X':
			switch(catCommand[1])
			{
				case 'I':								//Transmit Frequency & Mode
					break;
			}
			break;
		break;
	}
}
