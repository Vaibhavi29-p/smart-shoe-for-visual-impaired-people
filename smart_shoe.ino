// Smart Shoe for Visually Impaired People
// Components: Arduino UNO/Nano, HC-SR04 Ultrasonic Sensor, Vibrating Motor

#define trigPin 9
#define echoPin 10
#define motorPin 3

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If obstacle detected within 50 cm, vibrate motor
  if (distance > 0 && distance < 50) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  delay(200);
}
