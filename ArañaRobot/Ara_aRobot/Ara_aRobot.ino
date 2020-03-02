/*
Araña Robot controlada por aplicacion Arduino bluetooth controller
Importante = Calibrar todos los motores a 90 grados en la mecánica
Fecha= 10/02/2020
Autor= Brigitte Oviedo
*/
#include <Servo.h> //Incluye la librerias necesarias para el servo

//Nombrando los servos a trabajar
Servo   Mano1;
Servo   Base1;
Servo   Codo1;
Servo   Mano2;
Servo   Base2; 
Servo   Codo2; 
Servo   Mano3;
Servo   Base3;  
Servo   Codo3;
Servo   Mano4;
Servo   Base4;  
Servo   Codo4;

int tiempo = 200;
char estado;

void setup()
 {
   Serial.begin(9600);
  //Pines de los servos 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
   //Primera extremidad
    Mano1.attach(2);
    Base1.attach(3);  
    Codo1.attach(4); 

   //Segunda extremidad
    Mano2.attach(5);
    Base2.attach(6);  
    Codo2.attach(7); 

   //Tercera extremidad
    Mano3.attach(8);
    Base3.attach(9);  
    Codo3.attach(10);

   //Cuarta extremidad
   Mano4.attach(11);
   Base4.attach(12);  
   Codo4.attach(13);

   //Se estabiliza la araña
   condicion_inicial();
   delay(2000);
 }
 
void loop()
{
  if(Serial.available()>0){ // Lee el bluetooth y almacena en estado
      estado = Serial.read(); //Le lo mandado por el Celular

    if(estado=='f'){     //Camina hacia adelante   
      for (int i=0;i<2;i++){
      Adelante();
      }
      condicion_inicial();
    }
    if(estado=='t'){     //Camina hacia atras  
      for (int i=0;i<2;i++){
      Atras();
      }
      condicion_inicial();
    }
    if(estado=='d'){     //Gira hacia la derecha 
      for (int i=0;i<2;i++){
      Derecha();
      }
    }
    if(estado=='i'){     //Gira hacia la izquierda
    for (int i=0;i<2;i++){
      Izquierda();
      }
    }
    if(estado=='x'){     //Sube y baja 3 veces
      for (int i=0;i<=2;i++){
        subir_bajar();  
      }
    }
    if(estado=='o'){     //Sube y baja 3 veces
        condicion_inicial();  
    }

  }
}

//Secuencia para que suba y baje la araña
void subir_bajar()
{         
  condicion_inicial();
  delay(600);
  bajar();
  delay(600);
  condicion_inicial();
}

//Condicion inicial de los servos de la araña
void condicion_inicial() 
{
    Codo1.write(90);
    Mano1.write(90);
    Base1.write(90); 
  
    Codo2.write(90);
    Mano2.write(90);
    Base2.write(90);
 
    Codo3.write(90);
    Mano3.write(90);
    Base3.write(90);
   
    Codo4.write(90);
    Mano4.write(90);
    Base4.write(90);
}

//Funcion para que baje
void bajar()
{         
  Codo1.write(130);
  Mano1.write(130);
  Base1.write(90); 
  
  Codo2.write(50);
  Mano2.write(50);
  Base2.write(90);

  Codo3.write(130);
  Mano3.write(130);
  Base3.write(90);
  
  Codo4.write(50);
  Mano4.write(50);
  Base4.write(90);
}

//Funcion caminar hacia adelante
void Adelante()
{  
  BaseAdelante();
  MoverPata4f();
  MoverPata1f();

  MoverPata3f();
  MoverPata2f();
  BaseAdelante();
}

//Funcion caminar hacia atras
void Atras()
{
  BaseAdelante();
  MoverPata2();
  MoverPata3();

  MoverPata1();
  MoverPata4();
  BaseAdelante();
}

//Funcion girar hacia la derecha
void Derecha()
{    
  Codo3.write(120);
  Base3.write(130);
  delay(200);
  Codo3.write(90);
  Mano3.write(90);
  delay(tiempo); 

  Codo2.write(60);
  Base2.write(130);
  delay(200);
  Codo2.write(90);
  Mano2.write(90);
  delay(tiempo);

  Codo1.write(120);
  Base1.write(130);
  delay(200);
  Codo1.write(90);
  Mano1.write(90);
  delay(tiempo);
  
  Codo4.write(60);
  Base4.write(130);
  delay(200);
  Codo4.write(90);
  Mano4.write(90);
  delay(tiempo);
  
  Base3.write(90);
  Base2.write(90);
  Base1.write(90);
  Base4.write(90);
  delay(200); 
}

//Funcion girar hacia la derecha
void Izquierda()
{
  Codo4.write(60);
  Base4.write(50);
  delay(200);
  Codo4.write(90);
  Mano4.write(90);
  delay(tiempo); 

  Codo1.write(120);
  Base1.write(50);
  delay(200);
  Codo1.write(90);
  Mano1.write(90);
  delay(tiempo); 
      
  Codo2.write(60);
  Base2.write(50);
  delay(200);
  Codo2.write(90);
  Mano2.write(90);
  delay(tiempo);

  Codo3.write(120);
  Base3.write(50);
  delay(200);
  Codo3.write(90);
  Mano3.write(90);
  delay(tiempo);

  Base3.write(90);
  Base2.write(90);
  Base1.write(90);
  Base4.write(90);
  delay(200);
}

//////////////////////////////////////////////////
//Sub-Funciones para Caminar hacia adelante
//////////////////////////////////////////////////
void BaseAdelante()
{ 
  Base1.write(110); //70
  Base2.write(70);  //90
  Base3.write(90);  //90
  Base4.write(90); //120
  delay(tiempo);   
}

void MoverPata4f()
{
  Codo4.write(60);
  Base4.write(60);
  delay(200);
  Codo4.write(90);
  Mano4.write(90);
  
  delay(tiempo);   
}
void MoverPata1f()
{
  Codo1.write(120);
  Base1.write(50);
  delay(200);
  Codo1.write(90);
  Mano1.write(90);
  
  delay(tiempo);     
}
void MoverPata3f()
{
  Codo3.write(120);
  Base3.write(130);
  delay(200);
  Codo3.write(90);
  Mano3.write(90);

  delay(tiempo);  
}
void MoverPata2f()
{
  Codo2.write(60);
  Base2.write(120);
  delay(200);
  Codo2.write(90);
  Mano2.write(90);
  
  delay(tiempo);   
}

//////////////////////////////////
//Sub-Funciones para Caminar hacia atras
//////////////////////////////////
void BaseAtras(){
  Base3.write(50); //70
  Base4.write(130);  //90
  Base1.write(90);  //90
  Base2.write(90); //120
  delay(tiempo);      
}
void MoverPata2()
{
  Codo2.write(60);
  Base2.write(40);
  delay(200);
  Codo2.write(90);
  Mano2.write(90);
  delay(tiempo);   
}
void MoverPata3()
{
  Codo3.write(120);
  Base3.write(50);
  delay(200);
  Codo3.write(90);
  Mano3.write(90);
  delay(tiempo);   
}
void MoverPata1()
{
  Codo1.write(120);
  Base1.write(130);
  delay(200);
  Codo1.write(90);
  Mano1.write(90);
  delay(tiempo);   
}
void MoverPata4()
{
  Codo4.write(60);
  Base4.write(120);
  delay(200);
  Codo4.write(90);
  Mano4.write(90);
  delay(tiempo);   
}

