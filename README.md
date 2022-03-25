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
