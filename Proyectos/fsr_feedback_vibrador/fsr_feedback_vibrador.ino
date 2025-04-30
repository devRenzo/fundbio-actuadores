/*
 ============================================================================
 Título      : Feedback háptico avanzado con FSR y motor vibrador
 Descripción : Este código controla un motor vibrador cuya intensidad (PWM) 
               se ajusta en función de la fuerza aplicada sobre un sensor FSR. 
               Se incluye filtrado de señal, umbral mínimo y curva de sensibilidad.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.2
 ============================================================================
*/

const int pinFSR = A0;     // Entrada analógica
const int pinMotor = 3;    // Salida PWM

const int umbral = 50;     // Umbral mínimo para activar la vibración (ADC)
const int promedioN = 10;  // Ventana para promedio simple

int buffer[promedioN];     // Buffer para promediar
int index = 0;

void setup() {
  pinMode(pinMotor, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sistema iniciado: Feedback háptico con FSR y vibrador");

  // Inicializar buffer con ceros
  for (int i = 0; i < promedioN; i++) {
    buffer[i] = 0;
  }
}

void loop() {
  // Leer nueva muestra y guardarla en el buffer
  int nuevaLectura = analogRead(pinFSR);
  buffer[index] = nuevaLectura;
  index = (index + 1) % promedioN;

  // Calcular promedio
  int suma = 0;
  for (int i = 0; i < promedioN; i++) {
    suma += buffer[i];
  }
  int lecturaFiltrada = suma / promedioN;

  // Evaluar si supera el umbral
  int pwm = 0;
  if (lecturaFiltrada > umbral) {
    // Mapeo no lineal (cuadrático): mayor sensibilidad a baja presión
    float normalizado = (float)(lecturaFiltrada - umbral) / (1023 - umbral);
    pwm = pow(normalizado, 2.0) * 255;
    pwm = constrain(pwm, 0, 255);
  }

  analogWrite(pinMotor, pwm);

  // Mostrar datos
  Serial.print("FSR: ");
  Serial.print(lecturaFiltrada);
  Serial.print(" | PWM: ");
  Serial.println(pwm);

  delay(100);
}

