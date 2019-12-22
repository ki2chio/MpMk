#define LCHCLK 4
#define STFCLK 7
#define SDI 8

void setup()
{
    pinMode(LCHCLK, OUTPUT);
    pinMode(STFCLK, OUTPUT);
    pinMode(SDI,OUTPUT);

    digitalWrite(STFCLK,LOW);
}

void printLed(unsigned char num , unsigned char digit){
	digitalWrite(LCHCLK,LOW);

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

void loop()
{
  for(int i=0; i<255; i++){
      printLed(1,i);
      delay(350);
  }
	// printLed(1,192);
 //  delay(1000);
 //  printLed(1,249);
 //  delay(1000);
 //  printLed(1,164);
 //  delay(1000);
 //  printLed(1,176);
 //  delay(1000);
 //  printLed(1,153);
 //  delay(1000);
 //  printLed(1,146);
 //  delay(1000);
 //  printLed(1,130);
 //  delay(1000);
 //  printLed(1,248);
 //  delay(1000);
 //  printLed(1,128);
 //  delay(1000);
 //  printLed(1,144);
 //  delay(1000);
}
