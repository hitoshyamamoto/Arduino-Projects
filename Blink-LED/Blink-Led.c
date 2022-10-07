//Pinos digitais podem ser de 2 a 13
#define LED_pin 7

//Funcao que inicializa
void setup(){
    //Define o pino do LED como saida de sinal digital
    //Ele pode fornecer 3mA a 15mA dependendo do modelo do Arduino
    //Se a corrente for muito baixa, nao acendera LED
    //Para acender LED, eh necessario ter:
    // - Entre 10mA a 30mA (sendo o mais comum entre 12mA a 20mA)
    // - Entre 1,2V a 3,6V
    // - Resistor em serie com os valores entre 220ohms a 1000ohms
    pinMode(LED_pin, OUTPUT);
}

//Funcao que fica no loop de processo
void loop(){
    digitalWrite(LED_pin, HIGH); // Liga LED
    delay(500); // espera 500ms = 0,5s
    digitalWrite(LED_pin, LOW); //Desliga LED
    delay(500); // espera 500ms = 0,5s
}