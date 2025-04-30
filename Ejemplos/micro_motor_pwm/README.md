📘 Control de Dirección y Velocidad del Motor GA12-N20 con Arduino y L298N

Este ejemplo permite controlar tanto el sentido de giro como la velocidad de un motorreductor DC GA12-N20 utilizando un Arduino UNO y un módulo L298N. Se emplea una señal PWM (modulación por ancho de pulso) para ajustar la velocidad del motor, y se alterna el sentido de rotación cada 5 segundos. Esta estrategia puede aplicarse a sistemas biomédicos de bombeo, movilidad o rehabilitación mecánica.

🔧 ¿Qué es un motor GA12-N20?

El GA12-N20 es un motorreductor de bajo consumo y tamaño compacto, ideal para aplicaciones en robótica y dispositivos portátiles. Su velocidad puede controlarse con PWM y su dirección mediante inversión de polaridad usando un puente H como el L298N.

🔬 Principio de funcionamiento

- El Arduino controla la **dirección** del motor mediante los pines IN1 e IN2 del L298N.
- La **velocidad** se ajusta con una señal PWM enviada al pin ENA del L298N.
- El motor gira en un sentido durante 5 segundos, se detiene, luego gira en el sentido contrario, simulando un ciclo mecánico alternante.

🔌 Esquema de conexión

| Motor GA12-N20 | L298N         | Arduino UNO |
|----------------|---------------|-------------|
| Terminal A     | OUT1          |             |
| Terminal B     | OUT2          |             |
| ENA            | ENA (PWM)     | D3 (PWM)    |
| IN1            | IN1           | D4          |
| IN2            | IN2           | D5          |
| VCC (motor)    | 6V–12V        | Fuente externa |
| GND            | GND           | GND         |

📍 Notas:
- La velocidad máxima en este ejemplo está fijada en PWM = 255.
- Puedes experimentar variando el valor de `velocidad` en el código para observar los efectos de menor potencia.
- Se recomienda una fuente externa para alimentar el motor (batería o adaptador de 6V–12V).

💻 Código del ejemplo

Consulta el archivo: `motor_direccion_velocidad.ino`

Este programa:

- Controla la **velocidad** del motor usando PWM (pin ENA).
- Controla la **dirección** mediante IN1 e IN2.
- Alterna el sentido de giro cada 5 segundos.
- Detiene el motor entre cada cambio de dirección.

📈 Aplicaciones biomédicas

- Bombas peristálticas de flujo reversible
- Sistemas de asistencia para terapia de movilidad alternante
- Mecanismos de tracción rítmica para rehabilitación funcional
- Dispositivos de ejercicio activo-pasivo con retroalimentación de velocidad

📎 Requisitos

- 1 motorreductor GA12-N20 (6V)
- 1 módulo controlador L298N
- 1 fuente de alimentación externa (6–12V)
- 1 placa Arduino UNO o compatible
- Protoboard y cables Dupont
- Arduino IDE instalado (v1.8.x o 2.x)

🎥 Material Complementario

- 📄 *PWM Motor Speed Control – Arduino & L298N Tutorial*
- 📺 Video: *Arduino DC Motor Direction and Speed Control* (Español/Inglés)
- 📄 Artículo: *Variable-Speed Actuation in Wearable Rehab Devices* – IOP Bioengineering

🧑‍🏫 Créditos

Este ejemplo fue desarrollado para el curso **Fundamentos de Biodiseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
**Versión**: 0.1

