int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}
 
void got_char(char x) {
  if(x == 'l') {
    digitalWrite(ledPin, HIGH);  
  }else{
    digitalWrite(ledPin, LOW);
  }
}
 
void loop() {
  if(Serial.available() > 0) {
    byte byte_read = Serial.read();
    got_char((char)byte_read);
  }
}