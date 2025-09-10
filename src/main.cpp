#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String dhtStr;
float hum, temp;

void displayInLcd(int col, int row, String message);

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);

  Serial.println("System booting...");
  displayInLcd(0, 0, "System Booting..");
}

void loop()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(temp) || isnan(hum))
  {
    Serial.println("Status: Error, DHT connection!");
    dhtStr = "DHT Error!";
  }
  else
  {
    Serial.println("Status: DHT values read!");
    dhtStr = "T:" + String(temp, 1) + "C H:" + String(hum, 1) + "%";
  }
  displayInLcd(0, 0, dhtStr);
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}