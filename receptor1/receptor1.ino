#include <VirtualWire.h>

int IN3 = 4;    // Input3 conectada al pin 5              +
int IN4 = 3;    // Input4 conectada al pin 4              +Motor Derecho 
int ENB = 2;    // ENB conectada al pin 3 de Arduino      +
int IN1 = 6;    // Input3 conectada al pin 7              -
int IN2 = 7;    // Input3 conectada al pin 8              -Motor Izquierdo
int ENA = 5;    // ENA conectada al pin 6  de Arduino     -
int ibyte;
/*Adelante = W
  Alto = E
  Reversa = S
  Vuelta a la Izquierda = A
  Vuelta a la Derecha = D
*/  
void setup()
{
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  Serial.begin(9600); //Iniciamos el serial
}
void loop()
{
  uint8_t ibyte;
  uint8_t ibyteleng=1;
  
 if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    ibyte = Serial.read();
    if (ibyte == 'w')
       { adelante();
         Serial.println("ADELANTE");
         Serial.println(ibyte);}
    if (ibyte == 's')
       { reversa();
         Serial.println("REVERSA");}
    if (ibyte == 'a')
       { izquierda();
         Serial.println("IZQUIERDA");}
    if (ibyte == 'd')
       { derecha(); 
         Serial.println("DERECHA");}
    if (ibyte == 'e')
       { alto(); 
         Serial.println("ALTO");}
    }
  }

// FUNCIONES
void adelante(){
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  digitalWrite (ENB, HIGH);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (ENA, HIGH);
  }
void reversa(){
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  digitalWrite (ENB, HIGH);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENA, HIGH);
  }
void izquierda(){
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  digitalWrite (ENB, HIGH);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENA, HIGH);
  }
void derecha(){
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  digitalWrite (ENB, HIGH);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (ENA, HIGH);
  }
void alto(){
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, HIGH);
  digitalWrite (ENB, HIGH);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, HIGH);
  digitalWrite (ENA, HIGH);
  }
