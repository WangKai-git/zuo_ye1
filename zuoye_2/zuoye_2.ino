void setup()
{
  pinMode(5,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}
byte income;
void loop()
{if(Serial.available()>0){
  delay(10);
 digitalWrite(7,LOW);
 income=Serial.read()-'0';
   if(income&0x01)
     digitalWrite(5,HIGH);
   else
     digitalWrite(5,LOW);
 if((income>>1)&0x01)
     digitalWrite(2,HIGH);
   else
     digitalWrite(2,LOW);
 if((income>>2)&0x01)
     digitalWrite(3,HIGH);
   else
     digitalWrite(3,LOW);
 if((income>>3)&0x01)
     digitalWrite(4,HIGH);
   else
     digitalWrite(4,LOW);
 delay(10);
 digitalWrite(7,HIGH);
}
}
