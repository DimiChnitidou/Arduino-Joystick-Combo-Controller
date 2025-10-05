// Joystick combos:
// Left -> RED, Right -> GREEN, Up -> BUZZER (passive), Down -> LASER
// Diagonals trigger combinations (e.g., Up+Left => BUZZER + RED)

const int xPin = A0;      // VRx (οριζόντιος άξονας)
const int yPin = A1;      // VRy (κάθετος άξονας)

const int redLed    = 8;  // αριστερά
const int greenLed  = 9;  // δεξιά
const int buzzerPin = 6;  // πάνω (μπροστά) - passive buzzer
const int laserPin  = 7;  // κάτω (πίσω)

const int center = 512;   // τυπικό κέντρο αναλογικού
int deadzone = 120;       // νεκρή ζώνη γύρω από το κέντρο (ρύθμισε κατά βούληση)

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(laserPin, OUTPUT);

  // αρχικά όλα OFF
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  noTone(buzzerPin);
  digitalWrite(laserPin, LOW);

  Serial.begin(9600);
  Serial.println("Joystick combos: Left=RED, Right=GREEN, Up=BUZZER, Down=LASER, diagonals=combos");
}

void loop() {
  // Διαβάζουμε joystick
  int x = analogRead(xPin);
  int y = analogRead(yPin);

  int dx = x - center;   // <0: αριστερά, >0: δεξιά
  int dy = y - center;   // <0: κάτω,     >0: πάνω

  // Εντοπισμός κατευθύνσεων με deadzone (μπορούν να είναι πολλαπλές ταυτόχρονα)
  bool left  = (dx < -deadzone);
  bool right = (dx >  deadzone);
  bool up    = (dy >  deadzone);
  bool down  = (dy < -deadzone);

  // Εφαρμογή εξόδων: συνδυαστικά
  digitalWrite(redLed,   left  ? HIGH : LOW);
  digitalWrite(greenLed, right ? HIGH : LOW);

  if (up) {
    tone(buzzerPin, 200);   // passive buzzer σε ~2kHz
  } else {
    noTone(buzzerPin);
  }

  digitalWrite(laserPin, down ? HIGH : LOW);

  // Προαιρετικό debugging:
  // Serial.print("dx="); Serial.print(dx);
  // Serial.print(" dy="); Serial.print(dy);
  // Serial.print(" | L="); Serial.print(left);
  // Serial.print(" R="); Serial.print(right);
  // Serial.print(" U="); Serial.print(up);
  // Serial.print(" D="); Serial.println(down);

  delay(10);
}
