/*
Wall_E 
Descripcion= Falta implementar el diseño mecanico 
puede funcionar para un carrito con el sensor de ultrasonido
Fecha= 12/02/2020
Autor= Brigitte Oviedo
*/
int IN1 = 4;    // Input1 conectada al pin 4 de Arduino
int IN2 = 5;    // Input2 conectada al pin 5 de Arduino
int IN3 = 7;    // Input3 conectada al pin 7 de Arduino
int IN4 = 8;    // Input4 conectada al pin 8 de Arduino  
int ECHO = 3;  // ECHO al Arduino pin 3 de Arduino
int TRIG = 2;  // TRIG al Arduino pin 2 de Arduino
long duracion, distancia; 

void setup() {                
  Serial.begin (9600);       // inicializa el puerto serial
  pinMode (IN1, OUTPUT);     // Inicializa el pin 4  como salida digital.
  pinMode (IN2, OUTPUT);     // Inicializa el pin 5 como salida digital.
  
  pinMode (IN3, OUTPUT);     // Inicializa el pin 7 como salida digital.
  pinMode (IN4, OUTPUT);     // Inicializa el pin 8 como salida digital.

  pinMode (ECHO, INPUT);     // Inicializa el pin 11 como entrada (ECHO)
  pinMode (TRIG, OUTPUT);    // Inicializa el pin 12 como salida  (TRIGER)
  pinMode(13, OUTPUT);       // Inicializa el pin 13 como salida
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
    digitalWrite(IN1,HIGH);                
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH); 
    delay(2000);
                                
    // Codigo para girar
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW); 
    delay(1500);
    }

// Si la distancia se encuentra entre 10 y 500 el movil avanzara en linea recta

// Codigo para que el movil avance en linea recta
  else{
      Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
      Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW); 

      delay(400);
    }
     }
}
