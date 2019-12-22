int arr[16]={0,0,1,1,1,1,0,1,0,0,0,0,1,1,0,0};
int incomingByte = 0;
void setup() {               
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}
 
void loop() {
 if (Serial.available()>0)
  {
    incomingByte=0;
    digitalWrite(LED_BUILTIN,HIGH);
    incomingByte = Serial.parseInt();
    if (arr[incomingByte]==true)    {
      Serial.println("true");      
      digitalWrite(LED_BUILTIN,LOW);
    }else Serial.println("false");   
  } 
}