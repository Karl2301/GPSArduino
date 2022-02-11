void menudistance1() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Calcule distance");
  lcd.setCursor(0, 1);
  lcd.print("lat: ");
  if (distancechoix == 1) {
    if (lonDesti == "") {
      lcd.print(" Definir");
    } else {
      lcd.setCursor(6, 2);
      lcd.print(lonDesti);
    }
  } else {
    if (lonDesti == "") {
      lcd.print(">Definir<");
    } else {
      lcd.setCursor(5, 2);
      lcd.print(">");
      lcd.setCursor(6, 2);
      lcd.print(lonDesti);
    }
  }
  lcd.setCursor(0, 2);
  lcd.print("lat: ");
  if (distancechoix == 2) {
    if (latDesti == "") {
      lcd.print(" Definir");
    } else {
      lcd.setCursor(6, 2);
      lcd.print(latDesti);
    }
  } else {
    if (latDesti == "") {
      lcd.print(">Definir<");
    } else {
      lcd.setCursor(5, 2);
      lcd.print(">");
      lcd.setCursor(6, 2);
      lcd.print(latDesti);
    }
  }

  lcd.setCursor(0, 3);
  if (lonDesti != "" && latDesti != "" && latNOW != 0.0 && lonNOW != 0.0) {
    distance = calcule_distance( latNOW, lonNOW, latDesti.toDouble(), lonDesti.toDouble());
    lcd.print("Distance: ");
    lcd.print(distance, 3);
    lcd.print("Km");
  }

}

void printlatdistance() {
  SD.remove("/p/d/lat.txt");
  myFile = SD.open("/p/d/lat.txt", FILE_WRITE);
  myFile.print(latDesti);
  myFile.close();
  Serial.println("Ecritude de la distance lat");
}

void printlondistance() {
  SD.remove("/p/d/lon.txt");
  myFile = SD.open("/p/d/lon.txt", FILE_WRITE);
  myFile.print(lonDesti);
  myFile.close();
  Serial.println("Ecritude de la distance lon");
}
