#include <AFMotor.h>

// Definindo os motores
AF_DCMotor motor1(1);  // Motor esquerdo dianteiro
AF_DCMotor motor2(2);  // Motor direito dianteiro
AF_DCMotor motor3(3);  // Motor esquerdo traseiro
AF_DCMotor motor4(4);  // Motor direito traseiro

// Definindo os pinos dos sensores de linha
int S1 = 25;
int S2 = 27;
int S3 = 29;
int S4 = 31;
int S5 = 33;

// Variáveis para armazenar o estado dos sensores
int S1_lido = 0;
int S2_lido = 0;
int S3_lido = 0;
int S4_lido = 0;
int S5_lido = 0;

void moverFrente();
void moverTras();   
void virarEsquerda();  
void virarDireita();
void parar(); 

void setup() {
  motor1.setSpeed(100); 
  motor2.setSpeed(105); 
  motor3.setSpeed(105); 
  motor4.setSpeed(100); 
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void loop() {
  // Lê o estado de cada sensor
  S1_lido = digitalRead(S1);
  S2_lido = digitalRead(S2);
  S3_lido = digitalRead(S3);
  S4_lido = digitalRead(S4);
  S5_lido = digitalRead(S5);

  // Lógica de movimento baseada nos sensores

  if (S4_lido == HIGH || S2_lido == HIGH) {
    // Se o sensor central (S3) detectar a linha, move para frente
    moverFrente();
   
  } 
  if (S2_lido == LOW) {
    // Se o sensor S2 (esquerda) detectar a linha, virar para a direita
    virarDireita();
    
  } 
  if (S4_lido == LOW) {
    // Se o sensor S4 (direita) detectar a linha, virar para a esquerda
    virarEsquerda();
    
  }

}


void moverFrente() {  
  motor1.run(FORWARD); 
  motor3.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor4.run(BACKWARD);
}

void moverTras() {  
  motor1.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor2.run(FORWARD); 
  motor4.run(FORWARD);
}

void virarEsquerda() {
  motor1.run(BACKWARD); 
  motor3.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor4.run(FORWARD);
}

void virarDireita() {
  motor1.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor2.run(FORWARD); 
  motor4.run(BACKWARD);
}

// Função para parar o robô
void parar(){
  motor1.run(RELEASE); 
  motor3.run(RELEASE); 
  motor2.run(RELEASE); 
  motor4.run(RELEASE);
}

