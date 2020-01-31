#define HCSR04_ECHO_PIN A2
#define HCSR04_TRIG_PIN A3
#define GREEN_LED_PIN 12
#define RED_LED_PIN 13

void setup() {
  pinMode(HCSR04_ECHO_PIN, INPUT);
  pinMode(HCSR04_TRIG_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(HCSR04_TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(HCSR04_TRIG_PIN, LOW);

  float converter = 0.17;
  int distance = pulseIn(HCSR04_ECHO_PIN, HIGH)*converter;

  if (distance < 100) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  }
}
