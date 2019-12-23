#include "7segmentOutput.h"
#include "dht11read.h"

volatile short c_1000ms = 0;
volatile bool flag_1000ms = false;
volatile short c_5ms = 0;
volatile bool flag_5ms = false;
const int buzzer = 3;

int hours=0,minutes=0,seconds=0;

ISR(TIMER1_COMPA_vect){ // обработчик прерывания. Вызывается каждую миллисекунду
 c_1000ms++;
 if(c_1000ms == 1000) { // Выполняем каждые 1c
  flag_1000ms = true;
  c_1000ms = 0;
 }
 c_5ms++;
 if(c_5ms == 5) { // Выполняем каждые 1c
  flag_5ms = true;
  c_5ms = 0;
 }}
void initTimer() { // инициализация Timer1
 cli(); // отключить глобальные прерывания
 TCNT1 = 0;
 TCCR1A = 0; // установить регистр управления А в 0
 TCCR1B = 0;
 TCCR1B |= (1 << WGM12); // включить CTC режим
 TCCR1B |= (0b001 << CS10); // Установить биты на коэффициент деления

 OCR1A = 15999; // установка регистра совпадения
 TIMSK1 |= (1 << OCIE1A); // включить прерывание по совпадению таймера

 sei();} // включить глобальные прерывания

void setup() {
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(A3, INPUT);
 pinMode(LCHCLK,OUTPUT);
 pinMode(STFCLK,OUTPUT);
 pinMode(SDI,OUTPUT);
 pinMode(buzzer, OUTPUT);
 digitalWrite(buzzer, HIGH);
 initTimer();
 inputTime();
}


void loop() {
	if(flag_1000ms) { // Выполняем каждую 1 с
		flag_1000ms = false;
		timeCounter();
		dht_read();
	}
		if(flag_5ms){
		flag_5ms = false;
		writeTimeToSignemt();
	}
}

void writeTimeToSignemt(){
     printLed(1,numbers[minutes / 10]);
     printLed(2,numbers[minutes % 10]);
     printLed(3,numbers[seconds / 10]);
     printLed(4,numbers[seconds % 10]);}
void writeHumToSigment(){
	printLed(1,13);
	printLed(2,12);
	printLed(3,humidity/10);
	printLed(4,humidity%10);}
void writeTempToSignemt(){
	printLed(1,11);
	printLed(2,10);
	printLed(3,temperature/10);   
	printLed(4,temperature%10);}

void timeCounter(){
 seconds++;
 if(seconds==60){
     seconds=0;
     minutes++;
 }
 if(minutes==60){
     minutes=0;
 }}

void inputTime(){
	while(true){
	    if (!digitalRead(A1)){
	    	minutes--;
	    	digitalWrite(buzzer, LOW);
	    	delay(150);
	    	digitalWrite(buzzer, HIGH);
	    }
	    if (!digitalRead(A2)){
	    	minutes++;
	    	digitalWrite(buzzer, LOW);
	    	delay(150);
	    	digitalWrite(buzzer, HIGH);
	    }
	    if (minutes == 60)minutes=0;
	    if (minutes == -1)minutes=59;
	    if (!digitalRead(A3)){
			digitalWrite(buzzer, LOW);
			delay(200);
			digitalWrite(buzzer, HIGH);
	    	break;
	    }
	    writeTimeToSignemt();
	}
	delay(250);
	while(true){
	    if (!digitalRead(A1)){
	    	seconds--;    	
	    	digitalWrite(buzzer, LOW);
	    	delay(150);
	    	digitalWrite(buzzer, HIGH);
	    }
	    delay(70);	    
	    if (!digitalRead(A2)){
	    	seconds++;
	    	digitalWrite(buzzer, LOW);
	    	delay(150);
	    	digitalWrite(buzzer, HIGH);
	    }
	    delay(70);	    
	    if (seconds == 60)seconds=0;
	    if (seconds == -1)seconds=59;
	    if (!digitalRead(A3)){
			digitalWrite(buzzer, LOW);
			delay(200);
			digitalWrite(buzzer, HIGH);
	    	break;
	    }
	    writeTimeToSignemt();   
	}}
