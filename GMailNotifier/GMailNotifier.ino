int ledPin = 9;

void setup() {
  Serial.begin(9600); 
  //Set pin ledPin to be output pin (connect LED here)
  pinMode(ledPin, OUTPUT);
 
  //set pin ledPin to be high initially; LED is usually on, but, not blinking
  digitalWrite(ledPin, HIGH);
}
 
//this procedure is called if we need to blink the LED
void blink_led() {
 
  //we can't just blink it once, because that wouldn't be noticeable
  //so, we blink it three times
  for(int i = 0; i<10; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
 
  //reset the LED back to just on, not blinking
  digitalWrite(ledPin, HIGH);
}
 
//this function is called when we get a character
//over USB/Serial
void got_char(char x) {
 
  //if we get b over Serial
  if(x == 'b') {
    //... blink the LED
    blink_led();
  }
}
 
void loop() {
  //check if there's any data available on serial
  if(Serial.available() > 0) {
    //if there is, we read it
    byte byte_read = Serial.read();
 
    //and call "got_char"
    got_char((char)byte_read);
  }
}