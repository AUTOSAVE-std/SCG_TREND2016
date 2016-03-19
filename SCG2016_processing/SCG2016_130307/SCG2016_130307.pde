
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
Serial myPort2;
void setup() {
  size(1,1);
  frameRate(5);
  String portName = Serial.list()[2]; 
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n'); 
  
  String portName2 = Serial.list()[3]; 
  myPort2 = new Serial(this, portName2, 9611);
  myPort2.bufferUntil('\n'); 
  
  OscProperties myProperties = new OscProperties();
  myProperties.setDatagramSize(100000); 
  
  
  oscP5 = new OscP5(this,myProperties);
  
  
  myRemoteLocation = new NetAddress(ipAddressToSendTo, portToSendTo);  
  
  myBundle = new OscBundle();
  myMessage = new OscMessage("/"); 
  myMessage.add("0");

}
int[] GETintArray(Serial actualfuck){
  String Destring = actualfuck.readStringUntil(124);
  if(Destring != null) {
    Destring = trim(Destring);
    Destring = Destring.substring(0, Destring.length() - 1);
    int[] me = int(split(Destring, ','));
    return me;
  }
  return null;
}

void draw() {
 boolean send = false;
 int[] inputAR1 = GETintArray(myPort);
 int[] inputAR2 = GETintArray(myPort2);
 if(inputAR2 != null &&  inputAR2.length == 4){
 //print(inputAR2[0]);
 //print('-');
 //print(inputAR2[1]);
 //print('-');
 //print(inputAR2[2]);
 //print('-');
 //print(inputAR2[3]);
 //println("- NEW");
   if(inputAR2[0] !=0){
     myMessage.setAddrPattern("/track1/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   if(inputAR2[1]  !=0){
     myMessage.setAddrPattern("/track2/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   if(inputAR2[2] !=0){
     myMessage.setAddrPattern("/track3/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
  
   if(inputAR2[3]  !=0){
     myMessage.setAddrPattern("/track4/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
  
   }
 }
 if(inputAR1 != null &&  inputAR1.length == 4){
 //print(inputAR1[0]);
 //print('-');
 //print(inputAR1[1]);
 //print('-');
 //print(inputAR1[2]);
 //print('-');
 //print(inputAR1[3]);
 //println("- OLD");
   if(inputAR1[0] !=0){
     myMessage.setAddrPattern("/track1/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   if(inputAR1[1]  !=0){
     myMessage.setAddrPattern("/track2/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
   if(inputAR1[2] !=0){
     myMessage.setAddrPattern("/track3/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
  
   if(inputAR1[3]  !=0){
     myMessage.setAddrPattern("/track4/connect");
     myMessage.add(1);
     myBundle.add(myMessage);
     send = true;
   }
 }
 
 if(send) {
  oscP5.send(myBundle, myRemoteLocation); 
}
  myBundle.clear();
}