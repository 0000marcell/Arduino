import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Graph extends PApplet {


 
Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

public void setup () {
	// set the window size:
	size(400, 300);        

	// List all the available serial ports
	println(Serial.list());
	// I know that the first port in the serial list on my mac
	// is always my  Arduino, so I open Serial.list()[0].
	// Open whatever port is the one you're using.
	myPort = new Serial(this, "", 9600);
	// don't generate a serialEvent() unless you get a newline character:
	myPort.bufferUntil('\n');
	// set inital background:
	background(0);
}
public void draw () {
	// everything happens in the serialEvent()
}
 
public void serialEvent (Serial myPort) {
 // get the ASCII string:
 String inString = myPort.readStringUntil('\n');
 
 if (inString != null) {
	 // trim off any whitespace:
	 inString = trim(inString);
	 // convert to an int and map to the screen height:
	 float inByte = PApplet.parseFloat(inString); 
	 inByte = map(inByte, 0, 1023, 0, height);
	 
	 // draw the line:
	 stroke(127,34,255);
	 line(xPos, height, xPos, height - inByte);
	 
	 // at the edge of the screen, go back to the beginning:
	 if (xPos >= width) {
		 xPos = 0;
		 background(0); 
		 } 
		 else {
		 // increment the horizontal position:
		 xPos++;
 	 }
	}
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Graph" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
