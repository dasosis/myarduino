int btnPin=0;

int ledPin1=10;
int ledPin2=11;
int ledPin3=12;
int ledPin4=13;

int a=7; //definition digital 7  pins as pin to control 'a' section(segment)
int b=6; //definition digital 6  pins as pin to control 'b' section(segment)
int c=4; //definition digital 4  pins as pin to control 'c' section(segment)
int d=2;//definition digital 11 pins as pin to control 'd' section(segment)
int e=3;//definition digital 10 pins as pin to control 'e' section(segment)
int f=8; //definition digital 8  pins as pin to control 'f' section(segment)
int g=9; //definition digital 9  pins as pin to control 'g' section(segment)
int dp=5;//definition digital 5  pins as pin to control


/*
#define trigPin 12 // define TrigPin
#define echoPin 11 // define EchoPin.
#define MAX_DISTANCE 200 // Maximum sensor distance is rated at 400-500cm.
// define the timeOut according to the maximum range. timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
float timeOut = MAX_DISTANCE * 60; 
int soundVelocity = 340; // define sound speed=340m/s
*/

int btnPressCount = 0;

void displayLed(int btnPressCount);
void displayDigit(int displayCount);


unsigned char digitMatrix[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

void setup() {
  // put your setup code here, to run once:
  pinMode(btnPin,INPUT_PULLUP);
  
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  static int displayCount = 0;

  if(digitalRead(btnPin) == LOW) {
    delay(50);
    if(digitalRead(btnPin) == LOW) {
      btnPressCount++;
      String str = (String)("Button Count =  ")+btnPressCount+"\r\n";
      Serial.print(str);
      displayLed(btnPressCount);
      displayDigit(btnPressCount);
      while(digitalRead(btnPin) == LOW) {
        // do nothing
      }
    }
//    displayDigit(displayCount);
//    delay(500);
//    displayCount = (displayCount+1)%0x10;
  }
  
/*
  unsigned long pingTime;
  float distance;
  static float prevDistance;
  
  digitalWrite(trigPin, HIGH); // make trigPin output high level lasting for 10μs to triger HC_SR04,
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH, timeOut); // Wait HC-SR04 returning to the high level and measure out this waitting time
  distance = (float)pingTime * soundVelocity / 2 / 10000; // calculate the distance according to the time
  delay(100);
  if((distance != 0) && ((distance > prevDistance+50) || (distance < prevDistance-50))) {
    prevDistance = distance;
    String str = (String)("Distance = ")+distance+"cm\r\n";
    Serial.print(str);
    if(distance < 100) {
      btnPressCount++;
      displayLed();
      delay(2000);
    }
  }


  
  // put your main code here, to run repeatedly:
//  digitalWrite(ledPin,HIGH); //HIGH is set to about 5V PIN8
//  delay(500); //Set the delay time, 1000 = 1S
//  digitalWrite(ledPin,LOW); //LOW is set to about 5V PIN8
//  delay(500); //Set the delay time, 1000 = 1S
  */
}


void displayLed (int btnPressCount) {
  unsigned char btnCount = (btnPressCount & 0x000F);

  for(int i=0; i<4; i++) {
    int led = i+10;
    if((btnCount & (0x01 << i)) != 0) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
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
