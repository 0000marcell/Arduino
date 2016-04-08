#include LiquidCrystal.h;
 
// Inicializa a biblioteca com os números dos pinos da interface
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Cria um LCD objeto com estes pinos
 
void setup() {
  lcd.begin(16, 2); // Seta o display 16 colunas por 2 linhas
}
 
void loop() {
	basicPrintDemo();
	displayOnOffDemo();
	setCursorDemo();
	scrollLeftDemo();
}
 
void basicPrintDemo() {
  lcd.clear(); // Limpa Display
  lcd.print("FILIPEFLOP"); // Escreve algum texto
  delay(2000);
}
 
void displayOnOffDemo() {
  lcd.clear();
  lcd.print("Display On/Off");
  for(int x=0; x &lt; 3; x++) { // Loop 3 vezes
    lcd.noDisplay(); // Desliga Display
    delay(1000);
    lcd.display(); // Liga Display
    delay(1000);
  }
}
 
void setCursorDemo() {
  lcd.clear();
  lcd.print("SetCursor Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5,0); // Cursor coluna 5 linha 0
  lcd.print("5,0");
  delay(2000);
  lcd.setCursor(10,1); // Cursor coluna 10 linha 1
  lcd.print("10,1");
  delay(2000);
  lcd.setCursor(3,1); // Cursor coluna 3 linha 1
  lcd.print("3,1");
  delay(2000);
}
 
void scrollLeftDemo() {
  lcd.clear();
  lcd.print("Scroll Left Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("FILIPE");
  lcd.setCursor(9,1);
  lcd.print("FLOP");
  delay(1000);
  for(int x=0; x&lt;16; x++) {
    lcd.scrollDisplayLeft(); // Scroll o Display para a esquerda 16 vezes
    delay(250);
  }
}