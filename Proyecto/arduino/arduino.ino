const int EchoPin = 8;
const int TriggerPin = 9; 
const int pinLDR=A0;
const int SensorPIN = A1;//pin del termistor
const int pinIN4=11;
const int pinIN3=12;
const int pinIN1=10;
const int pinIN2=7;
#define led 13
#include <math.h> 
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
pinMode(led,OUTPUT);
while(!Serial) { ; }
pinMode(pinIN4,OUTPUT);
pinMode(pinIN3,OUTPUT);
pinMode(pinIN2,OUTPUT);
pinMode(pinIN1,OUTPUT);
}

void loop () {
 //*ULTRASONIDOS*//
  int cm = ping(TriggerPin, EchoPin);
 //*LDR*//
  int ilum=analogRead(pinLDR);
 //*TERMISTOR(temperatura)*//
  float raw = analogRead(SensorPIN);
  float V =  raw / 1024 * Vcc;
  float R = (Rc * V ) / (Vcc - V);
  float logR  = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR );
  float kelvin = R_th - V*V/(K * R)*1000;
  float celsius = kelvin - 273.15;
 ////**COMUNICACION**////
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
      else//Aquí empieza el control de los motores
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
   
}
//Aquí están las pruebas realizadas para cada sensor
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
 
   
////**LDR y LEDS**////
//int ilum=analogRead(pinLDR); //originalmente esta variable estaba aquí pero la he puesto arriba para que funcione la parte de comunicación
//Serial.println("Iluminacion:  ");//para ver en el programa de arduino los datos
//Serial.println(ilum);  
  delay(500);
  if(ilum<300){//para el led
    digitalWrite(led,HIGH);
  }
  else{
        digitalWrite(led,LOW);

  }
////**ULTRASON**////
//int cm = ping(TriggerPin, EchoPin); //originalmente esta variable estaba aquí pero la he puesto arriba para que funcione la parte de comunicación
//Serial.println("Distancia:  ");//para ver en el programa de arduino los datos
//Serial.println(cm);
delay(500);

}









////Función del ultrasonidos////
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
