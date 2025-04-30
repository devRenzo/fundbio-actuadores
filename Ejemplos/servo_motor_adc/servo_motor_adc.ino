#include <Servo.h>

Servo miServo;

// Rango calibrado
const int ADC_MIN = 0;
const int ADC_MAX = 1023;
const float ANGULO_MAX = 265.0;   // Ángulo máximo calibrado
const int PULSO_MIN = 500;        // µs a 0°
const int PULSO_MAX = 2400;       // µs a 265°

void setup() {
  miServo.attach(3);
  Serial.begin(9600);
}

void loop() {
  int lecturaADC = analogRead(A0);

  // Calcular el ángulo real a partir del ADC
  float angulo = map(lecturaADC, ADC_MIN, ADC_MAX, 0, ANGULO_MAX);

  // Calcular microsegundos según fórmula calibrada
  int pulso = PULSO_MIN + (angulo * ((float)(PULSO_MAX - PULSO_MIN) / ANGULO_MAX));

  // Enviar al servo
  miServo.writeMicroseconds(pulso);

  // Mostrar en el Monitor Serie
  Serial.print("ADC: ");
  Serial.print(lecturaADC);
  Serial.print(" | Microsegundos: ");
  Serial.print(pulso);
  Serial.print(" | Ángulo: ");
  Serial.print(angulo, 1);  // Mostrar con un decimal
  Serial.println("°");

  delay(100);
}

