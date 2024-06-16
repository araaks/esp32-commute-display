# esp32-commute-display

# ESP32 Commute Time Display using Google Maps API

![Project Image](path_to_project_image)

## Overview

This project uses an ESP32 to fetch and display the morning commute time using the Google Maps API. The commute time is shown on a 0.91 inch 128x32 I2C SSD1306 OLED screen. The system handles errors such as API call failures and displays relevant error messages.

## Features

- Fetches real-time commute time from Google Maps API.
- Displays commute time on an OLED screen.
- Handles errors and displays error messages.
- Refreshes commute time every 10 minutes.

## Materials Needed

- ESP32 DEVKITV1
- 0.91 inch 128x32 I2C SSD1306 OLED screen
- Breadboard and jumper wires for testing
- Soldering Iron and 3D printer for final project

## Setup Instructions

### Step 1: Google Maps API Setup

1. **Create a Google Cloud Project**:
   - Go to the [Google Cloud Console](https://console.cloud.google.com/).
   - Create a new project.
   
2. **Enable the Google Maps APIs**:
   - In the Cloud Console, go to the `API & Services` section.
   - Enable the following APIs:
     - Maps JavaScript API
     - Directions API

3. **Get Your API Key**:
   - In the `Credentials` section, create an API key.
   - Restrict the API key to the Maps API for security.

### Step 2: Hardware Setup

1. Connect the OLED screen to the ESP32:
   - VCC to 3.3V
   - GND to GND
   - SDA to GPIO 21
   - SCL to GPIO 22

### Step 3: Software Setup

1. **Clone this repository**:
   ```sh
   git clone https://github.com/your_username/esp32-commute-time-display.git
   cd esp32-commute-time-display

### Step 4: Install the necessary libraries:

- WiFi.h
- HTTPClient.h
- Adafruit_SSD1306.h
- Adafruit_GFX.h

You can install these libraries via the Arduino IDE Library Manager.

### Step 5: Update the code:

1. Open main.ino file in the Arduino IDE.

Replace ```YOUR_SSID```, ```YOUR_PASSWORD```, ```YOUR_GOOGLE_MAPS_API_KEY```, ```START_LOCATION,``` and ```DESTINATION_LOCATION``` with your actual values.

### Step 6: Upload and Test

1. Connect your ESP32 to your computer via USB.
2. Select the correct board and port in the Arduino IDE.
3. Upload the code to the ESP32.
4. Monitor the Serial output for debugging information.


### Troubleshooting
- WiFi Connection Issues: Ensure your credentials are correct and that your ESP32 is within range of your router.
- API Call Failures: Check your API key and ensure that it is properly restricted and enabled.
- OLED Display Issues: Ensure the wiring is correct and that the OLED is properly initialized.

### Contributions

Feel free to submit pull requests or issues to improve the project. Contributions are welcome!

### License
This project is licensed under the MIT License - see the LICENSE file for details.
