const int numbers[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
#define LCHCLK 4 //линия синхронизации
#define STFCLK 7 //линия тактирования
#define SDI 8 //линия передачи данных

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
