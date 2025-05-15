
const int buzzerPins[3] = {2, 3, 4};
const int ledPins[5] = {5, 6, 7, 8, 9};

const int pot1Pin = A0;
const int pot2Pin = A1;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(buzzerPins[i], OUTPUT);
    digitalWrite(buzzerPins[i], LOW);
  }
  
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  
  int pot1Val = analogRead(pot1Pin);  

  
  int buzzerIndex = pot1Val / 341;
  if (buzzerIndex > 2) buzzerIndex = 2;  

 
  for (int i = 0; i < 3; i++) {
    if (i == buzzerIndex) digitalWrite(buzzerPins[i], HIGH);
    else digitalWrite(buzzerPins[i], LOW);
  }

  
  int pot2Val = analogRead(pot2Pin); 

 
  int ledDelay = map(pot2Val, 0, 1023, 100, 1000);

  
  for (int i = 0; i < 5; i++) {
   
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], LOW);
    }
 
    digitalWrite(ledPins[i], HIGH);

    delay(ledDelay);
   
  }
}
//Tinkercad project link attached below
//https://www.tinkercad.com/things/cxvfV4XPv08/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcodeblocks&sharecode=QQodP8u5JWXg9rt6rK5-w5P16JuvENNPjqo1mqjwJN0