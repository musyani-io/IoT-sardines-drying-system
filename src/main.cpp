#include <Arduino.h>
#include <DHT.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LD_DOUT 26
#define LD_SCK 25

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 scale;

long rawWeight, weight;
float hum, temp;
String dhtStr, ldStr;
unsigned long currentMillis, lastActionP1;

void displayInLcd(int col, int row, String message);

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
  scale.begin(LD_DOUT, LD_SCK);
  scale.set_scale(420);
  // scale.tare();
  Serial.begin(115200);

  // Serial.println("System booting...");
  displayInLcd(0, 0, "System Booting..");
}

void loop()
{
  currentMillis = millis();
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  rawWeight = scale.read();
  weight = scale.get_units(5);
  // Serial.println(weight);
  ldStr = "Weight: " + String(weight) + "kg";

  if (isnan(temp) || isnan(hum))
  {
    // Serial.println("Status: Error, DHT connection!");
    dhtStr = "DHT Error!";
  }
  else
  {
    // Serial.println("Status: DHT values read!");
    dhtStr = "T:" + String(temp, 1) + "C H:" + String(hum, 1) + "%";
  }

  if (currentMillis - lastActionP1 >= 1000)
  {
    lastActionP1 = currentMillis;
    displayInLcd(0, 0, dhtStr);
    displayInLcd(0, 1, ldStr);
    // Serial.println(rawWeight);
  }
  // Serial.println(weight);
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}