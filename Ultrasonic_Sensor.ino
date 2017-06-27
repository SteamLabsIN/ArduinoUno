/*
 Base Code for HC-SR04 Ultrasonic Sensor
 Tested & Improvised by - Harkrishan Singh (harkrishan@steamlabs.in)
*/

/*
When VCC of the HC-SR04 is connected to 5V of Uno the sensor may not give any readings.
Hence, we are using the digital pin 2 to simulate VCC and D5 to simulate GND.
*/

/*
 The circuit:
 * VCC to digital pin 2
 * TRIG to digital pin 3
 * ECHO to digital pin 4
 * GND to digital pin 5
*/

int vcc = 2; //attach pin 2 to vcc
int trig = 3; // attach pin 3 to Trig
int echo = 4; //attach pin 4 to Echo
int gnd = 5; //attach pin 5 to GND
 
void setup() 
{
  pinMode (vcc,OUTPUT);
  pinMode (gnd,OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}
 
void loop()
{
  digitalWrite(vcc, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo,INPUT);
  duration = pulseIn(echo, HIGH);
  
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("cm ");
  Serial.println();
  delay(1000);
}
 
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second). This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PI...
  
  return microseconds / 74 / 2;
}
 
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  
  return microseconds / 29 / 2;
}
