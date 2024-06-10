#include <Ultrasonic.h>
Ultrasonic ultrasonic = Ultrasonic(8, 9);

#include <Servo.h>
Servo servo = Servo();

int In1 = 2;
int In2 = 4;
int EnA = 3;
int In3 = 5;
int In4 = 7;
int EnB = 6;
int servoPin = 10;
int blueLed = 11;
int redLed = 12;
int greenLed = 13;
int distanceLimit = 21;
int motorSpeed1 = 60;
int motorSpeed2 = 200;
int motorSpeed3 = 255;
int servoDelay = 350;
int vipLightDelay = 15;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  analogWrite(EnA, motorSpeed3);
  analogWrite(EnB, motorSpeed3);
}

void loop() {
  servo.write(90);

  int command = Serial.read();
  int distance = ultrasonic.distanceRead();

  Serial.println(distance);

  if (distance < distanceLimit) {
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
    int distance = ultrasonic.distanceRead();
    servo.write(0);
    delay(servoDelay);
    servo.write(90);
    delay(servoDelay);
    servo.write(180);
    delay(servoDelay);
    servo.write(90);
    delay(servoDelay);
  }

  analogWrite(EnA, motorSpeed3);
  analogWrite(EnB, motorSpeed3);

  if (command == '1') { // Forward
    if (distance > 8) {
      digitalWrite(In1, LOW);
      digitalWrite(In2, HIGH);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
      delay(400);
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
    }
  }
  if (command == '2') { // Backward
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    delay (500);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
  if (command == '3') { // Right
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    delay(400);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
  if (command == '4') { // Left
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    delay(400);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }

  if (command == '5') { // Stop
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }

  if (command == '6') {
    digitalWrite(greenLed, HIGH);
  }
  if (command == '7') {
    digitalWrite(greenLed, LOW);
  }

  if (command == '8') { //Forward
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
  }
  if (command == '9') { //Backward
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  }
  if (command == 'c') { //Left
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  }
  if (command == '0') { //Right
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
  }

  if (command == 'd') { // Forward-Left
    analogWrite(EnA, motorSpeed3);
    analogWrite(EnB, motorSpeed1);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
  if (command == 'e') { // Forward-Right
    analogWrite(EnA, 30);
    analogWrite(EnB, motorSpeed3);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
  if (command == 'f') { // Backward-Left
    analogWrite(EnA, motorSpeed3);
    analogWrite(EnB, motorSpeed1);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
  if (command == 'g') { // Backward-Right
    analogWrite(EnA, 30);
    analogWrite(EnB, motorSpeed3);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    delay(1000);
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }

  digitalWrite(redLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(redLed, LOW);
  delay(vipLightDelay);
  digitalWrite(redLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(redLed, LOW);
  delay(vipLightDelay);
  digitalWrite(redLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(redLed, LOW);
  delay(vipLightDelay);
  digitalWrite(blueLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(blueLed, LOW);
  delay(vipLightDelay);
  digitalWrite(blueLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(blueLed, LOW);
  delay(vipLightDelay);
  digitalWrite(blueLed, HIGH);
  delay(vipLightDelay);
  digitalWrite(blueLed, LOW);
  delay(vipLightDelay);

}
