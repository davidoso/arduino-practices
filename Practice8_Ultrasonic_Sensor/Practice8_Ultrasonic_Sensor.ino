/*
  Ultrasonic Sensor HC-SR04
  
Description:
  Los sensores de ultrasonido son muy útiles para medir distancias
  y detectar obstaculos. El funcionamiento es simple, envía una señal
  ultrasónica inaudible y nos entrega el tiempo que demoró en ir y venir
  hasta el obstáculo más cercano que detectó
  
Author:
  created November 16, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=Y7HmlsRMhoI
*/


const int pinTrigger = 10; // Pin digital 2 para el Trigger del sensor
const int pinEcho = 9;     // Pin digital 3 para el Echo del sensor


void setup() {
  Serial.begin(9600); // Iniciar la comunicación
  pinMode(pinTrigger, OUTPUT); // Pin como salida
  pinMode(pinEcho, INPUT); // Pin como entrada
  digitalWrite(pinTrigger, LOW); // Inicializar pin con 0
}

void loop() {
  long t; // Tiempo que demora en llegar el eco
  long d; // Distancia en cm
  
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10); // Enviar un pulso de 10us
  digitalWrite(pinTrigger, LOW);
  
  t = pulseIn(pinEcho, HIGH); // Obtener el ancho del pulso
  
  /*
   * Dado que la velocidad del sonido es de 343m/s o 29microseg/cm,
   * se debe dividir el tiempo entre 59, que es el tiempo
   * que tarda en recorrer ida y vuelta un cm la onda
   */
  d = t/59; // Escalar el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d); // Imprimir en el monitor serial el valor de la distancia
  Serial.print("cm");
  Serial.println();
  
  delay(100); // Pausa de 100ms
}
