#include <Servo.h>

Servo servo7, servo8, servo9, servo10, servo11, servo12; // create servo object to control a servo
int var1, var2, var3; // variables to store the servo position

void setup() {
  servo7.attach(7);
  servo8.attach(8);    // attaches the first servo on pin 8 to the servo object
  servo9.attach(9);    // attaches the second servo on pin 9 to the servo object
  servo10.attach(10);  // attaches the third servo on pin 10 to the servo object
  servo11.attach(11);  // attaches the fourth servo on pin 11 to the servo object
  servo12.attach(12);  // attaches the fifth servo on pin 12 to the servo object
  servo7.write(0);
  servo10.write(0);
  /* the initial position for the core motors is 0 degrees which is the lowest 
     point and the heighest point when the arm is lifted is 180 degrees*/ 
  servo8.write(0);
  servo11.write(0);
  /* the initial position for the shoulders is 0 degrees which is the tightest angle 
     the shoulder can get and 180 is the widest it can get*/ 
  servo9.write(90);
  servo12.write(90);
  /* the initial position for the hands is 90 degrees which is a midpoint 
     between 0 and 180 which the is capable of doing*/ 
  Serial.begin(9600);
}

void loop() {
  /* if a '1' is sent by the master arduino the arms will move as following
   * additional code could be added inside the if statement for more implementations  
   */
  if(Serial.read() == '1'){
    for(var1=0; var1<=90; var1+=1){
      servo7.write(var1);
      servo10.write(var1);
      delay(15);      
    }
    for(var2=0; var2<=45; var2+=1){
      servo8.write(var2);
      servo11.write(var2);
      delay(15);
    }
    for(var3=90; var3>=0; var3-=1){
      servo9.write(var3);
      servo12.write(var3);
      delay(15);
    }
    delay(3000); // after 3 seconds all servos will move back to their initial position
    for(var3=0; var3<=90; var3+=1){
      servo9.write(var3);
      servo12.write(var3);
      delay(15);
    }
    for(var2=45; var2>=0; var2-=1){
      servo8.write(var2);
      servo11.write(var2);
      delay(15);
    }
    for(var1=90; var1>=0; var1-=1){
      servo7.write(var1);
      servo10.write(var1);
      delay(15);      
    }
  }

}
