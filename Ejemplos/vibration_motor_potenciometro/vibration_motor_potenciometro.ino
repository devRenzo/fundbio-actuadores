/*
 ============================================================================
 Título      : Control de intensidad de vibración con potenciómetro y PWM
 Descripción : Este código permite controlar la intensidad de un micromotor de 
               vibración tipo coin cell utilizando un potenciómetro como entrada 
               analógica. La lectura del potenciómetro se convierte en una señal 
               PWM que regula el nivel de vibración. Se muestra en el monitor 
               serial tanto el valor ADC como el valor PWM aplicado.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Definir pines
const int pinMotor = 3;         // Pin PWM conectado a la base del transistor que controla el motor
const int pinPot = A0;          // Pin analógico conectado al potenciómetro

void setup() {
  pinMode(pinMotor, OUTPUT);    // Configurar el pin del motor como salida
  pinMode(pinPot, INPUT);       // Configurar el pin del potenciómetro como entrada
  Serial.begin(9600);           // Iniciar la comunicación con el monitor serial
}

void loop() {
  // Leer el valor del potenciómetro (valor entre 0 y 1023)
  int lecturaPot = analogRead(pinPot);

  // Mapear el valor a una escala de PWM (0 a 255)
  int valorPWM = map(lecturaPot, 0, 1023, 0, 255);

  // Aplicar señal PWM al motor mediante el transistor
  analogWrite(pinMotor, valorPWM);

  // Mostrar los valores en el Monitor Serie
  Serial.print("Potenciómetro: ");
  Serial.print(lecturaPot);
  Serial.print(" | PWM: ");
  Serial.println(valorPWM);

  delay(100);  // Retardo breve para evitar saturar el monitor
}

