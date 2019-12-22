int sensorPin = A0;
float temperaute;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  temperaute = (analogRead(sensorPin)/1024.0)*5.0*1000/10; 
  Serial.print(temperaute);            
  Serial.println(" C");
  delay(1000);                     
}
