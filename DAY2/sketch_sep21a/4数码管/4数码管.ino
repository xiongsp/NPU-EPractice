int pinDigitron = 2; //管脚D2连接到数码管的A脚，D3连B... D9连h
 
void setup() {
  for(int x=0; x<12; x++)
    pinMode(pinDigitron+x, OUTPUT); //设置各脚为输出状态
  for(int x=10;x<=12;x++)
    digitalWrite(x,1);
}
 
//在数码管中显示数字的函数
void displayDigit(unsigned char digit) {
  //定义一个数组表：不同数字的abcdefgh各段的取值
  unsigned char alphabet[][8] = {
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
  
  if ( digit >= 16 ) return;
  for (unsigned char x=0; x<8; x++)
    digitalWrite( pinDigitron + x, alphabet[digit][x] );
}
 
void loop() { 
   //在数码管中显示0-9,A-F各个数字
   for(int digit=4;digit>=1;digit--){
     digitalWrite(9+digit,0);
   for (int x=0; x<16; x++) {
     displayDigit(x);  //调用displayDigit()子函数，显示数字
     delay(100); //等待1000毫秒
   }
   digitalWrite(9+digit,1);
   }
}