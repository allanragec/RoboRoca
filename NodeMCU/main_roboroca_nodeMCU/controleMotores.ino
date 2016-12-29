int IN1_D0 = 16;
int IN2_D1 = 5;
int IN3_D2 = 4;
int IN4_D3 = 0;

char FRENTE = 'FRENTE';
char TRAS = 'TRAS';
char PARA = 'PARA';

char MOTOR_A = 'MOTOR_A';
char MOTOR_B = 'MOTOR_B';

int TIME_DEMO_MOTOR = 1000;

void setupMotores() {
  pinMode(IN1_D0, OUTPUT);
  pinMode(IN2_D1, OUTPUT);
  pinMode(IN3_D2, OUTPUT);
  pinMode(IN4_D3, OUTPUT);
}

void frente() {
  motor(MOTOR_A, FRENTE);
  motor(MOTOR_B, FRENTE);
  Serial.println("FRENTE");  
}

void tras() {
  motor(MOTOR_A, TRAS);
  motor(MOTOR_B, TRAS);
  Serial.println("TRAS");  
}

void para() {
  motor(MOTOR_A, PARA);
  motor(MOTOR_B, PARA);
  Serial.println("PARA"); 
}

void esquerda() {
  motor(MOTOR_A, TRAS);
  motor(MOTOR_B, FRENTE);
  Serial.println("ESQUERDA"); 
}

void direita() {
  motor(MOTOR_A, FRENTE);
  motor(MOTOR_B, TRAS);
  Serial.println("DIREITA"); 
}

void motor(char motor, char direcao) {
  int PINO1 = motor == MOTOR_A ? IN1_D0 : IN3_D2;
  int PINO2 = motor == MOTOR_A ? IN2_D1 : IN4_D3;
  
  if (direcao == FRENTE) {
    digitalWrite(PINO1, LOW);
    digitalWrite(PINO2, HIGH);
  }
  else if (direcao == TRAS) {
    digitalWrite(PINO1, HIGH);
    digitalWrite(PINO2, LOW);  
  }
  else if (direcao == PARA){
    digitalWrite(PINO1, LOW);
    digitalWrite(PINO2, LOW);
  }
}

void demoMotores() {
  frente();
  delay(TIME_DEMO_MOTOR);
  para();
  delay(TIME_DEMO_MOTOR);
  tras();
  delay(TIME_DEMO_MOTOR);
  para();
  delay(TIME_DEMO_MOTOR);
  esquerda();
  delay(TIME_DEMO_MOTOR);
  para();
  delay(TIME_DEMO_MOTOR);
  direita();
  delay(TIME_DEMO_MOTOR);
  para();
  delay(TIME_DEMO_MOTOR);
}

