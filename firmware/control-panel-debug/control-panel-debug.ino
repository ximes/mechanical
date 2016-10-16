#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson/
DynamicJsonBuffer jsonBuffer;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(57600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  printData("1");
  delay(3000);                       // wait for some seconds
  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  printData("0");
  delay(3000);                       // wait for some seconds 
}

void printData(String value){
  JsonArray& data = jsonBuffer.createArray();
  data.createNestedObject()["value"] = value;
  data.prettyPrintTo(Serial);
  Serial.println("--"); 
}
