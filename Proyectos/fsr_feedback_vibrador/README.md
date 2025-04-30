# 🖐️ Feedback Háptico con FSR y Motor Vibrador

Este proyecto permite generar una señal de vibración proporcional a la presión aplicada sobre un **sensor FSR (Force Sensitive Resistor)**. A medida que se aplica más fuerza, el motor vibrador aumenta su intensidad mediante una señal PWM. Es una forma efectiva y económica de implementar **retroalimentación táctil proporcional** en interfaces biomédicas o educativas.

---

## 🎯 Objetivo

Simular un sistema de **feedback háptico continuo**, donde el usuario recibe una señal táctil proporcional al nivel de presión ejercida, útil en aplicaciones de rehabilitación, entrenamiento sensorial o interfaces humano-máquina.

---

## 🔩 Componentes requeridos

| Componente                | Cantidad |
|---------------------------|----------|
| Sensor FSR (ej. Interlink 402) | 1 |
| Motor vibrador tipo coin cell | 1 |
| Transistor NPN (2N2222 o similar) | 1 |
| Resistencia de 1kΩ (base transistor)   | 1 |
| Diodo de protección (1N4007)  | 1 |
| Resistencia de 10kΩ (pull-down) | 1 |
| Arduino UNO o Nano         | 1 |
| Protoboard + cables        | Varios |

---

## 🔌 Esquema de conexión

### Sensor FSR (como divisor de voltaje):

- Un extremo del FSR al **5V**
- El otro extremo al pin **A0**
- Resistencia de 10kΩ entre A0 y GND

### Motor vibrador:

- Pin digital D3 → resistencia 1kΩ → base del transistor NPN
- Colector del transistor → terminal negativo del motor
- Emisor del transistor → GND
- Terminal positivo del motor → 5V
- Diodo flyback en paralelo con el motor

---

## ⚙️ Funcionamiento

1. El sensor FSR detecta la presión aplicada y cambia su resistencia.
2. Arduino lee ese cambio como valor analógico (ADC).
3. El valor se mapea a una señal PWM (0–255).
4. El motor vibra con una intensidad proporcional a la fuerza.
5. Los valores se muestran en el monitor serial.

---

## 📈 Aplicaciones biomédicas

- Retroalimentación táctil en interfaces para personas con discapacidad visual
- Simulación de presión aplicada en dispositivos de rehabilitación
- Sistemas de entrenamiento sensorial para niños o adultos mayores
- Entrenamiento de fuerza o dosificación de presión en terapia ocupacional

---

## 🧠 Conceptos integrados

| Concepto electrónico | Aplicación           |
|-----------------------|----------------------|
| ADC                  | Lectura de presión   |
| PWM                  | Control de vibración |
| Transistor NPN       | Conmutación segura   |
| Feedback háptico     | Estímulo proporcional|

---

## 🧑‍🏫 Créditos

Este proyecto fue desarrollado para el curso **Fundamentos de Biodiseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
Versión: 0.1

