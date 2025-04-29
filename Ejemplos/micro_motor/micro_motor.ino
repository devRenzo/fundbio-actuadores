// Pines conectados al L298N
const int ENA = 3;   // PWM para velocidad (pin 3)
const int IN1 = 4;
const int IN2 = 5;

int velocidad = 255; // PWM entre 0 y 255

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Giro en sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad); // Aplicar velocidad
  delay(5000); // 5 segundos

  motorStop();
  delay(1000); // 1 segundo de pausa

  // Giro en sentido antihorario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidad); // Aplicar velocidad
  delay(5000); // 5 segundos

  motorStop();
  delay(1000); // 1 segundo de pausa
}

void motorStop() {
  analogWrite(ENA, 0);         // Detener motor (sin energía)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
