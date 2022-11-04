// int pinDigitron = 2; //管脚D2连接到数码管的A脚，D3连B... D9连h
 
// void setup() {
//   for(int x=0; x<12; x++)
//     pinMode(pinDigitron+x, OUTPUT); //设置各脚为输出状态
//   for(int x=10;x<=12;x++)
//     digitalWrite(x,1);
// }
 
// //在数码管中显示数字的函数
// void displayDigit(unsigned char digit) {
//   //定义一个数组表：不同数字的abcdefgh各段的取值
//   unsigned char alphabet[][8] = {
//     {1,1,1,1,1,1,0,0},  //0
//     {0,1,1,0,0,0,0,0},  //1
//     {1,1,0,1,1,0,1,0},  //2
//     {1,1,1,1,0,0,1,0},  //3
//     {0,1,1,0,0,1,1,0},  //4
//     {1,0,1,1,0,1,1,0},  //5
//     {1,0,1,1,1,1,1,0},  //6
//     {1,1,1,0,0,0,0,0},  //7
//     {1,1,1,1,1,1,1,0},  //8
//     {1,1,1,1,0,1,1,0},  //9
//     {1,1,1,0,1,1,1,0},  //A
//     {0,0,1,1,1,1,1,0},  //b
//     {1,0,0,1,1,1,0,0},  //C
//     {0,1,1,1,1,0,1,0},  //d
//     {1,0,0,1,1,1,1,0},  //E
//     {1,0,0,0,1,1,1,0},  //F
//   };
  
//   if ( digit >= 16 ) return;
//   for (unsigned char x=0; x<8; x++)
//     digitalWrite( pinDigitron + x, alphabet[digit][x] );
// }

// void display(unsigned int a,unsigned int b,unsigned int c,unsigned int d){
//   for(int i=0;i<50;i++){
//     for(int dig=2;dig<=13;dig++){
//   digitalWrite(dig,1);
//     }


//   digitalWrite(10,0);
//   displayDigit(d);
//   digitalWrite(10,1);
//   delay(2);
//   digitalWrite(11,0);
//   displayDigit(c);
//   digitalWrite(11,1);
//   delay(2);
//   digitalWrite(12,0);
//   displayDigit(b);
//   digitalWrite(12,1);
//   delay(2);
//   digitalWrite(13,0);
//   displayDigit(a);
//   digitalWrite(13,1);
//   }
// }


// void loop() { 
//   for(int a=0;a<16;a++){
//       for(int b=0;b<16;b++){
//       for(int c=0;c<16;c++){
//       for(int d=0;d<16;d++){
//         display(a,b,c,d);
//         delay(20);
//   }
//   }
//   }
//   }
//   // display(1,2,3,4);
// }
int A= 2;
int B= 3;
int C= 4;
int D= 5;
int E= 6;
int F= 7;
int G= 8;
int H= 9;
int COM1= 10;
int COM2= 11;
int COM3= 12;
int COM4= 13;
void Display(unsigned char com, unsigned char num);
//定义输出引脚；
void setup(){
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(H,OUTPUT);

  pinMode(COM1,OUTPUT);
  pinMode(COM2,OUTPUT);
  pinMode(COM3,OUTPUT);
  pinMode(COM4,OUTPUT);
}
//设置十进制数在七段数码管下的显示；
unsigned char table[][8]={
//       {1,1,1,1,1,1,0,0},//0
//       {0,1,1,0,0,0,0,0},//1
//       {1,1,0,1,1,0,1,0},//2
//       {1,1,1,1,0,0,1,0},//3
//       {0,1,1,0,0,1,1,0},//4
//       {1,0,1,1,0,1,1,0},//5
//       {1,0,1,1,1,1,1,0},//6
//       {1,1,1,0,0,0,0,0},//7
//       {1,1,1,1,1,1,1,0},//8
//       {1,1,1,0,0,1,1,0},//9
// };
    {1,1,1,1,1,1,0,0},  //0
    {0,1,1,0,0,0,0,0},  //1
    {1,1,0,1,1,0,1,0},  //2
    {1,1,1,1,0,0,1,0},  //3
    {0,1,1,0,0,1,1,0},  //4
    {1,0,1,1,0,1,1,0},  //5
    {1,0,1,1,1,1,1,0},  //6
    {1,1,1,0,0,0,0,0},  //7
    {1,1,1,1,1,1,1,0},  //8
    {1,1,1,1,0,1,1,0},  //9
    {1,1,1,0,1,1,1,0},  //A
    {0,0,1,1,1,1,1,0},  //b
    {1,0,0,1,1,1,0,0},  //C
    {0,1,1,1,1,0,1,0},  //d
    {1,0,0,1,1,1,1,0},  //E
    {1,0,0,0,1,1,1,0},  //F
  };
void loop(){
  int G,S,B,Q;//个位，十位，百位，千位；
  G=0;
  S=0;
  B=0;
  Q=0;
  //计数并进位；
  for(Q=0;Q<16;Q++){
      for(B=0;B<16;B++){
          for(S=0;S<16;S++){
              for(G=0;G<16;G++){
              //闪烁50下以达到视觉辨别
                  for(int j=0;j<1;j++){
                      //通过扫描，达到视觉暂留效果
                      Display(1,G);
                      delay(2); 
                      Display(2,S);
                      delay(2); 
                      Display(3,B);
                      delay(2);
                      Display(4,Q);
                      delay(2);
                  }
              }
          }
      }
  }
}
//输出端信号输出函数，com为位，num为com位上的数；
void Display(unsigned char com, unsigned char num){
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
    digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(H,HIGH);
//由com控制读取位
    switch(com){
        case 1:
            digitalWrite(COM1,LOW);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,HIGH);
            break;
        case 2:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,LOW);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,HIGH);
            break;
        case 3:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,LOW);
            digitalWrite(COM4,HIGH);
            break;
        case 4:
            digitalWrite(COM1,HIGH);
            digitalWrite(COM2,HIGH);
            digitalWrite(COM3,HIGH);
            digitalWrite(COM4,LOW);
            break;
        defult:break;
    }
//构建num到table数组的映射关系，达到指定数字输出效果
    digitalWrite(A,table[num][0]);
    digitalWrite(B,table[num][1]);
    digitalWrite(C,table[num][2]);
    digitalWrite(D,table[num][3]);
    digitalWrite(E,table[num][4]);
    digitalWrite(F,table[num][5]);
    digitalWrite(G,table[num][6]);
    digitalWrite(H,table[num][7]);
}