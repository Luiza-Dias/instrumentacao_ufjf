#include "leitura_sensor.h"

Leitura_sensor::Leitura_sensor(int pino, float sensibilidade){
    this->sinal_sensor = 0;
    this-> resolucao = 5/1023; // Tensao de fundo de escala 5V e conversor de 10 bits
    this->numero_amostras = NUMERO_AMOSTRAS;
    this->indice = 0;
    this->sensibilidade = sensibilidade;
    this->pino = pino;

    pinMode(pino, INPUT);
    delay(100);
    for(int i = 0; i < this->numero_amostras; i++){
        this->vetor_medida_instantanea[i] = this->retorna_leitura_instantanea();
    }
}

float Leitura_sensor::retorna_leitura_instantanea(){
    this->sinal_sensor = analogRead(this->pino) * this->resolucao;
    return (this->sinal_sensor - 2.5)/(this->sensibilidade);
}
  
void Leitura_sensor::atualiza_leitura(){
    int i = this->indice % this->numero_amostras;
    this->vetor_medida_instantanea[i] = this->retorna_leitura_instantanea();
    this->indice += 1;
}
  
float Leitura_sensor::calcula_rms(){
    float media = 0;
    for(int i = 0; i < this->numero_amostras; i++){
      media += pow(this->vetor_medida_instantanea[i],2);
    }
    media = media / this->numero_amostras;
    return sqrt(media);
}
  
float Leitura_sensor::retorna_rms(){
    this->atualiza_leitura();
    return calcula_rms();
}

Leitura_sensor::~Leitura_sensor(){}