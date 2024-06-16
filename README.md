# esp32-commute-display

ESP32 Commute Time Display using Google Maps API

Overview
This project uses an ESP32 to fetch and display the morning commute time using the Google Maps API. The commute time is shown on a 0.91 inch 128x32 I2C SSD1306 OLED screen. The system handles errors such as API call failures and displays relevant error messages.

Features
Fetches real-time commute time from Google Maps API.
Displays commute time on an OLED screen.
Handles errors and displays error messages.
Refreshes commute time every 10 minutes.
Materials Needed
ESP32 DEVKITV1
0.91 inch 128x32 I2C SSD1306 OLED screen
Breadboard and jumper wires
USB cable for programming the ESP32
Setup Instructions
Step 1: Google Maps API Setup
Create a Google Cloud Project:

Go to the Google Cloud Console.
Create a new project.
Enable the Google Maps APIs:

In the Cloud Console, go to the API & Services section.
Enable the following APIs:
Maps JavaScript API
Directions API
Get Your API Key:

In the Credentials section, create an API key.
Restrict the API key to the Maps API for security.
Step 2: Hardware Setup
Connect the OLED screen to the ESP32:
VCC to 3.3V
GND to GND
SDA to GPIO 21
SCL to GPIO 22
Step 3: Software Setup
Clone this repository:

sh
Copy code
git clone https://github.com/your_username/esp32-commute-time-display.git
cd esp32-commute-time-display
Install the necessary libraries:

WiFi.h
HTTPClient.h
Adafruit_SSD1306.h
Adafruit_GFX.h
You can install these libraries via the Arduino IDE Library Manager.

Update the code:

Open main.ino file in the Arduino IDE.
Replace YOUR_SSID, YOUR_PASSWORD, YOUR_GOOGLE_MAPS_API_KEY, START_LOCATION, and DESTINATION_LOCATION with your actual values.
Step 4: Upload and Test
Connect your ESP32 to your computer via USB.
Select the correct board and port in the Arduino IDE.
Upload the code to the ESP32.
Monitor the Serial output for debugging information.
