// Pines conectados al L298N
const int IN1 = 4;
const int IN2 = 5;

void setup() {
  // Configurar los pines como salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Sentido horario (IN1 HIGH, IN2 LOW)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(5000); // 5 segundos girando
  motorStop();

  delay(1000); // 1 segundo de pausa

  // Sentido antihorario (IN1 LOW, IN2 HIGH)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(5000); // 5 segundos girando
  motorStop();

  delay(1000); // 1 segundo de pausa
}

void motorStop() {
  // Detener el motor (ambos LOW)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
