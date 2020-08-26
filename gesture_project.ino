const int trigPin = 2;
const int echoPin = 3;
int dist, mDist;
long time_taken;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

//Function to calculate distance
int getDistance(int trigger, int echo){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo,HIGH);
  dist = time_taken*0.034/2;
  if (dist>50){ 
    dist = 50;
  }
  return (dist);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  mDist = getDistance(trigPin,echoPin);
  
  // for play or pause
  /*if (mDist<50 && mDist >35){
    Serial.println("Play/Pause");
    delay(1000);
  }*/
  //Control volume
  if (mDist >=13 && mDist<=18){
    delay(100);//hand-hold time
    mDist = getDistance(trigPin, echoPin);
    if (mDist>=13 && mDist<=18){
      Serial.println("Left Locked");
      while (mDist<=35){
        mDist = getDistance(trigPin,echoPin);
        if (mDist<12){
          Serial.println("Vup");
          delay(300);
        }
        if (mDist>18){
          Serial.println("Vdown");
          delay(300);
        }
      }
    }
    
  }

}
