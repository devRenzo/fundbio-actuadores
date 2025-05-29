# ⚙️ Taller de Actuadores — Fundamentos de Biodiseño

<p align="center">
  <img src="image.png" alt="Taller de actuadores electromecánicos con Arduino" width="600"><br>
  <em>Figura 1. Taller de actuadores electromecánicos con Arduino.</em>
</p>

Este repositorio contiene el material completo del **Taller de Actuadores** del curso **Fundamentos de (Bio)diseño**, dictado en el 4.º ciclo de la carrera de Ingeniería Biomédica en la Universidad Peruana Cayetano Heredia (UPCH).

---

## 🎯 Objetivo del taller

Fortalecer competencias en electrónica aplicada al diseño y control de **actuadores eléctricos** básicos (motores DC, servomotores y motores de vibración), integrando conceptos de señales PWM, lectura analógica (ADC) y control digital mediante transistores.

---

## 🧩 ¿Qué aprenderás?

- Principios de funcionamiento de actuadores biomédicos simples
- Control de velocidad, dirección y posición mediante Arduino
- Uso de PWM para regulación de energía
- Conversión de señales analógicas con el ADC
- Conmutación de actuadores con transistores en modo saturación
- Aplicaciones reales en bioinstrumentación y dispositivos de asistencia

---

## 📁 Estructura del repositorio

### 🔸 `Ejemplos/`
Contiene 7 carpetas, cada una con un ejemplo funcional en Arduino:

- `motor_direccion_basica`: controla dirección de un motor GA12-N20
- `motor_direccion_velocidad`: controla dirección y velocidad fija con PWM
- `motor_velocidad_potenciometro`: control de velocidad proporcional con potenciómetro
- `vibration_motor_basico`: encendido/apagado simple de motor vibrador
- `vibration_motor_potenciometro`: control de intensidad con potenciómetro
- `servo_ds3235_control_basico`: posiciones angulares fijas con DS3235
- `servo_ds3235_adc_pwm`: control proporcional de posición con PWM derivado del ADC

Cada carpeta incluye:

- Código Arduino (`.ino`)
- `README.md` con descripción técnica
- Esquema de conexión y aplicaciones biomédicas sugeridas

---

## 🧪 Fundamentos teóricos integrados

Cada ejemplo está vinculado a los siguientes conceptos básicos:

| Concepto       | Aplicación en el taller                      |
|----------------|----------------------------------------------|
| Señal PWM      | Regulación de velocidad, vibración o posición |
| ADC            | Lectura de potenciómetros o sensores         |
| Transistor NPN | Conmutación de motores de forma segura       |

---

## 🧬 Aplicaciones biomédicas relacionadas

Los principios vistos aquí se aplican en el diseño de:

- Sistemas de rehabilitación motora
- Ortesis activas y exoesqueletos
- Interfaces hápticas para estimulación sensorial
- Dispositivos de terapia pasiva y biofeedback

---

## 🛠️ Requisitos para experimentar

- Arduino UNO o compatible
- Módulo L298N (para motores DC)
- Servomotor DS3235
- Motores GA12-N20 y coin cell vibradores
- Potenciómetros (10kΩ)
- Transistores NPN (2N2222, S8050)
- Diodos de protección (1N4007)
- Protoboard y cables Dupont
- Fuente externa (6–12 V) para actuadores

---

## 🧑‍🏫 Créditos

Este material fue desarrollado para el curso **Fundamentos de (Bio)diseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
Versión: 1.0

