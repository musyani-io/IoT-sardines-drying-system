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
bool buttonState = true, dryStatus = false, settingsMode = false, tempSelected = false, selectingMaxTemp = true;
long rawWeight, weight;
float hum, temp;
int highTemp = 45, lowTemp = 35;
String dhtStr, fanStr, htrStr, ldStr;
unsigned long currentMillis = 0, lastActionP1 = 0, lastActionP2 = 0, lastButtonPress = 0;
const unsigned long debounceDelay = 200;

// Function definition
void displayInLcd(int col, int row, String message);
void handleButtons();

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
  handleButtons();

  if (settingsMode)
  {
    displaySettings();
    return;
  }
  while (!dryStatus)
  {
    handleButtons();

    if (settingsMode)
    {
      break;
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
}

void displayInLcd(int col, int row, String message)
{
  lcd.setCursor(col, row);
  lcd.print(message);
}

void handleButtons()
{
  if (millis() - lastButtonPress < debounceDelay)
  {
    return;
  }

  if (digitalRead(SET_BTN) == LOW)
  {
    lastButtonPress = millis();
    settingsMode = !settingsMode;
    tempSelected = false; // Changed: reset selection when entering settings
    lcd.clear();
    if (!settingsMode)
    {
      displayInLcd(0, 0, "Settings saved!");
      delay(1000);
      lcd.clear();
    }
  }

  if (settingsMode)
  {
    // Changed: First check if no temperature is selected yet
    if (!tempSelected)
    {
      if (digitalRead(UP_BTN) == LOW)
      {
        lastButtonPress = millis();
        selectingMaxTemp = true;
        tempSelected = true;
      }
      if (digitalRead(DWN_BTN) == LOW)
      {
        lastButtonPress = millis();
        selectingMaxTemp = false;
        tempSelected = true;
      }
    }
    else
    {
      // Changed: Only adjust temperatures after selection is made
      if (digitalRead(UP_BTN) == LOW)
      {
        lastButtonPress = millis();
        if (selectingMaxTemp)
        {
          highTemp += 1.0;
          if (highTemp > 80.0)
            highTemp = 80.0;
        }
        else
        {
          lowTemp += 1.0;
          if (lowTemp >= highTemp)
            lowTemp = highTemp - 1.0;
        }
      }
      if (digitalRead(DWN_BTN) == LOW)
      {
        lastButtonPress = millis();
        if (selectingMaxTemp)
        {
          highTemp -= 1.0;
          if (highTemp <= lowTemp)
            highTemp = lowTemp + 1.0;
        }
        else
        {
          lowTemp -= 1.0;
          if (lowTemp < 10.0)
            lowTemp = 10.0;
        }
      }
    }
  }
}

void displaySettings()
{
  static unsigned long lastSettingsUpdate = 0;
  static bool showCursor = true;
  static unsigned long lastCursorBlink = 0;

  if (millis() - lastSettingsUpdate >= 500)
  {
    lastSettingsUpdate = millis();
    lcd.clear();

    String maxTempStr = "Max: " + String(highTemp, 1) + "C";
    String minTempStr = "Min: " + String(lowTemp, 1) + "C";
    displayInLcd(0, 0, maxTempStr);
    displayInLcd(0, 1, minTempStr);

    if (millis() - lastCursorBlink >= 250)
    {
      lastCursorBlink = millis();
      showCursor = !showCursor;
    }

    // Changed: Show different prompts based on selection state
    if (!tempSelected)
    {
      if (showCursor)
      {
        displayInLcd(0, 0, "UP=Max DN=Min");
        displayInLcd(0, 1, "Choose setting");
      }
    }
    else
    {
      if (showCursor)
      {
        if (selectingMaxTemp)
        {
          displayInLcd(15, 0, "<");
        }
        else
        {
          displayInLcd(15, 1, "<");
        }
      }
    }
  }
}