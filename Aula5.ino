//incompleto - falta ajustar nas curvas


#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int tempo2 = 2000;
int S1 = 25;
int S2 = 27;
int S3 = 29;
int S4 = 31;
int S5 = 33;
bool start = false;

int S1_lido = 0;
int S2_lido = 0;
int S3_lido = 0;
int S4_lido = 0;
int S5_lido = 0;

void moverFrente();
void moverTras();   
void virar(int tempo);  
void parar(); 

void setup() {
  motor1.setSpeed(154); 
  motor2.setSpeed(154); 
  motor3.setSpeed(154); 
  motor4.setSpeed(154); 
  delay(1000);
}

void loop() {
  S1_lido = digitalRead(S1);
  S2_lido = digitalRead(S2);
  S3_lido = digitalRead(S3);
  S4_lido = digitalRead(S4);
  S5_lido = digitalRead(S5);

  if (S3_lido == LOW && S2_lido == LOW && S4_lido == LOW) {
    start = true;
    moverFrente();
  }
  
  if (S3_lido == LOW) {         
    moverFrente();        
  }

  if (S1_lido == LOW && S2_lido == LOW && S3_lido == LOW && S4_lido == LOW && S5_lido == LOW) {
    moverTras();
    delay(1000); 
    moverFrente(); 
  }

  if (S3_lido == LOW && S2_lido == LOW && S4_lido == LOW && start == true) {
    start = false;
    parar();
  }
}  

void moverFrente() {  
  motor1.setSpeed(120); 
  motor2.setSpeed(120); 
  motor3.setSpeed(120); 
  motor4.setSpeed(120); 
  
  motor1.run(FORWARD); 
  motor3.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor4.run(BACKWARD);
}

void moverTras() {  
  motor1.setSpeed(120); 
  motor2.setSpeed(120); 
  motor3.setSpeed(120); 
  motor4.setSpeed(120); 
  
  motor1.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor2.run(FORWARD); 
  motor4.run(FORWARD);
}

void virar(int tempo2) {
  motor1.setSpeed(130); 
  motor2.setSpeed(150); 
  motor3.setSpeed(150); 
  motor4.setSpeed(130); 
  
  motor1.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor4.run(FORWARD);
  delay(tempo2);
}

void parar() {
  motor1.run(RELEASE); 
  motor3.run(RELEASE); 
  motor2.run(RELEASE); 
  motor4.run(RELEASE);
  delay(500); 
}
