/*
 Base Code for DHT-22 Sensor
 Developed by- Harkrishan Singh (harkrishan@steamlabs.in)
*/

/*
The Circuit:
  * When the grill of the sensor is facing you
  * 1st pin to 5V
  * 2nd pin to digital pin 2
  * 3rd - No Connection
  * 4th pin to GND
*/
#include "dht.h";

//Constants
dht DHT;
const int dhtPin = 2; //Data pin of DHT-22 to Arduino digital pin 2

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
}

void loop()
{
	chk = DHT.read22(dhtPin); //Check data pin and read values
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
}

   
