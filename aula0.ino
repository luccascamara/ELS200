#include <AFMotor.h>
   tempo = millis()
  AF_DCMotor motor1(1); 
  AF_DCMotor motor2(2); 
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);
  
void setup() 
{
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
  motor3.setSpeed(255); 
  motor4.setSpeed(255); 
}

void loop() 
{
  // Frente
  if (tempo >=delay(1000)
  {
    motor1.run(BACKWARD); 
    motor2.run(FORWARD); 
    motor3.run(BACKWARD); 
    motor4.run(FORWARD);
  }
 

  delay(1000);
 

}
