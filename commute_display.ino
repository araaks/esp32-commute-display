#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Google Maps API key
const char* api_key = "YOUR_GOOGLE_MAPS_API_KEY";

// Start and end locations for your commute
const char* origin = "START_LOCATION"; // e.g., "123+Main+Street,City,State"
const char* destination = "DESTINATION_LOCATION"; // e.g., "456+Elm+Street,City,State"

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize OLED
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.display();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Fetch and display commute time
  fetchCommuteTime();
}

void loop() {
  // Refresh commute time every 10 minutes
  delay(600000);
  fetchCommuteTime();
}

void fetchCommuteTime() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://maps.googleapis.com/maps/api/directions/json?origin=" + String(origin) + "&destination=" + String(destination) + "&key=" + String(api_key);

    http.begin(url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);

      // Parse the JSON response to extract commute time
      int timeIndex = payload.indexOf("duration") + 34;
      int timeEndIndex = payload.indexOf("\"", timeIndex);
      String commuteTime = payload.substring(timeIndex, timeEndIndex);

      // Display commute time on OLED
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 10);
      display.print("Time: ");
      display.print(commuteTime);
      display.display();

    } else {
      Serial.println("Error on HTTP request");

      // Display error on OLED
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 10);
      display.print("Error ");
      display.print(httpCode);
      display.display();
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");

    // Display WiFi error on OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 10);
    display.print("WiFi Disconnected");
    display.display();
  }
}
