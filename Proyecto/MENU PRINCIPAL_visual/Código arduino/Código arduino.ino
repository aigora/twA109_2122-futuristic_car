const int EchoPin = 8;
const int TriggerPin = 9; 
const int BuzzPin= 10;
const int pinLDR=A0;
#define led 13
#include <Servo.h>
Servo servo;
int pos = 0; 
 
void setup() {
servo.attach(11); 
Serial.begin(9600);
pinMode (TriggerPin, OUTPUT); 
pinMode (EchoPin, INPUT);
pinMode (BuzzPin, OUTPUT);
pinMode(led,OUTPUT);
while(!Serial) { ; }

}

void loop () {
////**COMUNICACION**////
  int cm = ping(TriggerPin, EchoPin);
  int ilum=analogRead(pinLDR);

if( Serial.available()> 0){
   String str = Serial.readStringUntil('\n');
    if (str.compareTo("GET_DISTANCIA")==0)
      str=cm;
    
    else
     if (str.compareTo("GET_ILUM")==0)
      str=ilum;
     else
      str="COMANDO DESCONOCIDO";
 
 Serial.println(str);
    
}

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
Serial.println("Iluminacion:  ");
Serial.println(ilum);   /*Serial.println(ilum-350);*/
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
if(cm>10){
  digitalWrite(BuzzPin,HIGH);
}
else{
  digitalWrite(BuzzPin,LOW);
}

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
