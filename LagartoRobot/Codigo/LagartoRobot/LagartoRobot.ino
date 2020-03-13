/*
Lagarto con sensor de ultrasonido
Fecha= 11/02/2020
ultima modificacion= 13/03/2020
Autor= Brigitte Oviedo
*/
#include <Servo.h> // Librería Servo

//Nombrando los servos a trabajar
Servo PatasDelanteras; 
Servo PatasTraseras; 
Servo Cabeza; 

int array_setup[] = {90,90,90};//Set the original angle of the servo
int angle1 = 25,angle2 = 35,angle3 = 55;
int delayedTime1 = 10;//The time needed for rotating 1 degree of the servo

int ECHO = 3;  // ECHO al Arduino pin 3 de Arduino
int TRIG = 2;  // TRIG al Arduino pin 2 de Arduino
long duracion,distancia;

void setup() {
  Serial.begin(9600);
  //Servos
  PatasDelanteras.attach(4);
  PatasTraseras.attach(5);
  Cabeza.attach(3);

  PatasTraseras.write(array_setup[0]);
  Cabeza.write(array_setup[1]);
  PatasDelanteras.write(array_setup[2]);
  delay(1000);

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
  if (distancia <= 15 && distancia >= 1) 
  {
  Serial.println("Alerta.....");      // Imprime la palabra Alerta en el monitor serial
          
 /* // Codigo para retroceder 
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cola.write(); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
   */                             
  // Codigo para girar
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cabeza.write(100); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cabeza.write(80); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cabeza.write(100); //Se ingresa el valor de "Angulo" en Cola
    delay(400);
    PatasDelanteras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    PatasTraseras.write(); //Se ingresa el valor de "Angulo" en PatasTraseras
    Cabeza.write(80); //Se ingresa el valor de "Angulo" en Cola
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

void waistOne()
{
  for(int i = 0;i < angle1;i++)
  {
    Cabeza.write(array_setup[1] + i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] + angle1;
}
  
void stepOne()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + angle2;
  array_setup[2] = array_setup[2] - angle2;
}

void backwardStepOne()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - angle2;
  array_setup[2] = array_setup[2] + angle2;
}
void waistTwo()
{
  for(int i = 0;i < 2*angle1;i++)
  {
    Cabeza.write(array_setup[1] - i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] - 2*angle1;
}

void stepTwo()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - 2*angle2;
  array_setup[2] = array_setup[2] + 2*angle2;
}

void backwardStepTwo()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + 2*angle2;
  array_setup[2] = array_setup[2] - 2*angle2;
}
void waistThree()
{
  for(int i = 0;i < 2*angle1;i++)
  {
    Cabeza.write(array_setup[1] + i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] + 2*angle1;
}


void stepThree()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + 2*angle2;
  array_setup[2] = array_setup[2] - 2*angle2;
}

void backwardStepThree()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - 2*angle2;
  array_setup[2] = array_setup[2] + 2*angle2;
}
void waistBack()
{
  for(int i = 0;i < angle1;i++)
  {
    Cabeza.write(array_setup[1] - i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] - angle1;
}

void stepBack()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - angle2;
  array_setup[2] = array_setup[2] + angle2;
}

void backwardStepBack()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + angle2;
  array_setup[2] = array_setup[2] - angle2;
}
void waistTurnleft()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(array_setup[1] + i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] + angle2;
}
  
void stepTurnleft()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + angle3;
  array_setup[2] = array_setup[2] + angle3;
}

void waistTurnleft2()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(array_setup[1] - i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] - angle2;
}

void stepTurnleft2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - angle3;
}
void turnLeftbacktwo()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[2] = array_setup[2] - angle3;
}

void waistTurnright()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(array_setup[1] - i);
    delay(delayedTime1);
  }
  array_setup[1] = array_setup[1] - angle2;
}
  
void stepTurnright()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(array_setup[0] - i);
    PatasDelanteras.write(array_setup[2] - i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] - angle3;
  array_setup[2] = array_setup[2] - angle3;
}

void waistTurnright2()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(array_setup[1] + i);
    delay(delayedTime1);
}
array_setup[1] = array_setup[1] + angle2;
}

void stepTurnright2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(array_setup[0] + i);
    delay(delayedTime1);
  }
  array_setup[0] = array_setup[0] + angle3;
}

void turnRightbacktwo()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasDelanteras.write(array_setup[2] + i);
    delay(delayedTime1);
  }
  array_setup[2] = array_setup[2] + angle3;
}


void keyTwo()
{
  waistOne();
  stepOne();
  waistTwo();
  stepTwo();
  waistThree();
  stepThree();
  waistBack();
  stepBack();
}

void keyADD() //atras izquierda
{
  waistOne();
  stepOne();
  for(int c = 0; c < 4; c++)
  {
    waistTwo();
    stepTwo();
    waistThree();
    stepThree();
  }
  waistBack();
  stepBack();
  delayedTime1 = 16;
}

void PosicionInicial()
{
  PatasTraseras.write(array_setup[0]);
  Cabeza.write(array_setup[1]);
  PatasDelanteras.write(array_setup[2]);
}

void keyFour() //derecha
{
   for(int a = 0;a < 2;a++)
   {
     waistTurnleft();
     stepTurnleft();
     waistTurnleft2();
     stepTurnleft2();
     turnLeftbacktwo();
   }
}

void keySix() //izquierda
{
  for(int a = 0;a < 2;a++)
  {
    waistTurnright();
    stepTurnright();
    waistTurnright2();
    stepTurnright2();
    turnRightbacktwo();
  }
}

void keyEight() //adelante
{
  waistOne();
  backwardStepOne();
  waistTwo();
  backwardStepTwo();
  waistThree();
  backwardStepThree();
  waistBack();
  backwardStepBack();
}
  
void keySUB() //adelante
{
  delayedTime1 = 8;
  waistOne();
  backwardStepOne();
  for(int c = 0; c < 3; c++)
  {
    waistTwo();
    backwardStepTwo();
    waistThree();
    backwardStepThree();
  }
  waistBack();
  backwardStepBack();
  delayedTime1 = 16;

}