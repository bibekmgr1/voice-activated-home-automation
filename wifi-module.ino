#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "wifiname";
const char* password = "wifipassword";

ESP8266WebServer server(80);


void setup()
{
  Serial.begin(9600);
  Serial.print("helow");
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  Serial.print("Connecting to %s ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  server.on("/",handleGenericArgs);
  //server.on("/specificArgs",handleSpecificArgs);

  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
}


void loop()
{
  server.handleClient();
}

// <-------------- get request format------------------>
//http://192.168.1.102/genericArgs?john=bro&greating=hello

void handleGenericArgs(){
  String message = "Number of Args:";
  message +=server.args(); // server.args gives you nuber of argument send
  message+="\n";
//  Serial.print("dsadadsa"+message);
  String serialMessage = "";
      for(int i=0;i <server.args();i++){
//        message +="Arg no" +(String)i + "->";
//        message +=server.argName(i) + ":";
//        message +=server.arg(i) + "\n";
        serialMessage +=server.arg(i);
//        Serial.print("insdi loop");
      }
//      Serial.print("serialMessage: "+serialMessage); 
//      Serial.print("serialMessage: "+server.args()); 
      serialMessage +="\n";
  digitalWrite(2,HIGH);
      if(!(Serial.print(serialMessage))){
            String errorMessage = "Error on Serial Print to Arduino";
            server.send(200,"text/plain",errorMessage);
      }
      else{
       String errorMessage = serialMessage;
        server.send(200,"text/plain",errorMessage);
      }
  digitalWrite(2,LOW);    
      
  server.send(200,"text/plain",message);
}


