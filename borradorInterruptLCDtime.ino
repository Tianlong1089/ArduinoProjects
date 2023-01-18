#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>

int analogPin = A0;
int entrada =0;

const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

volatile int hora1;
volatile int  minutos1;
volatile int segundo1;
volatile int mes1;
volatile int dia1;
volatile int ano1;
int hora;
int  minutos;
int segundo;
int mes;
int dia;
int ano;
char car;


void setup() {
 analogReference(INTERNAL);
lcd.begin(16, 2);
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(2,INPUT);

attachInterrupt(2,seteartime,FALLING);
}

void loop() {



 hora=hour();
 minutos=minute();
 segundo=second();
 dia=day();
 mes = month();
 ano = year();
 
 delay(1000);
  Serial.print(hora);
  Serial.print(";");
  Serial.print(minutos);
  Serial.print(";");
  Serial.print(segundo);
   Serial.print("   ");
  Serial.print(dia);
  Serial.print("/");
  Serial.print(mes);
   Serial.print("/");
  Serial.print(ano);
    Serial.println("  ");
  
   lcd.setCursor(2,0);
   lcd.print(hora);
   lcd.setCursor(6, 0);
   lcd.print(":");
   lcd.print(minutos);
   lcd.setCursor(10, 0);
   lcd.print(":");
    lcd.print(segundo);
    lcd.setCursor(2, 1);
   lcd.print(":");
    lcd.print(dia);
    lcd.setCursor(6, 1);
   lcd.print(":");
    lcd.print(mes);
    lcd.setCursor(8, 1);
   lcd.print(":");
    lcd.print(ano);
   
}


void seteartime(){
  noInterrupts();
  Serial.println("Set Mode on ");
  //state=!state;
  //while(Serial.available()>0){
    hora1=Serial.parseInt();
    
    minutos1=Serial.parseInt();
    
    segundo1=Serial.parseInt();
    
    dia1=Serial.parseInt();
    
    mes1=Serial.parseInt();
    
    ano1=Serial.parseInt();
    car =Serial.read()
    Serial.println(car);
    //if (car == "\n") break;
 // }
setTime(hora1,minutos1,segundo1,dia1,mes1,ano1);
Serial.println("Set Mode off ");
interrupts();
}

/* 



