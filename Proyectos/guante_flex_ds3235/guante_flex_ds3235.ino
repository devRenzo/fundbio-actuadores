/*
 ============================================================================
 Título      : Control de prótesis robótica con sensor flex y servomotor DS3235
 Descripción : Este código permite controlar un servomotor DS3235 mediante la lectura
               de un sensor flex montado en un guante. A medida que el dedo se flexiona,
               se varía la señal PWM al servo para simular una articulación robótica.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

#include <Servo.h>

Servo servoProtesis;

// Calibración PWM ↔ Ángulo del DS3235
const int PULSO_MIN = 500;       // µs (ángulo 0°)
const int PULSO_MAX = 2400;      // µs (ángulo 265°)
const float ANGULO_MAX = 265.0;  // ángulo máximo estimado

// Pin del sensor flex
const int pinFlex = A0;          // Conectado al punto medio del divisor de voltaje

void setup() {
  servoProtesis.attach(3);       // Servo en pin digital 3
  Serial.begin(9600);
}

void loop() {
  // Leer valor analógico del sensor flex
  int lecturaADC = analogRead(pinFlex);

  // Mapear directamente el ADC al rango de PWM
  int pulso = map(lecturaADC, 0, 1023, PULSO_MIN, PULSO_MAX);

  // Calcular ángulo estimado solo para monitoreo
  float angulo = ((float)(pulso - PULSO_MIN) * ANGULO_MAX) / (PULSO_MAX - PULSO_MIN);

  // Enviar señal PWM al servomotor
  servoProtesis.writeMicroseconds(pulso);

  // Imprimir datos en el Monitor Serial
  Serial.print("Flex ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | PWM: ");
  Serial.print(pulso);
  Serial.print(" µs | Ángulo estimado: ");
  Serial.print(angulo, 1);
  Serial.println("°");

  delay(100); // Retardo breve
}

