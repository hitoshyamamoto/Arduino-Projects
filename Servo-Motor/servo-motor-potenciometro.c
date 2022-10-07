//Inclusao da biblioteca
#include <Servo.h>

//Definir pino digital para o servo-motor
#DEFINE servo_pin = 9;

//Objeto do tipo Servo-Motor
Servo servo_motor;

//Definir pino analogico para potenciometro
int potenciometro_pin = 0;

//Variavel que ira ler o valor do pino analogico do potenciometro
int potenciometro_value;

//Funcao que inicializa o programa
void setup(){
    //Associar pino digital escolhido com o objeto do tipo servo
    servo_motor.attach(servo_pin);
}

//Funcao que fica no loop de processo
void loop(){
    //Faz a leitura do valor do potenciometro entre 0 a 1023
    potenciometro_value = analogRead(potenciometro_pin);
    //Cria uma escala proporcional entre "0 a 1023" com "0 a 180"
    potenciometro_value = map(potenciometro_value, 0, 1023, 0, 180);
    //Coloca o valor a posicao do servo-motor de acordo com a escala
    servo_motor.write(potenciometro_value);
    delay(50); // espera 50ms
}