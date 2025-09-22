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
#define OK_BTN 18

// Object definition
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 scale;

// Variables
bool buttonState, lastButtonState = true, dryStatus = false;
long rawWeight;
float hum, temp, weight, currentWeight, initialWeight, finalWeight;
int highTemp = 45, lowTemp = 35;
String dhtStr, fanStr, htrStr, ldStr, whiteSpc = "                ";
unsigned long currentMillis = 0, lastActionP1 = 0, lastActionP2 = 0;
const unsigned long debounceDelay = 200;

// Function definition
void displayInLcd(int col, int row, String message);
bool checkButton(int pin);

void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);

  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(SET_BTN, INPUT_PULLUP);
  pinMode(OK_BTN, INPUT_PULLUP);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);

  // Serial.println("System booting...");
  displayInLcd(0, 0, "System Booting..");
  delay(1500);

  scale.begin(LD_DOUT, LD_SCK);
  scale.set_scale(420);
  // scale.tare();

  lcd.clear();
  // Serial.println(checkButton(OK_BTN));
  while (true)
  {
    displayInLcd(0, 0, "Insert Weight");
    initialWeight = scale.get_units();
    ldStr = "Weight: " + String(initialWeight, 1) + "kg";
    displayInLcd(0, 1, ldStr);

    if (checkButton(OK_BTN) && (initialWeight > 1.0)) // Minimum load is 1 kg
    {
      // Serial.println("Out!");
      dryStatus = true;
      break;
    }
  }

  finalWeight = 0.7 * initialWeight; // Assuming 30% of the load is water (for sardines)
  Serial.println("Final Weight is: " + String(finalWeight, 1) + "kg");
}

void loop()
{
  while (dryStatus)
  {
    currentMillis = millis();
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    currentWeight = scale.get_units(5);
    ldStr = "Weight: " + String(currentWeight, 1) + "kg";
    // rawWeight = scale.read();
    // Serial.println(currentWeight);

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
      // Serial.println(currentWeight);
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

    if (currentWeight <= finalWeight)
    {
      dryStatus = false;
      Serial.println("Product is dried!");
    }

    if (weight != currentWeight)
    {
      float percent = ((initialWeight - currentWeight) * 100) / (initialWeight);
      weight = currentWeight;
      Serial.println("Weight loss: " + String(percent, 1));
    }
  }
  displayInLcd(0, 0, "Weight: " + String(currentWeight, 1) + "kg ");
  displayInLcd(0, 1, "Drying complete!");
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}

bool checkButton(int pin)
{
  bool ans = false;
  buttonState = digitalRead(pin);
  if (buttonState != lastButtonState)
  {
    if (!buttonState)
    {
      ans = !buttonState;
    }
    lastButtonState = buttonState;
  }
  return ans;
}