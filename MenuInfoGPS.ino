void menuinfogps1() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Info:");
  lcd.setCursor(0, 1);
  lcd.print("Lat: "); lcd.print(gps.location.lat(), 8);
  lcd.setCursor(0, 2);
  lcd.print("Lon: "); lcd.print(gps.location.lng(), 8);
  lcd.setCursor(0, 3);
  lcd.print("Satellite: "); lcd.print(gps.satellites.value());
}

void menuinfogps2() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vitesse: "); lcd.print(gps.speed.kmph(), 0); lcd.print(" Km/h");
  lcd.setCursor(0, 1);
  lcd.print("Altitude: "); lcd.print(gps.altitude.meters(), 0); lcd.print(" m");
  lcd.setCursor(0, 2);
  lcd.print("Angle: "); lcd.print(gps.course.deg(), 0); lcd.print(" deg");
  lcd.setCursor(0, 3);
  lcd.print("distance: "); lcd.print(distanceparcouru, 2); lcd.print(" Km");
  Serial.print(distanceparcouru, 2);
}

void menuinfogps3() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidite: "); lcd.print(h, 0); lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temperature: "); lcd.print(t, 0); lcd.print(" C");
  lcd.setCursor(0, 2);
  lcd.print("Temp ress.: "); lcd.print(tr, 0); lcd.print(" C");
}
