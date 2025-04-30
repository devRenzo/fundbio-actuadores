/*
 ============================================================================
 Título      : Control de servomotor DS3235 desde potenciómetro (PWM directo desde ADC)
 Descripción : Este código controla un servomotor DS3235 leyendo un potenciómetro. 
               La lectura analógica (ADC) se convierte directamente en una señal PWM 
               en microsegundos, que se aplica al servo. El ángulo se calcula solo 
               como referencia para el usuario (no como paso intermedio).
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.3
 ============================================================================
*/

#include <Servo.h>

Servo miServo;

// Calibración
const int ADC_MIN = 0;
const int ADC_MAX = 1023;
const int PULSO_MIN = 500;       // µs para 0°
const int PULSO_MAX = 2400;      // µs para ~265°
const float ANGULO_MAX = 265.0;  // Ángulo real aproximado

void setup() {
  miServo.attach(3);      // Conectar servo al pin 3
  Serial.begin(9600);     // Inicializar monitor serial
}

void loop() {
  // Leer el valor del potenciómetro
  int lecturaADC = analogRead(A0);

  // Convertir directamente a pulso PWM en microsegundos
  int pulso = map(lecturaADC, ADC_MIN, ADC_MAX, PULSO_MIN, PULSO_MAX);

  // Enviar el pulso al servomotor
  miServo.writeMicroseconds(pulso);

  // Calcular el ángulo estimado (solo para visualizar en el monitor)
  float angulo = ((float)(pulso - PULSO_MIN) * ANGULO_MAX) / (PULSO_MAX - PULSO_MIN);

  // Mostrar valores en el monitor serial
  Serial.print("ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | PWM: ");
  Serial.print(pulso);
  Serial.print(" µs | Ángulo estimado: ");
  Serial.print(angulo, 1);
  Serial.println("°");

  delay(100);
}

