void menutimedate1() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Horloge GPS");
  lcd.setCursor(0, 1);
  lcd.print("Jour: "); lcd.print(jour);
  lcd.setCursor(0, 2);
  lcd.print(Time);
  lcd.setCursor(0, 3);
  lcd.print(Date);
}
