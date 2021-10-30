#include <Servo.h>

const int illumPin = A0;
const int SERVO = 10;
Servo servo;

void setup() {
  Serial.begin(115200);  
  Serial.println("SETUP");
  
  servo.attach(SERVO);
  servo.write(0);
  delay(1000);
}

void loop() {
  int illumValue = analogRead(illumPin);
  Serial.println(illumValue);
  
  if(illumValue < 69){
    servo.write(70);
    delay(150);
    servo.write(0);
    delay(150);
  }
}
