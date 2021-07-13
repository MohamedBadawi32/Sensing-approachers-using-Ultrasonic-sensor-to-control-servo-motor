# Sensing approachers using Ultrasonic sensor to control Servo motors
In this project, Servo motors were controlled by ultrasonic sensor through two different Arduino to retate 6 Servo motors if an object stood in front of the sensor for 3 seconds or more in 75 cm range.

## Components and connection description
The project was constructed using two Arduinos Uno that are connected together by transmitter, receiver, and ground pins, 6 Servo motors their signal pins are connected to digital pins of the slave Arduino, and an ultrasonic sensor that is connected to the master Arduino. 

## Working principle 
Basically, if an object approaches the ultrasonic sensor, the master arduino will verify if it stays for 3 seconds or longer in a 75cm range. Consequently, if these two criteria are fulfilled, the master Arduino will write a '1'. Meanwhile, the slave Arduino is patiently waiting for a '1' to be written to perform his task. Once a '1' is written, for loops will be executed to rotate the Servo motors to a certain angle then they move back to their initial positions. During this process, the slave Arduino will perform the task once only unless the object moved away and stood again for 3 seconds in 75cm range.
