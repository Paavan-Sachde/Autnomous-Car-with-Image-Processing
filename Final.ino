// Photoresistor Sensor
int ldr = 11;
int x;

// Ultrasonic Sensor
int trig=9;
int echo=10;
int timeInMicro;
int distanceInCm;
int IR1,IR2,PR;

const int EnableL = 3;
const int HighL = 4;       // LEFT SIDE MOTOR
const int LowL =5;

const int EnableR = 6;
const int HighR = 7;       //RIGHT SIDE MOTOR
const int LowR =8;

const int D0 = 0;       //Raspberry pin 21    LSB
const int D1 = 1;       //Raspberry pin 22
const int D2 = 2;       //Raspberry pin 23
//const int D3 = 3;       //Raspberry pin 24    MSB

int a,b,c,d,data;

void setup() {
  // put your setup code here, to run once:
  
  //PRS
  Serial.begin(9600);
  pinMode(11, INPUT);
  //pinMode(12,OUTPUT);
  
  //USS
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);

  //IRS 
  //pinMode(13,OUTPUT);
  pinMode(13,INPUT);
  //pinMode(11,OUTPUT);
  pinMode(12,INPUT);

  pinMode(EnableL, OUTPUT);
pinMode(HighL, OUTPUT);
pinMode(LowL, OUTPUT);


pinMode(EnableR, OUTPUT);
pinMode(HighR, OUTPUT);
pinMode(LowR, OUTPUT);

}
void Forward()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,254);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,240);
  
}
void Stop()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL,0);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR,0);
  
}

void Left1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,190);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}

void Left2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,160);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}


void Left3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,120);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,255);
  
}

void Right1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,254);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,190);  
  
}
void Right2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,254);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,160);   
  
}

void Right3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,254);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,140);   
  
}
void Data()
{
   a = digitalRead(D0);
   b = digitalRead(D1);
   c = digitalRead(D2);

   data = 4*c+2*b+a;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //PRS
  x = digitalRead(11);
  //Serial.println(x);

  if(x == LOW)
  {
    PR = 1;
    //digitalWrite(12,LOW);
  }
  if(x == HIGH)
  {
    PR = 0;
    //digitalWrite(12, HIGH);
  }

  //IRS
  if (digitalRead(13)== LOW)
  {
    //digitalWrite(13,HIGH);
    IR1 = 1;// Condition for LEFT side object detection
    delay(10);
  }
  else 
  {    
    //digitalWrite(13,LOW);
    IR1 = 0;//Condition for LEFT side object detection
    delay(10); 
  }
  if (digitalRead(12)== LOW)
  {
    //digitalWrite(11,HIGH);
    IR2 = 1;// Condition for RIGHT side object detection
    delay(10);
  }
  else 
  {    
    //digitalWrite(11,LOW);
    IR2 = 0;//Condition for RIGHT side object detection
    delay(10); 
  }
  
  //USS
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  timeInMicro = pulseIn(echo,HIGH);

  distanceInCm = timeInMicro/29 /2;
  Serial.println(distanceInCm);
  delay(100);

  if(distanceInCm <= 25){
    Stop();
  }
  else{
    Data();
   // Forward();/*
  if(data==0)
   {
     Forward();
   }
   
  else if(data==1)
   {
     Forward();
     //Right1();
   }
     
  else if(data==2)
   {
     Right2();
   }
     
  else if(data==3)
   {
     Right3();
   }
     
  else if(data==4)
   {
     Left1();
   }
    
  else if(data==5)
   {
     Left2();
   }
    
  else if(data==6)
   {
     Left3();
   }
  
  else if (data>6)
   {
     Stop();
   }
   
  }
}