#include <SimpleDHT.h>
#include <LiquidCrystal.h>

// Definizione pin
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2); // Inizializza LCD 16x2
  lcd.print("Inizializzo...");
  delay(2000);
  lcd.clear();
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = dht11.read(&temperature, &humidity, NULL);

  lcd.clear();
  if (err != SimpleDHTErrSuccess) {
    lcd.setCursor(0, 0);
    lcd.print("Errore lettura");
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print((int)temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print((int)humidity);
  lcd.print(" %");

  delay(2000); // Attendi prima di rileggere
}
