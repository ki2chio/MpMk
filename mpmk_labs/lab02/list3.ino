char incomingByte = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 // Перевірка наявності даних
 if (Serial.available() > 0) {
 // Зчитування даних
 incomingByte = Serial.read();
 // Відправка у монітор
 Serial.print("I received - ");
 Serial.println(incomingByte);
 }
}