#include <Servo.h>

#define TRIG_PIN A1
#define ECHO_PIN A0
#define Lpwm_pin  5     //pin of controlling speed ENB of motor driver board
#define Rpwm_pin  6    //pin of controlling speed

Servo myservo;
int pos = 0; // servo
int pinLB=2; // turning IN1 of motor driver board
int pinLF=4; // turning IN2 of motor driver board
int pinRB=7; // turning IN3 of motor driver board
int pinRF=8; // turning IN4 of motor driver board


float checkdistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float distance = pulseIn(ECHO_PIN, HIGH) / 58.00;
  delay(10);
  return distance;
}

void go_forward(unsigned char speedVal) {
  digitalWrite(pinRB,HIGH); 
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,LOW);
  analogWrite(Lpwm_pin,speedVal);
  analogWrite(Rpwm_pin,speedVal);
}

void go_backward(unsigned char speedVal) {
  digitalWrite(pinRB,LOW);  
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,LOW);  
  digitalWrite(pinLF,HIGH);
  analogWrite(Lpwm_pin,speedVal);
  analogWrite(Rpwm_pin,speedVal);
}
    
void rotate_left(unsigned char speedVal) {
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,LOW );  
  digitalWrite(pinLB,LOW); 
  digitalWrite(pinLF,HIGH);
  analogWrite(Lpwm_pin,speedVal);
  analogWrite(Rpwm_pin,speedVal);
}

void rotate_right(unsigned char speedVal) {
  digitalWrite(pinRB,LOW);  
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,LOW);  
  analogWrite(Lpwm_pin,speedVal);
  analogWrite(Rpwm_pin,speedVal);
}    

void stopp() {
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,HIGH);
}

void setup() {
  Serial.begin(9600);
  // UltraSonic
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Servo
  myservo.attach(A2);  
  // Wheels
  pinMode(pinLB,OUTPUT); // /pin 2
  pinMode(pinLF,OUTPUT); // pin 4
  pinMode(pinRB,OUTPUT); // pin 7
  pinMode(pinRF,OUTPUT);  // pin 8
  pinMode(Lpwm_pin,OUTPUT);  // pin 5 (PWM) 
  pinMode(Rpwm_pin,OUTPUT);  // pin 6(PWM)  
}

void loop() {
  if (Serial.available()) { 
    char command = Serial.read();
    if (command == 'd') {
      float distance = checkdistance();
      Serial.println(distance);
    } else if (command == 'c') {
      int angle = Serial.parseInt();
      if (angle >= 0 && angle <= 180) {
        myservo.write(angle);
        Serial.println(1);
      }
    } else if (command == 'f') {
      int iSpeed = Serial.parseInt();
      if (iSpeed >= 0 && iSpeed <= 255) {
        unsigned char speed = static_cast<unsigned char>(iSpeed);
        go_forward(speed);
        Serial.println(1);
      }
    } else if (command == 'l') {
      int iSpeed = Serial.parseInt();
      if (iSpeed >= 0 && iSpeed <= 255) {
        unsigned char speed = static_cast<unsigned char>(iSpeed);
        rotate_left(speed);
        Serial.println(1);
      }
    }  else if (command == 'r') {
      int iSpeed = Serial.parseInt();
      if (iSpeed >= 0 && iSpeed <= 255) {
        unsigned char speed = static_cast<unsigned char>(iSpeed);
        rotate_right(speed);
        Serial.println(1);
      }
    }  else if (command == 'b') {
      int iSpeed = Serial.parseInt();
      if (iSpeed >= 0 && iSpeed <= 255) {
        unsigned char speed = static_cast<unsigned char>(iSpeed);
        go_backward(speed);
        Serial.println(1);
      }
    } else if (command == 's') {
      stopp();
      Serial.println(1);
    }
    while (Serial.available()) {
      Serial.read();
    }
  }
}
