#include "VirtualWire.h"

//Definir Pino Digital para o modulo Receptor (RX)
//Pode ser pino 2 a 13
#define RX_pin 3

//Armazena as mensagens recebidas
byte msg[VW_MAX_MESSAGE_LEN];
//Armazena o tamanho de todas as mensagens recebidas
byte tam_msg = VW_MAX_MESSAGE_LEN;

//Funcao que inicializa o programa
void setup(){
    //Configura a taxa de transferência em bits por segundo (baud rate) para transmissão serial.
    //Baud Rate: a taxa máxima de oscilação num sinal electrónico
    Serial.begin(9600);

    vw_set_rx_pin(RX_pin);  //Define o pino RX_pin como transmissor
    vw_setup(2000);         //Bits por segundo
    vw_rx_start();          //Inicializa o receptor
}

//Funcao que fica no loop de processo
void loop(){
    uint8_t mensagem[VW_MAX_MESSAGE_LEN];
    uint8_t tamanho_mensagem = VW_MAX_MESSAGE_LEN;

    if(nw_get_message(mensagem, &tamanho_mensagem)){
        Serial.print("Recebido: ");

        for(int i=0; i<tamanho_mensagem; i++){
            Serial.write(mensagem[i]);
        }
        Serial.println();
    }
}