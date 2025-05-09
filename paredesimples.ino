#include <AFMotor.h>

// Define os motores
AF_DCMotor motor1(1); // esquerda
AF_DCMotor motor2(2); // esquerda
AF_DCMotor motor3(3); // direita
AF_DCMotor motor4(4); // direita

// Pinos do sensor ultrassônico
int trig = 41;
int echo = 43;
int d = 0;
int goal = 30;

void moverFrente();
void moverTras();   
void virarEsquerda();  
void virarDireita();
void parar(); 

void setup() {
  // Configura velocidade dos motores
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
  motor3.setSpeed(255); 
  motor4.setSpeed(255); 

  // Corrigido: trig é OUTPUT, echo é INPUT
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
  moverFrente();
  
}

void loop() {
  // Envia pulso para o sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Lê a duração do pulso de retorno
  long duracao = pulseIn(echo, HIGH);
  d = duracao * 0.034 / 2; // Calcula a distância em cm

  Serial.print("Distância: ");
  Serial.print(d);
  Serial.println(" cm");

  moverFrente();

  // Lógica de desvio
  if (goal < d) {
    motor1.setSpeed(100); 
    motor2.setSpeed(100); 
    motor3.setSpeed(0); 
    motor4.setSpeed(0); 
  } else {
    motor1.setSpeed(0); 
    motor2.setSpeed(0); 
    motor3.setSpeed(100); 
    motor4.setSpeed(100); 
  }

}

// Funções de movimento
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

void parar() {
  motor1.run(RELEASE); 
  motor3.run(RELEASE); 
  motor2.run(RELEASE); 
  motor4.run(RELEASE);
}
