int TrgPin = A0;
int EcoPin = A1;
float dist;
void setup()
{   
Serial.begin(9600);
//设置TrgPin为输出状态
pinMode(TrgPin, OUTPUT);
// 设置EcoPin为输入状态
pinMode(EcoPin, INPUT);
}
void loop()
{
digitalWrite(TrgPin, LOW);
delayMicroseconds(8);
digitalWrite(TrgPin, HIGH);
// 维持10毫秒高电平用来产生一个脉冲
delayMicroseconds(10);
digitalWrite(TrgPin, LOW);
// 读取脉冲的宽度并换算成距离
// v = 0.0343厘米/微秒
// 1/v*2 ~= 58
dist = pulseIn(EcoPin, HIGH) / 58.3;
Serial.print("Distance:");
Serial.print(dist);
Serial.println("cm");
delay(100);
}

