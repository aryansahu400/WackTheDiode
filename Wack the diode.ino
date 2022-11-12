int score = 0;
int miss =0;
void printScore() {

  int n = score;
  int arr[6];
  int j = 6;
  while (n > 0) {
    if (n % 2 == 1)arr[j] = 1;
    else arr[j] = 0;

    n = n / 2;
    j--;
  }

  j = 13;
  for (int i = 0; i < 6; i++) {

    if (arr[i] == 1) {
      digitalWrite(j, HIGH);
    } else {
      digitalWrite(j, LOW);
    }
    j--;
  }


}

int hor = A0;
int ver = A1;
int getPos() {
  Serial.println("reached here");
  int ans = 13;
  delay(200);
  int horr = analogRead(hor);
  int verr = analogRead(ver);
//  Serial.println("horr"+horr);
//  Serial.println("ver"+verr);
  if(analogRead(ver)<500){
    Serial.println(5);
    return 2;
  }else if(analogRead(ver)>600){
    Serial.println(3);
    return 4;
  }
  if(analogRead(hor)>600){
    Serial.println(4);
    return 3;
  }else if(analogRead(hor)<400){
    Serial.println(2);
    return 5;
  }
  
  Serial.println(ans);
  return ans;


}
void setup() {
  Serial.begin(115200);
  
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);


}

void loop() {
  Serial.println("loop");
  if(miss==7){
    for(int i=2;i<=13;i++){
      digitalWrite(i, HIGH);
      
    }
    while(true){

    }
  }
  printScore();
  int led = random(2, 6);
  digitalWrite(led, HIGH);
  delay(1000);
  int joyStick = getPos();
  if (joyStick == led) {
    digitalWrite(6, HIGH);
    score += 1;
  } else {
    digitalWrite(7, HIGH);
    miss+=1;
  }
  digitalWrite(led, LOW);
  delay(100);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);

}


