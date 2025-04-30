/*
 ============================================================================
 Título      : Control de dirección del motor GA12-N20 con puente H L298N
 Descripción : Este código permite cambiar únicamente el sentido de giro de un 
               motorreductor DC tipo GA12-N20 utilizando un módulo L298N, sin 
               control de velocidad. El motor alterna su dirección cada 5 segundos, 
               simulando un mecanismo básico de inversión de flujo o movimiento 
               mecánico bidireccional.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Pines conectados al módulo L298N (solo para dirección)
const int IN1 = 4;   // Pin digital para dirección del motor (sentido 1)
const int IN2 = 5;   // Pin digital para dirección del motor (sentido 2)

void setup() {
  // Configurar los pines como salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Giro en sentido horario
  digitalWrite(IN1, HIGH);  // IN1 en alto
  digitalWrite(IN2, LOW);   // IN2 en bajo
  delay(5000);              // Mantener giro por 5 segundos

  motorStop();              // Detener motor
  delay(1000);              // Pausa de 1 segundo

  // Giro en sentido antihorario
  digitalWrite(IN1, LOW);   // IN1 en bajo
  digitalWrite(IN2, HIGH);  // IN2 en alto
  delay(5000);              // Mantener giro por 5 segundos

  motorStop();              // Detener motor
  delay(1000);              // Pausa de 1 segundo
}

// Función para detener el motor (ambos pines en bajo)
void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

