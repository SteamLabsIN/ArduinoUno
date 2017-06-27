/*
 Base Code for HC05-Bluetooth Module
 Tested & Improvised - Harkrishan Singh (harkrishan@steamlabs.in)
*/

/*
This program below allow us to control LED connected to D13 To blink on/off, 
by press # 1 from PC Keyboard the LED blink on, 
and if we press 0 LED blink off ! 

The Circuit:
  * RXD to digital pin 11
  * TXD to digital pin 10
  * GND to GND
  * VCC to 5V
  
Pair HC-05 from PC or Android phone using code 1234
and use a serial communication over bluetooth to send 1 and/or 0
and see the LED switch ON/OFF

*/

#include <SoftwareSerial.h>// import the serial library

SoftwareSerial mySerial(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  mySerial.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (mySerial.available()){
BluetoothData=mySerial.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
   mySerial.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   mySerial.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}
