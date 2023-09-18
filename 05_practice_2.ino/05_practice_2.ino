#define PIN_LED 7
unsigned int count;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  count = 0;
}

void loop() {
  digitalWrite(PIN_LED, count++ & 1);
  delay(count == 1 ? 1000 : 100);
  while(count > 11);
}
