#include <Servo.h>  // Incluye la librería Servo para controlar el servomotor

/*
  ===============================================
  Tabla de equivalencia aproximada para DS3235
  usando writeMicroseconds()

  Grados       Microsegundos (µs)
  -------      -------------------
    0°              500
   90°             1180
  180°             1800
  265°             2400
  ===============================================
  Nota: Estos valores son aproximados y pueden variar
  ligeramente entre unidades. Conviene calibrar cada
  servo individualmente si se necesita precisión.
*/

Servo miServo;  // Crea un objeto de tipo Servo

void setup() {
  miServo.attach(3);  // Conecta el servo al pin digital 3
}

void loop() {
  // Mover a 0° (posición inicial)
  miServo.writeMicroseconds(500);
  delay(5000);

  // Mover a 90°
  miServo.writeMicroseconds(1180);
  delay(5000);

  // Mover a 180°
  miServo.writeMicroseconds(1800);
  delay(5000);

  // Mover a 270°
  miServo.writeMicroseconds(2400);
  delay(5000);
}
