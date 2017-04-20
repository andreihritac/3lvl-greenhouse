#include <Arduino.h>

#define RELAY1    // de scris tip conexiune                      
#define RELAY2                          
#define RELAY3                          
#define RELAY4  
#define RELAY5
#define RELAY6
#define RELAY7
#define RELAY8
// ----------------------------------------------------------------------------------------

const int ENA = 7;
const int IN1 = 6;
const int IN2 = 5;
const int ENB = 8;
const int IN4 = 9;
const int IN3 = 10;
const int ledPin = 13;

void setup()
{
	Serial.begin(9600);
	pinMode(RELAY1, OUTPUT);
	pinMode(RELAY2, OUTPUT);
	pinMode(RELAY3, OUTPUT);
	pinMode(RELAY4, OUTPUT);
	pinMode(RELAY5, OUTPUT);
	pinMode(RELAY6, OUTPUT);
	pinMode(RELAY7, OUTPUT);
	pinMode(RELAY8, OUTPUT);
	//------------------------------------------------------------------
	 pinMode(ENA,OUTPUT);
	 pinMode(IN1,OUTPUT);
	 pinMode(IN2,OUTPUT);
	 pinMode(ENB,OUTPUT);
	 pinMode(IN3,OUTPUT);
	 pinMode(IN4,OUTPUT);
	 pinMode(ledPin,OUTPUT);
	 digitalWrite(ledPin, LOW);

  //delay is used to control the speed, the lower the faster.
  //reverse(step,delay);
//  reverse(80,20);
  //forward(step,delay);
//  forward(80,20);
}

void loop()
{
	if (Serial.available() > 0) {
		int inByte = Serial.read();
		switch (inByte) {
		case 'a':
			///
			break;
		case 'b':
			///
			break;
		}

	}




}

void reverse(int i, int j) {

  // set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;
  }

  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

}  // end reverse()

void forward(int i, int j) {

  // Set both motors ON
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  while (1)   {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    delay(j);
    i--;
    if (i < 1) break;
  }

  // set both motors OFF
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);

}  // end forward()
