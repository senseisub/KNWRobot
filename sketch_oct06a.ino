#include <KNWRobot.h> 
KNWRobot* myRobot;
int motorId = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  
  
  

  myRobot->setupServo(0,0);

  myRobot->setupMotor(motorId,6);

  bool success = myRobot->setupMotor(motorId,6);
  bool* activePCAPins = myRobot->getPCAPins();


         if (success){
        Serial.println("slatt");  
        
     } 
     if (activePCAPins[1] == true){
        Serial.println("slatt");  
     } 
         if (activePCAPins[0] == true){
        Serial.println("slatt");  
     } 
     myRobot->pcaDCMotor(motorId, 100);
}


void loop() {
  // put your main code here, to run repeatedly:
  
}
