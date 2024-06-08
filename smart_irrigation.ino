#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define MOISTURE_PIN 36 // Soil moisture sensor
#define DHTPIN 13       // DHT11 sensor
#define DHTTYPE DHT11   // DHT11 sensor type
#define RELAY_PIN 4     // Relay

const int dry = xxxx; 
const int wet = xxxx;

char auth[] = "blynk-auth-token";       // Blynk auth token
char ssid[] = "wifi"        // Wi-Fi SSID
char pass[] = "******";        // Wi-Fi password

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  dht.begin();

  Blynk.begin(auth, ssid, pass); // Connect to the Blynk server with authentication
  timer.setInterval(1500L, sendSensorData); // Set up a timer to send sensor data periodically

  // Connect to WiFi network
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi network...");
  }
}

void loop() {
   Blynk.run(); // Run the Blynk library loop to process incoming commands and maintain the connection
  timer.run(); // Run the BlynkTimer tasks
}

void sendSensorData() {
  int sensorValue = analogRead(MOISTURE_PIN); // Read the analog value from the soil moisture sensor
  int percentageHumidity = map(sensorValue, wet, dry, 100, 0); // Map the sensor value to percentage humidity

  float temp = dht.readTemperature(); // Read temperature in Celsius
  float hum = dht.readHumidity();     // Read relative humidity

  Serial.print("Soil Moisture: ");
  Serial.print(percentageHumidity);
  Serial.println("%");

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C\tHumidity: ");
  Serial.print(hum);
  Serial.println(" %");


// Control the relay based on soil moisture levels
  if (percentageHumidity < 20) {
    // Soil moisture is less than 20%, turn pump ON
    digitalWrite(RELAY_PIN, HIGH);
  } else if (percentageHumidity > 85) {
    // Soil moisture is more than 85%, turn pump OFF
    digitalWrite(RELAY_PIN, LOW);
  }

// Blynk

  if (Blynk.connected()) {
    // Send sensor data to Blynk app
    Blynk.virtualWrite(V3, percentageHumidity); // Send soil moisture level to virtual pin V3
    Blynk.virtualWrite(V0, temp);               // Send temperature to virtual pin V0
    Blynk.virtualWrite(V1, hum);                // Send humidity to virtual pin V1


    if (temp > 45) {
      Blynk.logEvent("temperature", "warning: High temperature detected! Please take appropriate measures to protect your crops.");
    }
    if (percentageHumidity > 85) {
      Blynk.logEvent("soilmoisture", "Alert : Soil moisture level is excessively high (>80%). Please adjust watering to prevent waterlogging and reduce the risk of root rot and fungal diseases.");
    }
    if (percentageHumidity < 20) {
      Blynk.logEvent("soilmoisture", "Alert : Soil moisture level is critically low (<20%). Please irrigate your plants immediately to prevent dehydration and ensure their health.");
    }
  }
}

BLYNK_WRITE(D4) {
  // Called whenever the Blynk app button is toggled
  int value = param.asInt();

  if (value == 1) {
    // Button is pressed, turn pump ON
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    // Button is released, turn pump OFF
    digitalWrite(RELAY_PIN, LOW);
  }
}
