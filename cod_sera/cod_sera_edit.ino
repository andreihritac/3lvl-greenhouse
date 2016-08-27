// RELAY TEST
//test pull
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int relay5 = 6;
int relay6 = 7;
int relay7 = 8;
int relay8 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
}

void loop() {  
      setRelayState(0,1);
      delay(1000);
      setRelayState(1, 1);
      delay(1000);
      setRelayState(1, 0);
      delay(1000);
      setRelayState(0, 0);
      delay(1000);
}


void setRelayState(int relay, int state) {
  if (relay == 1) digitalWrite(relay2, state);
  if (relay == 0) digitalWrite(relay1, state);
  if (relay == 1) digitalWrite(relay3, state);
  if (relay == 0) digitalWrite(relay4, state);
  if (relay == 1) digitalWrite(relay5, state);
  if (relay == 0) digitalWrite(relay6, state);
  if (relay == 1) digitalWrite(relay7, state);
  if (relay == 0) digitalWrite(relay8, state);
}
