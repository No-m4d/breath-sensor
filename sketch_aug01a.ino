// Variable resistance stretch cord testing code! Made Jan 29 by Erin Gee for Instructables

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int fadeValue = 0;
int downValue = 4;
int scaleValue = 4;  //This scales the input into something the LED can handle
int newArray[6];
int downArray[3];

void setup() 
{
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);   
}

void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // divide it into a value from 0-255
  fadeValue = sensorValue/scaleValue;
  //write these values to Serial Window
  //Serial.write(fadeValue);
  //Serial.println(fadeValue);
  downArray [2] = downArray [1];
  downArray [1] = downArray [0];

  newArray [5] = newArray [4];
  newArray [4] = newArray [3];
  newArray [3] = newArray [2];
  newArray [2] = newArray [1];
  newArray [1] = newArray [0];
  newArray [0] = fadeValue;
  if (((newArray [0] > newArray [2]) && (newArray[2] > newArray[4]))||((newArray [1] > newArray [3]) && (newArray[3] > newArray[5]))) 
          { 
              downArray [0] = 1;
            Serial.println("down");
          } 
  if (((newArray [0] < newArray [2]) && (newArray[2] < newArray[4]))||((newArray [1] < newArray [3]) && (newArray[3] < newArray[5]))) 
  { 
      downArray [0] = 0;
      Serial.println("up");
  } 
  if (((newArray [0] == newArray [2]) && (newArray[2] == newArray[4]))||((newArray [1] == newArray [3]) && (newArray[3] == newArray[5]))) 
  { 
      downArray [0] = 0;
      Serial.println("hold");
  } 
  else {
    Serial.println(".");
    }
  
  /*else 
 {
    if ((downArray [0]== 1)|| (downArray [2] ==1))
    {
      Serial.println("down2");
    }
    downArray [0] = 2;
    Serial.println("hold");
  }*/
  
 
  delay(70); //change the delay to change the result            
}

