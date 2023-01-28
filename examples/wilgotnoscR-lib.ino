#include <SYH_2R.h>

//connect sensing resistor between this digital pin
//and an analog (ANALOG_IN)
#define RH_PIN 4
//connect divider resistor between this digital pin
//and an analog (ANALOG_IN)
#define RT_PIN 5
//analog input for voltage measurement
//(midle point of voltage divider)
#define ANALOG_IN A0
// RT_VAL in kOhms
#define RT_VAL 53


SYH_2R hum;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
while(!Serial){}
Serial.println("start");
hum.begin(RH_PIN,RT_PIN,ANALOG_IN,RT_VAL);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Rezyst: ");
// ...measure runs polarization and returns resistance of sensor in kOhms
Serial.print(hum.measure(10));
Serial.println("kOhm");
delay(900);
// ...just run polarization without measurement 
hum.polarize(50);
}
