// CONNECTION SETUP 
int i = 1;
int j = 1;
int pc;
int pl;
int rc;
int rl;
/*
  4x4x4 Cube 
  Columnas:
  [(x,y)-Pin]
 A:  (1,1)-22
     (1,2)-23
     (1,3)-24
     (1,4)-25
 B:  (2,1)-26
     (2,2)-27
     (2,3)-28
     (2,4)-29
  C:  (3,1)-30
      (3-2)-31
      (3-3)-32
      (3,4)-33
  D:  (4,1)-34
      (4,2)-35
      (4,3)-36
      (4,4)-37
  Capas:
  [layer-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/

int a=1;
int b=1;

//Variables asociadas a los dos LEDs que se van a controlar.

char valor;  //Variable para indicar que llega una orden

//initializing and declaring led rows
  int column[16]={22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
//initializing and declaring led layers
  int layer[4]={A10,A11,A12,A13};

  int time = 250;
 

// SETUP

void setup() {  
//BT
  //pinMode(led_1, OUTPUT); 
  Serial.begin(9600);
 
//APP
  //setting rows to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random pattern
 // randomSeed(analogRead(10));
  //  pc= 3;
    //pl= 3;
}

// LOOP
void loop() {
 /*if (Serial.available())  //Si el puerto serie (Bluetooth) está disponible
  {
    valor = Serial.read();  //Lee el dato entrante via Bluetooth

    if (valor == '1') 
    { 
    
    izq();
    }
    if (valor == '1') 
    { 
    
    derecha();
    }
  }*/
//digitalWrite(column[a], 0);         //Columns turn on with 0
//digitalWrite(layer[b],1 );          //Layers turn on with 1
//if 
//snake1();
//izq();
//derecha();
//adelante();
//atras();
//arriba();
//abajo();
//checarleds();
ciclo1();
}
void snake() {
  turnEverythingOff();
 comidita();

 

}
void turnEverythingOff(){
 
   for(int i = 0; i<16; i++)
   {
    digitalWrite(column[i], 1);
    // if(Serial.available()>0){
     //if(Serial.read()!= '1'){ goto Lazarus;}}
   
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 0);
     //if(Serial.available()>0){
     //if(Serial.read()!= '1'){ goto Lazarus;}}
   
   }
   //Lazarus:
 }
void comidita(){
  a=random(0,16);
b=random(0,4);
if (b==4){
  b=random(0,4);
}
if (a==16){
  a=random(0,16);
}
 
 

  return a,b;
  }
void snake1(){
  turnEverythingOff();
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl], 1);

  /*for(i=0;i>-4;i--){
    
digitalWrite(column[7+i],0);
digitalWrite(column[7+i+1],1);
  digitalWrite(layer[3], 1);
  delay(1000);
  
  }*/

  
}
void adelante(){
 rc=pc;
 rl=pl;
  turnEverythingOff();
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl], 1);

  for(i=0;i<4;i++){
    
digitalWrite(column[pc-i],0);
digitalWrite(column[pc-i+1],1);
  digitalWrite(layer[pl], 1);
  rc= pc-i ;
  rl= pl ;
//  Serial.print(rc,rl);
  delay(1000);
  
  }
 // Serial.println(rc,rl);
  return rc,rl ;
}
void izq(){
   pc=rc;
   pl=rl;
  turnEverythingOff();
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl],1);

  for(i=0;i<4;i++){
    
digitalWrite(column[pc+(4*i)],0);
digitalWrite(column[pc+(4*i)] - 4,1);
  digitalWrite(layer[pl], 1);
  rc=pc+(4*i);
  rl=pl;
 
  delay(1000);
  
  }
  return rc,rl ;
}
 void derecha(){
  pc=rc;
  pl=rl;
  turnEverythingOff();
  
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl],1);

  for(i=0;i<4;i++){
    
digitalWrite(column[pc-(4*i)],0);
digitalWrite(column[pc-(4*i)+ 4] ,1);
  digitalWrite(layer[pl], 1);
  rc=pc-(4*i);
  rl=pl;
  delay(1000);
  
  }
  return rc,rl ;
}
void atras(){
  turnEverythingOff();
  pc=rc;
  pl=rl;
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl],1);

  for(i=0;i<4;i++){
    
digitalWrite(column[pc+(i)],0);
digitalWrite(column[pc+(i)- 1] ,1);
  digitalWrite(layer[pl], 1);
   rc=pc+(i);
  rl=pl;
  delay(1000);

}
return rc,rl ;
}
void arriba(){
  turnEverythingOff();
  pc=rc;
  pl=rl;
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl],1);

  for(i=0;i<4;i++){
    
  digitalWrite(column[pc],0);
  digitalWrite(layer[pl+i], 1);
  rc=pc;
  rl=pl+i;
  delay(1000);
   turnEverythingOff();

}
return rc,rl ;
}
void abajo(){
  turnEverythingOff();
  pc=rc;
  pl=rl;
 digitalWrite(column[pc],0);
  digitalWrite(layer[pl],1);

  for(i=0;i<4;i++){
    
  digitalWrite(column[pc],0);
  digitalWrite(layer[pl-i], 1);
  rc=pc;
  rl=pl-i;
   //Serial.println(rc);
   //Serial.print("   ");
   // Serial.print(rl);
  delay(1000);
   turnEverythingOff();

}
return rc,rl ;
}
void checarleds(){
  turnEverythingOff();
for(j=0;j<4;j++){
  
for(i=0;i<16;i++){
  
digitalWrite(column[i], 0);         //Columns turn on with 0
digitalWrite(layer[j],1 );          //Layers turn on with 1

delay(700);

}
turnEverythingOff();
}
}
void ciclo1(){
  pc=2;
  pl=3;
  adelante();
  abajo();
   //izq();
   //arriba();
   //derecha();
   //atras();
 
// Serial.print(rc,rl);
  
  }

