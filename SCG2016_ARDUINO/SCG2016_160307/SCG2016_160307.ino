 

//AAAAAAAAAAAAAAAAAAAAAAAAAAAA
#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin

//BBBBBBBBBBBBBBBBBBBBBBBBBBBB
#define echoPin1 4 // Echo Pin
#define trigPin1 5 // Trigger Pin

//CCCCCCCCCCCCCCCCCCCCCCCCCCCC
#define echoPin2 6 // Echo Pin
#define trigPin2 7 // Trigger Pin

//DDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#define echoPin3 8 // Echo Pin
#define trigPin3 9 // Trigger Pin


#define LEDPin 13 // Onboard LED

int maximumRange = 35; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long one, two, tree, four;

bool isLED;
void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 
 pinMode(trigPin3, OUTPUT);
 pinMode(echoPin3, INPUT);
 
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

int AUTOSAVEsensor(int xtrigPin, int xechoPin) {
 digitalWrite(xtrigPin, LOW);
 delayMicroseconds(2); 
 digitalWrite(xtrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(xtrigPin, LOW);
 int xduration = pulseIn(xechoPin, HIGH);
 int xdistance = xduration/58.2;
 if (xdistance >= maximumRange || xdistance <= minimumRange) {
  xdistance = 0;
 }
 return xdistance;
}

void loop() {

isLED = false; 

one = AUTOSAVEsensor(trigPin,echoPin);

two = AUTOSAVEsensor(trigPin1,echoPin1);

tree = AUTOSAVEsensor(trigPin2,echoPin2);

four = AUTOSAVEsensor(trigPin3,echoPin3);

if(one+two+tree+four != 0) {
  Serial.print(one,DEC);
  Serial.print(",");
  Serial.print(two,DEC);
  Serial.print(",");
  Serial.print(tree,DEC);
  Serial.print(",");
  Serial.print(four,DEC);
  Serial.print("|");
  digitalWrite(LEDPin, LOW); 
}

// MODEL START ________________________________
//AAAAAAAAAAAAAAAAAAAAAAAAAAAA
//  if (one >= maximumRange || one <= minimumRange){
//  isLED = true;
// }
// else {
//   Serial.println('A');
//   Serial.println(one);
//   Serial.println('|');
//   digitalWrite(LEDPin, LOW); 
// }

//BBBBBBBBBBBBBBBBBBBBBBBBBBBB
//  if (two >= maximumRange || two <= minimumRange){
//  isLED = true;
// }
// else {
//   Serial.println('B');
//   Serial.println(two);
//   Serial.println('|');
//   digitalWrite(LEDPin, LOW); 
// }
 
//CCCCCCCCCCCCCCCCCCCCCCCCCCCC
// if (tree >= maximumRange || tree <= minimumRange){
//  isLED = true;
// }
// else {
//   Serial.println('C');
//   Serial.println(tree);
//   Serial.println('|');
//   digitalWrite(LEDPin, LOW); 
// }

//DDDDDDDDDDDDDDDDDDDDDDDDDDDDD
//  if (four >= maximumRange || four <= minimumRange){
//  isLED = true;
// }
// else {
//   Serial.println('D');
//   Serial.println(four);
//   Serial.println('|');
//   digitalWrite(LEDPin, LOW); 
// }


 

   digitalWrite(LEDPin, HIGH); 
 

 
 //Delay 100ms before next reading.
 delay(100);
}



