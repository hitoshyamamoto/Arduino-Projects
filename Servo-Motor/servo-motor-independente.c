//Inclusao da biblioteca
#include "Servo.h"
 
//Definir pino digital para o servo-motor
#DEFINE servo_pin = 6;

//Objeto do tipo servo-motor
Servo servo_motor;

//Posicao do servo-motor
int servo_pos;

//Funcao que inicializa o programa
void setup (){
    //Associar pino digital escolhido com o objeto do tipo servo
    servo_motor.attach(servo_pin);
    //Inicializa a posicao do motor a zero graus
    servo_motor.write(0);
}

//Funcao que fica no loop de processo
void loop(){
    //Se servo_pos eh igual a 0 e enquanto o servo_pos for menor que 180, incrementa servo_pos
    for(servo_pos = 0; servo_pos < 180; servo_pos++){
        servo_motor.write(servo_pos); //comanda o servo-motor na posicao escrita pelo servo_pos
        delay(100); //espera 100ms
    }
    
    delay(1000); //INTERVALO DE 1 SEGUNDO
    
    //Se servo_pos eh igual a 180 e enquanto o servo_pos for maior que 0, decrementa servo_pos
    for(servo_pos = 180; servo_pos >= 0; servo_pos--){
        servo_motor.write(servo_pos); //comanda o servo-motor na posicao escrita pelo servo_pos
        delay(100); //espera 100ms
    }
}