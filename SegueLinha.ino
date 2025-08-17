#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int S1 = 25;
int S2 = 27;
int S3 = 29;
int S4 = 31;
int S5 = 33;

int S1_lido = 0;
int S2_lido = 0;
int S3_lido = 0;
int S4_lido = 0;
int S5_lido = 0;

void moverFrente();
void moverTras();   
void virar();  
void parar(); 

void setup() {
  motor1.setSpeed(105); 
  motor2.setSpeed(105); 
  motor3.setSpeed(105); 
  motor4.setSpeed(105); 

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

void loop() {
  S1_lido = digitalRead(S1);
  S2_lido = digitalRead(S2);
  S3_lido = digitalRead(S3);
  S4_lido = digitalRead(S4);
  S5_lido = digitalRead(S5);


  if(S3_lido == LOW) {
    moverFrente();
  }

  else if(S1_lido == LOW || S2_lido == LOW || S4_lido == LOW || S5_lido == LOW) {
    virar();
  }

  else {
    parar(); 
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

void virar() {
  motor1.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor4.run(FORWARD);
}

void parar(){
  motor1.run(RELEASE); 
  motor3.run(RELEASE); 
  motor2.run(RELEASE); 
  motor4.run(RELEASE);
}
