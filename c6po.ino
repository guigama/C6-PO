#include <Ultrasonic.h>
#include <Servo.h>

Servo servo;
 
#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo

Ultrasonic ultrasonic(12,13);

void setup(){
  
  Serial.begin(9600); //inicia a porta serial
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)

  servo.attach(3);

  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
}

void loop(){
  
int distancia = (ultrasonic.Ranging(CM));
Serial.print("Distancia em CM: ");
Serial.println(distancia);
delay(200); 


if(distancia >25){
  frente();
  servo.write(90);
  
  int distancia = (ultrasonic.Ranging(CM));
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(200);
}
else{
parar();
delay(200);

  servo.write(180);
  delay(1000);
  int distanciaDir = (ultrasonic.Ranging(CM));
  Serial.print("Direita: ");
  Serial.println(distanciaDir);
  delay(200);
  
   servo.write(10);
   delay(1000);
   int distanciaEsq = (ultrasonic.Ranging(CM));
   Serial.print("Esquerda: ");
   Serial.println(distanciaEsq);
   delay(200);
   servo.write(90);
   
   if (distanciaDir > distanciaEsq && distanciaDir >30){
        Serial.println("Vira para direita");
        direita();
        delay(400);
        parar();
   }
   
   else if (distanciaEsq > distanciaDir && distanciaEsq > 30){
     Serial.println("Vira para esquerda");
        esquerda();
        delay(400);
        parar();
   }
   
   else if (distanciaEsq < 30 && distanciaDir <30){
     Serial.println("Vira para trás");
    esquerda();
    delay(800);
    parar();
     
   }
     
   
}
}

void frente(){
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void tras(){
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void direita(){
  digitalWrite(6, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void esquerda(){
digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void parar(){
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
