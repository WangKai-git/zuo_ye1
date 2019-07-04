//f前进 b后退 l左转 r右转 s停止
void setup()
{
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
char income;
void loop()
{	if(Serial.available()>0)
    income=Serial.read();
     switch(income)
{
  case 'f':
     forward();
     break;
   case 'b':
     backward();
     break;
   case 'l':
     left();
     break;
   case 'r':
     right();
     break;
  case 's':
     stop();
     break;
}


}

void forward()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}

void backward()
{
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}

void left()
{
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
}

void right()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
}
 void stop()
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
}
