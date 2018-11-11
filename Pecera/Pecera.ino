// Creado Ene. 5, 2017
// por David Osorio, Williams Estrada, Paul Villicaña
// Modificado Ene. 12, 2017
// por Williams Estrada
//
//
// Pecera con calentador automático y alimentador accionado vía bluetooth
//
//

#include <LiquidCrystal_I2C.h>  // F Malpartida's NewliquidCrystal_1.3.4 library
#include <SoftwareSerial.h>
#include <Servo.h>
#include <Wire.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <TimeLib.h>

/*** Variables generales ***/
/*
 * Modificar esta sección según la conexión utilizada
 * y las condiciones deseadas de funcionamiento
 */
byte pinCalentador = 2;       // Pin digital para activar el relay del calentador
byte pinBomba = 3;            // Pin digital para activar el relay de la bomba de aire
byte pinTemp = 4;             // Pin digital para recibir señal de entrada de la sonda DS18B20
byte pinServo = 5;            // Pin digital para enviar señal a servo SG90
byte contadorTemp = 0;        // Contador del número de lecturas de la sonda DS18B20 (Inicializado en 0)
byte contadorLimit = 10;      // Número de lecturas para realizar el promedio de temperatura (Default 10)
float promTemp = 0;           // Sumador para obtener promedio de lecturas de temperatura (Inicializado en 0)
float tempCalentadorOn = 14.5;  // Temperatura mínima en grados requerida para activar el relay del calentador (Default 14.5)
float tempCalentadorOff = 22; // Una vez que el calentador esté activado, temperatura mínima en grados requerida para apagarlo (Default 22)
uint8_t edoBomba = LOW;       // Bandera para guardar el estado actual de la bomba y encenderla/apagarla según el toggle button de la app Bluetooth Controller
int delayTime = 1000;         // Tiempo default para delay en milisegundos (Default 1000)

/*** Variables para LCD ***/
// Macro I2C_ADDR establece la dirección del I2C, usualmente 0x27
#define I2C_ADDR    0x27

// Constructor para usar LCD 20x4 a partir de la dirección del I2C
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/*** Variables para sensor de temperatura DS18B20 para líquidos ***/
//#define ONE_WIRE_BUS 4
OneWire oneWire(pinTemp);
DallasTemperature sensorTemp(&oneWire);

/*** Variables para bluetooth ***/
SoftwareSerial bt(10,11);    // Pines RX y TX del Arduino conectados al módulo HC05

/*** Variables para servo SG90 ***/
Servo servo;
int angulo;
int anguloCerrado = 80;
int anguloAbierto = 20;
String comando;

/*** Variables para cronómetro en LCD ***/
/*
 * Variable tipo tiempo para almacenar el tiempo actual. Despliega el tiempo
 * transcurrido hasta que se activa el alimentador en formato HH:MM y se reinicia
 */
time_t t;



void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  
  pinMode(pinCalentador, OUTPUT);
  pinMode(pinBomba, OUTPUT);
  pinMode(pinTemp, INPUT);
  
  // Inicializar lcd y desplegar información estática
  lcd.begin (20,4);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Temp: ");
  lcd.setCursor(14,0);
  lcd.print("pH: ?");
  lcd.setCursor(3,1);
  lcd.print("Calentador: OFF");
  lcd.setCursor(27,0);
  lcd.print("Bomba: OFF");
  lcd.setCursor(21,1);
  // El tiempo HH:MM se despliega en los 4 espacios en blanco
  lcd.print("Ult. comida:  :  ");
  
  // Inicializar sonda DS18B20
  sensorTemp.begin();
  
  // Inicializar tiempo para cronómetro
  setTime(0);
  
  // Inicializar servo SG90
  servo.attach(pinServo);
  servo.write(anguloCerrado);
}


void loop() {
  // La función now() regresa el tiempo en determinado instante desde el tiempo especificado en setTime()
  t = now();
  
  // Desplegar tiempo transcurrido desde la última vez que se activó el alimentador
  if(hour(t) < 10)
    lcd.setCursor(34,1);
  else
    lcd.setCursor(33,1);
  lcd.print(hour(t));
  lcd.setCursor(36,1);
  lcd.print(minute(t));
  
  // Leer temperatura y sumarla para sacar un promedio cuando se alcance contadorLimit
  sensorTemp.requestTemperatures();
  float temp = sensorTemp.getTempCByIndex(0);
  promTemp+=temp;
  contadorTemp++;
  
  // Desplegar temperatura en monitor serial de Arduino y LCD
  Serial.print("Temp: ");
  Serial.print(temp, 2);
  Serial.println();
  lcd.setCursor(7,0);
  lcd.print(temp, 2);
  
  /*
   * Cuando se realizan n lecturas de temperatura (default 10), reiniciar el contador,
   * obtener el promedio de la temperatura y evaluar si se debe encender/apagar el calentador
   */
  if(contadorTemp == contadorLimit) {
    contadorTemp = 0;
    promTemp/=contadorLimit;
    if(promTemp < tempCalentadorOn) {
      digitalWrite(pinCalentador, HIGH);
      lcd.setCursor(15,1);
      lcd.print("ON");
      lcd.setCursor(17,1); // Limpiar última 'F' de mensaje OFF anterior
      lcd.print(" ");
    }
    else {
      if(promTemp < tempCalentadorOff)
        digitalWrite(pinCalentador, HIGH); // Mantener calentador encendido hasta alcanzar temperatura deseada
      else {
        digitalWrite(pinCalentador, LOW);
        lcd.setCursor(15,1);
        lcd.print("OFF");
      }
    }
  }
  
  /*
   * Interpretar strings recibidas vía bluetooth de la app Bluetooth Controller como
   * comandos para accionar el alimentador y la bomba
   */
  if(bt.available()) {
    comando = bt.readString();
    Serial.println(comando);
    
    if(comando == "feed1") {
      feed1();
      Serial.println("Alimento arrojado");
      setTime(0); // Reiniciar cronómetro
    }
    
    if(comando == "feed2") {
      feed2();
      Serial.println("Alimento arrojado");
      setTime(0); // Reiniciar cronómetro
    }
    
    if(comando == "bomba") {
      edoBomba = !edoBomba;
      bomba();
    }
  }
  
  delay(delayTime);
}


void feed1() {
  //for(int i = 0; i < 2; i++) {
    servo.write(anguloAbierto);
    delay(300);
    servo.write(anguloCerrado);
    delay(300);
  //}
}


void feed2() {
  for(int i = 0; i < 2; i++) {
    servo.write(anguloAbierto);
    delay(300);
    servo.write(anguloCerrado);
    delay(300);
  }
}


void bomba() {
  if(edoBomba == HIGH) {
    digitalWrite(pinBomba, HIGH);
    lcd.setCursor(34,0);
    lcd.print("ON");
    lcd.setCursor(36,0); // Limpiar última 'F' de mensaje OFF anterior
    lcd.print(" ");
  }
  else {
    digitalWrite(pinBomba, LOW);
    lcd.setCursor(34,0);
    lcd.print("OFF");
  }
}
