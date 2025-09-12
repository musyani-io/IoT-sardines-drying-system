#include <Arduino.h>
#include <DHT.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>

// Pin definition
#define DHTPIN 4
#define DHTTYPE DHT22
#define LD_DOUT 26
#define LD_SCK 25

// Object definition
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 scale;

// Variables
long rawWeight, weight;
float hum, temp;
int highTemp = 45, lowTemp = 35;
String dhtStr, fanStr, htrStr, ldStr;
unsigned long currentMillis, lastActionP1 = 0, lastActionP2 = 0;

// Function definition
void displayInLcd(int col, int row, String message);

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);

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
  // rawWeight = scale.read();
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

  if (temp < lowTemp)
  {
    digitalWrite(14, HIGH);
    digitalWrite(13, LOW);
    fanStr = "FAN STATUS: OFF";
    htrStr = "HTR STATUS: ON";
  }
  else if (temp > highTemp)
  {
    digitalWrite(14, LOW);
    digitalWrite(13, HIGH);
    fanStr = "FAN STATUS: ON";
    htrStr = "HTR STATUS: OFF";
  }

  if (currentMillis - lastActionP1 >= 1000)
  {
    lastActionP1 = currentMillis;
    lcd.clear();
    displayInLcd(0, 0, dhtStr);
    displayInLcd(0, 1, ldStr);
    // Serial.println(rawWeight);
    // Serial.println(weight);
    Serial.println("After 1 second!");
  }

  if (currentMillis - lastActionP2 >= 2000)
  {
    lastActionP2 = currentMillis;
    lcd.clear();
    displayInLcd(0, 0, fanStr);
    displayInLcd(0, 1, htrStr);
    Serial.println("After 2 seconds!");
  }
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}