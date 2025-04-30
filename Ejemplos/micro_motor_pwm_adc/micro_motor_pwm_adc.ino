/*
 ============================================================================
 Título      : Control de velocidad del motor GA12-N20 con potenciómetro y L298N
 Descripción : Este código permite controlar la velocidad de un motorreductor DC 
               GA12-N20 mediante un potenciómetro conectado a una entrada analógica. 
               La señal leída (valor ADC) se convierte en una señal PWM aplicada al 
               módulo L298N. Además, se imprime por el monitor serial el valor leído 
               y el valor PWM aplicado para facilitar el análisis.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.2
 ============================================================================
*/

// Pines del módulo L298N
const int ENA = 3;   // Pin PWM para velocidad
const int IN1 = 4;   // Control de dirección (sentido 1)
const int IN2 = 5;   // Control de dirección (sentido 2)

// Pin del potenciómetro
const int POT = A0;  // Entrada analógica A0

void setup() {
  // Configurar pines como salida
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Establecer la dirección del motor: sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Inicializar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del potenciómetro (0 a 1023)
  int lectura = analogRead(POT);

  // Convertir la lectura a un valor PWM (0 a 255)
  int velocidadPWM = map(lectura, 0, 1023, 0, 255);

  // Aplicar velocidad al motor
  analogWrite(ENA, velocidadPWM);

  // Imprimir valores en el monitor serial
  Serial.print("ADC: ");
  Serial.print(lectura);
  Serial.print("  |  PWM: ");
  Serial.println(velocidadPWM);

  delay(200); // Pausa para no saturar el monitor serial
}

