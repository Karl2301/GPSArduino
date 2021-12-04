void menudemtrajet() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Demarrage du trajet");
  lcd.setCursor(0, 2);
  lcd.print("veuillez patienter.");
  delay(1500);
}

void menuarrtrajet() {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Arret du trajet");
  lcd.setCursor(0, 2);
  lcd.print("veuillez patienter");
  delay(1500);
}

void menunotrajet() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("Pas de trajet");
  lcd.setCursor(5, 2);
  lcd.print("en cour !");
  delay(1500);
}

void menuyestrajet() {
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Trajet deja en");
  lcd.setCursor(6, 2);
  lcd.print("cours !");
  delay(1500);
}

void menurestarttrajet() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Redemarrage");
  lcd.setCursor(5, 1);
  lcd.print("du trajet");
  lcd.setCursor(0, 3);
  lcd.print("Trajet: "); lcd.print(nameFile); lcd.print(".kml");
  delay(1500);
}
