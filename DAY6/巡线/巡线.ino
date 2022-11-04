// int LG=8;
// int LB=7;

// int rightMotor1=2;
// int RB=4;

// int LP=6;
// int RP=5;


// int LEFT1=13;
// int LEFT2=12;
// int RIGHT1=11;
// int RIGHT2=10;

// // int TrightMotor1Pin = 13;
// // int EcoPin = 12;

// // float distance(){
// //   float dist=0;
// //   digitalWrite(TrightMotor1Pin, LOW);
// //   delayMicroseconds(8);
// //   digitalWrite(TrightMotor1Pin, HIGH);
// //   // 维持10毫秒高电平用来产生一个脉冲
// //   delayMicroseconds(10);
// //   digitalWrite(TrightMotor1Pin, LOW);
// //   // 读取脉冲的宽度并换算成距离
// //   // v = 0.0343厘米/微秒
// //   // 1/v*2 ~= 58
// //   dist = pulseIn(EcoPin, HIGH) / 58.3;
// //   Serial.print("Distance:");
// //   Serial.print(dist);
// //   Serial.println("cm");
// //   return dist;
// // }





// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(LG,OUTPUT);
//   pinMode(rightMotor1,OUTPUT);
//   pinMode(LB,OUTPUT);
//   pinMode(RB,OUTPUT);
//   pinMode(LP,OUTPUT);
//   pinMode(RP,OUTPUT);


//   pinMode(LEFT1,INPUT);
//   pinMode(LEFT2,INPUT);
//   pinMode(RIGHT1,INPUT);
//   pinMode(RIGHT2,INPUT);
// }

// void loop() {
//   int status=0;
//   #define trigger 210
//   bool status_l1=analogRead(LEFT1)<trigger;
//   bool status_l2=analogRead(LEFT2)<trigger;
//   bool status_r1=analogRead(RIGHT1)<trigger;
//   bool status_r2=analogRead(RIGHT2)<trigger;
//   status=(status_l1<<3)|(status_l2<<2)|(status_r1<<1)|(status_r2);
//   Serial.println(status);
//   switch(status){
//     case 0:
//       go(0);
//       Serial.println("stop");
//       break;
//     case 1:
//     case 2:
//     case 3:
//     case 5:
//     case 7:
//     case 11:
//       rightgo(10);
//       delay(100);
//       Serial.println("right");
//       break;
//     case 6:
//     case 9:
//     case 15:
//       go(20);
//       delay(10);
//       Serial.println("go");
//       break;
//     case 4:
//     case 8:
//     case 10:
//     case 12:
//     case 13:
//     case 14:
//       leftgo(10);
//       delay(100);
//       Serial.println("left");
//       break;

//   }
// }


// int data[4];
// int LG = 8;
// int LB = 7;
// int rightMotor1 = 2;
// int RB = 4;
// void state(); //小车循迹行走方向判断函数
// int trac1 = 10; //从车头方向的最右边开始排序
// int trac2 = 11; 
// int trac3 = 12; 
// int trac4 = 13; 
// int LP = 5;
// int RP = 6;
// int Speed=50;//车速





// void setup() {
//   // put your setup code here, to run once:
//   //串口初始化
//   Serial.begin(9600); 
//   //测速引脚初始化
//   pinMode(LG, OUTPUT);
//   pinMode(LB, OUTPUT);
//   pinMode(rightMotor1, OUTPUT);
//   pinMode(RB, OUTPUT);
//   pinMode(LP, OUTPUT);
//   pinMode(RP, OUTPUT);
//   //寻迹模块D0引脚初始化
//   pinMode(trac1, INPUT);
//   pinMode(trac2, INPUT);
//   pinMode(trac3, INPUT);
//   pinMode(trac4, INPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:

//     data[0] = analogRead(trac1);//left0，传感器遇黑时返回值180左右，遇白时返回值950左右
//     data[1] = analogRead(trac2);//left1
//     data[2] = analogRead(trac3);//right0
//     data[3] = analogRead(trac4);//right1
//     state();

// }
// void state(){
//   if(data[1]>=900&&data[0]<=200&&data[2]<=200&&data[3]>=900){
//     go(35);
//   }
//   if(data[2]<=200||data[3]<=200){
//     rightgo(35);
//     Serial.println("!!!");
//   }
//   if(data[1]<=200||data[0]<=200){
//     leftgo(35);
//   }
// }








void TurnLeft();//小车左转小角度函数
void TurnRight();//小车右转小角度函数
void RT_TurnRight();//小车右转大角度函数
void RT_TurnLeft();//小车左转小大度函数
void Go();
void Back();
void Stop();
int data[4];
int leftMotor1 = 8;
int leftMotor2 = 7;
int rightMotor1 = 2;
int rightMotor2 = 4;
void state(); //小车循迹行走方向判断函数
int trac1 = 10; //从车头方向的最右边开始排序
int trac2 = 11; 
int trac3 = 12; 
int trac4 = 13; 
int leftPWM = 5;
int rightPWM = 6;
bool judge=false;

int Speed=50;//车速

void setup() {
  // put your setup code here, to run once:
  //串口初始化
  Serial.begin(9600); 

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(rightPWM, OUTPUT);

  pinMode(trac1, INPUT);
  pinMode(trac2, INPUT);
  pinMode(trac3, INPUT);
  pinMode(trac4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(leftPWM, Speed);  //设置PWM输出，即设置速度
    analogWrite(rightPWM, Speed);
    data[0] = analogRead(A1);//left0，传感器遇黑时返回值180左右，遇白时返回值950左右
    data[1] = analogRead(A2);//left1
    data[2] = analogRead(A3);//right0
    data[3] = analogRead(A4);//right1
    state();
}
void LeftGo(){
  digitalWrite(leftMotor1,0);
  digitalWrite(leftMotor2,0);
  digitalWrite(rightMotor1,1);
  digitalWrite(rightMotor2,0);
  delay(20);
}
void RightGo(){
  digitalWrite(leftMotor1,1);
  digitalWrite(leftMotor2,0);
  digitalWrite(rightMotor1,0);
  digitalWrite(rightMotor2,0);
  delay(20);
}
void BigRight(){
  digitalWrite(leftMotor1,1);
  digitalWrite(leftMotor2,0);
  digitalWrite(rightMotor1,0);
  digitalWrite(rightMotor2,1);
  delay(5);
}
void BigLeft(){
  digitalWrite(leftMotor1,0);
  digitalWrite(leftMotor2,1);
  digitalWrite(rightMotor1,1);
  digitalWrite(rightMotor2,0);
  delay(5);
}

void Go(){
  digitalWrite(leftMotor1,1);
  digitalWrite(leftMotor2,0);
  digitalWrite(rightMotor1,1);
  digitalWrite(rightMotor2,0);
  delay(20);
}
void Stop(){
  digitalWrite(leftMotor1,0);
  digitalWrite(leftMotor2,0);
  digitalWrite(rightMotor1,0);
  digitalWrite(rightMotor2,0);
  delay(20);
}
void state(){
  if((data[1]>=900&&data[0]<=200&&data[2]<=200&&data[3]>=900)||(data[0]<=200&&data[1]<=200&&data[2]<=200&&data[3]<=200)){//0101,1111,0000
    Go();
  }
  // if((data[0]>=900&&data[1]>=900&&data[2]>=900&&data[3]>=900)){//1111
  //   if(judge)
  // }
  if(data[2]<=200||data[3]<=200){
    // BigRight();
    RightGo();
  }
  // if(data[2]>=900&&data[3]<=200){
  //   BigRight();
  // }
  if(data[1]<=200||data[0]<=200){
    // BigLeft();
    LeftGo();
  }
  // if(data[1]>=900&&data[0]<=200){
  //   BigLeft();
  // }
}