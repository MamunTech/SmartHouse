/*
 * 
 * developed by Abdullah Al Mamun,EEE(EWU),Bangladesh,Dhaka
 * 
 */
#include <Servo.h> 
#include <SoftwareSerial.h>
Servo myservo;
SoftwareSerial mySerial(2,3);
void setup()
{
  mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);    // baud rate 
  delay(500);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  myservo.attach(11);
   pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
   pinMode(A5, OUTPUT);//buzzer

}

void loop() {
  int sensorValue1 = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage1);
  if(voltage1>1){
    digitalWrite(A5,HIGH);
    }
    else
    {
    digitalWrite(A5,LOW);
    }
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
if(voltage>1)
{
 housekeeper();
 police();

  }
  
 while(Serial.available()){
  switch(Serial.read()){
    
  case 'A':
  MBLON();  // Master Bedroom Light ON 
  break;
  
  case 'B':
  MBLOFF();  //  Master Bedroom Light OFF
  break; 

  case 'C':
  MBFON();  // Master Bedroom Fan ON 
  break; 

  case 'D':
  MBFOFF();  // Master Bedroom Fan OFF
  break; 

  case 'E':
  BLON();  // Bedroom Light ON  
  break; 

  case 'F':
  BLOFF();  // Bedroom Light OFF 
  break; 

  case 'G':
  BFON();  // Bedroom Fan ON 
  break; 

  case 'H':
  BFOFF();  // Bedroom Fan OFF 
  break; 

  case 'I':
  LLON();  // Livingroom Light ON 
  break; 
  
  case 'J':
  LLOFF();  // Livingroom Light OFF 
  break; 

  case 'K':
  LFON();  // Livingroom Fan ON 
  break; 

  case 'L':
  LFOFF();  // Livingroom Light OFF 
  break; 

  case 'M':
  MWLON();  // Master Washroom Light ON 
  break; 

  case 'N':
  MWLOFF();  // Master Washroom Light OFF 
  break; 

  case 'O':
  KLON();  // Kitchen Light ON 
  break; 

  case 'P':
  KLOFF();  // Kitchen Light OFF 
  break; 

  case 'Q':
  CWLON();  // Common Washroom Light ON
  break; 

  case 'R':
  CWLOFF();  // Common Washroom Light OFF 
  break; 

  case 'S':
  DOPEN();  // Door Open
  break; 

  case 'T':
  DCLOSE();  // Door Close 
  break; 
  
  
 }
 }
}
void MBLON(){
  digitalWrite(4,HIGH);
    }
void MBLOFF(){
   digitalWrite(4,LOW);
  }
  void MBFON(){
  digitalWrite(5,HIGH);
  }
void MBFOFF(){
    digitalWrite(5,LOW);
  }
 void BLON(){
  digitalWrite(6,HIGH);
 }
  void BLOFF(){
  digitalWrite(6,LOW);
  }
  void BFON(){
  digitalWrite(7,HIGH);
  }
  void BFOFF(){
  digitalWrite(7,LOW);
  }
  void LLON(){
  digitalWrite(8,HIGH);
  }
  void LLOFF(){
  digitalWrite(8,LOW);
  }
  void LFON(){
  digitalWrite(9,HIGH);
  }
  void LFOFF(){
  digitalWrite(9,LOW);
  }
  void MWLON(){
  digitalWrite(10,HIGH);
  }
  void MWLOFF(){
  digitalWrite(10,LOW);
  }
  void KLON(){
  digitalWrite(13,HIGH);
  }
  void KLOFF(){
  digitalWrite(13,LOW);
  }
  void CWLON(){
  digitalWrite(12,HIGH);
  }
  void CWLOFF(){
  digitalWrite(12,LOW);
  }
  void DOPEN(){
 myservo.write(90); 
  }
  void DCLOSE(){
 myservo.write(0); 
  }

  void housekeeper()
  {
    mySerial.println("AT+CMGF=1");    //Because we want to send the SMS in text mode
  delay(1000);
  mySerial.println("AT + CMGS = \"+8801674533935\"\r");//send sms message, be careful need to add a country code before the cellphone number
  delay(1000);
  mySerial.println("Someone enter your house");//the content of the message
  delay(100);
  mySerial.println((char)26);//the ASCII code of the ctrl+z is 26 
  delay(100);
  mySerial.println(); 
    }

   void  police()
  {
    mySerial.println("AT+CMGF=1");    //Because we want to send the SMS in text mode
  delay(1000);
  mySerial.println("AT + CMGS = \"+8801672537977\"\r");//send sms message, be careful need to add a country code before the cellphone number
  delay(1000);
  mySerial.println("Emergency alert Anamik's Villa.");//the content of the message
  delay(100);
  mySerial.println((char)26);//the ASCII code of the ctrl+z is 26
  delay(100);
  mySerial.println(); 
    }
