 


#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin

#define echoPin1 4 // Echo Pin
#define trigPin1 5 // Trigger Pin

#define echoPin2 6 // Echo Pin
#define trigPin2 7 // Trigger Pin

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
 return xdistance;
}

void loop() {

isLED = false; 

one = AUTOSAVEsensor(trigPin,echoPin);

two = AUTOSAVEsensor(trigPin1,echoPin1);

tree = AUTOSAVEsensor(trigPin2,echoPin2);

four = AUTOSAVEsensor(trigPin3,echoPin3);



// MODEL START ________________________________
 //WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
  if (tree >= maximumRange || tree <= minimumRange){
  isLED = true;
 }
 else {
   Serial.println('W');
   Serial.println(tree);
   digitalWrite(LEDPin, LOW); 
 }
 //QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
  if (four >= maximumRange || four <= minimumRange){
  isLED = true;
 }
 else {
   Serial.println('Q');
   Serial.println(four);
   digitalWrite(LEDPin, LOW); 
 }
 
 //RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
 if (one >= maximumRange || one <= minimumRange){
  isLED = true;
 }
 else {
   Serial.println('R');
   Serial.println(one);
   digitalWrite(LEDPin, LOW); 
 }
 //EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
  if (two >= maximumRange || two <= minimumRange){
  isLED = true;
 }
 else {
   Serial.println('E');
   Serial.println(two);
   digitalWrite(LEDPin, LOW); 
 }

 if(isLED) {
   digitalWrite(LEDPin, HIGH); 
 }

 
 //Delay 100ms before next reading.
 delay(100);
}



