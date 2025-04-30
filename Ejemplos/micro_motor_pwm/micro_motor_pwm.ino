/*
 ============================================================================
 Título      : Control básico de motorreductor GA12-N20 con puente H L298N
 Descripción : Este código permite controlar la dirección de giro y la velocidad
               de un motorreductor DC tipo GA12-N20 utilizando un módulo L298N 
               y Arduino. La velocidad se ajusta mediante una señal PWM aplicada 
               al pin de habilitación (ENA) del puente H. Se alterna el sentido 
               de rotación cada 5 segundos, simulando un sistema de movimiento 
               alternante como los usados en bombas peristálticas o exoesqueletos 
               de rehabilitación.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Pines conectados al módulo L298N
const int ENA = 3;   // Pin PWM para controlar la velocidad del motor
const int IN1 = 4;   // Pin digital para dirección del motor (sentido 1)
const int IN2 = 5;   // Pin digital para dirección del motor (sentido 2)

int velocidad = 255; // Valor PWM entre 0 (apagado) y 255 (máxima velocidad)

void setup() {
  // Configurar los pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Giro en sentido horario
  digitalWrite(IN1, HIGH);    // IN1 en alto
  digitalWrite(IN2, LOW);     // IN2 en bajo
  analogWrite(ENA, velocidad); // Activar velocidad máxima
  delay(5000);                // Mantener giro por 5 segundos

  motorStop();                // Detener motor
  delay(1000);                // Pausa de 1 segundo

  // Giro en sentido antihorario
  digitalWrite(IN1, LOW);     
  digitalWrite(IN2, HIGH);    
  analogWrite(ENA, velocidad); 
  delay(5000);                

  motorStop();                
  delay(1000);                
}

// Función para detener el motor completamente
void motorStop() {
  analogWrite(ENA, 0);        // Desactiva PWM
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

