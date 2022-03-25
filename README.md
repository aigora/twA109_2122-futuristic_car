# Futuristic_car

El proyecto consiste en un coche que se maneja a distancia desde un móvil /ordenador a distancia usando bluetooth como enlace. El coche está dotado de sensor que detecta objetos cerca , te informa de la velocidad a la que va y además enciende las luces cuando no haya luz. El coche independientemente del bluetooth también es capaz de seguir una línea.


## Integrantes del equipo

<br />Julia Magallares Verde        Usuario: juliamagallares
<br />Beatrice Mangiameli           Usuario: bitrix2003
<br />David Oeo Muñoz               Usuario: DavidOM23

## Objetivos del trabajo

- Utilizar herramientas de programación como visual studio y arduino para aprender a utilizar sensores de luz y proximidad para 

## Explicación de sensores

#### Sensor de Ultra sonidos:
 La función principal del sensor de ultrasonidos en el proyecto será la de detectar objetos y paredes a cierta proximidad de la parte trasera del vehículo, haciendo que se vayan recogiendo datos de distancia y llegada a una marca establecida en el programa este mande la orden de parar para evitar que colisionen. 
Esto se llevará a cabo gracias a que con el funcionamiento del sensor este irá emitiendo una señal sonora de entre 2 y 400 cm que al rebotar con el objeto o pared en cuestión será reflejada y captada por el mismo, calculando el tiempo de ida y vuelta para devolver una distancia. Sabiendo que aproximadamente la velocidad de la señal sonora es de 343m/s.

Puesto que el sonido en ciertos casos se disipa y no tiende a funcionar tan bien el sensor no llega a ser tan preciso, es por esto que su funcionalidad estará basada en los sistemas de alarma de aparcado de los coches, tomando varias veces medidas que darán un aviso importante cuando estas sean ya muy pequeñas.
Código de ejemplo:

<br />const int EchoPin = 5;
<br />const int TriggerPin = 6:
<br />const int LedPin - 13;
<br />void setup() {
<br />Serial.begin (9600);
<br />pinMode(LedPin, OUTPUT); pinMode (TriggerPin, OUTPUT); pinMode (EchoPin, INPUT);
<br />void loop() {
<br />int cm ping (TriggerPin, Echo Pin); Serial.print ("Distancia: "); Serial.println (cm): delay(1000);
<br />int ping(int TriggerPin, int EchoPin) (
<br />long duration, distanceCm;
<br />digitalWrite(Trigger Pin, LOW); //para generar un pulao limpio ponemos a LOW dus
<br />delayMicroseconds (4);
<br />digitalWrite(TriggerPin, HIGH); //generamos Trigger (disparo) de 10us
<br />delayMicroseconds (10); digitalWrite(TriggerPin, LOW);
<br />duration pulseln (EchoPin, HIGH): //medimos el tiempo entre pulsca, en microsegundos
<br />distanceC duration 10/292/ 2: //convertimos a distancia, en ca
<br />return distanceCm;



#### Servomotor
Un servomotor, es un actuador rotativo o motor que permite un control preciso en términos de posición angular, aceleración y velocidad, capacidades que un motor normal no tiene. Al contrario que los motores normales, el servo no da vueltas completas, sino que tiene un rango de rotación (o movimiento) de 0º a 180º. El servo tiene en su interior un motor de corriente continua y también suelen tener un potenciómetro unido al eje del servo que permite a este conocer la posición del eje.

En nuestro proyecto vamos a utilizar un servomotor para abrir y cerrar la puerta de nuestro vehículo. Su posición inicial será de 90º cuando esté cerrado y se moverá a 180º cuando esté abierto. La posición que queremos encontrar en nuestro coche cuando este esté abierto es que la puerta se encuentre por encima del coche, consiguiendo así un coche con aspecto más futurista.

En nuestro caso utilizaremos un Micro Servo 9g SG90.

Su código será:

// Incluímos la librería para poder controlar el servo
<br />#include <Servo.h>
 
// Declaramos la variable para controlar el servo
<br />Servo servoMotor;
 
<br />void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
 <br />Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  <br />servoMotor.attach(9);
}
 
void loop() {
  
  // Desplazamos a la posición 0º
  <br />servoMotor.write(0);
  // Esperamos 1 segundo
  <br />delay(1000);
  
  // Desplazamos a la posición 90º
  <br />servoMotor.write(90);
  // Esperamos 1 segundo
  <br />delay(1000);
  
  // Desplazamos a la posición 180º
  <br />servoMotor.write(180);
  // Esperamos 1 segundo
  <br />delay(1000);

#### Fotorresistor

Los fotorresistores es un componente electrónico cuya resistencia se modifica, funciona según el principio de la fotoconductividad. La fotoconductividad es un fenómeno óptico en el que la conductividad del material aumenta cuando el material absorbe la luz. 
Porque es capaz de cambiar su conductividad puede detectar la luz que hay a su alrededor y obtener la intensidad de esta.  
Por lo tanto podemos utilizar este sensor para detectar la luz que hay alrededor de nuestro motor para así dar una intensidad menor o mayor al led que utilizaremos para contrarrestar la luz que falte. 

El código para el fotorresistor será:
//Creamos una variable de tipo entero
<br />int lectura = 0;

void setup() {
  //Iniciamos la comunicación serial
<br />  Serial.begin(9600);
}

void loop() {
  //Tomamos la lectura analógica del pin al cual conectamos
  //la señal de nuestro pequeño circuito divisor de tension
  //y la guardamos en una variable
<br />  lectura = analogRead(0);

  //Imprimimos por monitor serie el valor 
<br />  Serial.println(lectura);
<br />  delay(500);
}

#### LEDs

Una luz LED es un diodo, es decir, que trasvasa electrones entre dos materiales semiconductores (pareja positivo-negativo), produciendo así un voltaje entre la pareja, dando un flujo de partículas desde cada uno de los semiconductores al otro. Así es como el LED produce la luz.
En nuestro proyecto vamos a utilizar los LEDs para iluminar por donde pasará el coche y también, si hay falta de luz (esta falta la indicará el fotoresistor), podría incrementar su intensidad de luz haciendo así más visible el camino.
El código que utilizaremos será:

const int ledPIN = 9;
 
void setup() {
<br />  Serial.begin(9600);    //iniciar puerto serie
<br />  pinMode(ledPIN , OUTPUT);  //definir pin como salida
}
 
void loop(){
<br />  digitalWrite(ledPIN , HIGH);   <br />// poner el Pin en HIGH
<br />  delay(1000);                   <br />// esperar un segundo
<br />  digitalWrite(ledPIN , LOW);    <br />// poner el Pin en LOW
<br />  delay(1000);                   <br />// esperar un segundo
}

#### Sensor de infrarrojos

A diferencia del sensor de ultrasonidos, el sensor de infrarrojos es algo más preciso en ciertos aspectos, ya que al funcionar con señales de luz, estas no se dispersan ni son fáciles de hacer desaparecer, pero tiene el inconveniente de tener un menor rango de actuación.
Por todo esto, la finalidad del sensor de infrarrojos será la de detectar cuerpos que se interpongan en el camino del vehículo y así parar en seco para no chocar, simulando los sistemas que tienen algunos coches para no colisionar con peatones.
La señal que mandará al programa será simplemente si hay un cuerpo delante o no, para luego ordenar a los motores que paren.
Código de ejemplo:

<br />include <IRremote.h>
<br />const int irReceiverPin -7; //the SIG of receiver module attach to pin7 onst int ledPin= 13;//pin 13 built-in led Rrecv irrecv(irReceiverPin); //Creates a variable of type IRrecv
<br />ecode_results results; oid setup()
<br />pinMode(ledPin, OUTPUT); //set ledpin as OUTPUT
<br />Serial.begin(9600);//initialize serial
<br />irrecv.enableIRInO); //enable ir receiver module
<br />void loopO
<br />if (irrecv.decode(&results)) //if the ir receiver module receiver data
<br />{
<br />Serial.print("irCode: "); //print "irCode: Serial.print(results.value, HEX); //print the value in hexdecimal
<br />Serial.print(", bits: "); //print", bits: " Serial.println(results.bits); //print the bits irrecv.resume(); /Receive the next value
<br />} delay(600); //delay 600ms
<br />if(results.value= 0xFFA25D)//if receiver module receive OxFFAZSD
<br />digitalWrite(ledPin,HIGH);//turn on the led
<br />} else
<br />{ digitalWrite(ledPin, LOW)://turn off the led
<br />}
<br />tetch uses 6754 bytes (26) of ornaram storage space Maximum is 32256 bytes obal vortables use 426 bytes (20%) of dynamic menory, leaving
<br />1622 bytes for lo
<br />3:50/8:57 Arduino program >

#### Sensor de temperatura

El sensor de temperatura tendrá el trabajo de ir recopilando diversas temperaturas a lo largo del tiempo para después calcular una temperatura media.
Este sensor funciona gracias a un componente sensible a la humedad, un termistor y un circuito integrado. Puesto que lo que nos interesa es cómo detecta la temperatura, nos centraremos en el funcionamiento de esta parte, la cual es el termistor, el que en realidad es un resistor variable, lo cual se resume en una resistencia cuya capacidad disminuye a medida que aumenta su temperatura (en nuestro caso la temperatura del exterior) y da el valor de esta.
Código de ejemplo:

<br />#include <dht.h>
<br />#define dataPin 8
<br />dht DHT;
<br />void setup() 
<br />{
<br /> Serial.begin(9600);
<br />}
<br />void loop() 
<br />int readData = DHT.read22(dataPin); 
<br /> float t = DHT.temperature;
<br /> float h = DHT.humidity;
<br /> Serial.print("Temperature = ");
<br /> Serial.print(t);
<br /> Serial.print(" *C ");
<br /> Serial.print("    Humidity = ");
<br /> Serial.print(h);
<br /> Serial.println(" % ");
<br /> delay(2000);
<br />}

#### Motores

Estos funcionan gracias al alineamiento de dos campos magnéticos generados por un estator o parte fija del motor que con el suyo hace girar una espira con el otro campo generando así la rotación.
Los motores simplemente tendrán la función de mover el vehículo para darle sensación de realismo y complementar las funcionalidades de algunos de los otros sensores como el de ultrasonidos o el de infrarrojos. También haremos un cálculo de la velocidad media con datos recopilados por las revoluciones por segundo que estos motores den.
Código de ejemplo:

<br />int motorPin = 9;
<br />void setup() {
<br />pinMode(motorPin, OUTPUT);
<br />Serial.begin(9600);
<br />while (! Serial);
<br />Serial.println("Speed 0 to 255");
<br />}
<br />void loop() {
<br />if (Serial.available()) {
<br />int speed = Serial.parseInt();
<br />if (speed >= 0 && speed <= 255) {
<br />analogWrite(motorPin, speed);}}}




