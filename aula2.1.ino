
#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int i = 0;
int tempo1 = 2000;  
int tempo2 = 1600;

void moverFrente(int tempo);  
void virarDireita(int tempo);  
void parar(); 

void setup() {
  motor1.setSpeed(164); 
  motor2.setSpeed(164); 
  motor3.setSpeed(164); 
  motor4.setSpeed(164); 
}

void loop() {
  delay(1000);
  for (i = 0; i < 4; i++) {
    moverFrente(tempo1);  
    parar();             
    virar(tempo2); 
    parar();             
  }
  while(true){}
}

void moverFrente(int tempo1) {  
  motor1.setSpeed(164); 
  motor2.setSpeed(164); 
  motor3.setSpeed(164); 
  motor4.setSpeed(164); 
  
  motor1.run(FORWARD); 
  motor3.run(FORWARD); 
  motor2.run(BACKWARD); 
  motor4.run(BACKWARD);
  delay(tempo1);
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
