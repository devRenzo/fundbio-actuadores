📘 Control de Posición del Servomotor DS3235 con Arduino

Este ejemplo permite controlar la posición angular de un servomotor de alto torque DS3235 mediante la función `writeMicroseconds()` de la librería Servo. Se programan cuatro posiciones representativas (0°, 90°, 180°, 270°) utilizando valores de pulso personalizados, adecuados para servos con mayor rango que los SG90 estándar. Este tipo de actuadores es útil en ortesis robóticas o dispositivos de asistencia mecánica en rehabilitación.

🔧 ¿Qué es el servomotor DS3235?

El DS3235 es un servomotor digital de alto torque (hasta 35 kg·cm), alimentado típicamente con 6V–7.4V, y controlado mediante pulsos PWM. Su rango de movimiento puede superar los 270°, lo que lo hace ideal para aplicaciones con cargas o ángulos amplios.

🔬 Principio de funcionamiento

- Un pulso de duración específica (en microsegundos) define la posición angular del servo.
- El valor de pulso varía entre ~500 µs (mínimo) y ~2400 µs (máximo), dependiendo del modelo.
- Arduino envía estos pulsos a través de la librería Servo.

📐 Equivalencias aproximadas

| Ángulo objetivo | Ancho de pulso (µs) |
|------------------|----------------------|
| 0°               | 500                  |
| 90°              | 1180                 |
| 180°             | 1800                 |
| 265–270°         | 2400                 |

📍 Recomendaciones:

- Alimentar el servo desde una fuente externa (6V o 7.4V), no desde el pin 5V de Arduino.
- Asegurar conexión común a GND entre Arduino y la fuente del servo.
- Si se requiere mayor precisión, se recomienda calibrar cada unidad experimentalmente.

🔌 Esquema de conexión

| Pin DS3235      | Arduino UNO       |
|------------------|-------------------|
| Señal (naranja)  | D3 (PWM)          |
| V+ (rojo)        | Fuente externa 6V |
| GND (marrón)     | GND (común)       |

💻 Código del ejemplo

Consulta el archivo: `servo_ds3235_control_basico.ino`

Este programa:

- Usa la función `writeMicroseconds()` para enviar pulsos precisos.
- Mueve el servo entre 4 posiciones angulares distintas.
- Hace pausas de 5 segundos entre movimientos para observar su acción.

📈 Aplicaciones biomédicas

- Control de articulaciones robóticas en ortesis activas
- Sistemas de posicionamiento de válvulas en dispositivos de asistencia respiratoria
- Mecanismos de manipulación en brazos protésicos
- Dispositivos de entrenamiento motor asistido

📎 Requisitos

- 1 servomotor DS3235
- 1 fuente externa 6–7.4V (mínimo 2A)
- 1 placa Arduino UNO o compatible
- Cables Dupont o conectores de 3 pines
- Arduino IDE instalado

🎥 Material Complementario

- 📺 Video: *Servo Motor DS3235 – High Torque PWM Control with Arduino*
- 📄 Guía técnica: *DS3235 datasheet & calibration guide*
- 📘 Artículo: *Servomotor control in robotic orthoses* – Journal of Biomechatronics

🧑‍🏫 Créditos

Este ejemplo fue desarrollado para el curso **Fundamentos de Biodiseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
**Versión**: 0.1

