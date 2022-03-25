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
Esto se llevará a cabo gracias a que con el funcionamiento del sensor este irá emitiendo una señal sonora de entre 2 y 400 cm que al rebotar con el objeto o pared en cuestión será reflejada y captada por el mismo, calculando el tiempo de ida y vuelta para devolver una distancia. Sabiendo que aproximadamente la velocidad de la señal sonora es de 343m/s
Puesto que el sonido en ciertos casos se disipa y no tiende a funcionar tan bien el sensor no llega a ser tan preciso, es por esto que su funcionalidad estará basada en los sistemas de alarma de aparcado de los coches, tomando varias veces medidas que darán un aviso importante cuando estas sean ya muy pequeñas.
Código de ejemplo:



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


