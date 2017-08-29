// Variable resistance stretch cord testing code! Made Jan 29 by Erin Gee for Instructables

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int fadeValue = 0;
int scaleValue = 4;  //This scales the input into something the LED can handle
int newArray[6];

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200);   
}

void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // divide it into a value from 0-255
  fadeValue = sensorValue/scaleValue;
  //write these values to Serial Window
  //Serial.write(fadeValue);
  //Serial.println(fadeValue);
  newArray [5] = newArray [4];
  newArray [4] = newArray [3];
  newArray [3] = newArray [2];
  newArray [2] = newArray [1];
  newArray [1] = newArray [0];
  newArray [0] = fadeValue;
  if (((newArray [0] > newArray [2]) && (newArray[2] > newArray[4]))||((newArray [1] > newArray [3]) && (newArray[3] > newArray[5]))) 
          { 
            Serial.println("down");
          } 
  if (((newArray [0] < newArray [2]) && (newArray[2] < newArray[4]))||((newArray [1] < newArray [3]) && (newArray[3] < newArray[5]))) 
  { 
      Serial.println("up");
  } 
  
 
  delay(150);                
}


