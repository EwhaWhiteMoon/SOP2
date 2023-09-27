#define LED_PIN 7

unsigned long _period = 100;
unsigned long _duty = 100;
unsigned long _onTime = 100;

void set_period(int period){
  _period = period;
  _onTime = _duty * (_period / 100);
}

void set_duty(int duty){
  _duty = duty;
  _onTime = _duty * (_period / 100);
}

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_PIN, OUTPUT);
  set_period(10000);
}

// the loop routine runs over and over again forever:
void loop() {

  digitalWrite(LED_PIN, true);
  delayMicroseconds(_onTime);
  digitalWrite(LED_PIN, false);
  delayMicroseconds(_period - _onTime);

  int t = (millis() % 1000) / 10;
  set_duty(t > 50 ? t : 100 - t);

  /*
  if(_pwmTime++ >= _period){
    _pwmTime = 0;
  }
  delayMicroseconds(1);
  */
}
