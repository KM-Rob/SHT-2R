/*
SYH-2R.cpp
This code records data 
 */

#include "SYH_2R.h"


/*
	uint8_t Paa;
	uint8_t Pbb;
	uint8_t AN_in;
	uint8_t RT_kohm;

*/

/****************************************************************/
SYH_2R::begin(uint8_t Pa, uint8_t Pb, uint8_t A_in, uint8_t kohm)
{
	Paa = Pa;
	Pbb = Pb;
	AN_in = A_in;
	RT_kohm = kohm;
	
	pinMode(Paa,OUTPUT);
	pinMode(Pbb,OUTPUT);
	pinMode(AN_in,INPUT);
	
	digitalWrite(Paa,LOW);
	digitalWrite(Pbb,HIGH);
}

/****************************************************************/
uint8_t SYH_2R::toogle()
{
	digitalWrite(Paa,!digitalRead(Paa));
	digitalWrite(Pbb,!digitalRead(Pbb));	
	return digitalRead(Paa);
	
}


/****************************************************************/

uint16_t SYH_2R::measure(uint8_t times)
{
 	uint8_t no,pol;
	uint16_t val0, val1,meas;
	repeats = 14;
	if(times>6) repeats = times;
	
	no = repeats-2;
	pol=toogle();
	for(uint8_t i=0; i<repeats; i++)
	{
		delay(DELAY);
		pol = toogle();
		if(i>=no) 
		{
			meas = analogRead(AN_in);
			if(pol)
			{
				val1 = ((1023-meas)*RT_kohm)/meas;
//				Serial.print("1: ");
//				Serial.println(meas);
				if(val1==0) val1=1;
			}
			
			if(!pol)
			{
				val0 = (meas*RT_kohm/(1023-meas));
//				Serial.print("0: ");
//				Serial.println(meas);
				
			}
		}
	}
	
//	Serial.print(val0);
//	Serial.print("   ");
//	Serial.println(val1);
	
	return (val0+val1)/2;
}


SYH_2R::polirize(uint8_t times)
{
	repeats = 14;
	if(times>6) repeats = times;
	toogle();
	for(uint8_t i=0; i<repeats;i++)
	{
		delay(DELAY);
		toogle();
	}
}