// Definir pines
const int pinMotor = 3;         // Pin para controlar el transistor (PWM)
const int pinPot = A0;          // Pin donde está conectado el potenciómetro

void setup() {
  pinMode(pinMotor, OUTPUT);    // Configurar el pin del motor como salida
  pinMode(pinPot, INPUT);       // Configurar el pin del potenciómetro como entrada
  Serial.begin(9600);           // Iniciar el Monitor Serie
}

void loop() {
  // Leer el valor del potenciómetro (valor entre 0 y 1023)
  int lecturaPot = analogRead(pinPot);

  // Mapear el valor del potenciómetro a un rango PWM de 0 a 255
  int valorPWM = map(lecturaPot, 0, 1023, 0, 255);

  // Enviar señal PWM al motor vibrador a través del transistor
  analogWrite(pinMotor, valorPWM);

  // Imprimir en el Monitor Serie el valor del potenciómetro y el valor PWM
  Serial.print("Potenciómetro: ");
  Serial.print(lecturaPot);
  Serial.print(" | PWM: ");
  Serial.println(valorPWM);

  delay(100);  // Pausa para no saturar el monitor serie
}
