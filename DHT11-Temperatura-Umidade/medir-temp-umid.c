//Incluir biblioteca "DHT.h" no IDE do Arduino
#include "DHT.h"

//Definir Pino Digital para o sensor DHT
//Pode ser pino 2 a 13
#define DHT_pin 2

//Define tipo do sensor DHT a ser usado pela biblioteca
#define DHT_type DHT11

//Inicializa o sensor DHT e declara seus parametros
DHT dht(DHT_pin, DHT_type);

//Funcao que inicializa o programa
void setup(){
    //Inicializar Comunicacao Serial
    Serial.begin(9600);

    //Inicializar Sensor DHT
    dht.begin();
}

//Funcao que fica no loop de processo
void loop(){
    //Leitura dos valores
    float valor_umidade = dht.readHumidity(); //Le umidade (unidade %)
    float valor_temperatura_celsius = dht.readTemperature(); //Le temperatura (unidade graus celsius)
    float valor_temperatura_fahrenheit = dht.readTemperature(True); //Le temperatura (unidade graus fahrenheit)

    //Computar o indice de calor em Celsius
    float indice_calor_celsius = dht.computeHeatIndex(valor_temperatura_celsius, valor_umidade, false);
    
    //Computar o indice de calor em Fahrenheit
    float indice_calor_fahrenheit = dht.computeHeatIndex(valor_temperatura_fahrenheit, valor_umidade);

    //Tratamento de Erro de Leitura
    if(isnan(valor_umidade) || isnan(valor_temperatura_celsius) || isnan(valor_temperatura_fahrenheit)){
        Serial.println(F("Falha na leitura do sensor DHT11!"));
        return;
    }

    //Print dos valores
    Serial.println((String)F("Umidade: ")+valor_umidade+F("%"));
    Serial.println((String)F("Temperatura: ")+valor_temperatura_celsius+F("°C | ")+valor_temperatura_fahrenheit+F("°F"));
    Serial.println((String)F("Indice de Temperatura: ")+indice_calor_celsius+F("°C | ")+indice_calor_fahrenheit+F("°F"));


}