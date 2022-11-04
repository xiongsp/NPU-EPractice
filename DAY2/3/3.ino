#define SPEED 8
int brightness = 0;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  for (int id=9;id<=11;id++){
    for (brightness = 0; brightness <= 255; brightness += SPEED) {
      analogWrite(id, brightness);
      delay(30); // Wait for 30 millisecond(s)
    }
    for (brightness = 255; brightness >= 0; brightness -= SPEED) {
      analogWrite(id, brightness);
      delay(30); // Wait for 30 millisecond(s)
    }
    analogWrite(id, 0);
    }
}