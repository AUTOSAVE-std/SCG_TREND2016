
import oscP5.*;
import netP5.*;
import processing.serial.*;

int portToSendTo = 7000;
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
  size(10,10);
  frameRate(5);
  String portName = Serial.list()[5]; 
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); 

  OscProperties myProperties = new OscProperties();
  myProperties.setDatagramSize(100000); 
  
  
  oscP5 = new OscP5(this,myProperties);
  
  
  myRemoteLocation = new NetAddress(ipAddressToSendTo, portToSendTo);  
  
  myBundle = new OscBundle();
  myMessage = new OscMessage("/"); 
  myMessage.add("0");

}

/* ---------------------serialEvent ---------------------------*/
//void serialEvent(Serial cPort){
// boolean send = false;
// comPortString = cPort.readString();
// println(comPortString);

// if(comPortString != null) {
// comPortString = trim(comPortString);
// int recieveddistance = (Integer.parseInt(comPortString));
 

//if( recieveddistance <= 10 && recieveddistance >= 0){
//    myMessage.setAddrPattern("/layer2/clip1/connect");
//    myMessage.add(1);
//    myBundle.add(myMessage);
//    send = true;

//}
//if(send) {
//  oscP5.send(myBundle, myRemoteLocation); 
//}
//  myBundle.clear();
// }
//}
/* --------------------- end serialEvent ---------------------------*/
void draw() {
 boolean send = false;
 comPortString = myPort.readStringUntil(124);
 if(comPortString != null) {
 comPortString = trim(comPortString);
 //print(comPortString);
 int inputs[] = int(split(comPortString, ','));
 if(inputs.length == 4){
   //print( inputs[0]);
   //print('-');
   //print(inputs[1]);
   //print('-');
   //print( inputs[2]);
   //print('-');
   //print(inputs[3]);

   if(inputs[0] !=0){
     myMessage.setAddrPattern("/track1/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;

   }
   if(inputs[1]  !=0){
     myMessage.setAddrPattern("/track2/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   if(inputs[2] !=0){
     myMessage.setAddrPattern("/track3/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
  
   if(inputs[3]  !=0){
     myMessage.setAddrPattern("/track4/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   
 }
 
 //int recieveddistance = (Integer.parseInt(comPortString));
 

//if(true){
//    myMessage.setAddrPattern("/layer2/clip1/connect");
//    myMessage.add(1);
//    myBundle.add(myMessage);
//    send = true;

//}
if(send) {
  oscP5.send(myBundle, myRemoteLocation); 
}
  myBundle.clear();
 }
}