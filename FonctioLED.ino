void bleu() {
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(delayled);
  digitalWrite(bluePin, HIGH);
  delay(delayled);
  digitalWrite(bluePin, LOW);
  delay(delayled);
  digitalWrite(bluePin, HIGH);
  delay(delayled);
  digitalWrite(bluePin, LOW);
  delay(delayled);
  digitalWrite(bluePin, HIGH);
  delay(delayled);
}

void rouge() {
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(redPin, LOW);
  delay(delayled);
  digitalWrite(redPin, HIGH);
  delay(delayled);
  digitalWrite(redPin, LOW);
  delay(delayled);
  digitalWrite(redPin, HIGH);
  delay(delayled);
  digitalWrite(redPin, LOW);
  delay(delayled);
  digitalWrite(redPin, HIGH);
  delay(delayled);
}

void vert() {
  digitalWrite(bluePin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(delayled);
  digitalWrite(greenPin, HIGH);
  delay(delayled);
  digitalWrite(greenPin, LOW);
  delay(delayled);
  digitalWrite(greenPin, HIGH);
  delay(delayled);
  digitalWrite(greenPin, LOW);
  delay(delayled);
  digitalWrite(greenPin, HIGH);
  delay(delayled);
}
