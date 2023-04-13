#include <Servo.h>

Servo myservo;  // Créer un objet de type Servo pour le joystick
int joyPin = A0;  // Connecter le joystick à la broche analogique A0
int motorPin1 = 9; // Connecter la broche 1 du moteur à la broche 9 de l'Arduino
int motorPin2 = 10; // Connecter la broche 2 du moteur à la broche 10 de l'Arduino

void setup() {
  myservo.attach(joyPin);  // Initialiser le joystick
  pinMode(motorPin1, OUTPUT); // Initialiser la broche 1 du moteur
  pinMode(motorPin2, OUTPUT); // Initialiser la broche 2 du moteur
}

void loop() {
  int joyVal = myservo.read(); // Lire la valeur du joystick
  int motorSpeed = map(joyVal, 0, 1023, 0, 255); // Convertir la valeur du joystick en vitesse du moteur
  
  // Avancer
  if (joyVal > 550) {
    analogWrite(motorPin1, motorSpeed);
    digitalWrite(motorPin2, LOW);
  } 
  // Reculer
  else if (joyVal < 450) {
    analogWrite(motorPin2, motorSpeed);
    digitalWrite(motorPin1, LOW);
  } 
  // Arrêt
  else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
}
