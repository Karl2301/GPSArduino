void menuinfogps1() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Info GPS :");
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
  lcd.print("Vitesse: "); lcd.print(gps.speed.kmph()); lcd.print(" Km/h");
  lcd.setCursor(0, 1);
  lcd.print("Altitude: "); lcd.print(gps.altitude.meters()); lcd.print(" m");
  lcd.setCursor(0, 2);
  lcd.print("Angle: "); lcd.print(gps.course.deg()); lcd.print(" degree");
  lcd.setCursor(0, 3);
  lcd.print("distance: "); lcd.print(distanceparcouru, 2); lcd.print(" Km");
  Serial.print(distanceparcouru, 2);
}

//2(km) . 0(centaine de metre) 0(dizaine de metre) 0(metre)
