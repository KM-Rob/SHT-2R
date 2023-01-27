/*

SYH_2R.h

This code records data 

 */

#include "Arduino.h"


#define DELAY 1

class SYH_2R
{
private:
	uint8_t Paa;
	uint8_t Pbb;
	uint8_t AN_in;
	uint8_t repeats;
	uint8_t RT_kohm;
	
	// millis
	
	uint8_t toogle();

public:
	begin(uint8_t Pa, uint8_t Pb, uint8_t A_in, uint8_t kohm);
	uint16_t measure(uint8_t times);
	polirize(uint8_t times);
};

