void heureUTC() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Changer l'heure: ");
  lcd.setCursor(0, 1);
  lcd.print("UTC +"); lcd.print(nbrheure);
}
