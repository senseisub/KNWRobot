#include <KNWRobot.h> 
using namespace std;

int tempPin = 0;
KNWRobot *myRobot;
bool success;

void setup() {
  // put your setup code here, to run once:
  myRobot = new KNWRobot;
  success = myRobot->setupTemp(tempPin);
  if(success){
    Serial.begin(9600);
  }
}
int g = 5;
void loop() {
  // put your main code here, to run repeatedly:
  int i, adc;

  

  if(success){
//    double temp =0;
    adc =0; 
    for(i = 0; i< 10; i++){
      adc += myRobot->getTemp();
    }
    myRobot->clearLCD();
    myRobot->moveCursor(0,0);
    myRobot->printLCD((char*)"Our temp: ");
    myRobot->moveCursor(0,1);
    Serial.println(adc / 10);
    myRobot->printLCD(calc(adc/10));
  }
  delay(1000);
//  digitalWrite(9, LOW);
}
double calc(int x){
  double temp =0;
  temp = -.27*x+161.67; 
  return temp;
}
