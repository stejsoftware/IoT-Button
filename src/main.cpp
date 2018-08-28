#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <Timer.h>

#define NEOPIXEL_PIN 14 // NeoPixels are connected to this pin
#define NUM_LEDS 1      // Number of NeoPixels

Adafruit_NeoPixel led(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

const char *ssid = "adafruit";
const char *password = "ffffffff";

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    led.begin();
    led.clear();
    led.setPixelColor(0, led.Color(255, 255, 255));
    led.setBrightness(0);
    led.show();
}

uint8_t b = 0;
int8_t step = 1;

void loop()
{
    led.setBrightness(b += step);
    led.show();

    if (b == 255)
    {
        step = -1;
    }

    if (b == 0)
    {
        step = 1;
    }

    delay(100);
}
