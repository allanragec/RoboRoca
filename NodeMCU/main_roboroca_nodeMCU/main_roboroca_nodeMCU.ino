int TIME = 200;

void setup()
{
 // Configura porta Serial
 Serial.begin(115200);
 
 // Configura o WIFI para rodar no modo AP (onde qualquer dispositivo pode se conectar a ele diretamente)
 setupAccessPoint();

 // Configura UDP (Começa a escutar informações pelo protocolo UDP)
 setupUDP();
 
 // Configura os pinos da ponte H, para acionar os motores
 setupMotores();
}

void loop()
{
  // Vê se tem alguma mensagem nova via UDP
  String mensagem = lerPacoteUDP();

  // Valida se é alguma mensagem esperada, e aciona os motores a partir disso,
  // o delay faz esses motores rodarem por um curto tempo, enquanto acionados,
  // no final de cada comando, para os motores, para que possa ser executado o próximo comando
  if (mensagem == "frente") {
    frente();
    delay(TIME);
    para();
  }
  else if (mensagem == "tras") {
    tras();
    delay(TIME);
    para();
  }
  else if (mensagem == "esquerda") {
    esquerda();
    delay(TIME);
    para();
  }
  else if (mensagem == "direita") {
    direita();
    delay(TIME);
    para();
  }
}

