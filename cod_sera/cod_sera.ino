#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11 
#define RELAY1   22   // de scris tip conexiune                      
#define RELAY2   24                       
#define RELAY3   26                     
#define RELAY4   28
#define RELAY5   30
#define RELAY6   32
#define RELAY7   34
#define RELAY8   36
#define DHTPIN	 38
// ----------------------------------------------------------------------------------------
DHT dht(DHTPIN, DHTTYPE);
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
	dht.begin();
	pinMode(RELAY1, OUTPUT);
	pinMode(RELAY2, OUTPUT);
	pinMode(RELAY3, OUTPUT);
	pinMode(RELAY4, OUTPUT);
	pinMode(RELAY5, OUTPUT);
	pinMode(RELAY6, OUTPUT);
	pinMode(RELAY7, OUTPUT);
	pinMode(RELAY8, OUTPUT);
	//------------------------------------------------------------------
	pinMode(ENA, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(ledPin, OUTPUT);
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
			forward(80, 20);
			break;
		case 'b':
			digitalWrite(RELAY1, LOW);           
			delay(2000);                                
			digitalWrite(RELAY1, HIGH);          
			break;
		}

	}
	Serial.print("Humidity: ");
	// Wait a few seconds between measurements.
/*	delay(2000);

	// Reading temperature or humidity takes about 250 milliseconds!
	// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
	float h = dht.readHumidity();
	// Read temperature as Celsius
	float t = dht.readTemperature();
	// Read temperature as Fahrenheit
	float f = dht.readTemperature(true);

	// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t) || isnan(f)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

	// Compute heat index
	// Must send in temp in Fahrenheit!
	float hi = dht.computeHeatIndex(f, h);

	Serial.print("Humidity: ");
	Serial.print(h);
	Serial.print(" %\t");
	Serial.print("Temperature: ");
	Serial.print(t);
	Serial.print(" *C ");
	Serial.print(f);
	Serial.print(" *F\t");
	Serial.print("Heat index: ");
	Serial.print(hi);
	Serial.println(" *F");

*/	

}

void reverse(int i, int j) {

	// set both motors ON
	digitalWrite(ENA, HIGH);
	digitalWrite(ENB, HIGH);

	while (1) {
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

	while (1) {
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