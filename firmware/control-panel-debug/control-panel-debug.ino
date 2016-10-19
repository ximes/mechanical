#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson/
int sensorPin1 = A0;
int sensorPin2 = A1;
int sensorPin3 = A2;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  DynamicJsonBuffer jsonBuffer;
  JsonArray& data = jsonBuffer.createArray();

  digitalWrite(LED_BUILTIN, HIGH);
  
  sensorValue1 = analogRead(sensorPin1);
  data.createNestedObject()["value"] = sensorValue1;
  delay(100);
  
  sensorValue2 = analogRead(sensorPin2);
  data.createNestedObject()["value"] = sensorValue2;
  delay(100);
  
  sensorValue3 = analogRead(sensorPin3);
  data.createNestedObject()["value"] = sensorValue3;
  delay(100);

  data.prettyPrintTo(Serial);
  Serial.println("--"); 
 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
