#include <SoftwareSerial.h>

SoftwareSerial SIM900A(2,3);

int vib_pin=8;
int flame_pin=9;
void setup() {
 Serial.begin(9600);
 pinMode(vib_pin,INPUT); 
 pinMode(flame_pin,INPUT);
 SIM900A.begin(9600);  
 Serial.println ("SIM900A Ready");
 delay(100);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  int flame;
  val=digitalRead(vib_pin);
  flame=digitalRead(flame_pin);
  if (val==1)
  {
     SendMessage();
  }
  if (flame==0)
{
  SendNewMessage();
} 
if (flame==0 && val==1)
{
SendNewMessage();
}
  
 return val;
 return flame;
}

void SendMessage(){
  Serial.println ("Sending Message");
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+919894877244\"\r"); //Mobile phone number to send message
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Accident ALERT !!!!   \n  LOCATION : https://goo.gl/maps/iujvRFNcQgPxmwcU8");// Messsage content
  delay(100);
  Serial.println ("Finish");
  SIM900A.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println ("Message has been sent ->SMS Selesai dikirim");
}


void SendNewMessage(){
  Serial.println ("Sending Message");
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+919894877244\"\r"); //Mobile phone number to send message
  delay(1000);
  Serial.println ("Set SMS Content");
  SIM900A.println("Accident ALERT !!!! ACCIDENT WITH FIRE !!!!!!  \n  LOCATION : https://goo.gl/maps/iujvRFNcQgPxmwcU8 ");// Messsage content
  delay(100);
  Serial.println ("Finish");
  SIM900A.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  Serial.println ("Message has been sent ->SMS Selesai dikirim");
}
