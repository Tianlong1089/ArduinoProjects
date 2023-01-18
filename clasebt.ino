#include <SoftwareSerial.h>
SoftwareSerialBT(10,11);
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
 while(!serial);
 while(!BT);
 Serial.print("Ambos dispositivos contectados");

}

void loop() {
  BT.print("AT");
  BT.print("AT+NAME");
  BT.print("LOCOTES");
 
  if(BT.available()){
  Serial.print(BT.read());
  }
  while(1);
  
}
