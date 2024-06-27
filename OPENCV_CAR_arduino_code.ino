#define ENA 9
#define IN1 8
#define IN2 7
#define ENB 10
#define IN3 11
#define IN4 12

void setup() {
  Serial.begin(9600);  // Set the baud rate to match the HC-05 module
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'F') {  // Move forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 255);  // Adjust speed as necessary
      analogWrite(ENB, 255);  // Adjust speed as necessary
    } else if (command == 'B') {  // Move backward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 255);  // Adjust speed as necessary
      analogWrite(ENB, 255);  // Adjust speed as necessary
    } else if (command == 'L') {  // Turn left
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 255);  // Adjust speed as necessary
      analogWrite(ENB, 255);  // Adjust speed as necessary
    } else if (command == 'R') {  // Turn right
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 255);  // Adjust speed as necessary
      analogWrite(ENB, 255);  // Adjust speed as necessary
    } else if (command == 'S') {  // Stop
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    }
  }
}
