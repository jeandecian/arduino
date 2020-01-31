#define HCSR04_ECHO_PIN A2
#define HCSR04_TRIG_PIN A3
#define LED_PIN 13

void setup() {
  pinMode(HCSR04_ECHO_PIN, INPUT);
  pinMode(HCSR04_TRIG_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(HCSR04_TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(HCSR04_TRIG_PIN, LOW);

  float converter = 0.17;
  int distance = pulseIn(HCSR04_ECHO_PIN, HIGH)*converter;

  if (distance < 100) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
