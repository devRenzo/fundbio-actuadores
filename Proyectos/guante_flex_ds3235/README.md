# ✋ Guante de Control para Prótesis Robótica con Sensor Flex y Servomotor

Este proyecto demuestra cómo controlar un **servomotor DS3235** mediante un **sensor flex** colocado en un dedo de un guante, simulando el control de una articulación robótica tipo prótesis. Al flexionar el dedo, el sensor genera una señal analógica que se convierte en una señal PWM proporcional, haciendo que el servo imite el movimiento.

---

## 🎯 Objetivo del proyecto

Aplicar conceptos fundamentales de electrónica (ADC, PWM y control de actuadores) para construir un sistema de entrada analógica proporcional capaz de accionar un mecanismo robótico, integrando principios de biodiseño.

---

## 🔩 Componentes necesarios

| Componente         | Cantidad |
|--------------------|----------|
| Sensor flex (2.2" o 4.5")     | 1        |
| Servomotor DS3235             | 1        |
| Arduino UNO o Nano            | 1        |
| Fuente externa 6–7.4V (≥2A)   | 1        |
| Resistencia 10kΩ              | 1        |
| Protoboard + cables           | Varios   |
| Guante de tela o licra        | 1        |
| Estructura robótica (manual o impresa) | 1 |

---

## 🔌 Esquema de conexión

### Sensor flex (como divisor de voltaje):

| Pin Sensor Flex | Conexión             |
|------------------|----------------------|
| Extremo A        | 5V Arduino           |
| Extremo B        | A0 (Arduino UNO)     |
| Resistencia 10kΩ | Entre A0 y GND       |

### Servomotor DS3235:

| Pin Servo  | Conexión             |
|------------|----------------------|
| Señal      | D3 (PWM)             |
| V+         | Fuente externa (6V)  |
| GND        | GND común con Arduino |

---

## ⚙️ Funcionamiento

1. El **sensor flex** cambia su resistencia al flexionar el dedo.
2. El Arduino lee este cambio como un valor **ADC (0–1023)**.
3. El valor se transforma a un pulso **PWM (500–2400 µs)** usando `map()`.
4. El **servomotor** responde moviéndose en un rango angular proporcional (0° a ~265°).
5. El monitor serial muestra en tiempo real el valor ADC, el PWM y el ángulo estimado.

---

## 💻 Archivo principal

Consulta el archivo: `guante_flex_ds3235.ino`

Este programa:

- Lee el valor del sensor flex.
- Mapea el valor a PWM usando `map()`.
- Controla el servomotor con `writeMicroseconds()`.
- Imprime el ángulo estimado en el monitor serial.

---

## 📈 Aplicaciones biomédicas

- Simulación de control mioeléctrico en prótesis de mano
- Sistemas de asistencia robótica proporcional (exoesqueletos)
- Interfaces cuerpo-máquina para rehabilitación motora
- Entrenamiento clínico con dispositivos portables

---

## 🧠 Conceptos integrados

| Concepto electrónico | Aplicación práctica           |
|-----------------------|-------------------------------|
| ADC (entrada analógica) | Lectura del sensor flex       |
| PWM                   | Control de posición del servo |
| Ecuación de la recta  | Cálculo de ángulo desde PWM   |

---

## 🧑‍🏫 Créditos

Proyecto desarrollado para el curso **Fundamentos de Biodiseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
Versión: 0.1

