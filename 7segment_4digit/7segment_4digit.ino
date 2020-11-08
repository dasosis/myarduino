int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

unsigned char digitMatrix[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

void displayDigit(int displayCount);

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
}
 
//void loop() {
//  static int displayCount = 0;

//  if(digitalRead(btnPin) == LOW) {
//    delay(50);
//    if(digitalRead(btnPin) == LOW) {
//      btnPressCount++;
//      String str = (String)("Button Count =  ")+btnPressCount+"\r\n";
//      Serial.print(str);
//      displayLed(btnPressCount);
//      displayDigit(btnPressCount);
//      while(digitalRead(btnPin) == LOW) {
//        // do nothing
//      }
//    }
//    displayDigit(displayCount);
//    delay(500);
//    displayCount = (displayCount+1)%0x10;
//  }
  

void loop()
{
  static int displayCount = 0;
   displayDigit(displayCount);
//  digitalWrite(d1, HIGH);
//  digitalWrite(d2, LOW);
//  digitalWrite(d3, LOW);
//  digitalWrite(d4, LOW);
//  digitalWrite(a, LOW);
//  digitalWrite(b, HIGH);
//  digitalWrite(c, HIGH);
//  digitalWrite(d, HIGH);
//  digitalWrite(e, HIGH);
//  digitalWrite(f, HIGH);
//  digitalWrite(g, HIGH);
//  digitalWrite(p, HIGH);
}

void displayDigit(int displayCount) {
  if((displayCount < 0x00) || (displayCount > 0x0F)) {
    displayCount = displayCount & 0x0F;
  }
  
  unsigned char matrix = digitMatrix[displayCount];
  if(matrix & 0x80) { digitalWrite(a,HIGH); }
  else { digitalWrite(a,LOW); }
  if(matrix & 0x40) { digitalWrite(b,HIGH); }
  else { digitalWrite(b,LOW); }
  if(matrix & 0x20) { digitalWrite(c,HIGH); }
  else { digitalWrite(c,LOW); }
  if(matrix & 0x10) { digitalWrite(d,HIGH); }
  else { digitalWrite(d,LOW); }
  if(matrix & 0x08) { digitalWrite(e,HIGH); }
  else { digitalWrite(e,LOW); }
  if(matrix & 0x04) { digitalWrite(f,HIGH); }
  else { digitalWrite(f,LOW); }
  if(matrix & 0x02) { digitalWrite(g,HIGH); }
  else { digitalWrite(g,LOW); }
  if(matrix & 0x01) { digitalWrite(dp,HIGH); }
  else { digitalWrite(dp,LOW); }


}
