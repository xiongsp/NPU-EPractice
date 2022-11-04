int LG=8;
int LB=7;

int RG=2;
int RB=4;

int LP=6;
int RP=5;


int LEFT1=A2;
int LEFT2=A1;
int RIGHT1=A3;
int RIGHT2=A4;

void leftgo(int v){
  digitalWrite(LG,HIGH);
  digitalWrite(LB,LOW);
  digitalWrite(RG,LOW);
  digitalWrite(RB,HIGH);
  analogWrite(LP,v);
  analogWrite(RP,v);
}

void rightgo(int v){
  digitalWrite(RG,HIGH);
  digitalWrite(RB,LOW);
  digitalWrite(LG,LOW);
  digitalWrite(LB,HIGH);
  analogWrite(RP,v);
  analogWrite(LP,v);
}

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int L1_status=digitalRead(LEFT1);
  int L2_status=digitalRead(LEFT2);
  int R1_status=digitalRead(RIGHT1);
  int R2_status=digitalRead(RIGHT2);
  Serial.print(L1_status);
  Serial.print(L2_status);
  Serial.print(R1_status);
  Serial.println(R2_status);
  leftgo(255);
  rightgo(255);
}
