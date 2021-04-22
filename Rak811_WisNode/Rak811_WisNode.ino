// Sample code for my article here:
// https://www.hackster.io/antal-attila/rak811-wisnode-lora-as-shield-637f41

// more about AT commands
// https://www.thethingsnetwork.org/docs/devices/rak811-wisnode-lora-module/configuring-wisnode/index.html

#include <SoftwareSerial.h>

SoftwareSerial lora(D6, D7); // RX, TX

unsigned long sendDelay;

void setup() {
  Serial.begin(115200);
  lora.begin(115200);
   
  // waiting to WisNode to join to the network
  delay(30000);
}


void loop() {
  if (millis() > sendDelay + 60000) {
    sendMeassage(1,"AAAAAAAA"); 
    sendDelay = millis(); 
  }

  readMessage();

  delay(100);
}

// Send a customized data.
// port: LoRa port
// data: the data which you want to send. The limited length is 50 Bytes, and the data must be in HEX format.
void sendMeassage(int port, String data){ 
  String command = "at+send=lora:" + (String)port + ":" + data; 
  Serial.println(command); 
  lora.println(command); 
} 


String readMessage() { 
  String response = ""; 
  while(lora.available()){ 
    char ch = lora.read(); 
    response += ch; 
  }
  if(response != "") {
    Serial.println(response); 
  }
  return response;
}
