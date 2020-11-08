int ledPin1=10;
int ledPin2=11;
int ledPin3=12;
int ledPin4=13;

void displayLed(int ping);

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  //Serial.begin(115200);
}

void loop() {
  static int ping = 0; 
  displayLed(ping); 
  ping = (ping+1)%0x10;  
  delay(500);   
  }
  
void displayLed (int ping) {
  unsigned char Hexarr = (ping & 0x000F);

  for(int i=0; i<4; i++) {
    int led = i+10;
    if((Hexarr & (0x01 << i)) != 0) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
}
