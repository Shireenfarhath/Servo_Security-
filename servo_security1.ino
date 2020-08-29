#include<Servo.h>
//initialize
Servo myservo;
const int trigpin=7;
const int echopin=6;
int red=4;
int green=5;
int buz=8;
volatile float dis;
volatile float time;
//Setting the modes
void setup()
{
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buz,OUTPUT);
  myservo.attach(9);
}
// Operation Logic
void loop()
{   
//servo rotate 160deg
  for(int i=0;i<=160;i++)
  {
    myservo.write(i);
    delay(30);
  }
  for(int i=160;i>=0;i--)
  {
    myservo.write(i);
    delay(30);
  }
//ultrasonic 
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  time=pulseIn(echopin,HIGH);
  dis= time / 58.2;
  delay(10);
  
if (dis<=15)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(buz,HIGH);
  }
else if ((dis>15)&&(dis<25))
  {
     digitalWrite(green,HIGH);
     digitalWrite(red,HIGH);
     digitalWrite(buz,LOW);
  }
Serial.println(dis);  
}