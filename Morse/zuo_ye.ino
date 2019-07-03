#include <Morse.h>
Morse morse(13);
//#include<Morse.h>
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
  
 Serial.begin(9600);
}

void loop() {
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
  if(morsestr[i]=='.') morse.dot();
  else if(morsestr[i]=='-')morse.dash();
  else if(morsestr[i]=='$')morse.c_space();
  else if(morsestr[i]=='@')morse.w_space(); 
 }
 
}
