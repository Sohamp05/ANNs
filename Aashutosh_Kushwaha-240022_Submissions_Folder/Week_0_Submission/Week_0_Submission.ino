// Pin definitions
const int pot1 = A0;
const int pot2 = A1;

const int buzz1 = 2;
const int buzz2 = 3;
const int buzz3 = 4;

const int ledpin[] = {5, 6, 7, 8, 9};
const int count = 5;

int ledIndex = 0;
long last = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzz1, OUTPUT);
  pinMode(buzz2, OUTPUT);
  pinMode(buzz3, OUTPUT);

  for (int i = 0; i < count; i++) {
    pinMode(ledpin[i], OUTPUT);
  }
}

void loop() {
  
  int pot1Val = analogRead(pot1); 
  int pot2Val = analogRead(pot2);  
  
  
  //Buzzer
  digitalWrite(buzz1, pot1Val <= 341 ? HIGH : LOW);
  digitalWrite(buzz2, (pot1Val > 341 && pot1Val <= 682) ? HIGH : LOW);
  digitalWrite(buzz3, pot1Val > 682 ? HIGH : LOW);

  
  //LED
  long currentMillis = millis();
  int delayTime = map(pot2Val, 0, 1023, 100, 1000); 
  Serial.print("DelayTime: ");
  Serial.println(delayTime);

  if (currentMillis - last >= delayTime) {
    for (int i = 0; i < count; i++) {
      digitalWrite(ledpin[i], LOW);
    }
    
    digitalWrite(ledpin[ledIndex], HIGH);
    ledIndex++;
    
    if (ledIndex >= count) {
      ledIndex = 0;
    }

    last = currentMillis;
  }
}

//TinkerCadLink -https://www.tinkercad.com/things/iOZo9BdsnJH-eclub-summer-week-0-submission-aashutoshkushwaha?sharecode=Zq5sEq8TxFHPhpfizfYIznnk7UHJY8G93zklr_necbg