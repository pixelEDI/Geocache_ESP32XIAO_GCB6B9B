/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

https://links.pixeledi.eu
Geocache | V1.0 | 07.2024

*/

#include <Arduino.h>

#include <ESPmDNS.h>
#include <WebServer.h>
#include <WiFi.h>

const char *ssid = "Geocache";
const char *password = "12345678";

WebServer server(80);

// Mobile-optimierte HTML-Seite
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GeoCache</title>
    <style>
        body { 
            font-family: Arial, sans-serif; 
            text-align: center; 
            margin: 0; 
            padding: 20px; 
            background-color: #f4f4f4;
        }
        .container {
            max-width: 400px; 
            margin: auto; 
            background: white; 
            padding: 20px; 
            border-radius: 10px; 
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
        }
        h1 { color: black; font-size: 24px; }
        .code { 
            color: #336699; 
            font-size: 24px; 
            font-weight: bold; 
            padding: 10px; 
            border-radius: 5px; 
            background: #e0e8f0;
            display: inline-block;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Verbindung hergestellt...</h1>
        
        <p class="code">Du bist auf der richtigen Frequenz. Jetzt liegt das Ziel zum Greifen nah.<br><br>

           Mit 0/7/3 erhälst du Zutritt zum Logbuch.
        </p>

    </div>
</body>
</html>
)rawliteral";

void handleRoot() {
  // server.send(200, "text/html",
  //             "<html><head><title>GeoCache</title></head><body><h1>Willkommen
  //             " "beim Geocache!</h1></body></html>");
  server.send(200, "text/html", htmlPage);
}

void setup() {
  WiFi.softAP(ssid); // Access Point starten

  // url.local
  if (!MDNS.begin("GCB6B9B")) {
    Serial.println("Fehler beim Starten von mDNS");
  } else {
    Serial.println("mDNS gestartet");
  }

  server.on("/", handleRoot);
  server.begin();
}

void loop() { server.handleClient(); }
