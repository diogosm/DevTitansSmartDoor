#define RELE 16  // RELE conectado na porta 16

// código na função setup é executado apenas uma vez quando o ESP32 ou ARDUINO é iniciado
void setup() {
  Serial.begin(9600);
  
  // inicializar o PIN DIGITAL como uma saída.
  pinMode(RELE, OUTPUT);
}

// o código na função de loop é executado repetidamente infinitamente
void loop() {
  digitalWrite(RELE, LOW); // destranca a porta
  Serial.println("PORTA ABERTA");
  delay(5000);
  digitalWrite(RELE, HIGH);  // tranca a porta
  Serial.println("PORTA FECHADA");
  delay(5000);
}
