#include <Servo.h>
#include <Ultrasonic.h>

#define TRIG_PIN D5
#define ECHO_PIN D6

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN);
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(D7);
  myServo.write(0);
}

void loop() {
  long distance = ultrasonic.read();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 20) {
    myServo.write(0);
    delay(2000);
    myServo.write(180);
  }

  delay(500);
}

