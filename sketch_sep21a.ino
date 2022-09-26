#include <SoftwareSerial.h>
#include <Servo.h>
 
#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD);
Servo servo_9;

int angle = 0;
String val = "";
 
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);

  servo_9.attach(9);
  servo_9.write(20); 
}
 
void loop(){

  while(bluetooth.available()) {
    char c = (char)bluetooth.read();
    val += c;
    delay(5);
  }

  if(val.equals("YES")) {
    
    for(angle = 20; angle < 120; angle++) { 
      servo_9.write(angle); 
      delay(15); 
    }

    delay(1000);
    
    Serial.println("val : " + val);
    val = "";
    delay(5000);

    for(angle = 120; angle > 20; angle--) { 
      servo_9.write(angle); 
      delay(15); 
    }
  } else if(val.equals("NO")) {

    for(angle = 120; angle > 20; angle--) { 
      servo_9.write(angle); 
      delay(15); 
    }

    delay(1000);
    
    Serial.println("val : " + val);
    val = "";
    delay(100);
  } else {
    val = "";
  }

  delay(100);
}