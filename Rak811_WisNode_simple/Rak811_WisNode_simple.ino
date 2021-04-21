
void setup() {
  Serial.begin(115200);
     
  // waiting to WisNode to join to the network
  delay(20000);
}


void loop() {
  
  sendData(1,"1234"); 
  
  delay(10000);
}

void sendData(int port, String data){ 
  String command = "at+send=lora:" + (String)port + ":" + data; 
  sendCommand(command); 
} 

void sendCommand(String atComm){ 
  Serial.println(atComm); 
  readLora();
}

String readLora() { 
  String response = ""; 
  while(Serial.available()){ 
    char ch = Serial.read(); 
    response += ch; 
  }
  return response;
}
