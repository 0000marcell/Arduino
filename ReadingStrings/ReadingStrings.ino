// ReadingStrings.ino

void setup() {
	Serial.begin(9600);
}

void loop() {
	String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
  }

  if (content != "") {
    Serial.println(content);
  }
}

