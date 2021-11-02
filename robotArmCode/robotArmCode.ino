#include <Servo.h>

Servo bottom_servo;
Servo mid_servo;
Servo hand_servo;

//[Variation For Counter]
int first_counter = 0; //Count variation for moving 120,90,60,30 degree
int second_counter = 0; //Count variation for moving 10, 140 degree

//[Variation For Motor]
const int motor_btm = 11;
const int motor_mid = 10;
const int motor_hand = 9;

//[Variation For Controller]
const int first_btn_for_btm = A0; //120, 90, 60, 30 degree
const int second_btn_for_btm = A1; //10, 140 degree
const int ctl_mid = A2;
const int ctl_hand = A3;

void setup() {
  Serial.begin(115200);
  Serial.println("SETUP"); 
  
//[START Setting For bottom_servo]   
  pinMode(first_btn_for_btm, INPUT);
  pinMode(second_btn_for_btm, INPUT);
  
  bottom_servo.attach(motor_btm);
  bottom_servo.write(120);
  delay(1000);
  bottom_servo.detach();
//[END Setting For bottom_servo]
   
  mid_servo.attach(motor_mid);
  hand_servo.attach(motor_hand);
   
  delay(15);
}

void loop() {

  int first_btm_value = digitalRead(first_btn_for_btm);
  int second_btm_value = digitalRead(second_btn_for_btm);
  
//[START Bottom Motor Control]
  //[START 120, 90, 60, 30 Degree]
  if(first_btm_value == 1){
    delay(1000);
    
    if(first_counter == 0){
      bottom_servo.attach(motor_btm);
      delay(10);
      bottom_servo.write(120);
      first_counter ++;
      delay(20);
      bottom_servo.detach();
    }else if(first_counter == 1) {
      bottom_servo.attach(motor_btm);
      delay(10);
      bottom_servo.write(90);
      first_counter ++;
      delay(20);
      bottom_servo.detach();
    }else if(first_counter == 2) {
      bottom_servo.attach(motor_btm);
      delay(10);
      bottom_servo.write(60);
      first_counter ++;
      delay(20);
      bottom_servo.detach();
    }else {
      bottom_servo.attach(motor_btm);
      delay(10);    
      bottom_servo.write(30);
      first_counter = 0;
      delay(20);
      bottom_servo.detach();
    }
  }
  //[END 120, 90, 60, 30 Degree]

  //[START 10, 140 Degree]
  if(second_btm_value == 1){
    delay(1000);
    
    if(second_counter == 0){
      bottom_servo.attach(motor_btm);
      delay(10);
      bottom_servo.write(10);
      second_counter ++;
      delay(20);
      bottom_servo.detach();
    } else {
      bottom_servo.attach(motor_btm);
      bottom_servo.write(140);
      second_counter = 0;
      delay(20);
      bottom_servo.detach();
    }
  }
  //[END 10, 140 Degree]
//[END Bottom Motor Control]

//[START Middle and Hand Motor Control]  
  int input_ctl_mid = analogRead(ctl_mid);
  int input_ctl_hand = analogRead(ctl_hand);
  int rad_mid = map(input_ctl_mid, 0, 1023, 0, 70);
  int rad_hand = map(input_ctl_hand, 0, 1023, 0, 30);
  mid_servo.write(rad_mid);
  hand_servo.write(rad_hand);
  delay(30);
//[END Middle and Hand Motor Control]  

}
