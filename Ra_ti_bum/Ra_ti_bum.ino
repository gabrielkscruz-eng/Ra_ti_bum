#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int botao = 6, ldr1 = A0, ldr2 = A1, buzzer = 3, motor = 2;
int faixa1 = 800, faixa2 = 800, ldr1valor = 0, ldr2valor = 0;

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT);
  pinMode(buzzer, OUTPUT);
  
  servo1.attach(9);
  servo1.write(0);
  
  servo2.attach(10);
  servo2.write(0);
  
  servo3.attach(11);
  servo3.write(0);
}

void loop() {
  Serial.println(digitalRead(botao));
  
  if (digitalRead(botao) == 1) {
    musica();
    servo1.write(90);
    delay(1000);
    servo1.write(0);
    ldr();
  }
  
  Serial.println(analogRead(ldr1));
  Serial.println(analogRead(ldr2));
}

void ldr() {
  ldr1valor = analogRead(ldr1);
  if (faixa1 > ldr1valor) {
    servo2.write(90);
    delay(1000);
    
    ldr2valor = analogRead(ldr2);
    if (faixa2 > ldr2valor) {
      elevador();
      for (int i = 0; i <= 3; i++) {
        servo3.write(45);
        delay(1000);
        // servo3.write(//Música definido); <- Nota: Trecho incompleto no PDF
        delay(1000);
      }
      servo2.write(0);
    }
  }
}

void musica() {
  // tone(buzzer, 200);
  // Música a ser definido
}

void elevador() {
  digitalWrite(motor, 1);
  // delay(A ser definido); <- Nota: Valor não especificado no PDF
  digitalWrite(motor, 0);
}
