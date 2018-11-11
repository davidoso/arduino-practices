// Created Oct. 26, 2017
// by Jesus Macedo, Cesar Mora
// Modified Nov. 20, 2017
// by David Osorio
//
// Stepper motor used:
// Unipolar PM Stepper Motor 35BY48
// Model 35BY48B06
// 6 wires, 4 windings
//
// Motor wire | Arduino Pin | Winding
// ----------------------------------
// Black            1           A
// Yellow           2           B
// Orange           3           C
// Blue             4           D
//
// Winding configuration:
//  (Winding)(Pin)
//      A1
//  B2      D4
//      C3
//
//
// Descripción de la práctica:
// La práctica se compone de 6 ejercicios de
// movimiento continuo del motor con 360, 90 y 30
// grados hacia la izquierda y hacia la derecha.
// El primer bloque de código enciende 2 bobinas
// y apaga 2 del rotor del motor para lograr una
// secuencia normal con sentido horario (hacia
// la derecha). En el segundo bloque, la secuencia
// se invierte para lograr un movimiento con sentido
// antihorario (hacia la izquierda)
// Ciclo por default: Movimiento continuo de 360 a la derecha
//
//
// Instrucciones para modificar el código:
// Para hacer rotar el motor con giros continuos
// de 360, 90 o 30 grados, seleccionar el ciclo for correspondiente
// y dejar comentados los otros 2 ciclos. Solo debe seleccionarse
// un ejercicio a la vez, es decir un solo un ciclo for. También se
// debe elegir y comentar 1 de los 2 ciclos loop para el sentido del giro
//
//
// Evidencia:
// https://www.youtube.com/watch?v=jUw1MRo8QaQ


void setup() {
 pinMode(1, OUTPUT);  // Negro
 pinMode(2, OUTPUT);  // Amarillo
 pinMode(3, OUTPUT);  // Naranja
 pinMode(4, OUTPUT);  // Azul
}


/****** GIROS HACIA LA DERECHA ******/
void loop() {
  
  // Dejar sólo este for sin comentar para
  // Giro completo de 360 grados
  for (int i=0; i<12; i++) {
    
  // Dejar sólo estos 2 for sin comentar para
  // Giro de 90 grados
  //for (int i=0; i<4; i++)
    //for (int j=0; j<3; j++) {
      
  // Dejar sólo estos 2 for sin comentar para
  // Giro de 30 grados
  //for (int i=0; i<12; i++)
    //for (int j=0; j<1; j++) {
      
      digitalWrite(2,LOW);
      digitalWrite(1,HIGH);
      digitalWrite(4,HIGH);
      delay(20);
      digitalWrite(1,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(20);
      digitalWrite(4,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      delay(20);
      digitalWrite(3,LOW);
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      delay(20);
      // Dejar como comentario para
      // Giro completo de 360 grados
      // Descomentar para 90 y 30 grados
      //}
      //delay(1000);
    }
}


/****** GIROS HACIA LA IZQUIERDA ******/
/*void loop() {
  
  // Dejar sólo este for sin comentar para
  // Giro completo de 360 grados
  for (int i=0; i<12; i++) {
    
  // Dejar sólo estos 2 for sin comentar para
  // Giro de 90 grados
  //for (int i=0; i<4; i++)
    //for (int j=0; j<3; j++) {
      
  // Dejar sólo estos 2 for sin comentar para
  // Giro de 30 grados
  //for (int i=0; i<12; i++)
    //for (int j=0; j<1; j++) {
      
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      delay(20);
      digitalWrite(3,LOW);
      digitalWrite(1,HIGH);
      digitalWrite(4,HIGH);
      delay(20);
      digitalWrite(4,LOW);
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      delay(20);
      digitalWrite(1,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      delay(20);
      // Dejar como comentario para
      // Giro completo de 360 grados
      // Descomentar para 90 y 30 grados
      //}
      //delay(1000);
    }
}*/
