/*
Brazo robótico controlado por aplicacion Arduino bluetooth controller
Descripcion= Este codigo esta diseñado para un tipo de brazo robotico, el cual iene movimientos limitados. 
Este brazo no pude estirrse de forma diagonal. El movimiento permitido para su mecania es en movimiento de L
Fecha= 05/02/2020
Autor= Brigitte Oviedo
*/

#include <Servo.h> //Incluye Librería Servo
//Nombrando los servos a trabajar
Servo Base; 
Servo Horizontal; 
Servo Vertical; 
Servo Pinza; 

int ang1 = 90 ; // Empezamos en el origen Horizontal
int ang2 =10 ; // Empezamos en el origen Pinza
int ang3 =60 ; // Empezamos en el origen Vertical
int ang4 = 90 ; // Empezamos en el origen Base

char estado; //Caracter recibido por bluetooth

void setup()
{
  Serial.begin(9600);
  Base.attach(7); // Conectar servo1 al pin 7
  Horizontal.attach(8); // Conectar servo2 al pin 8
  Vertical.attach(9); // Conectar servo3 al pin 9
  Pinza.attach(10); // Conectar servo4 al pin 1
}

void loop () 
{
  if(Serial.available()){ //Si se detecta la conexion por bluetooth
      estado = Serial.read(); // Se lee el caracter mandado desde el Celular
      
    if(estado == 'd'){
      ang1 = ang1 + 10; // Aumenta 10 grados 
      Serial.print(ang1); // Se envia el valor al monitor serial
    }
    else if(estado == 'i'){
      ang1 = ang1 - 10; // Disminuye  10 grados 
      Serial.print(ang1); // Se envia el valor al monitor serial
    }
  
    ang1 = constrain(ang1,75,150); // Se limita los valores de los angulos de la Horizontal
  
    if(estado == 'a'){
      ang2 = ang2 + 10; // Aumenta 10 grados 
      Serial.print(ang2); // Se envia el valor al monitor serial
    }
    else if(estado == 'c'){
      ang2 = ang2 - 10; // Disminuye  10 grados 
      Serial.print(ang2); // Se envia el valor al monitor serial
    }
  
    ang2 = constrain(ang2,10,110); // Se limita los valores de los angulos de la pinza
    
    if(estado == 'u'){
      ang3= ang3 + 15; // Aumenta 15 grados 
      Serial.print(ang3); // Se envia el valor al monitor serial
    }
    else if(estado == 's'){
      ang3 = ang3 - 15; // Disminuye  15 grados
      Serial.print(ang3); // Se envia el valor al monitor serial
    }
  
    ang3 = constrain(ang3,50,140); // Se limita los valores de los angulos de la Vertical
  
    if(estado == 'h'){
      ang4= ang4 + 15; // Aumenta 15 grados 
      Serial.print(ang4); // Se envia el valor al monitor serial
    }
    else if(estado == 'g'){
      ang4 = ang4 - 15; // Disminuye  15 grados
      Serial.print(ang4); // Se envia el valor al monitor serial
    
    }
  
    ang4 = constrain(ang4,0,180); // Se limita los valores de los angulos de la base
  }

  Base.write(ang4); //Se ingresa el valor de "Angulo" en la Base
  Pinza.write(ang2); //Se ingresa el valor de "Angulo" en el pinza
  Vertical.write(ang3); //Se ingresa el valor de "Angulo" en Vertical
  Horizontal.write(ang1); //Se ingresa el valor de "Angulo" en Horizontal
  delay(100); // tiempo de espera 

}
