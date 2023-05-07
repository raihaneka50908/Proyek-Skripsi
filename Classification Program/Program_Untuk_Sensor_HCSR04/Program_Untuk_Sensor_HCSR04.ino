#define echoPin 2
#define trigPin 3

float duration;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration * 0.034)/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
