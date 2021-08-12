#define BUZZER_PIN 8
#define FREQ 2000
#define TIME 500

void setup() {
 pinMode(BUZZER_PIN, OUTPUT);
}

void setTone(int pin, int note, int duration) {
 tone(pin, note, duration);
 delay(duration);
 noTone(pin);
}

void loop() {  //putting the buzzer conditions
 setTone(BUZZER_PIN, FREQ, TIME);
 setTone(BUZZER_PIN, FREQ*2, TIME);
}
