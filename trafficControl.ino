#include <IRremote.h>//Include IRremote library

//Intialize pins
const int receiverPin = 2;
const int redLED= 9;
const int yellowLED=10;
const int greenLED=11;

void setup() {
  //Basic setup
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 if (IrReceiver.decode()) {
  //Prints signal
  Serial.print("Command: ");
  Serial.println(IrReceiver.decodedIRData.command, HEX);
  Serial.println("Raw Data: ");
  Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  
  //Led responses to signal
  if(IrReceiver.decodedIRData.decodedRawData != 0x0){
    //Red LED on
    if(IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) {
      Serial.println(">>> LED 1 ON");
      digitalWrite(redLED, HIGH);
    } 
    //Yellow LED on
    else if(IrReceiver.decodedIRData.decodedRawData == 0xE718FF00){
      Serial.println(">>> LED 2 ON");
      digitalWrite(yellowLED, HIGH);
    } 
    //Green LED on
    else if(IrReceiver.decodedIRData.decodedRawData == 0xA15EFF00){
      Serial.println(">>> LED 3 ON");
      digitalWrite(greenLED, HIGH);
    } 
    //Red LED off
    else if(IrReceiver.decodedIRData.decodedRawData == 0xF708FF00){
      Serial.println(">>> LED 1 OFF");
      digitalWrite(redLED, LOW);
    } 
    //Yellow LED off
    else if(IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00){
      Serial.println(">>> LED 2 OFF");
      digitalWrite(yellowLED, LOW);
    }
    //Green LED off
    else if(IrReceiver.decodedIRData.decodedRawData == 0xA55AFF00){
      Serial.println(">>> LED 3 OFF");
      digitalWrite(greenLED, LOW);
    }
  }
  
  IrReceiver.resume();//resume listening for other signals
 }
}
