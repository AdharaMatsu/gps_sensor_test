void setup() {
  Serial.begin(38400); // Inicializar el puerto serial a 9600 bps
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read(); // Leer los datos entrantes
    Serial.print("Dato recibido: ");
    Serial.println(data); // Mostrar el dato recibido en el monitor serial

    delay(1000);
  }
}
