#include "VirtualWire.h"

//Definir Pino Digital para o modulo Transmissor (TX)
//Pode ser pino 2 a 13
#define TX_pin 8

//Definicao do Buffer para readBytesUntil(character,buffer,length)
const int buffer_size = 100;
char buffer_space[buffer_size];

//Funcao que inicializa o programa
void setup(){
    //Configura a taxa de transferência em bits por segundo (baud rate) para transmissão serial.
    //Baud Rate: a taxa máxima de oscilação num sinal electrónico
    Serial.begin(9600);

    vw_set_tx_pin(TX_pin);  //Define o pino TX_pin como transmissor
    vw_setup(2000);         //Bits por segundo
}

//Funcao que fica no loop de processo
void loop(){
    char dados[buffer_size];
    int posicao_dado;

    if(Serial.available()>0){
        //Serial.readBytesUntil(character, buffer, length)
        //character: caracter que determina a parada
        //buffer: onde os dados serao guardados
        //length: quantidade de bytes a serem lidos no maximo
        posicao_dado = Serial.readBytesUntil('\n',dados,buffer_size);
        dados[posicao_dado] = 0;

        //Informa os dados colocado no buffer
        Serial.print("Enviado : ");
        Serial.print(dados);
        Serial.print(" - Caracteres : ");
        Serial.println(strlen(dados));

        //Funcao que transmite os dados via RF
        send(dados);
    }
}

void send(char *texto){
    vw_send( (uint8_t *)texto, strlen(texto) );
    vw_wait_tx();
}