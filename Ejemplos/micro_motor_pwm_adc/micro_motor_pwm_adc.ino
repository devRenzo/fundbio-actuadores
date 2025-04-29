// Pines del L298N
const int ENA = 3;
const int IN1 = 4;
const int IN2 = 5;

// Potenciómetro
const int POT = A0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Fijar dirección: sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {
  // Leer el potenciómetro continuamente
  int lectura = analogRead(POT);
  int velocidadPWM = map(lectura, 0, 1023, 0, 255);

  // Aplicar velocidad
  analogWrite(ENA, velocidadPWM);

  delay(10); // Suaviza la lectura (opcional)
}

