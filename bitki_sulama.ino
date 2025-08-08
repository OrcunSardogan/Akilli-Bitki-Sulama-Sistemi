#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int soilMoisturePin = A0;
const int relayPin = 8;
const int potentiometerPin = A1;

int thresholdValue = 0; //Nem miktarıyla karşılaştırılacak değerin belirlenmesi
int soilMoistureValue = 0;
int pumpDuration = 0;
boolean pumpStatus = false; 

void setup() {
  pinMode(relayPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Toprak Nem:");
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin); //Topraktan nem miktarı okunması
  thresholdValue = analogRead(potentiometerPin);

  lcd.setCursor(12, 0);
  lcd.print(soilMoistureValue); //LCD ekrana nem miktarının yazılması

  if (soilMoistureValue < thresholdValue) { //Okunan nem miktarının belirlenen değerle karşılaştırılması, küçükse pompa çalıştırılması
    if (!pumpStatus) { //Pompa çoktan çalışmıyorsa pompa çalışır
      pumpStatus = true;
      pumpDuration = 5000; // Su pompasının çalışma süresi
      digitalWrite(relayPin, HIGH);
    }
  } else {
    if (pumpStatus) { //Pompa çalışıyorsa durdurulur
      pumpStatus = false;
      digitalWrite(relayPin, LOW);
    }
  }

  lcd.setCursor(0, 1);
  lcd.print("Sulama: "); //Ekrana sulama durumu yazdırılır
  lcd.print(pumpStatus ? "Açik" : "Kapali");
  delay(1000); // Veri okumalarını belirli aralıklarla yapmak için
}
