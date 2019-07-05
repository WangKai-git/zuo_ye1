
#include<Arduino.h>
#define ms 250
char MORSE[][4]={
  {'.','-'},
  {'-','.','.','.'},
  {'-','.','-','.'},
  {'-','.','.'},
  {'.'},
  {'.','.','-','.'},
  {'-','-','.'},
  {'.','.','.','.'},
  {'.','.'},
  {'.','-','-','-'},
  {'-','.','-'},
  {'.','-','.','.'},
  {'-','-'},
  {'-','.'},
  {'-','-','-'},
  {'.','-','-','.'},
  {'-','-','.','-'},
  {'.','-','.'},
  {'.','.','.'},
  {'-'},
  {'.','.','-'},
  {'.','.','.','-'},
  {'.','-','-'},
  {'-','.','.','-'},
  {'-','.','-','-'},
  {'-','-','.','.'} ,
};

String incomingstr="";
  String morsestr="";
  int i,j,temp=0,n=0;
  void setup() {
  pinMode(13,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  String morsestr="";
  while(Serial.available()>0)
  {
    temp=1;
    incomingstr+=char(Serial.read());
    n++;
    delay(2);
  }
 if(temp)
 { 
  for(i=0;i<n;i++)
    {
      for(j=0;j<4;j++)
        {if(incomingstr[i]==' ')
           morsestr+='@';
         else if(MORSE[int(incomingstr[i]-97)][j]!='0')
          morsestr+=char(MORSE[int(incomingstr[i]-97)][j]);
        }
        morsestr+='$';  
    }
   
 } 
 Serial.println(morsestr);
 for(i=0;morsestr[i]!='\0';i++)
 {
  if(morsestr[i]=='.')        dot();
  else if(morsestr[i]=='-')   dash();
  else if(morsestr[i]=='$')   cspace();
  else if(morsestr[i]=='@')   wspace(); 
 }
 
}

void dot(){
  digitalWrite(13,HIGH);
  delay(ms);
  digitalWrite(13,LOW);
  delay(ms);
}
void dash(){
  digitalWrite(13,HIGH);
  delay(ms*4);
  digitalWrite(13,LOW);
  delay(ms);
}
void cspace(){
  digitalWrite(13,HIGH);
  delay(ms*3);
  digitalWrite(13,LOW);
  delay(ms);
}
void wspace(){
  digitalWrite(13,HIGH);
  delay(ms*7);
  digitalWrite(13,LOW);
  delay(ms);
}
