#include <Ultrasonic.h>
#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4);

int tempo2 = 2000;
int trig = 43;
int echo = 45;
long d = 0;

Ultrasonic ultrasonic (trig,echo);

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
  moverTras();  
  d = ultrasonic.read();
  if (d <= 5) {         
    moverFrente();
    delay(500); 
    virar(tempo2); 
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
