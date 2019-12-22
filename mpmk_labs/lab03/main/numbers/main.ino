#define LCHCLK 4
#define STFCLK 7
#define SDI 8
#define BUZZ 3

int numbers[] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144};//вывод символов от 0 до 9 согластно масиву
void setup(){
    pinMode(LCHCLK, OUTPUT);
    pinMode(STFCLK, OUTPUT);
    pinMode(SDI,OUTPUT);
    pinMode(BUZZ, OUTPUT);

    digitalWrite(STFCLK,LOW);

    Serial.begin(9600);
}

void printLed(unsigned char num , unsigned char digit){
	digitalWrite(LCHCLK,LOW);
	if(num==4)num=8;
	if(num==3)num=4;		

    for (int i = 7; i >= 0; --i)
    {
    	digitalWrite(SDI, (digit>>i)&1);
    	digitalWrite(STFCLK,HIGH);
    	delayMicroseconds(2);
    	digitalWrite(STFCLK,LOW);
    }

    for (int i = 7; i >= 0; --i)
    {
    	digitalWrite(SDI, (num>>i)&1);
    	digitalWrite(STFCLK,HIGH);
    	delayMicroseconds(2);
    	digitalWrite(STFCLK,LOW);
    }

	digitalWrite(LCHCLK,HIGH);
}

void timer(int time){
    for (int i = 0; i <= time; ++i)
    {
        if(i==time)
        {
            digitalWrite(BUZZ, HIGH);
            delay(1);
            digitalWrite(BUZZ, LOW);
        }
        printLed(1,numbers[i]);
        delay(1000);
    }
    if(i==time)
        {
            digitalWrite(BUZZ, HIGH);
            delay(1);
            digitalWrite(BUZZ, LOW);
        }
}

void loop()
{  
    static int input = 0;
    if (Serial.available() > 0){
    input = Serial.parseInt();
    }
    timer(input);
    input=NULL;
}