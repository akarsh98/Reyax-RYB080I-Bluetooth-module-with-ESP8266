#include <SoftwareSerial.h> 
#define rx 5                                          //BT TX
#define tx 4                                          //BT RX
String incomingString;
SoftwareSerial myserial(rx, tx);

void setup() {
  Serial.begin(115200);
  myserial.begin(9600);

  pinMode(15, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

   if (myserial.available()){
        incomingString = myserial.readString();
        Serial.println(incomingString);
        if(incomingString=="LED"||incomingString=="led"){
          static int blink;
          digitalWrite(15, blink);
          blink = ~blink;
          Serial.println("LED 15 TOGGLED");
        }
    }
}
    
