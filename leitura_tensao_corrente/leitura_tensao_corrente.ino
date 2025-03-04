#include "leitura_sensor.h"

Leitura_sensor leitura_tensao = Leitura_sensor(A1, 0.0053);  
Leitura_sensor leitura_corrente = Leitura_sensor(A0, 0.066);  

float energia;
uint32_t t_0;

void setup() {
  Serial.begin(115200);
  energia = 0;
  t_0 = millis();
}

void loop() {
  float tensao = leitura_tensao.retorna_rms();
  float corrente = leitura_corrente.retorna_rms();
  float potencia = tensao * corrente;
  energia = energia + (potencia * (millis() - t_0)/3600000);
  t_0 = millis();

  Serial.print("Valor de tensao lido (RMS) [V]: ");
  Serial.println(tensao);

  Serial.print("Valor de corrente lido (RMS) [A]: ");
  Serial.println(corrente);

  Serial.print("Valor de potencia calculado (RMS) [W]: ");
  Serial.println(potencia);

  Serial.print("Valor de energia calculado (RMS) [KWh]: ");
  Serial.println(energia);
}
//TO-DO Inserir display para mostrar os valores sem depender do terminal
