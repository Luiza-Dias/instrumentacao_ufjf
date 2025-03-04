#include "leitura_sensor.h"

Leitura_sensor leitura_tensao = Leitura_sensor(A1, 0.0053);  
Leitura_sensor leitura_corrente = Leitura_sensor(A0, 0.066);  

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Valor de tensao lido (RMS): ");
  Serial.println(leitura_tensao.retorna_rms());

  Serial.print("Valor de corrente lido (RMS): ");
  Serial.println(leitura_corrente.retorna_rms());
}
