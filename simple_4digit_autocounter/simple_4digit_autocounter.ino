int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;
int dt[] = {9, 10, 11, 12};
unsigned char digitMatrix[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

void displayDigit(int displayCount);

void setup()
{
  pinMode(dt[0], OUTPUT);
  pinMode(dt[1], OUTPUT);
  pinMode(dt[2], OUTPUT);
  pinMode(dt[3], OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
}
 
void loop(){
  static int displayCount = 0;
  displayDigit(displayCount);
//  delay(50);
  displayCount = (displayCount+1)%0x270F;

//   if((displayCount > 0x00) && (displayCount < 0x0A)){
//    digitalWrite(d1,HIGH); 
//    displayDigit(displayCount);
//    delay(200); 
//    }
//   if(displayCount >= 0x0A){
//    int n2 = displayCount%10;
//    int n1 = displayCount/10;
//    int i=0; 
//    while(i<10){
//      digitalWrite(d1,HIGH); 
//      displayDigit(n1);
//      delay(5);
//      digitalWrite(d1,LOW); 
//      digitalWrite(d2,HIGH); 
//      displayDigit(n2);
//      delay(5);
//      digitalWrite(d2,LOW); 
//      i++;
//      }
//    }
//   displayCount = (displayCount+1)%0x64;  
  }

void displayDigit(int displayCount){
    int number[] = {displayCount/1000%10, displayCount/100%10, displayCount/10%10, displayCount%10};
    for(int j=0; j<10; j++){
    for(int i=0; i<4; i++){
      digitalWrite(dt[i],HIGH);
      unsigned char matrix = digitMatrix[number[i]];
      if(matrix & 0x80) { digitalWrite(a,LOW); }
      else { digitalWrite(a,HIGH); }
      if(matrix & 0x40) { digitalWrite(b,LOW); }
      else { digitalWrite(b,HIGH); }
      if(matrix & 0x20) { digitalWrite(c,LOW); }
      else { digitalWrite(c,HIGH); }
      if(matrix & 0x10) { digitalWrite(d,LOW); }
      else { digitalWrite(d,HIGH); }
      if(matrix & 0x08) { digitalWrite(e,LOW); }
      else { digitalWrite(e,HIGH); }
      if(matrix & 0x04) { digitalWrite(f,LOW); }
      else { digitalWrite(f,HIGH); }
      if(matrix & 0x02) { digitalWrite(g,LOW); }
      else { digitalWrite(g,HIGH); }
      if(matrix & 0x01) { digitalWrite(p,LOW); }
      else { digitalWrite(p,HIGH); }
      
      delay(1);
      digitalWrite(dt[i],LOW);
      } 
    } 
  }
