#include <Arduino.h>
#include <DHT.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>

// Pin definition
#define DHTPIN 4
#define DHTTYPE DHT22
#define LD_DOUT 26
#define LD_SCK 25
#define SET_BTN 16
#define UP_BTN 17
#define DWN_BTN 5
// #define OK_BTN

// Object definition
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 scale;

// Variables
bool buttonState, lastButtonState = true;
long rawWeight, weight;
float hum, temp;
int highTemp = 45, lowTemp = 35;
String dhtStr, fanStr, htrStr, ldStr;
unsigned long currentMillis = 0, lastActionP1 = 0, lastActionP2 = 0;
const unsigned long debounceDelay = 200;

// Function definition
void displayInLcd(int col, int row, String message);

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(SET_BTN, INPUT_PULLUP);
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
  buttonState = digitalRead(SET_BTN);
  if (buttonState != lastButtonState)
  {
    if (!buttonState)
    {
      Serial.println("Pressed!");
    }
    lastButtonState = buttonState;
  }

  currentMillis = millis();
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  weight = scale.get_units(5);
  ldStr = "Weight: " + String(weight) + "kg";
  // rawWeight = scale.read();
  // Serial.println(weight);

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
    // Serial.println("After 1 second!");
  }

  if (currentMillis - lastActionP2 >= 2000)
  {
    lastActionP2 = currentMillis;
    lcd.clear();
    displayInLcd(0, 0, fanStr);
    displayInLcd(0, 1, htrStr);
    // Serial.println("After 2 seconds!");
  }
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}