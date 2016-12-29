#include <WiFiUdp.h>

WiFiUDP Udp;
int localPort = 9999;
char emptyBuffer[0];

void setupUDP() {
  // Começa a escutar informações na porta configurada
  Udp.begin(localPort);
}

String lerPacoteUDP() {
  // Verifica o tamnho do pacote disponível
  int packetSize = Udp.parsePacket();
  char packetBuffer[255];
  
  if (packetSize) {
    // Lê o pacote
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;
    Serial.print("Recebido(IP/Tamanho/Dado): ");
    Serial.print(Udp.remoteIP());Serial.print(" / ");
    Serial.print(packetSize);Serial.print(" / ");
    Serial.println(packetBuffer);

    Udp.beginPacket(Udp.remoteIP(),Udp.remotePort());
    // Informa que o dado foi recebido com sucesso
    Udp.write("dado recebido: ");
    Udp.write(packetBuffer);
    Udp.endPacket();

    // retorna o pacote
    return packetBuffer;
  }
  
    return emptyBuffer;
 }

