int numero=0;
void setup() {

  pinMode(13, OUTPUT);
}


void loop() {
  
 creciente();
}

 void creciente(){
  
 
   for (numero=0;numero<=2048;numero++) {
 digitalWrite(13, HIGH);   
  delayMicroseconds((numero));                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(2048-(numero)); 
   
   }
  
    for (numero=0;numero<=2048;numero++){
   digitalWrite(13, HIGH);
   delayMicroseconds(2048- (numero));
   digitalWrite(13, LOW);
   delayMicroseconds(numero);
  
   }
  
   
    }
