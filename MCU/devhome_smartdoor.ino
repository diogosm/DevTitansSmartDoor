#define RELE 16  // RELE conectado na porta 16

// código na função setup é executado apenas uma vez quando o ESP32 ou ARDUINO é iniciado
void setup() {
  // inicializar o PIN DIGITAL como uma saída.
  pinMode(RELE, OUTPUT);
}

// o código na função de loop é executado repetidamente infinitamente
void loop() {
  digitalWrite(RELE, HIGH); // destranca a porta
  delay(5000);
  digitalWrite(RELE, LOW);  // tranca a porta
  delay(5000);
}
