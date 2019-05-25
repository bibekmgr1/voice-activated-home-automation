#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); // RX pin, TX pin we design


const byte roomlight = 5;
const int kitchenfan = 4;
const int roomfan = 7;
const int livingroomfan = 6;
String rmessage;


boolean light1=false;
boolean light2=false;
boolean fan2=false;
boolean fan3=false;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(roomlight,OUTPUT);
  pinMode(kitchenfan,OUTPUT);
  pinMode(roomfan,OUTPUT);
  pinMode(livingroomfan,OUTPUT);
  pinMode(13,OUTPUT);
  
  digitalWrite(roomlight,HIGH);
digitalWrite(kitchenfan,HIGH);
digitalWrite(roomfan,HIGH);
digitalWrite(livingroomfan,HIGH);
digitalWrite(13,HIGH);
 //attachInterrupt(digitalPinToInterrupt(interrupPin), serialListener , HIGH);

}

    
    void loop() {
  
 
if(mySerial.available() > 0){
         
         rmessage = mySerial.readStringUntil('\n');  
         
       switchcase( rmessage);
      
       
}
}
 void switchcase(String rmessage){
 
  Serial.print(rmessage);
  //Serial.print("me");
  if(rmessage.equals("roomlighton")){
     digitalWrite(roomlight,HIGH);
     
     light1=true;
     }
    if(rmessage.equals("roomlightoff"))
    {
     digitalWrite(roomlight,LOW); 
     light2=false;  } 
     if(rmessage == "kitchenfanon")
   {
    digitalWrite(kitchenfan,HIGH);
    light2=true;
  }
 if(rmessage.equals("kitchenfanoff")){
    digitalWrite(kitchenfan,LOW);
    light2=false;
  }
   if (rmessage.equals("roomfanon")){
  digitalWrite(roomfan,HIGH);
  fan2=true;
  }
    if (rmessage.equals("roomfanoff")){
  digitalWrite(roomfan,LOW);
  fan2=false;
}
 if(rmessage.equals("livingroomfanon")){
digitalWrite(livingroomfan,HIGH);
fan3=true;
}
if(rmessage.equals("livingroomfanoff")){

digitalWrite(livingroomfan,LOW);
fan3=false;
}
if (rmessage.equals("allon"))
{
  digitalWrite(roomlight,HIGH);
  digitalWrite(kitchenfan,HIGH);
  digitalWrite(roomfan,HIGH);
    digitalWrite(livingroomfan,HIGH);
light1=true;
light1=true;
fan2=true;
fan3=true;
}
if (rmessage.equals("alloff"))
{
  digitalWrite(roomlight,LOW);
  digitalWrite(kitchenfan,LOW);
  digitalWrite(roomfan,LOW);
    digitalWrite(livingroomfan,LOW);
light1=false;
light2=false;
fan2=false;
fan3=false;
}

else{}
 
    } 
