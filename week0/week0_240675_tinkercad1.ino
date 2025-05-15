int leds[] = {5, 6, 7, 8, 9};
int numLeds = 5;
float t;
void setup() {
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int POT1 = analogRead(A0);
  float POT2 = analogRead(A1);
  t = (POT2 + 113.666667)/1.1366667; // t goes from 100ms to 1000ms
  Serial.println(t); 
  if (POT1 <= 341) {
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else if (POT1 <= 682) {
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }

  else {
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  } 
  
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);   
    delay(t);                    
    digitalWrite(leds[i], LOW);
  }
 
}

// link for tinkercad : https://www.tinkercad.com/things/0l0nHPfRB40-week0240675tinkercad?sharecode=JU0KvNr0gm8q2cRwti5o1vtSuGSLf-XOqVAkSsbprqw


