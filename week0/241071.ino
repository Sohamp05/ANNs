int led[] = {6,5,4,3,2};
int buss[]={12,8,7};
int pot[]={A0,A1};
int b=0;
void setup()
{
  Serial.begin(12000);
  for (int i=0 ; i<5 ; i++){
    pinMode(led[i], OUTPUT);
  }
  for (int i=0 ; i<3 ; i++){
    pinMode(buss[i], OUTPUT);
  }
  for (int i=0 ; i<2 ; i++){
    pinMode(pot[i], INPUT);
  }
}

void loop(){
    float a=(3*analogRead(pot[0]))/1023.0;
  Serial.print(analogRead(pot[0]));
  Serial.print(" : ");
  Serial.println(a);
    if (a<=1){
      digitalWrite(buss[0],HIGH);
      digitalWrite(buss[1],LOW);
      digitalWrite(buss[2],LOW);
    }
    else if (a<=2){
      digitalWrite(buss[1],HIGH);
      digitalWrite(buss[0],LOW);
      digitalWrite(buss[2],LOW);
    }
    else if (a<=3){
      digitalWrite(buss[2],HIGH);
      digitalWrite(buss[0],LOW);
      digitalWrite(buss[1],LOW);
    }
    //long long currT = millis();
    //double deltaT = ((double)(currT - prevT)) / (1.0e6);
   // prevT = currT;
    //timeElapsed += deltaT;
  b=(analogRead(pot[1])+500)/5;
  //while (1){
    LEDF();
  //}
}
int prevT=0;
int k=0;
void LEDF(){
  int currT = millis();
  int deltaT =(currT - prevT);
  if (deltaT>=b){
    prevT=currT;
    for (int i = 0; i < 5; i++) {
      digitalWrite(led[i], LOW);
    }
    digitalWrite(led[k], HIGH);
    if(k<4)k+= 1;
    else k=0;
  }
}

//https://www.tinkercad.com/things/2DKDhpfaNGp-week0tinkercad?sharecode=8DkOQIWDbSqBmCVqmYqHg78WYdPTJcX2h8KGyvfYOEo
    