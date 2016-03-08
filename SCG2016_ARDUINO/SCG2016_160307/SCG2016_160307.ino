 


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
long distance; // Duration used to calculate distance

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

void AUTOSAVEsensor(int xtrigPin, int xechoPin) {
 digitalWrite(xtrigPin, LOW);
 delayMicroseconds(2); 
 digitalWrite(xtrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(xtrigPin, LOW);
 int xduration = pulseIn(xechoPin, HIGH);
 int xdistance = xduration/58.2;
 distance = xdistance;
 
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
AUTOSAVEsensor(trigPin,echoPin);
one = distance;

AUTOSAVEsensor(trigPin1,echoPin1);
two = distance;

AUTOSAVEsensor(trigPin2,echoPin2);
tree = distance;

AUTOSAVEsensor(trigPin3,echoPin3);
four = distance;

// digitalWrite(trigPin, LOW); 
// digitalWrite(trigPin1, LOW); 
// digitalWrite(trigPin2, LOW); 
// digitalWrite(trigPin3, LOW); 
// delayMicroseconds(2); 

// digitalWrite(trigPin, HIGH);
// digitalWrite(trigPin1, HIGH);
// digitalWrite(trigPin2, HIGH);
// digitalWrite(trigPin3, HIGH);
// delayMicroseconds(10); 
// 
// digitalWrite(trigPin, LOW);
// digitalWrite(trigPin1, LOW);
// digitalWrite(trigPin2, LOW);
// digitalWrite(trigPin3, LOW);
 
// duration = pulseIn(echoPin, HIGH);
// duration1 = pulseIn(echoPin1, HIGH);
// duration2 = pulseIn(echoPin2, HIGH);
// duration3 = pulseIn(echoPin3, HIGH);
 //Calculate the distance (in cm) based on the speed of sound.
// distance = duration/58.2;
// distance1 = duration1/58.2;
// distance2 = duration2/58.2;
// distance3 = duration3/58.2;
 
// if (distance >= maximumRange || distance <= minimumRange){
// /* Send a negative number to computer and Turn LED ON 
// to indicate "out of range" */
// digitalWrite(LEDPin, HIGH); 
// }
// else {
// /* Send the distance to the computer using Serial protocol, and
// turn LED OFF to indicate successful reading. */
// Serial.println('g'+distance);
// digitalWrite(LEDPin, LOW); 
// }

// MODEL START ________________________________
  if (tree >= maximumRange || tree <= minimumRange){
  digitalWrite(LEDPin, HIGH); 
 }
 else {
   Serial.println('W');
   Serial.println(tree);
   digitalWrite(LEDPin, LOW); 
 }
  if (four >= maximumRange || four <= minimumRange){
  digitalWrite(LEDPin, HIGH); 
 }
 else {
   Serial.println('Q');
   Serial.println(four);
   digitalWrite(LEDPin, LOW); 
 }
 
 if (one >= maximumRange || one <= minimumRange){
  digitalWrite(LEDPin, HIGH); 
 }
 else {
   Serial.println('R');
   Serial.println(one);
   digitalWrite(LEDPin, LOW); 
 }
  if (two >= maximumRange || two <= minimumRange){
  digitalWrite(LEDPin, HIGH); 
 }
 else {
   Serial.println('E');
   Serial.println(two);
   digitalWrite(LEDPin, LOW); 
 }

 
 //Delay 100ms before next reading.
 delay(0);
}



