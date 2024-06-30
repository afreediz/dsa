const int sensorPin = 2; // Replace with your motion sensor pin
const int ledPin = 13;    // Replace with your LED pin
const int  MOTOR_PIN = 7

int previousState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(7, OUTPUT); // Set pin 7 to output
  digitalWrite(MOTOR_PIN, LOW)
}

void loop() {
  int currentState = digitalRead(sensorPin);
  Serial.begin(9600)
  // Check for motion detected (transition from HIGH to LOW)
  if(currentState == HIGH){
    digitalWrite(MOTOR_PIN, HIGH);
    Serial.println("Pump turned on");
    delay(10000);
    digitalWrite(MOTOR_PIN,LOW);
    Serial.println("Pump turned off");
  }
  previousState = currentState;
  delay(100);                    // Wait for 100 milliseconds
}

