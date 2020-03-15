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

int confAng[] = {90,90,90};//Angulo original del servo
int angle1 = 25,angle2 = 35,angle3 = 55;
int time1 = 10; //El tiempo necesario para rotar 1 grado del servo

int ECHO = 3;  // ECHO al pin 3 de Arduino
int TRIG = 2;  // TRIG al pin 2 de Arduino
long duracion,distancia;

void setup() {
  Serial.begin(9600);
  //Servos
  Cabeza.attach(3);
  PatasDelanteras.attach(4);
  PatasTraseras.attach(5);

  //Posicion inicial
  PatasTraseras.write(confAng[0]);
  Cabeza.write(confAng[1]);
  PatasDelanteras.write(confAng[2]);
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
    
// Si la distancia esta en el rango de 1 a 15 el movil retrocedera y girara    
  if (distancia <= 15 && distancia >= 1) 
  {
  Serial.println("Alerta.....");      // Imprime la palabra Alerta en el monitor serial
         //Atras y girara 

  }

// Si la distancia se encuentra entre 10 y 500 el movil avanzara en linea recta
// Codigo para que el movil avance en linea recta
  else{
      Serial.print(distancia);           // Imprime el valor de la distancia en el monitor serial
      Serial.println("cm");              // Imprime al lado de la distancia los centimetros "cm"
      //avanzara
    }
     }

}

void Cintura()
{
  for(int i = 0;i < angle1;i++)
  {
    Cabeza.write(confAng[1] + i);
    delay(time1);
  }
  confAng[1] = confAng[1] + angle1;
}
  
void Paso1()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] + angle2;
  confAng[2] = confAng[2] - angle2;
}

void P1HaciaAtras()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] - angle2;
  confAng[2] = confAng[2] + angle2;
}
void Cintura2()
{
  for(int i = 0;i < 2*angle1;i++)
  {
    Cabeza.write(confAng[1] - i);
    delay(time1);
  }
  confAng[1] = confAng[1] - 2*angle1;
}

void Paso2()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] - 2*angle2;
  confAng[2] = confAng[2] + 2*angle2;
}

void P2HaciaAtras()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] + 2*angle2;
  confAng[2] = confAng[2] - 2*angle2;
}
void cintura3()
{
  for(int i = 0;i < 2*angle1;i++)
  {
    Cabeza.write(confAng[1] + i);
    delay(time1);
  }
  confAng[1] = confAng[1] + 2*angle1;
}


void Paso3()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] + 2*angle2;
  confAng[2] = confAng[2] - 2*angle2;
}

void P3HaciaAtras()
{
  for(int i = 0;i < 2*angle2;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] - 2*angle2;
  confAng[2] = confAng[2] + 2*angle2;
}
void CinturaAtras()
{
  for(int i = 0;i < angle1;i++)
  {
    Cabeza.write(confAng[1] - i);
    delay(time1);
  }
  confAng[1] = confAng[1] - angle1;
}

void PasoAtras()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] - angle2;
  confAng[2] = confAng[2] + angle2;
}

void PAHaciaAtras()
{
  for(int i = 0;i < angle2;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] + angle2;
  confAng[2] = confAng[2] - angle2;
}
void CinturaIzq()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(confAng[1] + i);
    delay(time1);
  }
  confAng[1] = confAng[1] + angle2;
}
  
void PasoIzq()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] + angle3;
  confAng[2] = confAng[2] + angle3;
}

void CinturaIzq2()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(confAng[1] - i);
    delay(time1);
  }
  confAng[1] = confAng[1] - angle2;
}

void PasoIzq2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] - angle3;
}
void AtrasIzq2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[2] = confAng[2] - angle3;
}

void CinturaDer()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(confAng[1] - i);
    delay(time1);
  }
  confAng[1] = confAng[1] - angle2;
}
  
void PasoDer()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(confAng[0] - i);
    PatasDelanteras.write(confAng[2] - i);
    delay(time1);
  }
  confAng[0] = confAng[0] - angle3;
  confAng[2] = confAng[2] - angle3;
}

void CinturaDer2()
{
  for(int i = 0;i < angle2;i++)
  {
    Cabeza.write(confAng[1] + i);
    delay(time1);
}
confAng[1] = confAng[1] + angle2;
}

void PasoDer2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasTraseras.write(confAng[0] + i);
    delay(time1);
  }
  confAng[0] = confAng[0] + angle3;
}

void AtrasDer2()
{
  for(int i = 0;i < angle3;i++)
  {
    PatasDelanteras.write(confAng[2] + i);
    delay(time1);
  }
  confAng[2] = confAng[2] + angle3;
}

void keyTwo()
{
  Cintura();
  Paso1();
  Cintura2();
  Paso2();
  cintura3();
  Paso3();
  CinturaAtras();
  PasoAtras();
}

void keyADD() //atras izquierda
{
  Cintura();
  Paso1();
  for(int c = 0; c < 4; c++)
  {
    Cintura2();
    Paso2();
    cintura3();
    Paso3();
  }
  CinturaAtras();
  PasoAtras();
  time1 = 16;
}

void PosicionInicial()
{
  PatasTraseras.write(confAng[0]);
  Cabeza.write(confAng[1]);
  PatasDelanteras.write(confAng[2]);
}

void keyFour() //derecha
{
   for(int a = 0;a < 2;a++)
   {
     CinturaIzq();
     PasoIzq();
     CinturaIzq2();
     PasoIzq2();
     AtrasIzq2();
   }
}

void keySix() //izquierda
{
  for(int a = 0;a < 2;a++)
  {
    CinturaDer();
    PasoDer();
    CinturaDer2();
    PasoDer2();
    AtrasDer2();
  }
}

void keyEight() //adelante
{
  Cintura();
  P1HaciaAtras();
  Cintura2();
  P2HaciaAtras();
  cintura3();
  P3HaciaAtras();
  CinturaAtras();
  PAHaciaAtras();
}
  
void keySUB() //adelante
{
  time1 = 8;
  Cintura();
  P1HaciaAtras();
  for(int c = 0; c < 3; c++)
  {
    Cintura2();
    P2HaciaAtras();
    cintura3();
    P3HaciaAtras();
  }
  CinturaAtras();
  PAHaciaAtras();
  time1 = 16;
}