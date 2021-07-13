int tpin = 5, epin = 4; // declaring trigger and echo pins of the ultrasonic sensor
bool isInRange = false, doPrint = true; // declaring boolean variables
long starttime; // declaring a variable for time


void setup() {
  starttime = millis();   // initial time
  pinMode(tpin, OUTPUT);  // setting the trigger pin as an output
  pinMode(epin, INPUT);   // setting the echo pin as an input
  Serial.begin(9600);     // starting serial communication
}

void loop() {
  digitalWrite(tpin, LOW); // ensuring the trigger to be in low state
  delayMicroseconds(2);
  digitalWrite(tpin, HIGH); // sends a wave
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);  // reset to low
  int timingo = pulseIn(epin, HIGH); // reads the time required for the wave to travel from the trigger and back to the echo
  int distance = timingo * 0.0343 / 2; // calculating the displacement from the sensor to the nearest object

  if(distance<=75){ // if the object is 75cm or less close to the sensor and keeps its position for 3 seconds the serial will send a '1'
    if(isInRange){
      if((millis()-starttime)>=3000 && doPrint){
        Serial.write('1');
        Serial.println(' ');
        isInRange = false;
        doPrint = false;
      }
    }
    else{
      starttime = millis();
      isInRange = true;
    }
  }
  else{
    doPrint = true;
    isInRange = false;
  }
}
