/* signalPin is where the green signal wire from the 
motor controller connects to a PWM pin on the Arduino
 PWM pin  *///
int signalPin = 10;

// Analog force sensor inputs
int sensorPedalRight = A0;
//int sensorPedalLeft = A1;

int dataPedalRight = 0;
//int dataPealLeft = 0;

float voltagePedalRight = 0;
//float voltagePedalLeft = 0;

void setup() 
{
 Serial.begin(9600);
 pinMode(signalPin, OUTPUT); 
}

/* Funtion to control motor speed. Only use integers 0-255.
0 being "off" and 255 being max speed.
*/
int motorRun(float w)
{
  analogWrite(signalPin, w);
  delay(1000);
}
void loop()
{
  // Read sensor data from pedal sensors
  dataPedalRight = analogRead(sensorPedalRight);
  //dataPedalLeft = analogRead(sensorPedalLeft);
  
  /* Change sensor data into values representing signal to send to
  motor via PWM */
  voltagePedalRight = dataPedalRight * (255.0 / 1023);
 // voltagePedalLeft = dataPedalLeft * (5.0 / 1023);
  
  Serial.println(voltagePedalRight);
  Serial.println(dataPedalRight);
  
   /******* This part will be used to take data directly from 
  sensors as input for the motor speed control 
  int i;
  i = analogRead(11);
  motorRun(i);   *************/
  
  motorRun(voltagePedalRight);

}

