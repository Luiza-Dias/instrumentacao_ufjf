#ifndef __LEITURA_SENSOR_H
#define __LEITURA_SENSOR_H

#include <Arduino.h>
#include <stdint.h>
#include "math.h"

#define NUMERO_AMOSTRAS 20

class Leitura_sensor{
private: 
    int numero_amostras;
    uint32_t indice;
    int pino;

    float sinal_sensor;
    float resolucao; 
    float sensibilidade;
    float vetor_medida_instantanea[NUMERO_AMOSTRAS];
public:
    Leitura_sensor(int pino, float sensibilidade);
    float retorna_leitura_instantanea();
    float calcula_rms();
    void atualiza_leitura();
    float retorna_rms();
    ~Leitura_sensor();
};

#endif