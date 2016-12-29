#include <ESP8266WiFi.h>

const char *ssid = "ALLANIOT"; // Aqui você definirá o nome da rede WIFI que você irá criar, a qual você se comunicará através do Android por exemplo.
const char *password = "12345678"; // Aqui será a senha da sua rede WIFI

//AP configuration
IPAddress apIP(192, 168, 1, 1);  
IPAddress netMask(255, 255, 255, 0);

void setupAccessPoint() {  
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, netMask);
  WiFi.softAP(ssid, password);
  delay(100);
}
