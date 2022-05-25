const int EchoPin = 8;
const int TriggerPin = 9; 
//const int BuzzPin= 10;
const int pinLDR=A0;
const int SensorPIN = A1;
const int pinIN4=11;
const int pinIN3=12;
const int pinIN1=10;
const int pinIN2=7;
#define led 13
#include <Servo.h>
#include <math.h>
Servo servo;
int pos = 0; 
const int Rc = 10000; //valor de la resistencia
const int Vcc = 5;
float A = 1.11492089e-3;
float B = 2.372075385e-4;
float C = 6.954079529e-8;
float K = 2.5; //factor de disipacion en mW/C
int ping(int , int ) ;
 
void setup() {
servo.attach(11); 
Serial.begin(9600);
pinMode (TriggerPin, OUTPUT); 
pinMode (EchoPin, INPUT);
//pinMode (BuzzPin, OUTPUT);
pinMode(led,OUTPUT);
while(!Serial) { ; }
pinMode(pinIN4,OUTPUT);
pinMode(pinIN3,OUTPUT);
pinMode(pinIN2,OUTPUT);
pinMode(pinIN1,OUTPUT);
}

void loop () {
////**COMUNICACION**////
  int cm = ping(TriggerPin, EchoPin);
  int ilum=analogRead(pinLDR);
   float raw = analogRead(SensorPIN);
  float V =  raw / 1024 * Vcc;
  float R = (Rc * V ) / (Vcc - V);
  float logR  = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR );
  float kelvin = R_th - V*V/(K * R)*1000;
  float celsius = kelvin - 273.15;
if( Serial.available()> 0){
   String str = Serial.readStringUntil('\n');
    if (str.compareTo("GET_DISTANCIA")==0)
      str=cm;
    
    else
     if (str.compareTo("GET_ILUM")==0)
      str=ilum;
      else
      if(str.compareTo("GET_TEMPERATURA")==0)
      str=celsius;
      else
      if(str.compareTo("w")==0)
      {digitalWrite(pinIN4,HIGH);
      digitalWrite(pinIN3,LOW);
      digitalWrite(pinIN2,HIGH);
      digitalWrite(pinIN1,LOW);
      delay(200);
      
      }
      else
      if(str.compareTo("s")==0)
      { digitalWrite(pinIN4,LOW);
        digitalWrite(pinIN3,HIGH);
      digitalWrite(pinIN1,HIGH);
      digitalWrite(pinIN2,LOW);
      delay(200);}
      else
      if(str.compareTo("a")==0)
      {digitalWrite(pinIN4,HIGH);
      digitalWrite(pinIN3,LOW);
      digitalWrite(pinIN1,HIGH);
      digitalWrite(pinIN2,LOW);
      delay(200);}
      else
      if(str.compareTo("d")==0)
      {  digitalWrite(pinIN4,LOW);
        digitalWrite(pinIN3,HIGH);
      digitalWrite(pinIN2,HIGH);
      digitalWrite(pinIN1,LOW);
      delay(200);}
      else
      if(str.compareTo("e")==0)
      {digitalWrite(pinIN4,HIGH);
      digitalWrite(pinIN3,HIGH);
      digitalWrite(pinIN2,LOW);
      digitalWrite(pinIN1,LOW);}
      else
      str="COMANDO DESCONOCIDO";
 
 Serial.println(str);
   digitalWrite(pinIN3,HIGH); 
   digitalWrite(pinIN4,LOW);
}

  ////**TEMPERATURA**////
  /*float raw = analogRead(SensorPIN);
  float V =  raw / 1024 * Vcc;
  float R = (Rc * V ) / (Vcc - V);
  float logR  = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR );
  float kelvin = R_th - V*V/(K * R)*1000;
  float celsius = kelvin - 273.15;
  Serial.print("T = ");
  Serial.print(celsius);
  Serial.print("C\n");
  delay(2500);*/
  ////**SERVO**////
   for (pos = 0; pos <= 180; pos += 1) 
   {
      servo.write(pos);              
      delay(17);                       
   }
    for (pos = 0; pos <= 180; pos += 1) 
   {
      servo.write(pos);              
      delay(17);                       
   }
   
////**LDR y LEDS**////
//int ilum=analogRead(pinLDR); //originalmente esta variable estaba aquí pero la he puesto arriba para que funcione la parte de comunicación
//Serial.println("Iluminacion:  ");
//Serial.println(ilum);   /*Serial.println(ilum-350);*/
  delay(500);
  if(ilum<300){ /*if((ilum-350)<300)*/
    digitalWrite(led,HIGH);
  }
  else{
        digitalWrite(led,LOW);

  }
////**ULTRASON y BUZZ**////
//int cm = ping(TriggerPin, EchoPin); //originalmente esta variable estaba aquí pero la he puesto arriba para que funcione la parte de comunicación
//Serial.println("Distancia:  ");
//Serial.println(cm);
delay(500);
//if(cm>10){
  //digitalWrite(BuzzPin,HIGH);
//}
//else{
 // digitalWrite(BuzzPin,LOW);
//}

}









////Función del ultrason////
int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;

digitalWrite(TriggerPin, LOW); //para generar un pulse Larpio podemos a LON 405 
delayMicroseconds (4);
digitalWrite (TriggerPin, HIGH);//generamos Trigger (dispeta) de 1003
delayMicroseconds (10);
digitalWrite (TriggerPin, LOW);

duration = pulseIn (EchoPin, HIGH); //medimos el tiempo entre pulsos, en miezosegandos

distanceCm =duration * 10/292/2;

return distanceCm;
}