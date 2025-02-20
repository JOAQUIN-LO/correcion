Se requiere una solución programable para un sistema de control ambiental.
Dicho sistema cuenta con 2 sensores de 4 bits cada uno, donde el bit más significativo será el que informará cuando se pueda leer en todos.
El resto de bits dependerá del módulo que los entregue, que responde a la siguiente tabla:
Se requiere un código donde se tendrán 4 leds (verde, amarillo, naranja, rojo) de indicadores de temperatura y otros 4 iguales para la humedad.
Se deberá leer cuando corresponda a los sensores y según el resultado arrojado, deberá titilar el led que corresponda. Siendo (000-001: Verde ; 010-011: Amarillo ; 100-101: Naranja ; 110-111: Rojo).
Realizar también la librería que contenga una librería para cada sensor, donde se devuelva un caracter con la inicial de cada color, dependiendo de que se sense.
FUNCIONES
sensTemp();
sensHum();
Tener en cuenta que la temperatura tendrá mayor importancia que la humedad a la     hora de sensar. Los pines a utilizar son los siguientes, El LSB será el bit de aviso de cada uno.

