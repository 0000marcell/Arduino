#include "pitches.h"

int pushButton1 = 2;
int pushButton2 = 3;

int buttonState1;
int buttonState2;

int speakerPin = 8;

void setup() {
  tone(8, NOTE_G3, 100);
  Serial.begin(9600);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
}

void loop() {
  buttonState1 = digitalRead(pushButton1);
  buttonState2 = digitalRead(pushButton2);

  if(buttonState1 == 1){
   tone(speakerPin, NOTE_C4, 50); 
  }

  if(buttonState2 == 1){
    tone(speakerPin, NOTE_E4, 50);
  }

  Serial.println(buttonState1);
  Serial.println(buttonState2);
  delay(100);      
  noTone(speakerPin);  
}
