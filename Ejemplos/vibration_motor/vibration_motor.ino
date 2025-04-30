// Pin para controlar el transistor
const int pinMotor = 3;

void setup() {
  pinMode(pinMotor, OUTPUT);  // Configurar el pin 3 como salida
}

void loop() {
  // Encender el motor vibrador
  digitalWrite(pinMotor, HIGH);
  delay(2000);  // Motor encendido durante 2 segundos
  
  // Apagar el motor vibrador
  digitalWrite(pinMotor, LOW);
  delay(2000);  // Motor apagado durante 2 segundos
}
