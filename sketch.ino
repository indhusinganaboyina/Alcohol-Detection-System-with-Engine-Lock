#define POT_PIN     A0
#define BUZZER_PIN  5
#define RELAY_PIN   9
#define RED_LED     13

const int alcoholThreshold = 400;

// Typical Wokwi relay module: active LOW
const int RELAY_ON  = LOW;
const int RELAY_OFF = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(POT_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  // Startup buzzer test: sound for 2 seconds
  tone(BUZZER_PIN, 1000);
  delay(2000);
  noTone(BUZZER_PIN);

  Serial.println("Alcohol Detection System Ready");
  Serial.println("Turn potentiometer to change the value.");
}

void loop() {
  int alcoholValue = analogRead(POT_PIN);

  Serial.print("Alcohol Level: ");
  Serial.println(alcoholValue);

  if (alcoholValue >= alcoholThreshold) {
    // Alcohol detected
    tone(BUZZER_PIN, 1000);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RELAY_PIN, RELAY_ON);

    Serial.println("ALCOHOL DETECTED - BUZZER ON");
  } else {
    // No alcohol detected
    noTone(BUZZER_PIN);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY_PIN, RELAY_OFF);

    Serial.println("NO ALCOHOL - BUZZER OFF");
  }

  delay(300);
}
