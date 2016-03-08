/*
Example sketch that enables the user to control Resolume Avenue 3 using OSC
*/
 
// start OSC config
import oscP5.*;
import netP5.*;
import processing.serial.*;

/*portToListenTo, port we are listening on, this should be the same as
the outgoing port of TouchOsc on your iphone
*/
int portToListenTo = 7001; 
/*portToSendTo, port we are sending to, this should be the same as
the incomning port of Resolume 3, default it is set to 7000, so you wouldn't need to change it.
*/
int portToSendTo = 7000;
/*ipAddressToSendTo, ip address of the computer we are sending messages to (where Resolume 3 runs)
*/
String ipAddressToSendTo = "localhost";

OscP5 oscP5;
NetAddress myRemoteLocation;
OscBundle myBundle;
OscMessage myMessage;
//end OSC config

boolean mouseDown;

String comPortString;
Serial myPort;

void setup() {
  size(640,480);
  frameRate(5);
  String portName = Serial.list()[5]; 
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); // Trigger a SerialEvent on new line
 
  oscP5 = new OscP5(this,portToListenTo);
  myRemoteLocation = new NetAddress(ipAddressToSendTo, portToSendTo);  
  myBundle = new OscBundle();
  myMessage = new OscMessage("/"); 
  myMessage.add("0");
}

/* ---------------------serialEvent ---------------------------*/
void serialEvent(Serial cPort){
 boolean send = false;
 comPortString = cPort.readString();
 println(comPortString);

 if(comPortString != null) {
 comPortString = trim(comPortString);
 int recieveddistance = (Integer.parseInt(comPortString));
 //print(recieveddistance);
 //print('\n');
 //(Integer.parseInt(comPortString))

if( recieveddistance <= 10 && recieveddistance >= 0){
    myMessage.setAddrPattern("/layer2/clip1/connect");
    myMessage.add(1);
    myBundle.add(myMessage);
   send = true;
}
  if (send)
    oscP5.send(myBundle, myRemoteLocation);
  myBundle.clear();
 }
}

void draw() {

  //background(0);  
  
  ////draw some rectangles and text
  //fill(255);
  //rect(1, 1, width-3, height-103);
  //fill(0);
  //text("hold mouse to rotate", 5, 24);

  //fill(200);
  //rect(1, height-100, width-3, 98);
  //fill(0);
  //text("hold mouse to scrub", 5, 400);
  
  ////calculate x and y pos in the range 0.0 - 1.0
  //float xpos = (float) mouseX / (float) width;
  //float ypos = (float) mouseY / (float) height;
  
  //boolean send = false;
 

  ////check if we need to send a rotate messages  
  //if (mouseDown && mouseY < height-100) {
  
  // myMessage.setAddrPattern("/layer1/clip1/connect");
  // myMessage.add(ypos);
  // myBundle.add(myMessage);
  // myMessage.clear();
    
  // send = true;
    
  //}
  
  ////check if a scrubbing message should be send
  //if ( mouseDown && mouseY > height-100 ) {
  // myMessage.setAddrPattern("/layer3/clip1/connect");
  // myMessage.add(xpos);
  // myBundle.add(myMessage);
  // myMessage.clear();
  // send = true;
  //}
  
  ///* send the bundle*/
  //if (send)
  // oscP5.send(myBundle, myRemoteLocation); 
  
  //myBundle.clear();
 
}