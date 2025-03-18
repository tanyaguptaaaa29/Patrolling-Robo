// MOTOR PINS
int in1 = 6;   // Control pin 1 for Motor A
int in2 = 7;   // Control pin 2 for Motor A
int in3 = 8;   // Control pin 1 for Motor B
int in4 = 9;   // Control pin 2 for Motor B
int enb = 10;  // Enable pin for Motor B

// ULTRASONIC SENSOR PINS
const int trigPinFront = 11;  // Front sensor
const int echoPinFront = 12;
const int trigPinLeft = 5;    // Left-tilted sensor
const int echoPinLeft = 4;
const int trigPinRight = 3;   // Right-tilted sensor
const int echoPinRight = 2;

// DISTANCE THRESHOLD (in cm)
const int distanceThreshold = 25;

void setup() {
  // Set motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("System initialized with 3 sensors");
}

void loop() {
  // Measure distances from all sensors
  long frontDist = measureDistance(trigPinFront, echoPinFront);
  long leftDist = measureDistance(trigPinLeft, echoPinLeft);
  long rightDist = measureDistance(trigPinRight, echoPinRight);

  // Print distances for debugging
  Serial.print("Front: ");
  Serial.print(frontDist);
  Serial.print("cm\tLeft: ");
  Serial.print(leftDist);
  Serial.print("cm\tRight: ");
  Serial.print(rightDist);
  Serial.println("cm");

  // Enhanced obstacle avoidance logic with else if
  if (frontDist <= distanceThreshold) {
    // Front obstacle detected - make decision
    handleFrontObstacle(leftDist, rightDist);
  } else if (leftDist <= distanceThreshold * 0.7) {
    // Left obstacle too close - adjust right
    Serial.println("Left obstacle close - adjusting right");
    slightRight();
  } else if (rightDist <= distanceThreshold * 0.7) {
    // Right obstacle too close - adjust left
    Serial.println("Right obstacle close - adjusting left");
    slightLeft();
  } else {
    // Clear path - move forward
    moveForward();
  }

  delay(100);
}

void handleFrontObstacle(long leftDist, long rightDist) {
  Serial.println("Front obstacle detected! Taking evasive action...");
  stopMotors();
  reverseCar();
  
  // Re-check side distances after reversing
  if(leftDist <= distanceThreshold && rightDist<= distanceThreshold){
    turn180();
  }
  leftDist = measureDistance(trigPinLeft, echoPinLeft);
  rightDist = measureDistance(trigPinRight, echoPinRight);
  
  if (leftDist > rightDist && leftDist > distanceThreshold) {
    Serial.println("Turning left");
    turnLeft();
  } else if (rightDist > distanceThreshold) {
    Serial.println("Turning right");
    turnRight();
  } else {
    Serial.println("Both sides blocked - Turning 180");
    turn180();
  }
}

// Add slight adjustment functions
void slightRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  // Left motor forward
  digitalWrite(in3, HIGH);  // Right motor reverse
  digitalWrite(in4, LOW);
  analogWrite(enb, 60);
  delay(150);
}

void slightLeft() {
  digitalWrite(in1, HIGH);  // Left motor reverse
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);   // Right motor forward
  digitalWrite(in4, HIGH);
  analogWrite(enb, 60);
  delay(150);
}

long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void handleObstacle(long leftDist, long rightDist) {
  Serial.println("Front obstacle detected! Taking evasive action...");
  stopMotors();
  reverseCar();
  
  // Re-measure side distances after reversing
  leftDist = measureDistance(trigPinLeft, echoPinLeft);
  rightDist = measureDistance(trigPinRight, echoPinRight);
  
  Serial.print("Post-reverse measurements - Left: ");
  Serial.print(leftDist);
  Serial.print("cm\tRight: ");
  Serial.print(rightDist);
  Serial.println("cm");

  // Decision making for turn direction
  if (leftDist > rightDist && leftDist > distanceThreshold) {
    Serial.println("Turning left");
    turnLeft();
  } else if (rightDist > distanceThreshold) {
    Serial.println("Turning right");
    turnRight();
  } else {
    Serial.println("Both sides blocked - Turning 180");
    turn180();
  }
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enb, 0);
}

void moveForward() {
  // Both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 80);
}

void reverseCar() {
  // Both motors reverse
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 80);
  delay(500);
  stopMotors();
}

void turnRight() {
  // Right wheel reverse, left wheel forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 80);
  delay(300);
  stopMotors();
}

void turnLeft() {
  // Left wheel reverse, right wheel forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 80);
  delay(500);
  stopMotors();
}

void turn180() {
  // Perform two consecutive left turns
  turnLeft();
  delay(500);
  turnLeft();
}
