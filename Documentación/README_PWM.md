
# ⚡ Introducción a las Señales PWM (Modulación por Ancho de Pulso)

La **PWM (Pulse Width Modulation)** es una técnica fundamental en electrónica para controlar la energía entregada a dispositivos como **motores, LEDs o servomotores**, utilizando una señal digital.

En el contexto del curso **Fundamentos de Biodiseño**, la PWM es esencial para regular la **intensidad de vibración**, **velocidad de motores** y **posición angular** de actuadores en prótesis y sistemas de rehabilitación.

---

## 🎯 ¿Qué es una señal PWM?

Una señal PWM es una **onda cuadrada** que alterna entre nivel alto (5 V) y bajo (0 V), pero lo importante es cuánto tiempo permanece **encendida** en cada ciclo.

El **Duty Cycle (ciclo de trabajo)** indica ese tiempo como porcentaje:

$$
\text{Duty Cycle (\%)} = \frac{t_{\text{alto}}}{T_{\text{total}}} \times 100
$$

Donde:
- \( T_{\text{total}} \): duración de un ciclo completo (en ms o µs)
- \( t_{\text{alto}} \): tiempo en nivel alto (ON)

---

## 📈 Ejemplo visual

A continuación se muestran tres señales PWM con diferentes ciclos de trabajo (frecuencia constante, T = 2 ms):

![Ejemplo PWM](./pwm_duty_cycles.png)

- **20 %**: la señal está encendida poco tiempo → poca energía promedio
- **50 %**: la señal está encendida la mitad del ciclo → energía media
- **80 %**: la señal está encendida la mayor parte del tiempo → energía alta

---

## ⚙️ ¿Para qué sirve PWM?

| Aplicación             | Cómo lo usa PWM                       |
|------------------------|----------------------------------------|
| Motores DC             | Controla la velocidad                 |
| Motor vibrador         | Regula la intensidad de vibración     |
| Servomotores (con calibración) | Determina el ángulo de giro          |
| Luces LED              | Controla el brillo                    |

---

## 🛠️ En Arduino

Arduino ofrece PWM por hardware en varios pines digitales (3, 5, 6, 9, 10, 11) usando la función:

```cpp
analogWrite(pin, valorPWM);
```

Donde `valorPWM` va de **0** (0 %) a **255** (100 %).

---

## 🔍 Notas para servomotores

Los **servos como el DS3235** no usan `analogWrite()`, sino pulsos PWM calibrados en microsegundos (ej. 500–2400 µs) con funciones como:

```cpp
servo.writeMicroseconds(valor);
```

Este PWM **no regula energía**, sino que **codifica posición angular**.

---

## 🧑‍🏫 Créditos

Material desarrollado para el curso **Fundamentos de Biodiseño**  
**Docentes**: Renzo Chan Ríos / Lewis De La Cruz  
**Universidad Peruana Cayetano Heredia (UPCH)** — 2025  
Versión: 1.0
