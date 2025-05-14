const int pot1 = A0;  
const int pot2 = A1;  

const int buzzer1 = 7;
const int buzzer2 = 8;
const int buzzer3 = 9;

const int leds[] = {2, 3, 4, 5, 6};
const int numLeds = 5;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int val1 = analogRead(pot1);  // POT1
  Serial.print("POT1: ");
  Serial.print(val1);


  digitalWrite(buzzer1, val1 >= 0 && val1 <= 341 ? HIGH : LOW);
  digitalWrite(buzzer2, val1 > 341 && val1 <= 682 ? HIGH : LOW);
  digitalWrite(buzzer3, val1 > 682 && val1 <= 1023 ? HIGH : LOW);

  int val2 = analogRead(pot2);  // POT2
  Serial.print(" | POT2: ");
  Serial.println(val2);

  int delayTime = ((val2 * 900) / 1023) + 100; // From 100ms to 1000ms

  for (int i = 0; i < numLeds; i++) {
    turnOnOneLed(i);
    delay(delayTime);
  }
}

void turnOnOneLed(int index) {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], i == index ? HIGH : LOW);
  }
}

// https://www.tinkercad.com/things/i5ujKSeFk0x/editel?sharecode=Ol2c8y_bYUcSwgnRGGenzPXBPAQv8mON28WXkbucKNU
