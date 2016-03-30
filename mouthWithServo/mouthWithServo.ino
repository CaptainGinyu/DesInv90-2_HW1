#include <Servo.h>

Servo mouthServo;
const int servoPin = 9;
const int prPin = A0;
const int piezoPin = 5;

bool angry;

void setup()
{
  pinMode(prPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  angry = false;
}

void loop()
{
  if (!angry)
  {
    if (random(0, 4) == 1)
    {
       angry = true;
    }
  }
  if (angry)
  {
    tone(piezoPin, random(500, 1000));
    chomp();
    if (analogRead(prPin) < 700)
    {
      angry = false;
      noTone(piezoPin);
      delay(5000);
    }
  }
  
}

void chomp()
{
  if (!mouthServo.attached())
  {
    mouthServo.attach(servoPin);
  }
  mouthServo.write(180);
  delay(1000);
  mouthServo.write(0);
  delay(500);
  mouthServo.detach();
}

