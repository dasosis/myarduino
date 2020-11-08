
int ledPin2=11;
int ledPin3=12;


void setup() {
 
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin3, LOW);
}
