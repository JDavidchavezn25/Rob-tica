#include <VirtualWire.h>

int ibyte;

void setup()
{
  
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(2);//Iniciamos el serial
}
 
void loop()
{
 if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    ibyte = Serial.read();
    if (ibyte == 'w')
      // { adelante();
         Serial.println("ADELANTE");
         Serial.println(ibyte);//}
    if (ibyte == 's')
       //{ reversa();
         Serial.println("REVERSA");//}
    if (ibyte == 'a')
      // { izquierda();
         Serial.println("IZQUIERDA");//}
    if (ibyte == 'd')
       //{ derecha(); 
         Serial.println("DERECHA");//}
    if (ibyte == 'e')
      // { alto(); 
         Serial.println("ALTO");//}
         vw_send((uint8_t*)ibyte,sizeof(ibyte));
         vw_wait_tx();
    }
}
  
