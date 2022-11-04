#define COM3 3

#define LOW1 261
#define LOW2 293
#define LOW3 329
#define LOW4 349
#define LOW5 391
#define LOW6 440
#define LOW7 493

#define MID1 532
#define MID2 587
#define MID3 659
#define MID4 698
#define MID5 783
#define MID6 880
#define MID7 987

void sound(int fre){
  tone(COM3,fre);
  delay(300);
  noTone(COM3);
  delay(30);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(COM3,OUTPUT);
}

void loop() {
  // 小星星
  // sound(LOW1);
  // sound(LOW1);
  // sound(LOW5);
  // sound(LOW5);
  // sound(LOW6);
  // sound(LOW6);
  // sound(LOW5);
  // delay(500);
  // sound(LOW4);
  // sound(LOW4);
  // sound(LOW3);
  // sound(LOW3);
  // sound(LOW2);
  // sound(LOW2);
  // sound(LOW1);
  // delay(500);



  sound(MID1);
  sound(MID2);
  sound(MID3);
  sound(MID5);
  sound(MID3);
  sound(MID3);
  delay(100);
  sound(MID2);
  sound(MID2);
  sound(MID1);
  sound(MID2);
  delay(100);
  sound(MID1);
  sound(LOW6);
  sound(MID1);
  sound(MID2);
  sound(MID3);
  delay(100);
 
  delay(500);
}
