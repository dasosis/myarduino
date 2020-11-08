#include "DHT.h"
#define DHTPIN 13    
#define DHTTYPE DHT11   

int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;
int dt[] = {9, 10, 11, 12};

unsigned char digitMatrix[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E, 0x6E, 0xC6, 0x01};

//0=0xFC
//1=0x60 
//2=0xDA
//3=0xF2 
//4=0x66
//5=0xB6
//6=0xBE
//7=0xE0
//8=0xFE
//9=0xF6
//A=0xEE
//b=0x3E
//C=0x9C
//d=0x7A
//E=0x9E
//F=0x8E
//H=0x6E
//Degree=0xC6
//Point=0x01

void displayTemp(int, int, int);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
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
  
//  Serial.begin(9600);
//  Serial.println("DHT11 Ready!");

  dht.begin();
}
//void loop(){
//  digitalWrite(dt[0],HIGH);
//  unsigned char matrix = 0xDA;
//  if(matrix & 0x80) { digitalWrite(a,LOW); }
//  else { digitalWrite(a,HIGH); }
//  if(matrix & 0x40) { digitalWrite(b,LOW); }
//  else { digitalWrite(b,HIGH); }
//  if(matrix & 0x20) { digitalWrite(c,LOW); }
//  else { digitalWrite(c,HIGH); }
//  if(matrix & 0x10) { digitalWrite(d,LOW); }
//  else { digitalWrite(d,HIGH); }
//  if(matrix & 0x08) { digitalWrite(e,LOW); }
//  else { digitalWrite(e,HIGH); }
//  if(matrix & 0x04) { digitalWrite(f,LOW); }
//  else { digitalWrite(f,HIGH); }
//  if(matrix & 0x02) { digitalWrite(g,LOW); }
//  else { digitalWrite(g,HIGH); }
//  if(matrix & 0x01) { digitalWrite(p,LOW); }
//  else { digitalWrite(p,HIGH); }
//  delay(1000);
//  digitalWrite(dt[0],LOW);
//}


void loop() {
   int cen = dht.readTemperature();
   DisplayCen(cen);
   int fah = dht.readTemperature(true);
   DisplayFah(fah);
   int hum = dht.readHumidity();
   DisplayHum(hum);
   }
void DisplayCen(int cen){
   int number[] = {cen/10, cen%10, 17, 12};
   for(int j=0;j<500;j++){
     for(int i=0;i<4;i++){
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
void DisplayFah(int fah){
   int number[] = {fah/10, fah%10, 17, 15};
   for(int j=0;j<500;j++){
     for(int i=0;i<4;i++){
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
void DisplayHum(int hum){
   int number[] = {hum/10, hum%10, 18, 16};
   for(int j=0;j<500;j++){
   for(int i=0;i<4;i++){
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
//       digitalWrite(dt[1],HIGH);
//    matrix =  digitMatrix[number[1]];
//      if(matrix & 0x80) { digitalWrite(a,LOW); }
//      else { digitalWrite(a,HIGH); }
//      if(matrix & 0x40) { digitalWrite(b,LOW); }
//      else { digitalWrite(b,HIGH); }
//      if(matrix & 0x20) { digitalWrite(c,LOW); }
//      else { digitalWrite(c,HIGH); }
//      if(matrix & 0x10) { digitalWrite(d,LOW); }
//      else { digitalWrite(d,HIGH); }
//      if(matrix & 0x08) { digitalWrite(e,LOW); }
//      else { digitalWrite(e,HIGH); }
//      if(matrix & 0x04) { digitalWrite(f,LOW); }
//      else { digitalWrite(f,HIGH); }
//      if(matrix & 0x02) { digitalWrite(g,LOW); }
//      else { digitalWrite(g,HIGH); }
//      if(matrix & 0x01) { digitalWrite(p,LOW); }
//      else { digitalWrite(p,HIGH); }
//      
//      delay(1000);
// digitalWrite(dt[2],HIGH);
//    matrix =  digitMatrix[number[2]];
//      if(matrix & 0x80) { digitalWrite(a,LOW); }
//      else { digitalWrite(a,HIGH); }
//      if(matrix & 0x40) { digitalWrite(b,LOW); }
//      else { digitalWrite(b,HIGH); }
//      if(matrix & 0x20) { digitalWrite(c,LOW); }
//      else { digitalWrite(c,HIGH); }
//      if(matrix & 0x10) { digitalWrite(d,LOW); }
//      else { digitalWrite(d,HIGH); }
//      if(matrix & 0x08) { digitalWrite(e,LOW); }
//      else { digitalWrite(e,HIGH); }
//      if(matrix & 0x04) { digitalWrite(f,LOW); }
//      else { digitalWrite(f,HIGH); }
//      if(matrix & 0x02) { digitalWrite(g,LOW); }
//      else { digitalWrite(g,HIGH); }
//      if(matrix & 0x01) { digitalWrite(p,LOW); }
//      else { digitalWrite(p,HIGH); }
//      
//      delay(1000);
//      digitalWrite(dt[3],HIGH);
//    matrix =  digitMatrix[number[3]];
//      if(matrix & 0x80) { digitalWrite(a,LOW); }
//      else { digitalWrite(a,HIGH); }
//      if(matrix & 0x40) { digitalWrite(b,LOW); }
//      else { digitalWrite(b,HIGH); }
//      if(matrix & 0x20) { digitalWrite(c,LOW); }
//      else { digitalWrite(c,HIGH); }
//      if(matrix & 0x10) { digitalWrite(d,LOW); }
//      else { digitalWrite(d,HIGH); }
//      if(matrix & 0x08) { digitalWrite(e,LOW); }
//      else { digitalWrite(e,HIGH); }
//      if(matrix & 0x04) { digitalWrite(f,LOW); }
//      else { digitalWrite(f,HIGH); }
//      if(matrix & 0x02) { digitalWrite(g,LOW); }
//      else { digitalWrite(g,HIGH); }
//      if(matrix & 0x01) { digitalWrite(p,LOW); }
//      else { digitalWrite(p,HIGH); }
//      
//      delay(1000);


//*/
