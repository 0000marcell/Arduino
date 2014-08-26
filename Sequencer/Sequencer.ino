#include "pitches.h"
int pushButton1 = 2;
int buttonState1 = 0;
int speakerPin = 8;
void setup() {
  tone(8, NOTE_G3, 100);
  Serial.begin(9600);
  pinMode(pushButton1, INPUT);
}

void loop() {
  int SR_delay = analogRead(A0);
  int SR_pitch  = analogRead(A3);
  int thisPitch = map(SR_pitch, 0, 1000, 120, 1500);
  buttonState1 = digitalRead(pushButton1);
  if(buttonState1 == 1){
   tone(speakerPin, thisPitch, 50); 
  }
  
  Serial.println(buttonState1);
  // Serial.println(SR_delay);
  // Serial.println(thisPitch);
  delay(SR_delay);      
  noTone(speakerPin);  
}
