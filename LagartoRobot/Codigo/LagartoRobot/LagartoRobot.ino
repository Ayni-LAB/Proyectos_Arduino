/*
Lagarto con sensor de ultrasonido
Descripcion= Todavia Falta prueba mecanica para implementar los angulos correctos
Fecha= 11/02/2020
Autor= Brigitte Oviedo
*/
#include <Servo.h> // Librería Servo

//Nombrando los servos a trabajar
Servo PatasDelanteras; 
Servo PatasTraseras; 
Servo Cola; 

int ECHO = 3;  // ECHO al Arduino pin 3 de Arduino
int TRIG = 2;  // TRIG al Arduino pin 2 de Arduino
long duracion,distancia;

void setup() {
  Serial.begin(9600);
  //Servos
  PatasDelanteras.attach();
  PatasTraseras.attach();
  Cola.attach();

  //Sensor de Ultrasonido
  pinMode (ECHO, INPUT);     // Inicializa el pin 11 como entrada (ECHO)
  pinMode (TRIG, OUTPUT);    // Inicializa el pin 12 como salida  (TRIGER)
  digitalWrite(TRIG, LOW);//Inicializamos el pin con 0  
}

void loop() {
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);   // genera el pulso de TRIGER por 10ms
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duracion = pulseIn(ECHO, HIGH);       //Lectura del sensor
  distancia = duracion / 59;            //Formula para calcular distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // Si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("Nada");                 // No mide nada
  }
  else {
    Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
    Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
    digitalWrite(13, 0);               // Pin 13 en bajo
    
// Si la distancia esta en el rango de 1 a 10 el movil retrocedera y girara    
  if (distancia <= 10 && distancia >= 1) 
  {
  Serial.println("Alerta.....");      // Imprime la palabra Alerta en el monitor serial
          
  // Codigo para retroceder 
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cola.write(); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
                                
  // Codigo para girar
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cola.write(); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
  }

// Si la distancia se encuentra entre 10 y 500 el movil avanzara en linea recta
// Codigo para que el movil avance en linea recta
  else{
      Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
      Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
      PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
      PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
      Cola.write(); //Se ingresa el valor de "Angulo" en Cola
      delay(400);
    }
     }

}
