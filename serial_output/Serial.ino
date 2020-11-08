void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

String incomingBytes;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    delay(100);
    int byteCount = Serial.available();
    String str = (String)"Number of Bytes Received: "+byteCount;
    Serial.println(str);

    for(int i=0; i<byteCount; i++) {
      incomingBytes += (char)(Serial.read());  
    }
    
    str = (String)("You have sent: ")+incomingBytes;
    Serial.println(str);
    incomingBytes = "";

  }
}
